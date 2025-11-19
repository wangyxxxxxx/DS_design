//
// Created by 王雨轩 on 25-11-19.
//

#ifndef DSLFUNCTIONSORT_H
#define DSLFUNCTIONSORT_H


#include <iostream>
#include <map>
#include <qtextstream.h>
#include <QObject>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "GraphWidget.h"

using namespace std;

class DSLSort :public QObject{
    Q_OBJECT
public:
    DSLSort() {
        // 使用 lambda 捕获 this 指针
        commands["seq"] = [this](const std::vector<std::string>& args) {
            this->creatSEQ(args);
        };
        commands["IS"] = [this](const std::vector<std::string>& args) {
            this->executeIS(args);
        };
        commands["SS"] = [this](const std::vector<std::string>& args) {
            this->executeSS(args);
        };
        commands["QS"] = [this](const std::vector<std::string>& args) {
            this->executeQS(args);
        };
    };

    ~DSLSort(){};

    std::map<std::string, std::function<void(const std::vector<std::string>&)>> commands;


public slots:


    // 命令处理函数作为类的静态成员
    void creatSEQ(const std::vector<std::string>& args) {
        QString str="";

        cout << "execute command creat seq :" ;
        for (int i = 0; i < args.size(); i++) {
            cout << args[i] << " ";
            str += args[i] + ",";
        }
        cout << endl;

        emit sendSEQ(str);

    }

    void executeIS(const std::vector<std::string>& args) {
        cout << "execute command IS" << endl;
        emit sendSelectSort("IS");
    }

    void executeSS(const std::vector<std::string>& args) {
        cout << "execute command SS" << endl;
        emit sendSelectSort("IS");
    }

    void executeQS(const std::vector<std::string>& args) {
        cout << "execute command QS" << endl;
        emit sendSelectSort("QS");
    }

    // 执行DSL代码
    void execute(const string& code) {
        cout << "begin to execute commands" << endl;

        istringstream stream(code);
        string line;

        while (getline(stream, line)) {
            // 跳过空行和注释
            if (line.empty() || line[0] == '#') continue;

            // 分割命令和参数
            std::vector<std::string> parts;     // 存储分割后的单词
            std::stringstream ss(line);         // 使用字符串流分割字符串
            std::string part;                   // 临时存储每个单词

            while (ss >> part) {
                parts.push_back(part);          // 将单词添加到向量中
            }

            // 如果分割后没有内容，跳过这一行
            if (parts.empty()) continue;

            // 第一个单词是命令，其余的是参数
            std::string cmd = parts[0];
            // 从第二个元素开始到最后都是参数
            std::vector<std::string> args(parts.begin() + 1, parts.end());

            // 执行命令
            // 在命令映射表中查找命令
            if (commands.find(cmd) != commands.end()) {
                // 如果找到命令，调用对应的处理函数并传入参数
                commands[cmd](args);
            } else {
                // 如果命令不存在，输出错误信息
                std::cout << "Not found command: " << cmd << std::endl;
            }
        }
    }



signals:
    void sendSEQ(QString);
    void sendSelectSort(QString);

};





#endif //DSLFUNCTIONSORT_H
