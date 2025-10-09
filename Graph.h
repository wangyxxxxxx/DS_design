//
// Created by 王雨轩 on 25-10-5.
//

#ifndef GRAPH_H
#define GRAPH_H

#define _HAS_STD_BYTE 0

#include <iostream>
#include <QString>
#include <vector>
#include <QObject>
#include <QChar>
#include <rpc.h>
using namespace std;
//
// // 顶点结构
// struct VertexBackend {
//
// private:
//     QString id;
// public:
//     VertexBackend(QString i) {
//         id = i;
//     }
// };
//
// // 边结构
// struct EdgeBackend {
//
// private:
//     QString v1;
//     QString v2;
//     int weight;
//
// public:
//     EdgeBackend(QString from, QString to, int w) {
//         v1=from;
//         v2=to;
//         weight=w;
//     }
// };

// 相邻矩阵存储结构
class Adjacency :public QObject{
    Q_OBJECT
private:
    vector<vector<int>> matrix;
    vector<int> vertexList;
    int vertexNum;

public:
    Adjacency() {
        vertexNum = 0;
    }

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
    void addEdge(QString v1,QString v2,int weight) {
        QChar c1 = v1.front();
        QChar c2 = v2.front();
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
        matrix[n2][n1]=weight;
    }

    void removeEdge(int v1, int v2) {}

    void showMatrix() {
        cout<<"    "<<vertexList[0];
        for (int i = 1; i < vertexNum; i++) {
            cout<<"   "<<vertexList[i];
        }
        cout<<endl;
        for(int i=0;i<vertexNum;i++) {
            cout<<vertexList[i]<<"   ";
            for(int j=0;j<vertexNum;j++) {
                cout<<matrix[i][j]<<"   ";
            }
            cout<<endl;
        }
    }

};
//
// // 邻接表节点
// struct AdjListNode {
//     int vertexId;
//     int weight;
//     std::shared_ptr<AdjListNode> next;
//
//     AdjListNode(int id, int w) : vertexId(id), weight(w), next(nullptr) {}
// };
//
// // 邻接表存储结构
// class AdjacencyList {
// private:
//     struct VertexList {
//         Vertex vertex;
//         std::shared_ptr<AdjListNode> head;
//
//         VertexList(const Vertex& v) : vertex(v), head(nullptr) {}
//     };
//
//     std::vector<VertexList> vertices;
//     bool directed;
//
// public:
//     AdjacencyList(bool directed = false);
//
//     // 顶点操作
//     void addVertex(const std::string& label, sf::Vector2f position);
//     void removeVertex(int vertexId);
//
//     // 边操作
//     void addEdge(int from, int to, int weight = 1);
//     void removeEdge(int from, int to);
//
//     // 遍历算法
//     std::vector<int> depthFirstTraversal(int startVertex);
//     std::vector<int> breadthFirstTraversal(int startVertex);
//
//     // 最小生成树
//     std::vector<Edge> primMST();
//     std::vector<Edge> kruskalMST();
//
//     // 获取信息
//     const std::vector<Vertex>& getVertices() const;
//     std::vector<Edge> getEdges() const;
//
//     // 可视化相关
//     void draw(sf::RenderWindow& window);
//     void highlightTraversal(const std::vector<int>& order, sf::Color color);
//     void highlightMST(const std::vector<Edge>& mstEdges);
// };
//
//

#endif //GRAPH_H
