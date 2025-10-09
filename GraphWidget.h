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
using namespace std;


class GraphWidget : public QWidget {
    Q_OBJECT

public:
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
        //布局
        QHBoxLayout *chooseLayout = new QHBoxLayout();
        chooseLayout->addWidget(chooseLabel);
        chooseLayout->addWidget(chooseBox);
        chooseLayout->addStretch(1);// 添加一个拉伸因子为1的spacer，它会吸收多余空间
        QGroupBox *chooseGroup = new QGroupBox("算法");
        chooseGroup->setLayout(chooseLayout);

        ///////////////按钮
        QPushButton *traverseButton = new QPushButton("遍历");
        QPushButton *clearButton = new QPushButton("清除");

        //////////////延时
        QLabel *delayLabel = new QLabel("延时");
        QLineEdit *delayEdit = new QLineEdit("1000");
        delayEdit->setFixedHeight(30);
        QHBoxLayout *delayLayout = new QHBoxLayout();
        delayLayout->addWidget(delayLabel);
        delayLayout->addWidget(delayEdit);
        QGroupBox *delayGroup = new QGroupBox("延时");
        delayGroup->setLayout(delayLayout);

        //////////////控制区总布局
        QVBoxLayout *controlLayout = new QVBoxLayout();
        controlLayout->addWidget(vertexGroup);
        controlLayout->addWidget(edgeGroup);
        controlLayout->addWidget(chooseGroup);
        controlLayout->addWidget(delayGroup);
        controlLayout->addWidget(traverseButton);
        controlLayout->addWidget(clearButton);
        controlLayout->addStretch(1);// 添加一个拉伸因子为1的spacer，它会吸收多余空间
        QGroupBox *controlGroup = new QGroupBox("控制区");
        controlGroup->setLayout(controlLayout);


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

        Layout->addWidget(controlGroup,1);//拉伸因子
        Layout->addLayout(viewLayout,3);//拉伸因子

        mainLayout->addWidget(titleLabel);
        mainLayout->addLayout(Layout);



        Adjacency *adjacency = new Adjacency();
        ///////////////////////////////////////////////////////////////信号槽
        connect(addVertexButton,&QPushButton::clicked,this, &GraphWidget::addVertex);
        connect(addEdgeButton,&QPushButton::clicked,this, &GraphWidget::addEdge);

        connect(this,&GraphWidget::sendVertex,adjacency,&Adjacency::addVertex);


    }


signals :
    void sendVertex(QString);

private slots:
    void addVertex() {
        int x = QRandomGenerator::global()->bounded(100, 600);
        int y = QRandomGenerator::global()->bounded(100, 400);
        vertex = new Vertex(vertexEdit->text(), x, y);
        scene->addItem(vertex);
        vertexList.append(vertex);

        emit sendVertex(vertexEdit->text());
    }

    void addEdge() {

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
        edge=new Edge(vertexList.operator[](v1), vertexList.operator[](v2), edgeWeightEdit->text().toInt());
        scene->addItem(edge);

    }



private:
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

    int ItemX;
    int ItemY;
    int arr[100];
    int size;

    Vertex *vertex;
    QList<Vertex *> vertexList;

    Edge *edge;

};



#endif //GRAPHWIDGET_H
