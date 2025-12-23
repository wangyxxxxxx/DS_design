#pragma once

#include <QObject>
#include <QMetaObject>
#include <QString>
#include <QByteArray>
#include <QBuffer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUuid>
#include <QRegularExpression>

#include <QMediaDevices>
#include <QAudioDevice>
#include <QAudioFormat>
#include <QAudioSource>

#include <functional>
#include <memory>
#include <algorithm>
#include <cmath>
#include <thread>
#include <atomic>

#ifdef _WIN32
  #ifndef WIN32_LEAN_AND_MEAN
  #define WIN32_LEAN_AND_MEAN
  #endif
  #include <windows.h>
  #include <winhttp.h>
#endif

class SpeechInput final {
public:
    using TextCallback  = std::function<void(const QString&)>;
    using ErrorCallback = std::function<void(const QString&)>;

    SpeechInput() = default;
    ~SpeechInput() {
        alive_.store(false);
        stop(false);
        if (worker_.joinable()) worker_.join();
    }

    SpeechInput(const SpeechInput&) = delete;
    SpeechInput& operator=(const SpeechInput&) = delete;

    // ✅ 外部输入设置（类比 deepseek 的 setAPI）
    void setCredential(QString appid, QString token) {
        appid_ = clean(appid);
        token_ = clean(token);
    }

    bool hasCredential() const { return !appid_.isEmpty() && !token_.isEmpty(); }

    // 按下开始录音（按住说）
    void startHold(QObject* uiContext, TextCallback onFinalText, ErrorCallback onError = {}) {
        uiContext_ = uiContext;
        onText_ = std::move(onFinalText);
        onError_ = std::move(onError);

        if (recording_) return;

        const QAudioDevice device = QMediaDevices::defaultAudioInput();
        if (device.isNull()) {
            postError(QStringLiteral("未找到可用麦克风设备。"));
            return;
        }

        QAudioFormat fmt;
        fmt.setSampleRate(16000);
        fmt.setChannelCount(1);
        fmt.setSampleFormat(QAudioFormat::Int16);

        if (!device.isFormatSupported(fmt)) {
            fmt = device.preferredFormat();
            if (!fmt.isValid()) {
                postError(QStringLiteral("无法获取有效录音格式。"));
                return;
            }
        }
        format_ = fmt;

        pcm_.clear();
        if (!buffer_) buffer_ = std::make_unique<QBuffer>();
        buffer_->setBuffer(&pcm_);
        buffer_->open(QIODevice::WriteOnly);

        audio_.reset(new QAudioSource(device, format_));
        audio_->start(buffer_.get());

        recording_ = true;
    }

    // 松开停止：上传并转文字
    void stop(bool finalize = true) {
        if (!recording_) return;
        recording_ = false;

        if (audio_) { audio_->stop(); audio_.reset(); }
        if (buffer_) buffer_->close();

        if (!finalize) { pcm_.clear(); return; }

        if (pcm_.isEmpty()) {
            postError(QStringLiteral("未录到音频数据。"));
            return;
        }

        if (!hasCredential()) {
            postError(QStringLiteral("豆包语音 AppID/Token 未设置，请先在主界面点击“设置语音”。"));
            return;
        }

        if (busy_.exchange(true)) {
            postError(QStringLiteral("上一条语音还在识别中，请稍后再试。"));
            return;
        }

        const QByteArray wav = buildWavInt16(pcm_, format_);
        if (wav.isEmpty()) {
            busy_.store(false);
            postError(QStringLiteral("音频转 WAV 失败。"));
            return;
        }

#ifndef _WIN32
        busy_.store(false);
        postError(QStringLiteral("当前 WinHTTP 方案仅支持 Windows。"));
#else
        if (worker_.joinable()) worker_.join();
        worker_ = std::thread([this, wav]() {
            QString err;
            const QString text = recognizeFlashWinHTTP(wav, err);
            busy_.store(false);
            if (!alive_.load()) return;

            if (!err.isEmpty()) { postError(err); return; }
            if (text.trimmed().isEmpty()) { postError(QStringLiteral("识别完成但返回文本为空。")); return; }
            postText(text.trimmed());
        });
#endif
    }

private:
    // ✅ 把所有空白字符都去掉（解决“看起来没问题但401”的情况）
    static QString clean(QString s) {
        s.remove(QRegularExpression("\\s+"));
        return s;
    }

    // PCM -> int16 WAV
    static QByteArray buildWavInt16(const QByteArray& pcmRaw, const QAudioFormat& fmt) {
        if (!fmt.isValid()) return {};

        QByteArray pcm16;
        const int channels = std::max(1, fmt.channelCount());
        const int sampleRate = std::max(8000, fmt.sampleRate());

        auto appendLE16 = [&](qint16 v) {
            pcm16.append(char(v & 0xFF));
            pcm16.append(char((v >> 8) & 0xFF));
        };

        const auto sf = fmt.sampleFormat();
        if (sf == QAudioFormat::Int16) {
            pcm16 = pcmRaw;
        } else if (sf == QAudioFormat::Float) {
            const int count = pcmRaw.size() / 4;
            pcm16.reserve(count * 2);
            const float* f = reinterpret_cast<const float*>(pcmRaw.constData());
            for (int i = 0; i < count; ++i) {
                float x = std::clamp(f[i], -1.0f, 1.0f);
                qint16 v = static_cast<qint16>(std::lrintf(x * 32767.0f));
                appendLE16(v);
            }
        } else if (sf == QAudioFormat::Int32) {
            const int count = pcmRaw.size() / 4;
            pcm16.reserve(count * 2);
            const qint32* p = reinterpret_cast<const qint32*>(pcmRaw.constData());
            for (int i = 0; i < count; ++i) {
                qint16 v = static_cast<qint16>(p[i] >> 16);
                appendLE16(v);
            }
        } else if (sf == QAudioFormat::UInt8) {
            const int count = pcmRaw.size();
            pcm16.reserve(count * 2);
            const unsigned char* p = reinterpret_cast<const unsigned char*>(pcmRaw.constData());
            for (int i = 0; i < count; ++i) {
                int centered = int(p[i]) - 128;
                qint16 v = static_cast<qint16>(centered << 8);
                appendLE16(v);
            }
        } else {
            return {};
        }

        const quint32 dataSize = static_cast<quint32>(pcm16.size());
        const quint16 bitsPerSample = 16;
        const quint16 numChannels = static_cast<quint16>(channels);
        const quint32 byteRate = sampleRate * numChannels * (bitsPerSample / 8);
        const quint16 blockAlign = numChannels * (bitsPerSample / 8);

        QByteArray wav;
        wav.reserve(44 + pcm16.size());

        auto put4 = [&](const char* s) { wav.append(s, 4); };
        auto putLE16 = [&](quint16 v) { wav.append(char(v & 0xFF)); wav.append(char((v >> 8) & 0xFF)); };
        auto putLE32 = [&](quint32 v) {
            wav.append(char(v & 0xFF));
            wav.append(char((v >> 8) & 0xFF));
            wav.append(char((v >> 16) & 0xFF));
            wav.append(char((v >> 24) & 0xFF));
        };

        put4("RIFF"); putLE32(36 + dataSize); put4("WAVE");
        put4("fmt "); putLE32(16); putLE16(1);
        putLE16(numChannels); putLE32(sampleRate); putLE32(byteRate);
        putLE16(blockAlign); putLE16(bitsPerSample);
        put4("data"); putLE32(dataSize);
        wav.append(pcm16);
        return wav;
    }

#ifdef _WIN32
    static std::wstring toW(const QString& s) { return s.toStdWString(); }

    static bool winhttpReadAll(HINTERNET hRequest, QByteArray& out, QString& errOut) {
        out.clear();
        DWORD dwSize = 0;
        for (;;) {
            dwSize = 0;
            if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) {
                errOut = QStringLiteral("WinHttpQueryDataAvailable 失败：%1").arg(GetLastError());
                return false;
            }
            if (dwSize == 0) break;

            QByteArray buf;
            buf.resize((int)dwSize);
            DWORD dwRead = 0;
            if (!WinHttpReadData(hRequest, buf.data(), dwSize, &dwRead)) {
                errOut = QStringLiteral("WinHttpReadData 失败：%1").arg(GetLastError());
                return false;
            }
            buf.resize((int)dwRead);
            out += buf;
        }
        return true;
    }

    static QByteArray winhttpPostJsonHttps(const QString& host,
                                          const QString& path,
                                          const QByteArray& headersUtf8,
                                          const QByteArray& bodyUtf8,
                                          DWORD& httpStatus,
                                          QString& errOut) {
        errOut.clear();
        httpStatus = 0;

        HINTERNET hSession = WinHttpOpen(L"DS_d1/1.0",
                                        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                        WINHTTP_NO_PROXY_NAME,
                                        WINHTTP_NO_PROXY_BYPASS, 0);
        if (!hSession) {
            errOut = QStringLiteral("WinHttpOpen 失败：%1").arg(GetLastError());
            return {};
        }
        WinHttpSetTimeouts(hSession, 8000, 8000, 15000, 15000);

        HINTERNET hConnect = WinHttpConnect(hSession, toW(host).c_str(),
                                            INTERNET_DEFAULT_HTTPS_PORT, 0);
        if (!hConnect) {
            errOut = QStringLiteral("WinHttpConnect 失败：%1").arg(GetLastError());
            WinHttpCloseHandle(hSession);
            return {};
        }

        HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"POST", toW(path).c_str(),
                                                nullptr, WINHTTP_NO_REFERER,
                                                WINHTTP_DEFAULT_ACCEPT_TYPES,
                                                WINHTTP_FLAG_SECURE);
        if (!hRequest) {
            errOut = QStringLiteral("WinHttpOpenRequest 失败：%1").arg(GetLastError());
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return {};
        }

        const QString headersQ = QString::fromUtf8(headersUtf8);
        const std::wstring headersW = headersQ.toStdWString();

        BOOL ok = WinHttpSendRequest(
            hRequest,
            headersW.empty() ? WINHTTP_NO_ADDITIONAL_HEADERS : headersW.c_str(),
            headersW.empty() ? 0 : (DWORD)headersW.size(),
            (LPVOID)bodyUtf8.data(),
            (DWORD)bodyUtf8.size(),
            (DWORD)bodyUtf8.size(),
            0
        );

        if (!ok) {
            errOut = QStringLiteral("WinHttpSendRequest 失败：%1").arg(GetLastError());
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return {};
        }

        ok = WinHttpReceiveResponse(hRequest, nullptr);
        if (!ok) {
            errOut = QStringLiteral("WinHttpReceiveResponse 失败：%1").arg(GetLastError());
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return {};
        }

        DWORD status = 0;
        DWORD statusSize = sizeof(status);
        WinHttpQueryHeaders(hRequest,
                            WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                            WINHTTP_HEADER_NAME_BY_INDEX,
                            &status, &statusSize, WINHTTP_NO_HEADER_INDEX);
        httpStatus = status;

        QByteArray resp;
        if (!winhttpReadAll(hRequest, resp, errOut)) {
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return {};
        }

        WinHttpCloseHandle(hRequest);
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);

        return resp;
    }

    QString recognizeFlashWinHTTP(const QByteArray& wav, QString& errOut) const {
        errOut.clear();
        const QString host = "openspeech.bytedance.com";
        const QString path = "/api/v3/auc/bigmodel/recognize/flash";

        const QByteArray b64 = wav.toBase64(QByteArray::Base64Encoding);

        QJsonObject body;
        body["user"] = QJsonObject{{"uid", "ds_user"}}; // ✅ 不用 appid 当 uid，避免奇怪联动
        body["audio"] = QJsonObject{{"data", QString::fromLatin1(b64)}};
        body["request"] = QJsonObject{{"model_name", "bigmodel"}};
        const QByteArray payload = QJsonDocument(body).toJson(QJsonDocument::Compact);

        const QString reqId = QUuid::createUuid().toString(QUuid::WithoutBraces);

        QByteArray headers;
        headers += "Content-Type: application/json\r\n";
        headers += "Host: " + host.toUtf8() + "\r\n";
        headers += "X-Api-App-Key: " + appid_.toUtf8() + "\r\n";
        headers += "X-Api-Access-Key: " + token_.toUtf8() + "\r\n";
        headers += "X-Api-Resource-Id: volc.bigasr.auc_turbo\r\n";
        headers += "X-Api-Request-Id: " + reqId.toUtf8() + "\r\n";
        headers += "X-Api-Sequence: -1\r\n";

        DWORD httpStatus = 0;
        QString netErr;
        const QByteArray resp = winhttpPostJsonHttps(host, path, headers, payload, httpStatus, netErr);
        if (!netErr.isEmpty()) { errOut = netErr; return {}; }

        if (resp.isEmpty()) {
            errOut = QStringLiteral("豆包语音请求失败：空响应（HTTP %1）。").arg(httpStatus);
            return {};
        }
        if (httpStatus < 200 || httpStatus >= 300) {
            errOut = QStringLiteral("豆包语音请求失败：HTTP %1\n%2").arg(httpStatus).arg(QString::fromUtf8(resp));
            return {};
        }

        QJsonParseError pe{};
        QJsonDocument doc = QJsonDocument::fromJson(resp, &pe);
        if (pe.error != QJsonParseError::NoError || !doc.isObject()) {
            errOut = QStringLiteral("豆包语音返回不是合法 JSON：%1").arg(QString::fromUtf8(resp));
            return {};
        }

        const QJsonObject root = doc.object();
        const QJsonObject result = root.value("result").toObject();
        return result.value("text").toString();
    }
#endif

    void postText(const QString& t) {
        if (!uiContext_ || !onText_) return;
        QMetaObject::invokeMethod(uiContext_, [cb = onText_, t]() { cb(t); }, Qt::QueuedConnection);
    }

    void postError(const QString& e) {
        if (!uiContext_ || !onError_) return;
        QMetaObject::invokeMethod(uiContext_, [cb = onError_, e]() { cb(e); }, Qt::QueuedConnection);
    }

private:
    QObject* uiContext_ = nullptr;
    TextCallback  onText_;
    ErrorCallback onError_;

    std::atomic<bool> alive_{true};
    std::atomic<bool> busy_{false};
    std::thread worker_;

    bool recording_ = false;
    QAudioFormat format_;
    QByteArray pcm_;
    std::unique_ptr<QBuffer> buffer_;
    std::unique_ptr<QAudioSource> audio_;

    // ✅ 不写死：外部 setCredential 设置
    QString appid_;
    QString token_;
};
