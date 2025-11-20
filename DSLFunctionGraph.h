//
// Created by 王雨轩 on 25-11-19.
//

#ifndef DSLFUNCTIONGRAPH_H
#define DSLFUNCTIONGRAPH_H

#include <QObject>
#include <iostream>
#include <sstream>
#include <QString>
#include <QWidget>
#include <iostream>
#include <map>
#include <qtextstream.h>
#include <QObject>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QPropertyAnimation>
#include <QGraphicsWidget>
#include <QGraphicsTextItem>
#include <QGraphicsItemGroup>
#include <QGroupBox>
#include <QComboBox>
#include <QTimer>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QMessageBox>
#include <QDoubleValidator>
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <iostream>
#include "Sort.h"
#include "Tool.h"
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
using namespace std;

class DSLGraph :public QObject{
    Q_OBJECT
public:
    DSLGraph() {
        // 使用 lambda 捕获 this 指针
        commands["addv"] = [this](const std::vector<std::string>& args) {
            this->creatVertex(args);
        };
        commands["adde"] = [this](const std::vector<std::string>& args) {
            this->creatEdge(args);
        };
        commands["DFS"] = [this](const std::vector<std::string>& args) {
            this->executeDFS(args);
        };
        commands["BFS"] = [this](const std::vector<std::string>& args) {
            this->executeBFS(args);
        };
        commands["MST"] = [this](const std::vector<std::string>& args) {
            this->executeMST(args);
        };
        commands["delv"] = [this](const std::vector<std::string>& args) {
            this->deletVertex(args);
        };
        commands["dele"] = [this](const std::vector<std::string>& args) {
            this->deletEdge(args);
        };
    };

    ~DSLGraph(){};

    std::map<std::string, std::function<void(const std::vector<std::string>&)>> commands;


public slots:


    // 命令处理函数作为类的静态成员
    void creatVertex(const std::vector<std::string>& args) {


        cout << "execute command creat vertex :" ;
        for (int i = 0; i < args.size(); i++) {
            cout << args[i] << " ";
            emit sendV(QString::fromStdString(args[i]));
        }
        cout << endl;



    }

    void deletVertex(const std::vector<std::string>& args) {

        cout << "execute command delet vertex :" ;
        for (int i = 0; i < args.size(); i++) {
            cout << args[i] << " ";
            emit delV(QString::fromStdString(args[i]));
        }
        cout << endl;



    }

    void creatEdge(const std::vector<std::string>& args) {
        QString strfrom="";
        QString strto="";
        QString weight="";

        cout << "execute command creat edge :" ;
        for (int i = 0; i < args.size(); i++) {
            cout << args[i] << " ";
        }
        strfrom = QString::fromStdString(args[0]);
        strto = QString::fromStdString(args[1]);
        weight = QString::fromStdString(args[2]);
        cout << endl;

        emit sendE(strfrom,strto,weight);

    }

    void deletEdge(const std::vector<std::string>& args) {
        QString strfrom="";
        QString strto="";

        cout << "execute command creat edge :" ;
        for (int i = 0; i < args.size(); i++) {
            cout << args[i] << " ";
        }
        strfrom = QString::fromStdString(args[0]);
        strto = QString::fromStdString(args[1]);
        cout << endl;

        emit delE(strfrom,strto);

    }

    void executeDFS(const std::vector<std::string>& args) {
        QString temp=QString::fromStdString(args[0]);
        cout << "execute command DFS" << endl;
        emit sendSelect("DFS",temp);
    }

    void executeBFS(const std::vector<std::string>& args) {
        QString temp=QString::fromStdString(args[0]);
        cout << "execute command BFS" << endl;
        emit sendSelect("BFS",temp);
    }

    void executeMST(const std::vector<std::string>& args) {
        cout << "execute command MST" << endl;
        emit sendSelect("MST","");
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
    void sendV(QString);
    void delV(QString);
    void sendE(QString,QString,QString);
    void delE(QString,QString);
    void sendSelect(QString,QString);

};



#endif //DSLFUNCTIONGRAPH_H
