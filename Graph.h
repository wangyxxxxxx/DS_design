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

        vertexList.erase(vertexList.begin()+i);

        for (int j=0;j<vertexList.size();j++) {
            matrix[j].erase(matrix[j].begin()+i);
        }


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

    void setWeight(QString from,QString to,int weight) {
        int m,n;
        for(int i=0;i<vertexList.size();i++) {
            if(vertexList[i] == from) {
                m=i;
            }

            if(vertexList[i] == to) {
                n=i;
            }
        }

        matrix[m][n]=weight;
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

    void clearall() {
        for (auto& innerVec : matrix) {
            innerVec.clear();           // 清空元素
            innerVec.shrink_to_fit();   // 释放内存
        }

        // 清空外层 vector 的内存
        matrix.clear();           // 清空元素
        matrix.shrink_to_fit();   // 释放内存

        vertexList.clear();
    }

    void showMatrix() {
        string showmatrix="";
        cout<<"    "<<vertexList[0].toStdString();
        showmatrix += ",("+vertexList[0].toStdString()+")";
        for (int i = 1; i < vertexList.size(); i++) {
            cout<<"   "<<vertexList[i].toStdString();
            showmatrix += ",("+vertexList[i].toStdString()+")";
        }
        cout<<endl<<"   ";

        for (int i = 0; i < vertexList.size(); i++) {
            cout<<"--- ";
        }
        cout<<endl;
        showmatrix += '@';

        for(int i=0;i<vertexList.size();i++) {
            cout<<vertexList[i].toStdString()<<" | ";
            showmatrix += "("+vertexList[i].toStdString() +")";
            for(int j=0;j<vertexList.size();j++) {
                cout<<matrix[i][j]<<"   ";
                showmatrix += "<["+to_string(matrix[i][j])+"]";
            }
            cout<<endl;
            showmatrix += '@';
        }
        cout<<endl;
        emit showmatrixstruct(showmatrix);
        cout<<showmatrix<<endl;
    }


signals:
    void showmatrixstruct(string);



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
    int isdirect;

public:
    AdjacencyList():delay(1000){isdirect=1;}
    ~AdjacencyList(){}
public slots:
    void setDirect(int d) {
        isdirect=d;
    }

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
    void setWeight(QString from,QString to,int weight) {

        for(int i=0;i<edgeList.size();i++) {
            if (edgeList[i]->from == from && edgeList[i]->adjvex == to) {

                edgeList[i]->weight = weight;
                break;
            }

        }
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
            if (temp == nullptr) {continue;}

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
        string s;
        string showstr = "";
        EdgeBackend *temp = nullptr;
        for(int i=0;i<vertexList.size();i++) {
            s = vertexList[i].data.toStdString();
            cout<<s;
            showstr += "("+s+")";

            if (vertexList[i].firstarc == nullptr) {
                cout<<endl;
                showstr += "@";
                continue;
            }else {
                cout<<"->";
                showstr += "->";
                temp=vertexList[i].firstarc;
                while (temp->nextarc != nullptr) {
                    cout << temp->adjvex.toStdString() << "|"<<temp->weight<<"->";
                    showstr += "("+temp->adjvex.toStdString() +")"+ "|" + "["+QString::number(temp->weight).toStdString() +"]"+ "->";
                    temp = temp->nextarc;
                }
                cout << temp->adjvex.toStdString() << "|"<<temp->weight<<endl;
                showstr += "("+temp->adjvex.toStdString()+")" + "|" + "["+QString::number(temp->weight).toStdString() +"]"+ "@";
            }

        }
        //showstr = showstr - "@";
        cout<<endl;

        emit showstruct(showstr);
        cout<<showstr<<endl;

    }

    void clearall() {
        //清除点
        vertexList.clear();
        //清除边
        for (auto* ptr : edgeList) {
            delete ptr;
        }
        edgeList.clear();
    }



    void DFT(QString startVertex) {
        // 重置所有顶点和边的访问状态
        for (auto& vertex : vertexList) {
            vertex.visit = 0;
        }
        for (auto* edge : edgeList) {
            edge->visit = 0;
        }

        emit resetcolor();

        vector<QString> result;

        // 如果有指定起始顶点，从该顶点开始
        if (!startVertex.isEmpty()) {
            int startIndex = findVertexIndex(startVertex);
            if (startIndex >= vertexList.size()) {
                emit showresult("起始顶点不存在！");
                return;
            }

            // 从指定顶点开始DFS
            DFSFromVertex(startIndex, result);
        }

        // 遍历所有未访问的顶点（处理多个连通分支）
        for (int i = 0; i < vertexList.size(); ++i) {
            if (vertexList[i].visit == 0) {
                // 非阻塞延时，区分不同连通分支
                QEventLoop loop;
                QTimer::singleShot(delay, &loop, &QEventLoop::quit);
                loop.exec();
                QCoreApplication::processEvents();

                // 开始新的连通分支
                DFSFromVertex(i, result);
            }
        }

        // 显示遍历结果
        QString traversalResult = "DFS遍历结果: ";
        for (int i = 0; i < result.size(); ++i) {
            traversalResult += result[i];
            if (i < result.size() - 1) {
                traversalResult += " -> ";
            }
        }
        emit showresult(traversalResult);
    }

    // 从指定顶点开始DFS
    void DFSFromVertex(int startIndex, vector<QString>& result) {
        // 使用栈实现DFS
        stack<int> vertexStack;

        // 访问起始顶点
        vertexList[startIndex].visit = 1;
        vertexStack.push(startIndex);
        result.push_back(vertexList[startIndex].data);

        // 设置起始顶点颜色
        emit setvertexcolor(vertexList[startIndex].data, "green");

        // 非阻塞延时
        QEventLoop loop;
        QTimer::singleShot(delay, &loop, &QEventLoop::quit);
        loop.exec();
        QCoreApplication::processEvents();

        while (!vertexStack.empty()) {
            int currentIndex = vertexStack.top();
            bool foundUnvisited = false;

            // 遍历当前顶点的所有邻接边
            EdgeBackend* currentEdge = vertexList[currentIndex].firstarc;
            while (currentEdge != nullptr) {
                // 找到邻接顶点的索引
                int adjIndex = findVertexIndex(currentEdge->adjvex);

                if (adjIndex < vertexList.size() && vertexList[adjIndex].visit == 0) {
                    // 标记边为已访问
                    currentEdge->visit = 1;

                    // 对于无向图，需要同时标记反向边
                    if (isdirect == 0) {
                        markReverseEdge(currentEdge->from, currentEdge->adjvex);
                    }

                    // 访问邻接顶点
                    vertexList[adjIndex].visit = 1;
                    vertexStack.push(adjIndex);
                    result.push_back(vertexList[adjIndex].data);



                    // 非阻塞延时
                    QEventLoop loop;
                    QTimer::singleShot(delay, &loop, &QEventLoop::quit);
                    loop.exec();
                    QCoreApplication::processEvents();

                    emit setvertexcolor(vertexList[adjIndex].data, "green");

                    // 非阻塞延时
                    QEventLoop loop2;
                    QTimer::singleShot(delay, &loop2, &QEventLoop::quit);
                    loop2.exec();
                    QCoreApplication::processEvents();

                    foundUnvisited = true;
                    break;
                }
                currentEdge = currentEdge->nextarc;
            }

            // 如果没有找到未访问的邻接顶点，则回溯
            if (!foundUnvisited) {
                vertexStack.pop();
            }
        }
    }

    // 辅助函数：标记反向边（用于无向图）
    void markReverseEdge(QString from, QString to) {
        // 找到to顶点的索引
        int toIndex = findVertexIndex(to);
        if (toIndex >= vertexList.size()) return;

        // 在to顶点的边链表中找到指向from的边
        EdgeBackend* edge = vertexList[toIndex].firstarc;
        while (edge != nullptr) {
            if (edge->adjvex == from) {
                edge->visit = 1;
                break;
            }
            edge = edge->nextarc;
        }

        // 同时在edgeList中标记
        for (auto* e : edgeList) {
            if (e->from == to && e->adjvex == from) {
                e->visit = 1;
                break;
            }
        }
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

    void Kruskal(QString startVertex) {
        emit resetcolor();

        // 1. 从邻接表中提取所有边
        QVector<EdgeBackend*> allEdges;
        QSet<QString> edgeSet; // 用于去重（无向图每条边存储了两次）

        for(int i = 0; i < vertexList.size(); i++) {
            EdgeBackend* edge = vertexList[i].firstarc;
            while(edge != nullptr) {
                // 使用排序的顶点名称作为键来去重
                QString key1 = vertexList[i].data + "-" + edge->adjvex;
                QString key2 = edge->adjvex + "-" + vertexList[i].data;

                if(!edgeSet.contains(key1) && !edgeSet.contains(key2)) {
                    allEdges.append(edge);
                    edgeSet.insert(key1);
                }
                edge = edge->nextarc;
            }
        }

        // 2. 初始化并查集
        QVector<int> parent(vertexList.size());
        for(int i = 0; i < vertexList.size(); i++) {
            parent[i] = i;
        }

        // 查找函数（带路径压缩）
        auto find = [&](int x) {
            int root = x;
            while(parent[root] != root) {
                root = parent[root];
            }

            // 路径压缩
            while(parent[x] != root) {
                int next = parent[x];
                parent[x] = root;
                x = next;
            }
            return root;
        };

        // 3. 对边按权重排序
        std::sort(allEdges.begin(), allEdges.end(),
                  [](EdgeBackend* a, EdgeBackend* b) {
                      return a->weight < b->weight;
                  });

        // 4. 重置访问状态
        for(int i = 0; i < vertexList.size(); i++) {
            vertexList[i].visit = 0;
        }
        for(int i = 0; i < allEdges.size(); i++) {
            allEdges[i]->visit = 0;
        }

        int sum = 0;
        int edgesSelected = 0;
        int totalVertices = vertexList.size();

        // 5. Kruskal算法主循环
        for(int i = 0; i < allEdges.size() && edgesSelected < totalVertices - 1; i++) {
            EdgeBackend* edge = allEdges[i];

            // 找到边的两个端点在vertexList中的索引
            int u = -1, v = -1;
            for(int j = 0; j < vertexList.size(); j++) {
                if(vertexList[j].data == edge->from) u = j;
                if(vertexList[j].data == edge->adjvex) v = j;
                if(u != -1 && v != -1) break;
            }

            if(u == -1 || v == -1) continue; // 顶点未找到，跳过

            int rootU = find(u);
            int rootV = find(v);

            // 如果两个顶点不在同一集合中，选择这条边
            if(rootU != rootV) {
                // 合并集合
                parent[rootV] = rootU;

                edge->visit = 1;
                sum += edge->weight;
                edgesSelected++;

                // 标记顶点为已访问（用于可视化）
                vertexList[u].visit = 1;
                vertexList[v].visit = 1;

                // 可视化
                emit setedgecolor(edge->from, edge->adjvex, "lightgreen");
                emit setedgecolor(edge->adjvex, edge->from, "lightgreen");

                // 非阻塞延时
                QEventLoop loop;
                QTimer::singleShot(delay, &loop, &QEventLoop::quit);
                loop.exec();

                // 处理事件，保持UI响应
                QCoreApplication::processEvents();
            }
        }

        emit showresult(QString::number(sum));
    }

    void Prim(QString startVertex) {
        emit resetcolor();

        // 检查是否为空图
        if (vertexList.empty()) {
            emit showresult("图为空！");
            return;
        }

        // 找到起始顶点索引
        int startIndex = findVertexIndex(startVertex);
        if (startIndex >= vertexList.size()) {
            emit showresult("起始顶点不存在！");
            return;
        }

        int n = vertexList.size();
        vector<int> key(n, INT_MAX);        // 存储顶点到MST的最小权值
        vector<int> parent(n, -1);          // 存储MST中顶点的父节点
        vector<bool> inMST(n, false);       // 标记顶点是否已在MST中

        // 初始化起始顶点
        key[startIndex] = 0;
        parent[startIndex] = -1;

        int totalWeight = 0;
        int edgesSelected = 0;

        // 需要选择n-1条边
        for (int count = 0; count < n; count++) {
            // 找到不在MST中且具有最小key值的顶点
            int minKey = INT_MAX;
            int u = -1;

            for (int v = 0; v < n; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            if (u == -1) {
                // 图不连通
                emit showresult("图不连通，无法构建最小生成树！");
                return;
            }

            // 将顶点u加入MST
            inMST[u] = true;

            // 如果不是起始顶点，标记对应的边并累加权值
            if (parent[u] != -1) {
                QString fromVertex = vertexList[parent[u]].data;
                QString toVertex = vertexList[u].data;

                emit setedgecolor(fromVertex, toVertex, "lightgreen");
                emit setedgecolor(toVertex, fromVertex, "lightgreen");
                // if (isdirect == 0) {
                //     emit setedgecolor(toVertex, fromVertex, "lightgreen");
                // }

                totalWeight += key[u];
                edgesSelected++;

                // 非阻塞延时
                QEventLoop loop;
                QTimer::singleShot(delay, &loop, &QEventLoop::quit);
                loop.exec();
                QCoreApplication::processEvents();
            }

            // 更新u的所有邻接顶点的key值
            EdgeBackend* edge = vertexList[u].firstarc;
            while (edge != nullptr) {
                int v = findVertexIndex(edge->adjvex);

                // 如果顶点v不在MST中，且当前边的权值小于已知的最小权值
                if (!inMST[v] && edge->weight < key[v]) {
                    key[v] = edge->weight;
                    parent[v] = u;
                }
                edge = edge->nextarc;
            }
        }

        // 检查是否成功构建MST
        if (edgesSelected == n - 1) {
            emit showresult("Prim算法最小生成树总权重: " + QString::number(totalWeight));
        } else {
            emit showresult("图不连通，无法构建最小生成树！");
        }
    }

    // Dijkstra 最短路径（适用于有向 / 无向图）
    void Dijkstra(QString startVertex) {
        if (vertexList.empty()) {
            emit showresult("图为空！");
            return;
        }

        int n = vertexList.size();
        int start = findVertexIndex(startVertex);
        if (start >= n) {
            emit showresult("起始顶点不存在！");
            return;
        }

        emit resetcolor();

        const int INF = INT_MAX / 2;
        vector<int> dist(n, INF);
        vector<int> pre(n, -1);
        vector<bool> used(n, false);

        dist[start] = 0;
        pre[start]  = start;

        // ---------- 构造过程表字符串 ----------
        // 约定格式：
        // 第一段：列标题（所有顶点名），用逗号分隔，以 '@' 结束
        // 后面每一段：行标题 + "#" + 每列内容（逗号分隔），再以 '@' 结束
        // 例： "v1,v2,v3@初始状态#length:0 pre:v1,length:∞ pre:-,...@v1进入第一组#..."
        QString table;

        // 第一行：列标题（所有顶点名）
        for (int i = 0; i < n; ++i) {
            table += vertexList[i].data;
            if (i != n - 1) table += ",";
        }
        table += "@";

        auto appendRow = [&](const QString& rowTitle) {
            table += rowTitle + "#";
            for (int i = 0; i < n; ++i) {
                QString cell;
                if (dist[i] >= INF/2) {
                    cell = "length:∞ pre:-";
                } else {
                    QString preName = (pre[i] == -1 ? "-" : vertexList[pre[i]].data);
                    cell = QString("length:%1 pre:%2").arg(dist[i]).arg(preName);
                }
                table += cell;
                if (i != n - 1) table += ",";
            }
            table += "@";
        };

        // 初始状态
        appendRow("初始状态");
        emit showDijkstraProcess(table);          // 【新增】一开始就发，前端立即弹窗并显示初始状态
        QCoreApplication::processEvents();        // 【新增】确保UI及时刷新


        for (int step = 0; step < n; ++step) {
            // 1. 选出未确定顶点中 dist 最小的顶点 u
            int u = -1;
            int best = INF;
            for (int i = 0; i < n; ++i) {
                if (!used[i] && dist[i] < best) {
                    best = dist[i];
                    u = i;
                }
            }
            if (u == -1) break;   // 剩余顶点不可达

            used[u] = true;

            // 2. 以 u 为中介点松弛所有邻接点
            EdgeBackend* e = vertexList[u].firstarc;
            while (e != nullptr) {
                int v = findVertexIndex(e->adjvex);
                if (v < n && !used[v] && dist[u] < INF/2) {
                    if (dist[u] + e->weight < dist[v]) {
                        dist[v] = dist[u] + e->weight;
                        pre[v]  = u;
                    }
                }
                e = e->nextarc;
            }

            // 3. 记录这一轮进入“第一组”的顶点（即 u）
            QString rowTitle = vertexList[u].data + " 进入第一组";
            appendRow(rowTitle);
            emit showDijkstraProcess(table);          // 【新增】每确定一个顶点就更新一次过程表
            QCoreApplication::processEvents();        // 【新增】确保窗口里的表格实时刷新


            // 4. 可视化高亮当前确定的顶点
            emit setvertexcolor(vertexList[u].data, "yellow");
            QEventLoop loop;
            QTimer::singleShot(delay, &loop, &QEventLoop::quit);
            loop.exec();
            QCoreApplication::processEvents();
        }

        // 把过程表发给前端弹窗
        //emit showDijkstraProcess(table);

        // 输出最终从起点到各点的最短距离
        QString result = "Dijkstra 最短路径长度:\n";
        for (int i = 0; i < n; ++i) {
            result += vertexList[i].data + ": ";
            if (dist[i] >= INF/2) result += "∞";
            else result += QString::number(dist[i]);
            result += "\n";
        }
        emit showresult(result);
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
    void showresult(QString);
    void showstruct(string);
    void resetcolor();
    void setvertexcolor(QString,QString);
    void setedgecolor(QString,QString,const QColor&);
    void showDijkstraProcess(QString);

};




#endif //GRAPH_H




