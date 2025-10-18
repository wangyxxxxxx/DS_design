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
#include <QFont>
#include <QDataStream>
#include <QDebug>
using namespace std;


// 相邻矩阵存储结构
class AdjacencyMatrix :public QObject{
    Q_OBJECT
private:
    vector<vector<int>> matrix;
    vector<QString> vertexList;

public:
    AdjacencyMatrix() {}
    ~AdjacencyMatrix() {}

public slots:

    // 顶点操作
    void addVertex(QString vertexId) {

        vertexList.push_back(vertexId);

        vector<int> tempv(vertexList.size(),0);

        for(int i=0;i<vertexList.size()-1;i++) {
            matrix[i].push_back(0);
        }
        matrix.push_back(tempv);

        showMatrix();

    }
    void removeVertex(QString v) {
        int i=0;
        for (i=0;i<vertexList.size()-1;i++) {
            if (vertexList[i] == v) {break;}
        }

        matrix.erase(matrix.begin()+i);

        for (int j=0;j<vertexList.size();j++) {
            matrix[j].erase(matrix[j].begin()+i);
        }

        vertexList.erase(vertexList.begin()+i);

        showMatrix();
    }

    // 边操作
    void addEdge(QString from,QString to,int weight) {
        int i,j;
        for(i=0;i<vertexList.size()-1;i++) {
            if(vertexList[i] == from) {break;}
        }
        for(j=0;j<vertexList.size()-1;j++) {
            if(vertexList[j] == to) {break;}
        }
        matrix[i][j]=weight;
        showMatrix();
    }

    void removeEdge(QString from,QString to) {
        int i,j;
        for(i=0;i<vertexList.size()-1;i++) {
            if(vertexList[i] == from) {break;}
        }
        for(j=0;j<vertexList.size()-1;j++) {
            if(vertexList[j] == to) {break;}
        }
        matrix[i][j]=0;
        showMatrix();
    }

    void showMatrix() {
        cout<<"    "<<vertexList[0].toStdString();
        for (int i = 1; i < vertexList.size(); i++) {
            cout<<"   "<<vertexList[i].toStdString();
        }
        cout<<endl<<"   ";

        for (int i = 0; i < vertexList.size(); i++) {
            cout<<"--- ";
        }
        cout<<endl;

        for(int i=0;i<vertexList.size();i++) {
            cout<<vertexList[i].toStdString()<<" | ";
            for(int j=0;j<vertexList.size();j++) {
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
    QString from;
    EdgeBackend *nextarc;
    int weight;
    int visit;

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
    vector<EdgeBackend*> edgeList;
    int delay;

public:
    AdjacencyList():delay(1000){}
    ~AdjacencyList(){}
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
    void removeVertex(QString v) {
        removeEdge1(v);
        vertexList.erase(vertexList.begin()+findVertexIndex(v));
        showList();
    }

    // 边操作
    void addEdge(QString from, QString to, int weight) {
        EdgeBackend *edge = new EdgeBackend();
        edge->from = from;
        edge->adjvex = to;
        edge->weight = weight;
        edge->visit=0;
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

        edgeList.push_back(edge);

        showList();
    }
    void removeEdge2(QString from,QString to) {
        int i=0;
        for(i=0;i<vertexList.size();i++) {
            if (from == vertexList[i].data) {break;}
        }

        EdgeBackend *temp = vertexList[i].firstarc;

        if (temp -> adjvex == to) {
            vertexList[i].firstarc = temp->nextarc;
        }else {
            while (temp->nextarc != nullptr) {
                if (temp->nextarc->adjvex == to) {
                    temp->nextarc = temp->nextarc->nextarc;
                    break;
                }
                temp = temp->nextarc;
            }

        }

        for (int i=0;i<edgeList.size();i++) {
            if(edgeList[i]->adjvex == to && edgeList[i]->from == from) {
                delete edgeList[i];
                edgeList.erase(edgeList.begin()+i);
            }
        }
        showList();
    }
    void removeEdge1(QString v) {

        for(int i=0;i<vertexList.size();i++) {
            EdgeBackend *temp = vertexList[i].firstarc;
            if (temp == nullptr) {break;}
            if (temp -> adjvex == v) {vertexList[i].firstarc = temp->nextarc;}
            else {
                while (temp->nextarc != nullptr) {
                    if (temp->nextarc->adjvex == v) {
                        temp->nextarc = temp->nextarc->nextarc;
                        break;
                    }
                    temp = temp->nextarc;
                }

            }

        }


        int i=0;
        while (i<edgeList.size()) {
            if (edgeList[i]->from == v || edgeList[i]->adjvex == v) {
                delete edgeList[i];
                edgeList.erase(edgeList.begin()+i);
            }else {
                i++;
            }
        }
    }

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
                emit setvertexcolor(vertexList[vs.top()].data,"green");

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
            emit setvertexcolor(vertexList[i].data,"green");

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
                                emit setvertexcolor(vertexList[j].data,"green");

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

    void MST(QString startVertex) {
        emit resetcolor();

        int minweight,minindex;
        int sum=0;


        for(int i=0; i<vertexList.size(); i++) {
            vertexList[i].visit = 0;
        }

        for(int i=0; i<edgeList.size(); i++) {
            edgeList[i]->visit = 0;
        }


        int out = 0;
        while (out == 0){

            minweight=INT_MAX;
            minindex = -1;

            for (int i=0; i<edgeList.size(); i++) {
                if (edgeList[i]->weight <minweight && edgeList[i]->visit == 0 ) {

                    if (vertexList[findVertexIndex(edgeList[i]->from)].visit == 0 || vertexList[findVertexIndex(edgeList[i]->adjvex)].visit == 0) {
                        minweight=edgeList[i]->weight;
                        minindex=i;
                    }
                }
            }

            edgeList[minindex]->visit = 1;
            vertexList[findVertexIndex(edgeList[minindex]->from)].visit = 1;
            vertexList[findVertexIndex(edgeList[minindex]->adjvex)].visit = 1;
            sum+=edgeList[minindex]->weight;
            emit setedgecolor(edgeList[minindex]->from,edgeList[minindex]->adjvex,"lightgreen");

            // 非阻塞延时
            QEventLoop loop;
            QTimer::singleShot(delay, &loop, &QEventLoop::quit);
            loop.exec();
            // 处理事件，保持UI响应
            QCoreApplication::processEvents();


            //检查是否结束
            int m;
            for (m=0;m<vertexList.size();m++) {
                if (vertexList[m].visit == 0) {break;}
            }
            if (m==vertexList.size()) {out=1;}


        }

        emit showresult(QString::number(sum));




    }

    int findVertexIndex(QString id) {
        int i;
        for (i=0; i < vertexList.size(); i++) {
            if (vertexList[i].data == id) {break;}
        }
        return i;
    }

    void changeDelay(int d) {
        delay=d;
    }


signals:
    void showstruct(QString);
    void showresult(QString);
    void resetcolor();
    void setvertexcolor(QString,QString);
    void setedgecolor(QString,QString,const QColor&);

};




#endif //GRAPH_H




