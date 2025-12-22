//
// Created by 王雨轩 on 25-12-22.
//

#ifndef SPEECHINPUT_H
#define SPEECHINPUT_H

#pragma once

#include <QObject>
#include <QMetaObject>
#include <QString>

#include <atomic>
#include <functional>
#include <thread>

#ifdef _WIN32
  #include <windows.h>

  // 关键修复：避免 sapi 里的 byte 与 std::byte 二义性
  #pragma push_macro("byte")
  #undef byte
  #define byte unsigned char
  #include <sapi.h>
  #pragma pop_macro("byte")
#endif

class SpeechInput final {
public:
    using TextCallback  = std::function<void(const QString&)>;
    using ErrorCallback = std::function<void(const QString&)>;

    SpeechInput() = default;
    ~SpeechInput() { stop(false); }

    SpeechInput(const SpeechInput&) = delete;
    SpeechInput& operator=(const SpeechInput&) = delete;

    // 按下开始：持续听写直到 stop(true) 输出最终文本
    void startHold(QObject* uiContext, TextCallback onFinalText, ErrorCallback onError = {}) {
        stop(false);
        stopFlag_.store(false);
        finalize_.store(true);

        worker_ = std::thread([this, uiContext, onFinalText, onError]() {
#ifndef _WIN32
            postError(uiContext, onError, QStringLiteral("当前语音识别仅实现 Windows（SAPI）。"));
            return;
#else
            HRESULT hrInit = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
            bool needUninit = SUCCEEDED(hrInit);

            if (FAILED(hrInit) && hrInit != RPC_E_CHANGED_MODE) {
                postError(uiContext, onError, QStringLiteral("COM 初始化失败。"));
                return;
            }

            ISpRecognizer* recognizer = nullptr;
            ISpRecoContext* context = nullptr;
            ISpRecoGrammar* grammar = nullptr;

            auto cleanup = [&]() {
                if (grammar)    { grammar->Release();    grammar = nullptr; }
                if (context)    { context->Release();    context = nullptr; }
                if (recognizer) { recognizer->Release(); recognizer = nullptr; }
                if (needUninit) { CoUninitialize(); }
            };

            HRESULT hr = CoCreateInstance(CLSID_SpSharedRecognizer, nullptr, CLSCTX_INPROC_SERVER,
                                          IID_ISpRecognizer, (void**)&recognizer);
            if (FAILED(hr) || !recognizer) {
                cleanup();
                postError(uiContext, onError, QStringLiteral("创建语音识别器失败。"));
                return;
            }

            hr = recognizer->CreateRecoContext(&context);
            if (FAILED(hr) || !context) {
                cleanup();
                postError(uiContext, onError, QStringLiteral("创建识别上下文失败。"));
                return;
            }

            hr = context->SetNotifyWin32Event();
            if (FAILED(hr)) {
                cleanup();
                postError(uiContext, onError, QStringLiteral("设置通知事件失败。"));
                return;
            }

            const ULONGLONG interest =
                (1ULL << SPEI_RECOGNITION) |
                (1ULL << SPEI_FALSE_RECOGNITION);
            context->SetInterest(interest, interest);

            hr = context->CreateGrammar(1, &grammar);
            if (FAILED(hr) || !grammar) {
                cleanup();
                postError(uiContext, onError, QStringLiteral("创建语法失败。"));
                return;
            }

            hr = grammar->LoadDictation(nullptr, SPLO_STATIC);
            if (FAILED(hr)) {
                cleanup();
                postError(uiContext, onError, QStringLiteral("加载听写词典失败（LoadDictation）。"));
                return;
            }

            hr = grammar->SetDictationState(SPRS_ACTIVE);
            if (FAILED(hr)) {
                cleanup();
                postError(uiContext, onError, QStringLiteral("启用听写失败（SetDictationState）。"));
                return;
            }

            HANDLE hEvent = context->GetNotifyEventHandle();
            if (!hEvent) {
                cleanup();
                postError(uiContext, onError, QStringLiteral("获取通知句柄失败。"));
                return;
            }

            QString buffer;

            while (!stopFlag_.load()) {
                DWORD wait = WaitForSingleObject(hEvent, 100);
                if (wait != WAIT_OBJECT_0) continue;

                while (!stopFlag_.load()) {
                    SPEVENT ev{};
                    ULONG fetched = 0;
                    HRESULT hrEv = context->GetEvents(1, &ev, &fetched);
                    if (FAILED(hrEv) || fetched == 0) break;

                    if (ev.eEventId == SPEI_RECOGNITION && ev.elParamType == SPET_LPARAM_IS_OBJECT) {
                        ISpRecoResult* result = reinterpret_cast<ISpRecoResult*>(ev.lParam);
                        if (result) {
                            WCHAR* wtext = nullptr;
                            HRESULT hrText = result->GetText(
                                SP_GETWHOLEPHRASE, SP_GETWHOLEPHRASE, TRUE, &wtext, nullptr
                            );
                            if (SUCCEEDED(hrText) && wtext) {
                                QString seg = QString::fromWCharArray(wtext).trimmed();
                                CoTaskMemFree(wtext);

                                if (!seg.isEmpty()) {
                                    if (!buffer.isEmpty()) buffer += " ";
                                    buffer += seg;
                                }
                            }
                        }
                    }

                    if (ev.elParamType == SPET_LPARAM_IS_OBJECT && ev.lParam) {
                        reinterpret_cast<IUnknown*>(ev.lParam)->Release();
                    } else if (ev.elParamType == SPET_LPARAM_IS_STRING && ev.lParam) {
                        CoTaskMemFree(reinterpret_cast<void*>(ev.lParam));
                    }
                }
            }

            if (grammar) grammar->SetDictationState(SPRS_INACTIVE);

            if (finalize_.load()) {
                QString finalText = buffer.trimmed();
                if (!finalText.isEmpty()) {
                    postText(uiContext, onFinalText, finalText);
                }
            }

            cleanup();
#endif
        });
    }

    // 松开结束：finalize=true 输出最终文字；false 只停止不输出
    void stop(bool finalize = true) {
        finalize_.store(finalize);
        stopFlag_.store(true);
        if (worker_.joinable()) worker_.join();
    }

private:
    std::atomic<bool> stopFlag_{false};
    std::atomic<bool> finalize_{true};
    std::thread worker_;

    static void postText(QObject* ctx, const TextCallback& cb, const QString& text) {
        if (!ctx || !cb) return;
        QMetaObject::invokeMethod(ctx, [cb, text]() { cb(text); }, Qt::QueuedConnection);
    }

    static void postError(QObject* ctx, const ErrorCallback& cb, const QString& err) {
        if (!ctx || !cb) return;
        QMetaObject::invokeMethod(ctx, [cb, err]() { cb(err); }, Qt::QueuedConnection);
    }
};


#endif //SPEECHINPUT_H
