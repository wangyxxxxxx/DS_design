#ifndef QWENIMAGETODSL_H
#define QWENIMAGETODSL_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QByteArray>

// Qt JSON（用于稳健解析 DashScope 返回）
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <windows.h>
#include <winhttp.h>

#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <stdexcept>
#include <algorithm>

// 链接 WinHTTP（如果你已在 CMake target_link_libraries 里链接 winhttp，可保留也可删除）
#pragma comment(lib, "winhttp.lib")

class QwenImageToDSL : public QObject {
    Q_OBJECT
public:
    explicit QwenImageToDSL(QObject* parent = nullptr) : QObject(parent) {}

    void setApiKey(const QString& k) { apiKey_ = k.trimmed(); }
    QString apiKey() const { return apiKey_; }

    // imagePath: 本地图片路径
    // extraContext: 可选上下文（例如当前图是有向/无向、已有顶点等），可提升识别准确率
    QString translateImageToDSL(const QString& imagePath, const QString& extraContext = QString()) {
        if (apiKey_.isEmpty()) return "# 错误: 未设置千问(DashScope) API Key\n";

        const QString dataUri = fileToDataUri(imagePath);
        if (dataUri.isEmpty()) return "# 错误: 读取图片失败\n";

        const std::string req = buildRequestJSON(dataUri.toStdString(), extraContext.toStdString());
        std::string resp;
        try {
            resp = postDashScope(req);
        } catch (const std::exception& e) {
            return QString("# 错误: 请求失败: %1\n").arg(e.what());
        }

        const std::string dslOrErr = parseResponse(resp);
        if (dslOrErr.empty()) return "# 错误: 未解析到DSL输出\n";
        return QString::fromStdString(dslOrErr);
    }

private:
    QString apiKey_;

    // DashScope：HTTPs Host/Path
    static constexpr const wchar_t* kHost = L"dashscope.aliyuncs.com";
    static constexpr const wchar_t* kPath = L"/api/v1/services/aigc/multimodal-generation/generation";


    static QString fileToDataUri(const QString& path) {
        QFile f(path);
        if (!f.open(QIODevice::ReadOnly)) return {};

        const QByteArray bytes = f.readAll();
        f.close();

        QString fmt = QFileInfo(path).suffix().toLower();
        if (fmt == "jpg") fmt = "jpeg";
        if (fmt.isEmpty()) fmt = "png";

        const QByteArray b64 = bytes.toBase64();
        return QString("data:image/%1;base64,%2").arg(fmt, QString::fromLatin1(b64));
    }

    static std::string escapeJson(const std::string& s) {
        std::ostringstream o;
        for (char c : s) {
            switch (c) {
                case '\\': o << "\\\\"; break;
                case '\"': o << "\\\""; break;
                case '\n': o << "\\n"; break;
                case '\r': o << "\\r"; break;
                case '\t': o << "\\t"; break;
                default:   o << c; break;
            }
        }
        return o.str();
    }

    static std::string trim(const std::string& s) {
        const char* ws = " \t\r\n";
        const auto b = s.find_first_not_of(ws);
        if (b == std::string::npos) return "";
        const auto e = s.find_last_not_of(ws);
        return s.substr(b, e - b + 1);
    }

    static bool isValidDSLCommandLine(const std::string& line) {
        if (line.empty()) return false;
        if (line[0] == '#') return true;

        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if (cmd.empty()) return false;

        // 命令小写化：避免模型输出 Direct/ADDV 被过滤
        std::transform(cmd.begin(), cmd.end(), cmd.begin(),
                       [](unsigned char c) { return (char)std::tolower(c); });

        static const std::set<std::string> kCmd = {
            // Graph DSL
            "direct","addv","adde","delv","dele","dfs","bfs","prim","kruskal","dijkstra",
            // Sort DSL（保留不影响；即便你不接排序页）
            "seq","is","ss","qs","bs"
        };
        return kCmd.count(cmd) > 0;
    }

    static std::string cleanDSLOutput(const std::string& content) {
        std::stringstream in(content);
        std::stringstream out;
        std::string line;

        while (std::getline(in, line)) {
            if (line.find("```") != std::string::npos) continue;
            line = trim(line);
            if (!line.empty() && isValidDSLCommandLine(line)) {
                out << line << "\n";
            }
        }
        return out.str();
    }

    std::string buildRequestJSON(const std::string& imageDataUri, const std::string& extraContext) const {
        // system prompt：只输出 DSL，不要解释，不要 markdown
        const std::string systemPrompt =
            "你是一个“DSL指令生成器”。请根据用户提供的图片内容生成本项目支持的DSL代码。\n"
            "要求：只输出DSL代码；每条指令一行；不要解释；不要输出markdown代码块。\n"
            "可用指令：\n"
            "【图(Graph)】direct <0|1>；addv <v1> <v2> ...；adde <from> <to> <weight>；delv <v>；dele <from> <to>；"
            "DFS <start>；BFS <start>；Prim <start>；Kruskal；Dijkstra <start>\n"
            "【排序(Sort)】seq <a1> <a2> ...；IS；SS；QS；BS\n"
            "如果图片表达不清导致无法确定，请输出一行：# 错误: 无法从图片确定DSL\n";

        const std::string userText =
            std::string("请理解这张图，并生成DSL。\n")
            + (extraContext.empty() ? "" : (std::string("补充上下文：\n") + extraContext + "\n"));

        // DashScope 协议：model + input.messages + parameters.result_format
        // 注意：Qwen-VL content 支持 array，其中元素可包含 text / image（image 可传 data:image/...;base64,...）
        std::ostringstream json;
        json << "{"
             << "\"model\":\"qwen3-vl-plus\","
             << "\"input\":{"
             <<   "\"messages\":["
             <<     "{"
             <<       "\"role\":\"system\","
             <<       "\"content\":\"" << escapeJson(systemPrompt) << "\""
             <<     "},"
             <<     "{"
             <<       "\"role\":\"user\","
             <<       "\"content\":["
             <<         "{"
             <<           "\"text\":\"" << escapeJson(userText) << "\""
             <<         "},"
             <<         "{"
             <<           "\"image\":\"" << escapeJson(imageDataUri) << "\""
             <<         "}"
             <<       "]"
             <<     "}"
             <<   "]"
             << "},"
             << "\"parameters\":{"
             <<   "\"result_format\":\"message\""
             << "}"
             << "}";
        return json.str();
    }

    std::string postDashScope(const std::string& requestBody) const {
        HINTERNET hSession = nullptr, hConnect = nullptr, hRequest = nullptr;
        try {
            hSession = WinHttpOpen(L"DSL-QwenImage/1.0",
                                   WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                   WINHTTP_NO_PROXY_NAME,
                                   WINHTTP_NO_PROXY_BYPASS, 0);
            if (!hSession) throw std::runtime_error("WinHttpOpen failed");

            hConnect = WinHttpConnect(hSession, kHost, INTERNET_DEFAULT_HTTPS_PORT, 0);
            if (!hConnect) throw std::runtime_error("WinHttpConnect failed");

            hRequest = WinHttpOpenRequest(hConnect, L"POST", kPath,
                                          nullptr, WINHTTP_NO_REFERER,
                                          WINHTTP_DEFAULT_ACCEPT_TYPES,
                                          WINHTTP_FLAG_SECURE);
            if (!hRequest) throw std::runtime_error("WinHttpOpenRequest failed");

            std::wstring auth = L"Authorization: Bearer " + apiKey_.toStdWString() + L"\r\n";
            std::wstring headers = auth + L"Content-Type: application/json\r\n";

            if (!WinHttpAddRequestHeaders(hRequest, headers.c_str(), (DWORD)-1L, WINHTTP_ADDREQ_FLAG_ADD)) {
                throw std::runtime_error("WinHttpAddRequestHeaders failed");
            }

            BOOL ok = WinHttpSendRequest(hRequest,
                                         WINHTTP_NO_ADDITIONAL_HEADERS, 0,
                                         (LPVOID)requestBody.data(),
                                         (DWORD)requestBody.size(),
                                         (DWORD)requestBody.size(),
                                         0);
            if (!ok) throw std::runtime_error("WinHttpSendRequest failed");

            ok = WinHttpReceiveResponse(hRequest, nullptr);
            if (!ok) throw std::runtime_error("WinHttpReceiveResponse failed");

            std::string response;
            DWORD dwSize = 0;
            do {
                if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) break;
                if (dwSize == 0) break;

                std::vector<char> buf(dwSize + 1);
                DWORD dwDownloaded = 0;
                if (!WinHttpReadData(hRequest, buf.data(), dwSize, &dwDownloaded)) break;
                buf[dwDownloaded] = '\0';
                response.append(buf.data(), dwDownloaded);
            } while (dwSize > 0);

            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return response;

        } catch (...) {
            if (hRequest) WinHttpCloseHandle(hRequest);
            if (hConnect) WinHttpCloseHandle(hConnect);
            if (hSession) WinHttpCloseHandle(hSession);
            throw;
        }
    }

    // 解析 DashScope 返回：优先 Qt JSON（避免正则抓不到 content array）
    static std::string parseResponse(const std::string& response) {
        QJsonParseError err{};
        const QByteArray raw = QByteArray::fromStdString(response);
        QJsonDocument doc = QJsonDocument::fromJson(raw, &err);
        if (err.error != QJsonParseError::NoError || !doc.isObject()) {
            return ""; // 让上层显示“未解析到DSL输出”
        }

        QJsonObject root = doc.object();

        // 1) 若有明确错误信息，返回一行错误（方便你在 DSL 框里看到原因）
        if (root.contains("message") && root["message"].isString()) {
            const QString msg = root["message"].toString();
            if (!msg.trimmed().isEmpty()) {
                return cleanDSLOutput(("# 错误: " + msg.toStdString()));
            }
        }

        QString text;

        // 2) DashScope 标准：root["output"]
        if (root.contains("output") && root["output"].isObject()) {
            QJsonObject output = root["output"].toObject();

            // 2.1 output.text（部分返回会直接给）
            if (output.contains("text") && output["text"].isString()) {
                text = output["text"].toString();
            }

            // 2.2 output.choices[0].message.content（可能是 string 或 array）
            if (text.isEmpty() && output.contains("choices") && output["choices"].isArray()) {
                QJsonArray choices = output["choices"].toArray();
                if (!choices.isEmpty() && choices[0].isObject()) {
                    QJsonObject c0 = choices[0].toObject();
                    if (c0.contains("message") && c0["message"].isObject()) {
                        QJsonObject msg = c0["message"].toObject();
                        if (msg.contains("content")) {
                            QJsonValue content = msg["content"];
                            if (content.isString()) {
                                text = content.toString();
                            } else if (content.isArray()) {
                                QJsonArray arr = content.toArray();
                                QStringList parts;
                                for (const auto& v : arr) {
                                    if (!v.isObject()) continue;
                                    QJsonObject obj = v.toObject();
                                    if (obj.contains("text") && obj["text"].isString()) {
                                        parts << obj["text"].toString();
                                    }
                                }
                                text = parts.join("\n");
                            }
                        }
                    }
                }
            }
        }

        // 3) 兼容：OpenAI 兼容模式结构：{"choices":[{"message":{"content":"..."}}]}
        if (text.isEmpty() && root.contains("choices") && root["choices"].isArray()) {
            QJsonArray choices = root["choices"].toArray();
            if (!choices.isEmpty() && choices[0].isObject()) {
                QJsonObject c0 = choices[0].toObject();
                if (c0.contains("message") && c0["message"].isObject()) {
                    QJsonObject msg = c0["message"].toObject();
                    if (msg.contains("content") && msg["content"].isString()) {
                        text = msg["content"].toString();
                    }
                }
            }
        }

        if (text.isEmpty()) return "";
        return cleanDSLOutput(text.toStdString());
    }
};

#endif // QWENIMAGETODSL_H
