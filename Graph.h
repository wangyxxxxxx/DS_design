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
#include <rpc.h>
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
        QString showstr;
        //cout<<"    "<<vertexList[0];
        showstr = "     " + QString::number(vertexList[0]);
        for (int i = 1; i < vertexNum; i++) {
            //cout<<"   "<<vertexList[i];
            showstr+="   "+QString::number(vertexList[i]);
        }
        //cout<<endl<<"   ";

        for (int i = 0; i < vertexNum; i++) {
            //cout<<"--- ";
        }
        //cout<<endl;
        showstr+="\n";

        for(int i=0;i<vertexNum;i++) {
            //cout<<vertexList[i]<<" | ";
            showstr+=QString::number(vertexList[i])+" | ";
            for(int j=0;j<vertexNum;j++) {
                //cout<<matrix[i][j]<<"   ";
                showstr+=QString::number(matrix[i][j])+"   ";
            }
            //cout<<endl;
            showstr+="\n";
        }
        //cout<<endl;
        showstr+="\n";
        emit sendshow(showstr);
    }

signals:
    void sendshow(QString);

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
};


// 邻接表存储结构
class AdjacencyList :public QObject{
    Q_OBJECT
private:
    vector<VertexBackend> vertexList;

public:
    AdjacencyList(){}

    // 顶点操作
    void addVertex(QString vertexId) {
        VertexBackend vertex;
        vertex.data = vertexId;
        vertex.firstarc = nullptr;
        vertexList.push_back(vertex);

        showList();
    }
    void removeVertex();

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
        string s;
        EdgeBackend *temp = nullptr;
        for(int i=0;i<vertexList.size();i++) {
            s = vertexList[i].data.toStdString();
            cout<<s;

            if (vertexList[i].firstarc == nullptr) {
                cout<<endl;
                continue;
            }else {
                cout<<"->";
                temp=vertexList[i].firstarc;
                while (temp->nextarc != nullptr) {
                    cout << temp->adjvex.toStdString() << "|"<<temp->weight<<"->";
                    temp = temp->nextarc;
                }
                cout << temp->adjvex.toStdString() << "|"<<temp->weight<<endl;
            }

        }
        cout<<endl;

    }

    // // 遍历算法
    // std::vector<int> depthFirstTraversal(int startVertex);
    // std::vector<int> breadthFirstTraversal(int startVertex);
    //
    // // 最小生成树
    // std::vector<Edge> primMST();
    // std::vector<Edge> kruskalMST();



};



#endif //GRAPH_H
