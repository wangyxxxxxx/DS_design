
#include <windows.h>
#include <winhttp.h>
#include <QObject>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <regex>
#include <algorithm>
#pragma once
#pragma comment(lib, "winhttp.lib")


class NaturalLanguageToDSL : public QObject{
    Q_OBJECT
private:
    std::wstring api_key;
    std::wstring api_url = L"https://api.deepseek.com/v1/chat/completions";

    // 更新关键词映射表，添加新算法命令
    std::map<std::string, std::vector<std::string>> keyword_mapping = {
        // 排序相关
        {"序列", {"seq"}}, {"数列", {"seq"}}, {"数组", {"seq"}}, {"数据", {"seq"}},
        {"插入排序", {"IS"}}, {"选择排序", {"SS"}}, {"快速排序", {"QS"}}, {"冒泡排序", {"BS"}}, {"排序", {"IS"}},

        // 图方向设置
        {"有向图", {"direct"}}, {"无向图", {"direct"}}, {"有向", {"direct"}}, {"无向", {"direct"}},
        {"方向", {"direct"}}, {"设置方向", {"direct"}},

        // 图顶点操作
        {"顶点", {"addv"}}, {"节点", {"addv"}}, {"添加顶点", {"addv"}}, {"增加顶点", {"addv"}}, {"创建顶点", {"addv"}},
        {"删除顶点", {"delv"}}, {"移除顶点", {"delv"}},

        // 图边操作
        {"边", {"adde"}}, {"连接", {"adde"}}, {"添加边", {"adde"}}, {"增加边", {"adde"}}, {"创建边", {"adde"}},
        {"删除边", {"dele"}}, {"移除边", {"dele"}},

        // 图算法
        {"深度优先", {"DFS"}}, {"深度遍历", {"DFS"}}, {"广度优先", {"BFS"}}, {"广度遍历", {"BFS"}},
        {"最小生成树", {"MST"}}, {"生成树", {"MST"}}, {"普里姆", {"Prim"}}, {"克鲁斯卡尔", {"Kruskal"}},
        {"迪杰斯特拉", {"Dijkstra"}}, {"最短路径", {"Dijkstra"}}
    };

public:
    NaturalLanguageToDSL(const std::wstring& key = L"") : api_key(key) {}

    // 设置API密钥 - 接受QString
    void setApiKey(const QString& key) {
        api_key = key.toStdWString();
        std::cout << "API密钥已设置" << std::endl;
    }

    // 设置API密钥 - 接受std::wstring
    void setApiKey(const std::wstring& key) {
        api_key = key;
        std::cout << "API密钥已设置" << std::endl;
    }

    // 主翻译函数
    std::string translate(const std::string& natural_language) {
        std::string result;

        // 首先尝试DeepSeek API
        if (!api_key.empty()) {
            result = translateWithDeepSeek(natural_language);
            if (!result.empty() && result.find("# 错误") == std::string::npos) {
                std::cout << "=== 使用DeepSeek翻译 ===" << std::endl;
                return result;
            }
        }

        // 如果API失败或没有API密钥，使用关键词匹配
        std::cout << "=== 使用关键词匹配翻译 ===" << std::endl;
        return fallbackTranslation(natural_language);
    }

private:
    // 使用DeepSeek API翻译
    std::string translateWithDeepSeek(const std::string& natural_language) {
        HINTERNET hSession = NULL;
        HINTERNET hConnect = NULL;
        HINTERNET hRequest = NULL;

        try {
            std::cout << "正在调用DeepSeek API..." << std::endl;

            // 初始化WinHTTP
            hSession = WinHttpOpen(L"DSL Translator/1.0",
                                  WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                  WINHTTP_NO_PROXY_NAME,
                                  WINHTTP_NO_PROXY_BYPASS, 0);
            if (!hSession) {
                throw std::runtime_error("WinHttpOpen失败");
            }

            // 设置超时
            WinHttpSetTimeouts(hSession, 10000, 10000, 10000, 10000);

            // 解析URL
            URL_COMPONENTS urlComp = {0};
            urlComp.dwStructSize = sizeof(urlComp);
            urlComp.dwHostNameLength = (DWORD)-1;
            urlComp.dwUrlPathLength = (DWORD)-1;
            urlComp.dwExtraInfoLength = (DWORD)-1;

            if (!WinHttpCrackUrl(api_url.c_str(), (DWORD)api_url.length(), 0, &urlComp)) {
                throw std::runtime_error("URL解析失败");
            }

            // 提取主机名和路径
            std::wstring hostName(urlComp.lpszHostName, urlComp.dwHostNameLength);
            std::wstring urlPath(urlComp.lpszUrlPath, urlComp.dwUrlPathLength);
            if (urlComp.dwExtraInfoLength > 0) {
                urlPath += std::wstring(urlComp.lpszExtraInfo, urlComp.dwExtraInfoLength);
            }

            std::cout << "连接到服务器: " << wideStringToString(hostName) << std::endl;

            // 连接到服务器
            hConnect = WinHttpConnect(hSession, hostName.c_str(), urlComp.nPort, 0);
            if (!hConnect) {
                throw std::runtime_error("WinHttpConnect失败");
            }

            // 创建请求
            hRequest = WinHttpOpenRequest(hConnect, L"POST", urlPath.c_str(),
                                         NULL, WINHTTP_NO_REFERER,
                                         WINHTTP_DEFAULT_ACCEPT_TYPES,
                                         WINHTTP_FLAG_SECURE);
            if (!hRequest) {
                throw std::runtime_error("WinHttpOpenRequest失败");
            }

            // 构建请求JSON
            std::string request_json = buildRequestJSON(natural_language);

            // 设置请求头
            std::wstring headers = L"Content-Type: application/json\r\n";
            headers += L"Authorization: Bearer " + api_key + L"\r\n";
            headers += L"User-Agent: DSL-Translator/1.0\r\n";

            if (!WinHttpAddRequestHeaders(hRequest, headers.c_str(), (DWORD)headers.length(),
                                         WINHTTP_ADDREQ_FLAG_ADD)) {
                throw std::runtime_error("设置请求头失败");
            }

            std::cout << "发送请求到DeepSeek API..." << std::endl;

            // 发送请求
            if (!WinHttpSendRequest(hRequest,
                                   WINHTTP_NO_ADDITIONAL_HEADERS, 0,
                                   (LPVOID)request_json.c_str(),
                                   (DWORD)request_json.length(),
                                   (DWORD)request_json.length(), 0)) {
                throw std::runtime_error("WinHttpSendRequest失败");
            }

            // 接收响应
            if (!WinHttpReceiveResponse(hRequest, NULL)) {
                throw std::runtime_error("WinHttpReceiveResponse失败");
            }

            // 检查HTTP状态码
            DWORD statusCode = 0;
            DWORD sizeofStatusCode = sizeof(statusCode);
            if (!WinHttpQueryHeaders(hRequest,
                                   WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                                   WINHTTP_HEADER_NAME_BY_INDEX,
                                   &statusCode, &sizeofStatusCode, WINHTTP_NO_HEADER_INDEX)) {
                throw std::runtime_error("获取HTTP状态码失败");
            }

            if (statusCode != 200) {
                throw std::runtime_error("HTTP错误: " + std::to_string(statusCode));
            }

            std::cout << "API响应成功，正在读取数据..." << std::endl;

            // 读取响应数据
            std::string response = readResponseData(hRequest);

            // 解析响应
            std::string result = parseResponse(response);

            std::cout << "DeepSeek翻译完成" << std::endl;
            return result;

        } catch (const std::exception& e) {
            std::cerr << "DeepSeek API错误: " << e.what() << std::endl;
            return "# 错误: " + std::string(e.what()) + "\n";
        } catch (...) {
            std::cerr << "DeepSeek API未知错误" << std::endl;
            return "# 错误: 未知错误\n";
        }

        // 清理资源
        if (hRequest) WinHttpCloseHandle(hRequest);
        if (hConnect) WinHttpCloseHandle(hConnect);
        if (hSession) WinHttpCloseHandle(hSession);

        return "";
    }

    // 构建API请求JSON - 更新system prompt以包含新命令
    std::string buildRequestJSON(const std::string& natural_language) {
        std::stringstream json;
        json << "{";
        json << "\"model\": \"deepseek-chat\",";
        json << "\"messages\": [";
        json << "{\"role\": \"system\", \"content\": \"将以下自然语言翻译为排序和图算法的DSL代码。DSL命令包括：\\n排序：seq [数字] - 创建序列，IS - 插入排序，SS - 选择排序，QS - 快速排序\\n图：direct [0/1] - 设置图方向（0无向，1有向），addv [顶点名] - 添加顶点，delv [顶点名] - 删除顶点，adde [起点] [终点] [权重] - 添加边，dele [起点] [终点] - 删除边，DFS [起点] - 深度优先搜索，BFS [起点] - 广度优先搜索，Prim - 普里姆算法，Kruskal - 克鲁斯卡尔算法，Dijkstra - 迪杰斯特拉算法\\n只输出DSL代码，每行一条命令。\"},";
        json << "{\"role\": \"user\", \"content\": \"" << escapeJSON(natural_language) << "\"}";
        json << "],";
        json << "\"temperature\": 0.1,";
        json << "\"max_tokens\": 1000";
        json << "}";

        return json.str();
    }

    // 读取响应数据
    std::string readResponseData(HINTERNET hRequest) {
        std::string response;
        DWORD dwSize = 0;
        DWORD dwDownloaded = 0;

        do {
            // 检查可用数据量
            if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) {
                break;
            }

            if (dwSize == 0) break;

            // 分配缓冲区
            std::vector<char> buffer(dwSize + 1);

            // 读取数据
            if (!WinHttpReadData(hRequest, (LPVOID)buffer.data(), dwSize, &dwDownloaded)) {
                break;
            }

            if (dwDownloaded == 0) break;

            buffer[dwDownloaded] = '\0';
            response.append(buffer.data(), dwDownloaded);

        } while (dwSize > 0);

        return response;
    }

    // 解析API响应
    std::string parseResponse(const std::string& response) {
        try {
            // 查找content字段
            std::regex content_regex("\"content\":\"([^\"]*)\"");
            std::smatch match;

            if (std::regex_search(response, match, content_regex) && match.size() > 1) {
                std::string content = match[1].str();
                content = unescapeJSON(content);

                // 清理输出，只保留DSL命令
                return cleanDSLOutput(content);
            }

            return "";
        } catch (const std::exception& e) {
            std::cerr << "解析响应失败: " << e.what() << std::endl;
            return "";
        }
    }

    // 清理DSL输出
    std::string cleanDSLOutput(const std::string& content) {
        std::stringstream result;
        std::stringstream ss(content);
        std::string line;

        while (std::getline(ss, line)) {
            // 移除代码块标记
            if (line.find("```") != std::string::npos) continue;

            // 移除多余的空格
            line = trim(line);

            // 只保留有效的DSL命令
            if (isValidDSLCommand(line)) {
                result << line << "\n";
            }
        }

        std::string output = result.str();
        return output.empty() ? "" : output;
    }

    // 检查是否为有效的DSL命令 - 添加新命令
    bool isValidDSLCommand(const std::string& line) {
        if (line.empty() || line[0] == '#') return true;

        std::vector<std::string> valid_commands = {
            "seq", "IS", "SS", "QS", "BS",
            "direct", "addv", "delv", "adde", "dele",
            "DFS", "BFS", "Prim", "Kruskal", "Dijkstra"
        };

        std::string first_word = line.substr(0, line.find(' '));
        for (const auto& cmd : valid_commands) {
            if (first_word == cmd) {
                return true;
            }
        }

        return false;
    }

    // 关键词匹配翻译 - 添加新算法支持
    std::string fallbackTranslation(const std::string& natural_language) {
        std::cout << "正在使用关键词匹配..." << std::endl;

        std::stringstream dsl_code;

        // 提取数字序列
        std::vector<int> numbers = extractNumbers(natural_language);

        // 提取顶点名称
        std::vector<std::string> vertices = extractVertices(natural_language);

        // 首先处理图方向设置
        if (containsChinese(natural_language, "有向图") || containsChinese(natural_language, "有向")) {
            dsl_code << "direct 1\n";
            std::cout << "检测到有向图设置" << std::endl;
        } else if (containsChinese(natural_language, "无向图") || containsChinese(natural_language, "无向")) {
            dsl_code << "direct 0\n";
            std::cout << "检测到无向图设置" << std::endl;
        }

        // 根据关键词生成DSL代码
        if (containsChinese(natural_language, "序列") ||
            containsChinese(natural_language, "数列") ||
            containsChinese(natural_language, "数组")) {
            if (!numbers.empty()) {
                dsl_code << "seq";
                for (int num : numbers) {
                    dsl_code << " " << num;
                }
                dsl_code << "\n";
                std::cout << "检测到序列创建命令" << std::endl;
            } else {
                dsl_code << "seq 1 2 3 4 5\n";
                std::cout << "使用默认序列" << std::endl;
            }
        }

        if (containsChinese(natural_language, "插入排序")) {
            dsl_code << "IS\n";
            std::cout << "检测到插入排序命令" << std::endl;
        }

        if (containsChinese(natural_language, "选择排序")) {
            dsl_code << "SS\n";
            std::cout << "检测到选择排序命令" << std::endl;
        }

        if (containsChinese(natural_language, "快速排序")) {
            dsl_code << "QS\n";
            std::cout << "检测到快速排序命令" << std::endl;
        }

        if (containsChinese(natural_language, "顶点") ||
            containsChinese(natural_language, "节点")) {
            for (const auto& vertex : vertices) {
                if (containsChinese(natural_language, "删除") ||
                    containsChinese(natural_language, "移除")) {
                    dsl_code << "delv " << vertex << "\n";
                    std::cout << "检测到删除顶点命令: " << vertex << std::endl;
                } else {
                    dsl_code << "addv " << vertex << "\n";
                    std::cout << "检测到添加顶点命令: " << vertex << std::endl;
                }
            }
            if (vertices.empty()) {
                dsl_code << "addv A\n";
                std::cout << "使用默认顶点A" << std::endl;
            }
        }

        if (containsChinese(natural_language, "边") ||
            containsChinese(natural_language, "连接")) {
            if (vertices.size() >= 2) {
                if (containsChinese(natural_language, "删除") ||
                    containsChinese(natural_language, "移除")) {
                    dsl_code << "dele " << vertices[0] << " " << vertices[1] << "\n";
                    std::cout << "检测到删除边命令: " << vertices[0] << " -> " << vertices[1] << std::endl;
                } else {
                    int weight = extractWeight(natural_language);
                    dsl_code << "adde " << vertices[0] << " " << vertices[1] << " " << weight << "\n";
                    std::cout << "检测到添加边命令: " << vertices[0] << " -> " << vertices[1] << " 权重=" << weight << std::endl;
                }
            }
        }

        if (containsChinese(natural_language, "深度优先")) {
            dsl_code << "DFS " << (vertices.empty() ? "A" : vertices[0]) << "\n";
            std::cout << "检测到深度优先搜索命令" << std::endl;
        }

        if (containsChinese(natural_language, "广度优先")) {
            dsl_code << "BFS " << (vertices.empty() ? "A" : vertices[0]) << "\n";
            std::cout << "检测到广度优先搜索命令" << std::endl;
        }

        // 新增算法命令
        if (containsChinese(natural_language, "普里姆") ||
            containsChinese(natural_language, "最小生成树") ||
            containsChinese(natural_language, "生成树")) {
            dsl_code << "Prim\n";
            std::cout << "检测到普里姆算法命令" << std::endl;
        }

        if (containsChinese(natural_language, "克鲁斯卡尔")) {
            dsl_code << "Kruskal\n";
            std::cout << "检测到克鲁斯卡尔算法命令" << std::endl;
        }

        if (containsChinese(natural_language, "迪杰斯特拉") ||
            containsChinese(natural_language, "最短路径")) {
            dsl_code << "Dijkstra\n";
            std::cout << "检测到迪杰斯特拉算法命令" << std::endl;
        }

        std::string result = dsl_code.str();
        if (result.empty()) {
            std::cout << "无法识别命令: " << natural_language << std::endl;
            return "# 无法识别的命令: " + natural_language + "\n";
        }

        std::cout << "关键词匹配完成" << std::endl;
        return result;
    }

    // 工具函数
    std::string escapeJSON(const std::string& str) {
        std::string result;
        for (char c : str) {
            switch (c) {
                case '\"': result += "\\\""; break;
                case '\\': result += "\\\\"; break;
                case '\b': result += "\\b"; break;
                case '\f': result += "\\f"; break;
                case '\n': result += "\\n"; break;
                case '\r': result += "\\r"; break;
                case '\t': result += "\\t"; break;
                default: result += c; break;
            }
        }
        return result;
    }

    std::string unescapeJSON(const std::string& str) {
        std::string result;
        for (size_t i = 0; i < str.length(); ++i) {
            if (str[i] == '\\' && i + 1 < str.length()) {
                switch (str[i + 1]) {
                    case '\"': result += '\"'; ++i; break;
                    case '\\': result += '\\'; ++i; break;
                    case 'b': result += '\b'; ++i; break;
                    case 'f': result += '\f'; ++i; break;
                    case 'n': result += '\n'; ++i; break;
                    case 'r': result += '\r'; ++i; break;
                    case 't': result += '\t'; ++i; break;
                    default: result += str[i]; break;
                }
            } else {
                result += str[i];
            }
        }
        return result;
    }

    std::string trim(const std::string& str) {
        size_t start = str.find_first_not_of(" \t\n\r");
        if (start == std::string::npos) return "";
        size_t end = str.find_last_not_of(" \t\n\r");
        return str.substr(start, end - start + 1);
    }

    bool containsChinese(const std::string& str, const std::string& substr) {
        return str.find(substr) != std::string::npos;
    }

    std::vector<int> extractNumbers(const std::string& str) {
        std::vector<int> numbers;
        std::regex num_regex("\\d+");
        std::smatch match;

        std::string::const_iterator searchStart(str.cbegin());
        while (std::regex_search(searchStart, str.cend(), match, num_regex)) {
            numbers.push_back(std::stoi(match[0]));
            searchStart = match.suffix().first;
        }

        return numbers;
    }

    std::vector<std::string> extractVertices(const std::string& str) {
        std::vector<std::string> vertices;
        std::regex vertex_regex("[A-Z]");
        std::smatch match;

        std::string::const_iterator searchStart(str.cbegin());
        while (std::regex_search(searchStart, str.cend(), match, vertex_regex)) {
            vertices.push_back(match[0]);
            searchStart = match.suffix().first;
        }

        return vertices;
    }

    int extractWeight(const std::string& str) {
        std::vector<int> numbers = extractNumbers(str);
        return numbers.empty() ? 1 : numbers[0];
    }

    std::string wideStringToString(const std::wstring& wstr) {
        int len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
        std::string str(len, 0);
        WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], len, NULL, NULL);
        return str.c_str();
    }


    public slots:
        void execute(string str) {

        std::vector<std::string> lines;

        // 直接在main函数中处理
        std::istringstream stream(str);
        std::string line;

        while (std::getline(stream, line)) {
            lines.push_back(line);
        }

        string result="";

        for (const auto& test_case : lines) {
            std::cout << "\n=========================================" << std::endl;
            std::cout << "自然语言: " << str << std::endl;
            std::string dsl_code = translate(str);
            std::cout << "生成的DSL代码:\n" << dsl_code;
            result += dsl_code + "\n";
            std::cout << "=========================================" << std::endl;
        }

        QString qstr = QString::fromStdString(escapeJSON(result));

        qstr.replace("\\n", "\n");    // 替换字面的\n
        qstr.replace("\\r\\n", "\n"); // 替换字面的\r\n
        qstr.replace("\r\n", "\n");   // 替换Windows换行符

        emit sendDSL(qstr);
    }

    signals:
        void sendDSL(QString);
};

