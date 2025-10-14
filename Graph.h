//
// Created by 王雨轩 on 25-10-5.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <QString>
#include <string.h>
#include <vector>
#include <QObject>
#include <QChar>
#include <QTimer>
#include <rpc.h>
#include <stack>
#include <queue>
using namespace std;


// 相邻矩阵存储结构
class AdjacencyMatrix :public QObject{
    Q_OBJECT
private:
    vector<vector<int>> matrix;
    vector<int> vertexList;
    int vertexNum;

public:
    AdjacencyMatrix() {
        vertexNum = 0;
    }

public slots:

    // 顶点操作
    void addVertex(QString vertexId) {
        vertexNum++;

        QChar c = vertexId.front();
        int n;
        if (c.isLetter()) {
            n=c.toUpper().unicode() - 'A';
        }else if (c.isDigit()) {
            n=c.toUpper().unicode() - '0';
        }

        vertexList.push_back(n);

        vector<int> tempv(vertexList.size(),0);

        for(int i=0;i<vertexList.size()-1;i++) {
            matrix[i].push_back(0);
        }
        matrix.push_back(tempv);

        showMatrix();

    }
    void removeVertex(){}

    // 边操作
    void addEdge(QString from,QString to,int weight) {
        QChar c1 = from.front();
        QChar c2 = to.front();
        int n1;
        int n2;
        if (c1.isLetter() && c2.isLetter()) {
            n1=c1.toUpper().unicode() - 'A';
            n2=c2.toUpper().unicode() - 'A';
        }else if (c1.isDigit() && c2.isDigit()) {
            n1=c1.toUpper().unicode() - '0';
            n2=c2.toUpper().unicode() - '0';
        }
        matrix[n1][n2]=weight;
        showMatrix();
    }

    void removeEdge(int v1, int v2) {}

    void showMatrix() {
        cout<<"    "<<vertexList[0];
        for (int i = 1; i < vertexNum; i++) {
            cout<<"   "<<vertexList[i];
        }
        cout<<endl<<"   ";

        for (int i = 0; i < vertexNum; i++) {
            cout<<"--- ";
        }
        cout<<endl;

        for(int i=0;i<vertexNum;i++) {
            cout<<vertexList[i]<<" | ";
            for(int j=0;j<vertexNum;j++) {
                cout<<matrix[i][j]<<"   ";
            }
            cout<<endl;
        }
        cout<<endl;
    }



};


// 邻接表存储结构
// 顶点结构


// 边结构
struct EdgeBackend {

    QString adjvex;
    EdgeBackend *nextarc;
    int weight;

};

struct VertexBackend {
    QString data;
    EdgeBackend *firstarc;
    int visit;
};


// 邻接表存储结构
class AdjacencyList :public QObject{
    Q_OBJECT
private:
    vector<VertexBackend> vertexList;
    int delay;

public:
    AdjacencyList():delay(1000){}
public slots:
    // 顶点操作
    void addVertex(QString vertexId) {
        VertexBackend vertex;
        vertex.data = vertexId;
        vertex.firstarc = nullptr;
        vertex.visit=0;
        vertexList.push_back(vertex);

        showList();
    }
    void removeVertex(){}

    // 边操作
    void addEdge(QString from, QString to, int weight) {
        EdgeBackend *edge = new EdgeBackend();
        edge->adjvex = to;
        edge->weight = weight;
        edge->nextarc = nullptr;
        for(int i=0;i<vertexList.size();i++) {
            if (from == vertexList[i].data) {
                if (vertexList[i].firstarc == nullptr) {
                    vertexList[i].firstarc = edge;
                }else{
                    EdgeBackend *temp = vertexList[i].firstarc;
                    while (temp->nextarc != nullptr) {
                        temp = temp->nextarc;
                    }
                    temp->nextarc = edge;
                }
                break;
            }
        }

        showList();
    }
    void removeEdge(int from, int to){}

    void showList() {
        QString showstr="";
        string s;
        EdgeBackend *temp = nullptr;
        for(int i=0;i<vertexList.size();i++) {
            s = vertexList[i].data.toStdString();
            //cout<<s;
            showstr+=s;

            if (vertexList[i].firstarc == nullptr) {
                //cout<<endl;
                showstr+="\n";
                continue;
            }else {
                //cout<<"->";
                showstr+="->";
                temp=vertexList[i].firstarc;
                while (temp->nextarc != nullptr) {
                    //cout << temp->adjvex.toStdString() << "|"<<temp->weight<<"->";
                    showstr+=temp->adjvex + "|" + QString::number(temp->weight) + "->";
                    temp = temp->nextarc;
                }
                //cout << temp->adjvex.toStdString() << "|"<<temp->weight<<endl;
                showstr+= temp->adjvex + "|" + QString::number(temp->weight) + "\n";
            }

        }
        //cout<<endl;
        showstr+="\n";

        emit showstruct(showstr);
    }

    // // 遍历算法
    void DFT(QString startVertex) {
        emit resetcolor();

        stack<int> vs,ts;

        QString result="";

        for(int i=0; i<vertexList.size(); i++) {
            vertexList[i].visit = 0;
        }

        int startIndex = -1;
        for(int i=0; i<vertexList.size(); i++) {
            if(vertexList[i].data == startVertex) {
                startIndex = i;
                break;
            }
        }


        int out=0;
        for (int i = startIndex; i != startIndex || out != 1 ; i++,i=i%vertexList.size()) {
            if (i==startIndex-1 || i==startIndex-1+vertexList.size()) {out++;}

            vs.push(i);
            EdgeBackend* temp;
            while (!vs.empty()) {

                if (vertexList[vs.top()].visit == 1) {break;}
                vertexList[vs.top()].visit = 1;

                qDebug() << vertexList[vs.top()].data;
                result+=vertexList[vs.top()].data + " ";
                emit setcolor(vertexList[vs.top()].data,"green");

                // 非阻塞延时
                QEventLoop loop;
                QTimer::singleShot(delay, &loop, &QEventLoop::quit);
                loop.exec();
                // 处理事件，保持UI响应
                QCoreApplication::processEvents();

                if (vertexList[vs.top()].firstarc == nullptr) {vs.pop();break;}
                temp=vertexList[vs.top()].firstarc;
                vs.pop();


                while (temp!=nullptr) {
                    for (int j=0; j<vertexList.size(); j++) {
                        if (vertexList[j].data == temp->adjvex) {
                            ts.push(j);
                        }
                    }
                    temp=temp->nextarc;

                }

                while(!ts.empty()) {
                    vs.push(ts.top());
                    ts.pop();
                }


            }





        }

        emit showresult(result);

    }

    void BFT(QString startVertex) {
        emit resetcolor();

        stack<int> vs,ts;

        QString result="";

        for(int i=0; i<vertexList.size(); i++) {
            vertexList[i].visit = 0;
        }

        int startIndex = -1;
        for(int i=0; i<vertexList.size(); i++) {
            if(vertexList[i].data == startVertex) {
                startIndex = i;
                break;
            }
        }



        int out=0;
        for (int i = startIndex; i != startIndex || out != 1 ; i++,i=i%vertexList.size()) {
            if (i==startIndex-1 || i==startIndex-1+vertexList.size()) {out++;}

            if (vertexList[i].visit == 1) {continue;}

            vs.push(i);

            qDebug() << vertexList[i].data;
            result+=vertexList[i].data + " ";
            emit setcolor(vertexList[i].data,"green");

            // 非阻塞延时
            QEventLoop loop;
            QTimer::singleShot(delay, &loop, &QEventLoop::quit);
            loop.exec();
            // 处理事件，保持UI响应
            QCoreApplication::processEvents();

            vertexList[i].visit = 1;
            EdgeBackend* temp;

            while (!vs.empty()){
                while (!vs.empty()) {

                    if (vertexList[vs.top()].firstarc == nullptr) {vs.pop();break;}
                    temp=vertexList[vs.top()].firstarc;
                    vs.pop();

                    while (temp!=nullptr) {
                        for (int j=0; j<vertexList.size(); j++) {
                            if (vertexList[j].data == temp->adjvex) {
                                if (vertexList[j].visit == 1) {break;}
                                vertexList[j].visit = 1;
                                qDebug() << vertexList[j].data;
                                result+=vertexList[j].data + " ";
                                emit setcolor(vertexList[j].data,"green");

                                ts.push(j);

                                // 非阻塞延时
                                QEventLoop loop;
                                QTimer::singleShot(delay, &loop, &QEventLoop::quit);
                                loop.exec();
                                // 处理事件，保持UI响应
                                QCoreApplication::processEvents();


                            }
                        }
                        temp=temp->nextarc;

                    }
                }

                while(!ts.empty()) {
                    vs.push(ts.top());
                    ts.pop();
                }
            }


        }

        emit showresult(result);


    }

    void MST(QString startVertex){cout<<"MST";}


signals:
    void showstruct(QString);
    void showresult(QString);
    void resetcolor();
    void setcolor(QString,QString);

};



#endif //GRAPH_H


// vs.push(i);
// EdgeBackend* temp;
// while (!vs.empty()) {
//
//     if (vertexList[vs.top()].visit == 1) {break;}
//     vertexList[vs.top()].visit = 1;
//     qDebug() << vertexList[vs.top()].data;
//     result+=vertexList[vs.top()].data + " ";
//
//     if (vertexList[vs.top()].firstarc == nullptr) {vs.pop();break;}
//     temp=vertexList[vs.top()].firstarc;
//     vs.pop();
//
//     while (temp!=nullptr) {
//         for (int j=0; j<vertexList.size(); j++) {
//             if (vertexList[j].data == temp->adjvex) {
//                 vs.push(j);
//             }
//         }
//         temp=temp->nextarc;
//
//     }
//
//
// }




