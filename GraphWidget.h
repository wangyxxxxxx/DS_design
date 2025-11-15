//
// Created by 王雨轩 on 25-9-30.
//

#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H
//#include <qtmetamacros.h>
#include <QWidget>
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

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QList>
#include <QPointF>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QDataStream>
#include <QVector>
#include <QPen>
#include <QBrush>
#include <cmath>
using namespace std;


class GraphWidget : public QWidget {
    Q_OBJECT

public :
    GraphWidget(QWidget *parent = nullptr) : QWidget(parent) {
        /////////////////////////////////////////////////////////////左侧控制区

        ////////////////////节点
        //节点输入框
        QLabel *vertexLabel = new QLabel("节点:");
        vertexEdit = new QLineEdit();
        vertexEdit->setFixedHeight(30);
        //节点按钮
        addVertexButton = new QPushButton("添加节点");
        delVertexButton = new QPushButton("删除节点");
        //节点布局
        QHBoxLayout *vertexInputLayout = new QHBoxLayout();
        vertexInputLayout->addWidget(vertexLabel);
        vertexInputLayout->addWidget(vertexEdit);
        QVBoxLayout *vertexLayout = new QVBoxLayout();
        vertexLayout->addLayout(vertexInputLayout);
        vertexLayout->addWidget(addVertexButton);
        vertexLayout->addWidget(delVertexButton);
        QGroupBox *vertexGroup = new QGroupBox("节点");
        vertexGroup->setLayout(vertexLayout);

        ///////////////////边
        //边输入框
        QLabel *edgeLabel1 = new QLabel("起点:");
        QLabel *edgeLabel2 = new QLabel("终点:");
        QLabel *edgeWeightLabel = new QLabel("权重:");
        edgeEdit1 = new QTextEdit();
        edgeEdit1->setFixedHeight(30);
        edgeEdit2 = new QTextEdit();
        edgeEdit2->setFixedHeight(30);
        edgeWeightEdit = new QLineEdit();
        edgeWeightEdit->setFixedHeight(30);

        //边按钮
        addEdgeButton = new QPushButton("添加边");
        delEdgeButton = new QPushButton("删除边");
        //边布局
        QHBoxLayout *edgeInputLayout1 = new QHBoxLayout();
        edgeInputLayout1->addWidget(edgeLabel1);
        edgeInputLayout1->addWidget(edgeEdit1);
        QHBoxLayout *edgeInputLayout2 = new QHBoxLayout();
        edgeInputLayout2->addWidget(edgeLabel2);
        edgeInputLayout2->addWidget(edgeEdit2);
        QHBoxLayout *edgeInputLayout3 = new QHBoxLayout();
        edgeInputLayout3->addWidget(edgeWeightLabel);
        edgeInputLayout3->addWidget(edgeWeightEdit);
        QVBoxLayout *edgeLayout = new QVBoxLayout();
        edgeLayout->addLayout(edgeInputLayout1);
        edgeLayout->addLayout(edgeInputLayout2);
        edgeLayout->addLayout(edgeInputLayout3);
        edgeLayout->addWidget(addEdgeButton);
        edgeLayout->addWidget(delEdgeButton);
        QGroupBox *edgeGroup = new QGroupBox("边");
        edgeGroup->setLayout(edgeLayout);

        ///////////////算法
        //选择
        chooseBox = new QComboBox();
        QLabel *chooseLabel = new QLabel("算法:");
        chooseBox->addItem("请选择算法");
        chooseBox->addItem("深度优先遍历");
        chooseBox->addItem("广度优先遍历");
        chooseBox->addItem("最小生成树");
        chooseBox->setFixedHeight(30);
        chooseBox->setFixedWidth(210);

        startLabel = new QLabel("起点:");
        startEdit = new QTextEdit();
        startEdit->setFixedHeight(30);
        //布局
        QHBoxLayout *chooseLayout = new QHBoxLayout();
        chooseLayout->addWidget(chooseLabel);
        chooseLayout->addWidget(chooseBox);
        chooseLayout->addStretch(1);// 添加一个拉伸因子为1的spacer，它会吸收多余空间
        QHBoxLayout *startLayout = new QHBoxLayout();
        startLayout->addWidget(startLabel);
        startLayout->addWidget(startEdit);
        QVBoxLayout *algorithmLayout = new QVBoxLayout();
        algorithmLayout->addLayout(chooseLayout);
        algorithmLayout->addLayout(startLayout);
        QGroupBox *algorithmGroup = new QGroupBox("算法");
        algorithmGroup->setLayout(algorithmLayout);

        ///////////////按钮
        QPushButton *traverseButton = new QPushButton("开始");
        QPushButton *clearButton = new QPushButton("清除");

        //////////////延时
        QLabel *delayLabel = new QLabel("延时");
        delayEdit = new QLineEdit("1000");
        delayEdit->setFixedHeight(30);
        QHBoxLayout *delayLayout = new QHBoxLayout();
        delayLayout->addWidget(delayLabel);
        delayLayout->addWidget(delayEdit);
        QGroupBox *delayGroup = new QGroupBox("延时");
        delayGroup->setLayout(delayLayout);

        //////////////文件
        savefileButton = new QPushButton("保存文件");
        readfileButton = new QPushButton("打开文件");
        QHBoxLayout *fileLayout = new QHBoxLayout();
        fileLayout->addWidget(savefileButton);
        fileLayout->addWidget(readfileButton);


        //////////////控制区总布局
        QVBoxLayout *controlLayout = new QVBoxLayout();
        controlLayout->addWidget(vertexGroup);
        controlLayout->addWidget(edgeGroup);
        controlLayout->addWidget(algorithmGroup);
        controlLayout->addWidget(delayGroup);
        controlLayout->addWidget(traverseButton);
        controlLayout->addWidget(clearButton);
        controlLayout->addStretch(1);// 添加一个拉伸因子为1的spacer，它会吸收多余空间
        QGroupBox *controlGroup = new QGroupBox("控制区");
        controlGroup->setLayout(controlLayout);

        QVBoxLayout *leftLayout = new QVBoxLayout();
        leftLayout->addWidget(controlGroup);
        leftLayout->addLayout(fileLayout);




        /////////////////////////////////////////////////////////////右侧观看区
        QVBoxLayout *viewLayout = new QVBoxLayout();

        //可视化区域
        QLabel *graphLabel = new QLabel("图形可视化区域");
        graphView= new QGraphicsView();
        scene= new QGraphicsScene(this);
        graphView->setScene(scene);
        graphView->setRenderHint(QPainter::Antialiasing);

        //序列输出框
        QHBoxLayout *resultLayout = new QHBoxLayout();
        QLabel *resultLabel = new QLabel("结果:");
        resultEdit = new QTextEdit();
        resultEdit->setFixedHeight(30);
        resultEdit->setReadOnly(true); // 结果框设为只读

        //用时输出框
        QLabel *timetLabel = new QLabel("用时:");
        QLabel *nsLabel = new QLabel("ms");
        timeEdit = new QTextEdit();
        timeEdit->setFixedHeight(30);
        timeEdit->setReadOnly(true);

        resultLayout->addWidget(resultLabel);
        resultLayout->addWidget(resultEdit);
        resultLayout->addWidget(timetLabel);
        resultLayout->addWidget(timeEdit);
        resultLayout->addWidget(nsLabel);

        viewLayout->addWidget(graphLabel);
        viewLayout->addWidget(graphView);
        viewLayout->addLayout(resultLayout);


        ////////////////////////////////////////////////////////////（总）
        QHBoxLayout *Layout = new QHBoxLayout();
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        QLabel *titleLabel = new QLabel("图形结构演示");
        titleLabel->setAlignment(Qt::AlignCenter);

        Layout->addLayout(leftLayout,1);//拉伸因子
        Layout->addLayout(viewLayout,3);//拉伸因子

        mainLayout->addWidget(titleLabel);
        mainLayout->addLayout(Layout);



        adjacencymatrix = new AdjacencyMatrix();
        adjacencylist = new AdjacencyList();
        ///////////////////////////////////////////////////////////////信号槽
        connect(addVertexButton,&QPushButton::clicked,this, &GraphWidget::addVertex);
        connect(addEdgeButton,&QPushButton::clicked,this, &GraphWidget::addEdge);

        connect(this,&GraphWidget::sendVertex,adjacencymatrix,&AdjacencyMatrix::addVertex);
        connect(this,&GraphWidget::sendEdge,adjacencymatrix,&AdjacencyMatrix::addEdge);


        connect(this,&GraphWidget::sendVertex,adjacencylist,&AdjacencyList::addVertex);
        connect(this,&GraphWidget::sendEdge,adjacencylist,&AdjacencyList::addEdge);

        connect(traverseButton,&QPushButton::clicked,this, &GraphWidget::traverseGraph);
        connect(this,&GraphWidget::sendDFT,adjacencylist,&AdjacencyList::DFT);
        connect(this,&GraphWidget::sendBFT,adjacencylist,&AdjacencyList::BFT);
        connect(this,&GraphWidget::sendMST,adjacencylist,&AdjacencyList::MST);
        connect(adjacencylist,&AdjacencyList::showresult,this,&GraphWidget::showResult);

        connect(adjacencylist,&AdjacencyList::resetcolor,this,&GraphWidget::resetColor);
        connect(adjacencylist,&AdjacencyList::setvertexcolor,this,&GraphWidget::setVertexColor);
        connect(adjacencylist,&AdjacencyList::setedgecolor,this,&GraphWidget::setEdgeColor);

        connect(chooseBox,&QComboBox::currentIndexChanged,this, &GraphWidget::changeEdgeArrow);

        connect(this,&GraphWidget::sendDelay,adjacencylist,&AdjacencyList::changeDelay);

        //删除顶点
        connect(delVertexButton,&QPushButton::clicked,this, &GraphWidget::removeVertex);
        connect(this,&GraphWidget::sendRemoveVertex,adjacencylist,&AdjacencyList::removeVertex);
        connect(this,&GraphWidget::sendRemoveVertex,adjacencymatrix,&AdjacencyMatrix::removeVertex);
        connect(delEdgeButton,&QPushButton::clicked,this, &GraphWidget::removeEdge2);
        connect(this,&GraphWidget::sendRemoveEdge,adjacencylist,&AdjacencyList::removeEdge2);
        connect(this,&GraphWidget::sendRemoveEdge,adjacencymatrix,&AdjacencyMatrix::removeEdge);

        //文件
        connect(savefileButton,&QPushButton::clicked,this, &GraphWidget::saveFile);
        connect(readfileButton,&QPushButton::clicked,this, &GraphWidget::openFile);

    }


signals :
    void sendVertex(QString);
    void sendEdge(QString,QString,int);
    void sendDFT(QString);
    void sendBFT(QString);
    void sendMST(QString);
    void sendDelay(int);
    void sendRemoveVertex(QString);
    void sendRemoveEdge(QString,QString);


public slots:
    void addVertex() {
        int x = QRandomGenerator::global()->bounded(100, 600);
        int y = QRandomGenerator::global()->bounded(100, 400);
        vertex = new Vertex(vertexEdit->text(), x, y);
        scene->addItem(vertex);
        vertexList.append(vertex);

        emit sendVertex(vertexEdit->text());
    }

    void removeVertex() {



        int i;
        for (i=0;i<vertexList.size();i++) {
            if (vertexList[i]->getNumber() == vertexEdit->text()) {break;}
        }
        if (i==vertexList.size()) {
            QMessageBox::warning(this, "错误", "未找到顶点");
            return;
        }

        removeEdge1(vertexEdit->text());
        delete vertexList.takeAt(i);
        emit sendRemoveVertex(vertexEdit->text());


    }

    void addEdge() {

        bool hasArrow;
        if (chooseBox->currentText() == "最小生成树") {
            hasArrow = false;
        }
        else {
            hasArrow = true;
        }


        int v1=-1;
        int v2=-1;
        for (int i = 0; i < vertexList.size(); ++i) {
            if (vertexList.at(i)->getNumber() == edgeEdit1->toPlainText()) {
                v1 = i;
            }

            if (vertexList.at(i)->getNumber() == edgeEdit2->toPlainText()) {
                v2 = i;
            }
        }

        if (v1==-1 || v2==-1) {
            QMessageBox::warning(this, "错误", "未找到边");
            return;
        }
        edge=new Edge(vertexList.operator[](v1), vertexList.operator[](v2), edgeWeightEdit->text().toInt(),hasArrow);
        edgeList.append(edge);
        scene->addItem(edge);

        emit sendEdge(edgeEdit1->toPlainText(),edgeEdit2->toPlainText(),edgeWeightEdit->text().toInt());
        //emit sendEdge(edgeEdit2->toPlainText(),edgeEdit1->toPlainText(),edgeWeightEdit->text().toInt());

    }

    void removeEdge1(QString v) {

        int i=0;
        while (i<edgeList.size()) {
            if (edgeList[i]->getStartVertex()->getNumber() == v || edgeList[i]->getEndVertex()->getNumber() == v) {
                delete edgeList.at(i);
                edgeList.removeAt(i);
            }else {
                i++;
            }
        }


    }

    void removeEdge2() {

        int i=0;
        while (i<edgeList.size()) {
            if (edgeList[i]->getStartVertex()->getNumber() == edgeEdit1->toPlainText() && edgeList[i]->getEndVertex()->getNumber() == edgeEdit2->toPlainText()) {
                delete edgeList.at(i);
                edgeList.removeAt(i);
            }else {
                i++;
            }
        }

        emit sendRemoveEdge(edgeEdit1->toPlainText(),edgeEdit2->toPlainText());


}



    void traverseGraph() {
        emit sendDelay(delayEdit->text().toInt());
        if (chooseBox->currentText() == "深度优先遍历") {emit sendDFT(startEdit->toPlainText());}
        else if (chooseBox->currentText() == "广度优先遍历"){emit sendBFT(startEdit->toPlainText());}
        else if (chooseBox->currentText() == "最小生成树") {emit sendMST(startEdit->toPlainText());}

    }

    void showResult(QString result) {
        resultEdit->setText(result);
    }

    void resetColor() {
        for (int i = 0; i < vertexList.size(); ++i) {
            vertexList[i]->setColor("white");
        }
        scene->update();
    }

    void setVertexColor(QString vertex,QString color) {
        int i;
        for (i = 0; i < vertexList.size(); ++i) {
            if (vertexList.at(i)->getNumber() == vertex) {break;}
        }
        vertexList[i]->setColor(color);
        scene->update();

        for (int i = 0; i < edgeList.size(); ++i) {
            edgeList[i]->setLineColor("black");
        }
    }

    void setEdgeColor(QString from,QString to,const QColor& color) {
        int i;
        for (i=0; i < edgeList.size(); i++) {
            if (from == edgeList[i]->getStartVertex()->getNumber() && to == edgeList[i]->getEndVertex()->getNumber()) {
                break;
            }
        }

        edgeList[i]->setLineColor(color);

    }

    void changeEdgeArrow() {
        if (chooseBox->currentText() == "最小生成树") {
            for (int i = 0; i < edgeList.size(); ++i) {
                edgeList[i]->setArrowEnabled(false);
            }
        }else {
            for (int i = 0; i < edgeList.size(); ++i) {
                edgeList[i]->setArrowEnabled(true);
            }
        }
    }

    ////////////////文件
    bool saveData(const QString &fileName) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, "错误", "无法创建文件！");
            return false;
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_15);

        // 写入文件标识
        out << QString("GRAPH_SORT_V1.0");
        qDebug() << "写入文件标识完成，数据流状态:" << out.status();

        // 保存顶点数量
        int vertexCount = vertexList.size();
        out << vertexCount;
        qDebug() << "写入顶点数量:" << vertexCount << "，数据流状态:" << out.status();

        for (int i = 0; i < vertexCount; ++i) {
            Vertex* vertex = vertexList[i];
            out << *vertex;
            if (out.status() != QDataStream::Ok) {
                qDebug() << "写入顶点" << i << "时出错，数据流状态:" << out.status();
                file.close();
                return false;
            }
        }

        // 保存边数量
        int edgeCount = edgeList.size();
        out << edgeCount;
        qDebug() << "写入边数量:" << edgeCount << "，数据流状态:" << out.status();

        for (int i = 0; i < edgeCount; ++i) {
            Edge* edge = edgeList[i];
            out << *edge;
            if (out.status() != QDataStream::Ok) {
                qDebug() << "写入边" << i << "时出错，数据流状态:" << out.status();
                file.close();
                return false;
            }
        }


        file.close();
        qDebug() << "文件保存完成";
        return true;
    }

    void saveFile() {
        QString fileName = QFileDialog::getSaveFileName(this, "保存文件", "", "可视化文件 (*.wyx)");
        if (!fileName.isEmpty()) {
            if (!fileName.endsWith(".wyx", Qt::CaseInsensitive)) {
                fileName += ".wyx";
            }
            if (saveData(fileName)) {
                QMessageBox::information(this, "成功", "文件保存成功！");
            }
        }
    }

    // 辅助函数：根据顶点编号查找顶点
    Vertex* findVertexByNumber(const QString& number) {
        for (Vertex* vertex : vertexList) {
            if (vertex->getNumber() == number) {
                return vertex;
            }
        }
        return nullptr;
    }

    bool loadData(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "错误", "无法打开文件！");
        return false;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_15);

    // 读取文件标识
    QString fileTag;
    in >> fileTag;
    qDebug() << "文件标识:" << fileTag << "，数据流状态:" << in.status();

    if (fileTag != "GRAPH_SORT_V1.0") {
        QMessageBox::warning(this, "错误", "文件格式不正确！");
        file.close();
        return false;
    }

    // 清空现有数据
    qDeleteAll(vertexList);
    vertexList.clear();
    qDeleteAll(edgeList);
    edgeList.clear();

    // 读取顶点数量
    int vertexCount;
    in >> vertexCount;
    qDebug() << "顶点数量:" << vertexCount << "，数据流状态:" << in.status();

    if (in.status() != QDataStream::Ok) {
        qDebug() << "读取顶点数量时出错";
        file.close();
        return false;
    }

    // 读取顶点
    for (int i = 0; i < vertexCount; ++i) {
        //前端
        Vertex* vertex = new Vertex();
        in >> *vertex;

        if (in.status() != QDataStream::Ok) {
            qDebug() << "读取顶点" << i << "时出错，数据流状态:" << in.status();
            delete vertex;
            file.close();
            return false;
        }

        vertexList.append(vertex);

        //后端
        emit sendVertex(vertex->getNumber());

    }

    // 读取边数量
    int edgeCount;
    in >> edgeCount;
    qDebug() << "边数量:" << edgeCount << "，数据流状态:" << in.status();

    if (in.status() != QDataStream::Ok) {
        qDebug() << "读取边数量时出错";
        file.close();
        return false;
    }

    // 读取边
    for (int i = 0; i < edgeCount; ++i) {
        //前端
        Edge* edge = new Edge();
        in >> *edge;

        if (in.status() != QDataStream::Ok) {
            qDebug() << "读取边" << i << "时出错，数据流状态:" << in.status();
            delete edge;
            file.close();
            return false;
        }

        edgeList.append(edge);

    }

    // 建立边与顶点的连接
    qDebug() << "开始建立边与顶点的连接";
    for (Edge* edge : edgeList) {
        QString startNumber = edge->getStartVertexNumber();
        QString endNumber = edge->getEndVertexNumber();

        Vertex* startVertex = nullptr;
        Vertex* endVertex = nullptr;

        // 查找对应的顶点
        for (Vertex* vertex : vertexList) {
            if (vertex->getNumber() == startNumber) {
                startVertex = vertex;
            }
            if (vertex->getNumber() == endNumber) {
                endVertex = vertex;
            }
        }

        if (startVertex && endVertex) {
            edge->setVertices(startVertex, endVertex);
            qDebug() << "成功连接边:" << startNumber << "->" << endNumber;
        } else {
            qDebug() << "连接失败: 找不到顶点" << startNumber << "或" << endNumber;
        }

        //后端
        emit sendEdge(edge->getStartVertex()->getNumber(),edge->getEndVertex()->getNumber(),edge->getWeight());
    }


    file.close();
    qDebug() << "文件加载完成";
    return true;
}

    void openFile() {
        QString fileName = QFileDialog::getOpenFileName(this, "打开文件", "", "可视化文件 (*.wyx)");
        if (!fileName.isEmpty()) {
            if (loadData(fileName)) {
                QMessageBox::information(this, "成功", "文件读取成功！");
                updateDisplay(); // 确保这个函数能正确更新显示
            }
        }
    }

    void updateDisplay() {
    // 清空当前场景
    scene->clear();

    // 先添加边（确保边在顶点下方）
    for (Edge* edge : edgeList) {
        scene->addItem(edge);
    }

    // 再添加顶点
    for (Vertex* vertex : vertexList) {
        scene->addItem(vertex);
    }
}





private:
    AdjacencyList *adjacencylist;
    AdjacencyMatrix *adjacencymatrix;

    QLineEdit *vertexEdit;
    QPushButton *addVertexButton;
    QPushButton *delVertexButton;

    QTextEdit *edgeEdit1;
    QTextEdit *edgeEdit2;
    QLineEdit *edgeWeightEdit;
    QPushButton *addEdgeButton;
    QPushButton *delEdgeButton;

    QPushButton *traverseButton;
    QPushButton *clearButton;

    QComboBox *chooseBox;

    QPushButton *delayButton;

    QGraphicsView *graphView;
    QGraphicsScene *scene;
    QTextEdit *resultEdit;
    QTextEdit *timeEdit;


    QLabel *startLabel;
    QTextEdit *startEdit;

    QLineEdit *delayEdit;

    QPushButton *savefileButton;
    QPushButton *readfileButton;


    int ItemX;
    int ItemY;
    int arr[100];
    int size;

    Vertex *vertex;
    QList<Vertex *> vertexList;

    Edge *edge;
    QList<Edge *> edgeList;

};



#endif //GRAPHWIDGET_H
