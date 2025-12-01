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
#include <QButtonGroup>
#include <QRadioButton>
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
#include <sstream>
#include "GraphStruct.h"
#include "DSLFunctionGraph.h"
#include "NaturalLanguageToDSL.h"
using namespace std;


class GraphWidget : public QWidget {
    Q_OBJECT

public :
    GraphWidget(QWidget *parent = nullptr) : QWidget(parent) {

        isdirect=1;

        /////////////////////////////////////////////////////////////左侧控制区

        //有无向图
        QHBoxLayout *directlayout = new QHBoxLayout();
        directbuttonGroup = new QButtonGroup();
        // 创建两个单选按钮
        optiondirect = new QRadioButton("有向图");
        optionundirect = new QRadioButton("无向图");
        directbuttonGroup->addButton(optiondirect);
        directbuttonGroup->addButton(optionundirect);
        directlayout->addWidget(optiondirect);
        directlayout->addWidget(optionundirect);
        optiondirect->setChecked(true);

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
        QHBoxLayout *vertexButtonLayout = new QHBoxLayout();
        vertexButtonLayout->addWidget(addVertexButton);
        vertexButtonLayout->addWidget(delVertexButton);
        QVBoxLayout *vertexLayout = new QVBoxLayout();
        vertexLayout->addLayout(vertexInputLayout);
        vertexLayout->addLayout(vertexButtonLayout);
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
        QHBoxLayout *edgeButtonLayout = new QHBoxLayout();
        edgeButtonLayout->addWidget(addEdgeButton);
        edgeButtonLayout->addWidget(delEdgeButton);
        QVBoxLayout *edgeLayout = new QVBoxLayout();
        edgeLayout->addLayout(edgeInputLayout1);
        edgeLayout->addLayout(edgeInputLayout2);
        edgeLayout->addLayout(edgeInputLayout3);
        edgeLayout->addLayout(edgeButtonLayout);
        QGroupBox *edgeGroup = new QGroupBox("边");
        edgeGroup->setLayout(edgeLayout);

        ///////////////算法
        //选择
        chooseBox = new QComboBox();
        QLabel *chooseLabel = new QLabel("算法:");
        chooseBox->addItem("请选择算法");
        chooseBox->addItem("深度优先遍历");
        chooseBox->addItem("广度优先遍历");
        chooseBox->addItem("Kruskal");
        chooseBox->addItem("Prim");
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

        //DSL组件
        QLabel *DSLLabel = new QLabel("DSL:");
        DSLEdit = new QTextEdit();
        DSLEdit->setFixedHeight(100);
        DSLButton = new QPushButton("执行");
        QVBoxLayout *DSLInputLayout = new QVBoxLayout();
        DSLInputLayout->addWidget(DSLLabel);
        DSLInputLayout->addWidget(DSLEdit);
        QVBoxLayout *DSLLayout = new QVBoxLayout();
        DSLLayout->addLayout(DSLInputLayout);
        DSLLayout->addWidget(DSLButton);

        //自然语言
        QLabel *naturalLabel = new QLabel("自然语言");
        naturalEdit = new QTextEdit();
        naturalEdit->setFixedHeight(100);
        naturalButton = new QPushButton("自然语言执行");
        QVBoxLayout *naturalInputLayout = new QVBoxLayout();
        naturalInputLayout->addWidget(naturalLabel);
        naturalInputLayout->addWidget(naturalEdit);
        QVBoxLayout *naturalLayout = new QVBoxLayout();
        naturalLayout->addLayout(naturalInputLayout);
        naturalLayout->addWidget(naturalButton);

        QHBoxLayout* languageLayout = new QHBoxLayout();
        languageLayout-> addLayout(DSLLayout);
        languageLayout->addLayout(naturalLayout);
        QGroupBox * languageGroup = new QGroupBox("DLS & 自然语言");
        languageGroup->setLayout(languageLayout);

        //开始和清除按钮水平排列
        QHBoxLayout * ButtonLayout = new QHBoxLayout();
        ButtonLayout->addWidget(traverseButton);
        ButtonLayout->addWidget(clearButton);

        //////////////控制区总布局
        QVBoxLayout *controlLayout = new QVBoxLayout();
        controlLayout->addLayout(directlayout);
        controlLayout->addWidget(vertexGroup);
        controlLayout->addWidget(edgeGroup);
        controlLayout->addWidget(algorithmGroup);
        controlLayout->addWidget(delayGroup);
        controlLayout->addWidget(languageGroup);
        controlLayout->addLayout(ButtonLayout);
        controlLayout->addLayout(fileLayout);
        controlLayout->addStretch(1);// 添加一个拉伸因子为1的spacer，它会吸收多余空间
        QGroupBox *controlGroup = new QGroupBox("控制区");
        controlGroup->setLayout(controlLayout);

        QVBoxLayout *leftLayout = new QVBoxLayout();
        leftLayout->addWidget(controlGroup);




        /////////////////////////////////////////////////////////////右侧观看区
        QVBoxLayout *viewLayout = new QVBoxLayout();

        //可视化区域
        QLabel *graphLabel = new QLabel("图形可视化区域");
        graphView= new QGraphicsView();
        scene= new QGraphicsScene(this);
        graphView->setScene(scene);
        graphView->setRenderHint(QPainter::Antialiasing);

        //邻接表结构展示
        structView = new QGraphicsView();
        scene2= new QGraphicsScene(this);
        scene2->setSceneRect(0, 0, 800, 600);
        structView->setScene(scene2);
        structView->setRenderHint(QPainter::Antialiasing);
        //矩阵结构展示
        matrixView = new QGraphicsView();
        scene3= new QGraphicsScene(this);
        scene3->setSceneRect(0, 0, 800, 600);
        matrixView->setScene(scene3);
        matrixView->setRenderHint(QPainter::Antialiasing);

        //选项卡切换画布
        tabWidget = new QTabWidget(this);
        tabWidget -> addTab(graphView,"图形演示");
        tabWidget -> addTab(structView,"邻接表");
        tabWidget -> addTab(matrixView,"相邻矩阵");


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
        viewLayout->addWidget(tabWidget);
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
        connect(this,&GraphWidget::sendKruskal,adjacencylist,&AdjacencyList::Kruskal);
        connect(this,&GraphWidget::sendPrim,adjacencylist,&AdjacencyList::Prim);
        connect(adjacencylist,&AdjacencyList::showresult,this,&GraphWidget::showResult);

        connect(adjacencylist,&AdjacencyList::resetcolor,this,&GraphWidget::resetColor);
        connect(adjacencylist,&AdjacencyList::setvertexcolor,this,&GraphWidget::setVertexColor);
        connect(adjacencylist,&AdjacencyList::setedgecolor,this,&GraphWidget::setEdgeColor);


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

        //结构展示
        connect(adjacencylist,&AdjacencyList::showstruct,this,&GraphWidget::showStruct);
        connect(adjacencymatrix,&AdjacencyMatrix::showmatrixstruct,this,&GraphWidget::showMatrix);

        //清除
        connect(clearButton,&QPushButton::clicked,this, &GraphWidget::clearall);
        connect(this,&GraphWidget::clear,adjacencymatrix,&AdjacencyMatrix::clearall);
        connect(this,&GraphWidget::clear,adjacencylist,&AdjacencyList::clearall);

        //DSL连接
        DSLGraph *dslgraph = new DSLGraph();
        connect(DSLButton, QPushButton::clicked, this, &GraphWidget::executeDSL);
        connect(this, &GraphWidget::sendDataDSL, dslgraph, &DSLGraph::execute);
        connect(dslgraph, DSLGraph::sendV, this, &GraphWidget::DSLaddVertex);
        connect(dslgraph, DSLGraph::sendE, this, &GraphWidget::DSLaddEdge);
        connect(dslgraph, DSLGraph::sendSelect, this, &GraphWidget::DSLSelect);
        connect(dslgraph, DSLGraph::delV, this, &GraphWidget::DSLdelVertex);
        connect(dslgraph, DSLGraph::delE, this, &GraphWidget::DSLdelEdge);
        connect(dslgraph, DSLGraph::senddirect, this, &GraphWidget::DSLsetdirect);

        //自然语言
        ntod = new NaturalLanguageToDSL();
        connect(naturalButton, QPushButton::clicked, this, &GraphWidget::executeNatural);
        connect(this, &GraphWidget::sendNatural, ntod, &NaturalLanguageToDSL::execute);
        connect(ntod, NaturalLanguageToDSL::sendDSL, this, &GraphWidget::showNaturalToDSL);

        //方向
        connect(directbuttonGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),this, &GraphWidget::setDirect);
        connect(this, &GraphWidget::sendDirect, adjacencylist, &AdjacencyList::setDirect);

        //更改边权重
        connect(this,&GraphWidget::setweight,adjacencylist,&AdjacencyList::setWeight);
        connect(this,&GraphWidget::setweight,adjacencymatrix,&AdjacencyMatrix::setWeight);

    }


signals :
    void sendVertex(QString);
    void sendEdge(QString,QString,int);
    void sendDFT(QString);
    void sendBFT(QString);
    void sendKruskal(QString);
    void sendPrim(QString);
    void sendDelay(int);
    void sendRemoveVertex(QString);
    void sendRemoveEdge(QString,QString);
    void clear();
    void sendDataDSL(string);
    void sendNatural(string);
    void sendDirect(int);
    void setweight(QString,QString,int);


public slots:
    //方向
    void setDirect() {
        if (optiondirect->isChecked()) {
            isdirect=1;
            cout<<"有向图";
        }else if (optionundirect->isChecked()) {
            isdirect=0;
            cout<<"无向图";
        }
        emit sendDirect(isdirect);
    }

    //自然语言相关
    void setAPI(QString getapi) {
        APIkey = getapi;
        ntod->setApiKey(APIkey);
    }

    void executeNatural() {
        string str="";
        if (vertexList.size()!=0){str += "当前已有的顶点为 ";}

        for (int i=0;i<vertexList.size();i++) {
            str += vertexList[i]->getNumber().toStdString() + " ";
        }

        if (vertexList.size()!=0){str += "现在是";}
        if (vertexList.size()!=0&&isdirect==1) {str+="有向图";}
        if (vertexList.size()!=0&&isdirect==0) {str+="无向图";}

        if (vertexList.size()!=0){str += "(在需要让你创建顶点时注意以下要求如果未指定顶点编号时让你创建顶点，你创建的定点编号要接在已有的编号后；若指定编号则生成指定编号的顶点。严重注意！！！若没有让你创建顶点，那你千万不要创建顶点，就当我刚刚的那些要求没说过）。";}

        str += naturalEdit->toPlainText().toStdString();

        emit sendNatural(str);

    }

    void showNaturalToDSL(QString str) {
        DSLEdit->setText(str);
        executeDSL();
    }

    //DSL相关
    void DSLsetdirect(int d) {
        isdirect=d;
        if (isdirect==0) {
            optionundirect -> setChecked(true);
        }else if (isdirect==1) {
            optiondirect -> setChecked(true);
        }
    }

    void executeDSL() {
        const string& code = DSLEdit->toPlainText().toStdString();
        emit sendDataDSL(code);
    }

    void DSLaddVertex(QString v) {
        vertexEdit->setText(v);
        addVertex();
    }

    void DSLdelVertex(QString v) {
        vertexEdit->setText(v);
        removeVertex();
    }

    void DSLaddEdge(QString from,QString to, QString weight) {
        edgeEdit1->setText(from);
        edgeEdit2->setText(to);
        edgeWeightEdit->setText(weight);
        addEdge();
    }

    void DSLdelEdge(QString from,QString to) {
        edgeEdit1->setText(from);
        edgeEdit2->setText(to);
        removeEdge2();
    }

    void DSLSelect(QString s,QString v) {
        if (s=="DFS") {
            chooseBox->setCurrentIndex(1);
        }else if (s=="BFS") {
            chooseBox->setCurrentIndex(2);
        }else if (s=="Kruskal") {
            chooseBox->setCurrentIndex(3);
        }else if (s=="Prim") {
            chooseBox->setCurrentIndex(4);
        }

        startEdit->setText(v);

        traverseGraph();
    }

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
        if (optionundirect->isChecked()) {
            hasArrow = false;
        }
        else if (optiondirect->isChecked()) {
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

        int ifhaveweight=0;
        //判断是否已有该边
        for (int i = 0; i < edgeList.size(); ++i) {
            if (isdirect==1) {
                if (edgeList[i]->getStartVertexNumber() == edgeEdit1->toPlainText()  &&  edgeList[i]->getEndVertexNumber() == edgeEdit2->toPlainText()) {
                    if (QString::number(edgeList[i]->getWeight()) != edgeWeightEdit->text()) {
                        setWeight(edgeEdit1->toPlainText(),edgeEdit2->toPlainText(),edgeWeightEdit->text().toInt());
                        edgeList[i]->setWeight(edgeWeightEdit->text().toInt());

                    }else {
                        QMessageBox::warning(this, "错误", "边已存在");
                    }
                    ifhaveweight++;
                    break;
                }
            }else if (isdirect==0) {
                if (edgeList[i]->getStartVertexNumber() == edgeEdit1->toPlainText()  &&  edgeList[i]->getEndVertexNumber() == edgeEdit2->toPlainText()) {
                    if (QString::number(edgeList[i]->getWeight()) != edgeWeightEdit->text()) {
                        setWeight(edgeEdit1->toPlainText(),edgeEdit2->toPlainText(),edgeWeightEdit->text().toInt());
                        edgeList[i]->setWeight(edgeWeightEdit->text().toInt());
                    }
                    ifhaveweight++;
                }

                if (edgeList[i]->getStartVertexNumber() == edgeEdit2->toPlainText()  &&  edgeList[i]->getEndVertexNumber() == edgeEdit1->toPlainText()) {
                    if (QString::number(edgeList[i]->getWeight()) != edgeWeightEdit->text()) {
                        setWeight(edgeEdit2->toPlainText(),edgeEdit1->toPlainText(),edgeWeightEdit->text().toInt());
                        edgeList[i]->setWeight(edgeWeightEdit->text().toInt());


                    }else {
                        QMessageBox::warning(this, "错误", "边已存在");
                    }
                    ifhaveweight++;

                }
            }
        }

        if (ifhaveweight!=0) {return;}


        edge=new Edge(vertexList.operator[](v1), vertexList.operator[](v2), edgeWeightEdit->text().toInt(),hasArrow);
        edgeList.append(edge);
        scene->addItem(edge);
        emit sendEdge(edgeEdit1->toPlainText(),edgeEdit2->toPlainText(),edgeWeightEdit->text().toInt());

        if (isdirect==0) {
            edge=new Edge(vertexList.operator[](v2), vertexList.operator[](v1), edgeWeightEdit->text().toInt(),hasArrow);
            edgeList.append(edge);
            emit sendEdge(edgeEdit2->toPlainText(),edgeEdit1->toPlainText(),edgeWeightEdit->text().toInt());
        }


    }

    void setWeight(QString from,QString to,int weight) {
        for (int i = 0; i < edgeList.size(); ++i) {
            if (edgeList[i]->getStartVertexNumber() == from  &&  edgeList[i]->getEndVertexNumber() == to) {
                edgeList[i]->setWeight(weight);
                emit setweight(from,to,weight);
            }
        }

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

        if (isdirect==0) {
            i=0;
            while (i<edgeList.size()) {
                if (edgeList[i]->getStartVertex()->getNumber() == edgeEdit2->toPlainText() && edgeList[i]->getEndVertex()->getNumber() == edgeEdit1->toPlainText()) {
                    delete edgeList.at(i);
                    edgeList.removeAt(i);
                }else {
                    i++;
                }
            }

            emit sendRemoveEdge(edgeEdit2->toPlainText(),edgeEdit1->toPlainText());
        }




}

    void clearall() {

        //清除结构
        showlist = "";
        showmatrix = "";

        while (!structnodelist.isEmpty()) {
            delete structnodelist.takeAt(0);
        }
        while (!structedgelist.isEmpty()) {
            delete structedgelist.takeAt(0);
        }
        while (!structarrowlist.isEmpty()) {
            delete structarrowlist.takeAt(0);
        }

        while (!structmatrixlist.isEmpty()) {
            delete structmatrixlist.takeAt(0);
        }

        //清除前端边
        while (!edgeList.isEmpty()) {
            delete edgeList.takeAt(0);
        }
        //清除前端点
        while (!vertexList.isEmpty()) {
            delete vertexList.takeAt(0);
        }

        emit clear();

    }

    void traverseGraph() {
        emit sendDelay(delayEdit->text().toInt());
        if (chooseBox->currentText() == "深度优先遍历") {emit sendDFT(startEdit->toPlainText());}
        else if (chooseBox->currentText() == "广度优先遍历"){emit sendBFT(startEdit->toPlainText());}
        else if (chooseBox->currentText() == "Kruskal") {emit sendKruskal(startEdit->toPlainText());}
        else if (chooseBox->currentText() == "Prim") {emit sendPrim(startEdit->toPlainText());}

    }

    void showStruct(string str) {

        showlist = QString::fromStdString(str);

        int structx=0;
        int structy=0;
        int firstarrow=0;

         //清除
         while (!structnodelist.isEmpty()) {
             delete structnodelist.takeAt(0);
         }
        while (!structedgelist.isEmpty()) {
            delete structedgelist.takeAt(0);
        }
        while (!structarrowlist.isEmpty()) {
            delete structarrowlist.takeAt(0);
        }

        string temp="";

        for (std::size_t i = 0; i < str.length(); i++) {

            if (i==0) {

                temp="";
                i++;
                while (str[i]!=')'){temp+=str[i]; i++;}

                structnode = new StructNode(structx,structy,QString::fromStdString(temp));
                scene2->addItem(structnode);
                structnodelist.append(structnode);
                firstarrow=1;
                continue;
            }

            if (str[i] == '@' && i+1<str.length()) {
                structy = structy + 100;
                structx = 0;
                i++;

                temp="";
                i++;
                while (str[i]!=')'){temp+=str[i]; i++;}

                structnode = new StructNode(structx,structy,QString::fromStdString(temp));
                structnodelist.append(structnode);
                scene2->addItem(structnode);
                firstarrow=1;
                continue;
            }

            string num="";
            string weight="";

            if (str[i] == '>' ) {
                structx = structx + 200;
                i++;

                num="";
                i++;
                while (str[i]!=')'){num+=str[i]; i++;}

                i = i + 2;
                weight="";
                i++;
                while (str[i]!=']'){weight+=str[i]; i++;}



                //绘制箭头
                if (firstarrow==1) {
                    structarrow = new StructArrow(structx-125,structx,structy);
                }else {
                    structarrow = new StructArrow(structx-75,structx,structy);
                }

                structarrowlist.append(structarrow);
                scene2->addItem(structarrow);

                //绘制矩形
                structedge = new StructEdge(structx,structy,QString::fromStdString(num),QString::fromStdString(weight));
                structedgelist.append(structedge);
                scene2->addItem(structedge);

                firstarrow=0;
                continue;
            }



        }


        update();

    }

    void showMatrix(string str) {

        showmatrix = QString::fromStdString(str);

        int structx=0;
        int structy=0;

         //清除
         while (!structmatrixlist.isEmpty()) {
             delete structmatrixlist.takeAt(0);
         }

        string temp="";

        for (std::size_t i = 0; i < str.length(); i++) {

            if (i==0) {
                structmatrix = new StructMatrixRect(structx,structy," ","yellow");
                scene3->addItem(structmatrix);
                structmatrixlist.append(structmatrix);
            }

            if (str[i] == ',' ) {
                i++;
                temp="";
                i++;
                while (str[i]!=')'){temp+=str[i]; i++;}
                structx = structx + 50;
                structmatrix = new StructMatrixRect(structx,structy,QString::fromStdString(temp),"yellow");
                scene3->addItem(structmatrix);
                structmatrixlist.append(structmatrix);
                continue;

            }

            if (str[i] == '@' && i+1<str.length()) {
                structy = structy + 50;
                structx = 0;
                i++;
                temp="";
                i++;
                while (str[i]!=')'){temp+=str[i]; i++;}
                structmatrix = new StructMatrixRect(structx,structy,QString::fromStdString(temp),"yellow");
                scene3->addItem(structmatrix);
                structmatrixlist.append(structmatrix);
                continue;
            }


            if (str[i] == '<' ) {
                i++;
                temp="";
                i++;
                while (str[i]!=']'){temp+=str[i]; i++;}
                structx = structx + 50;
                structmatrix = new StructMatrixRect(structx,structy,QString::fromStdString(temp),"white");
                scene3->addItem(structmatrix);
                structmatrixlist.append(structmatrix);
                continue;

            }


        }


        update();

    }

    void showResult(QString result) {
        resultEdit->setText(result);
    }

    void resetColor() {
        for (int i = 0; i < vertexList.size(); ++i) {
            vertexList[i]->setColor("white");
        }
        scene->update();

        for (int i = 0; i < edgeList.size(); i++) {
            edgeList[i]->setLineColor("black");
        }
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

        //保存是有向图还是无向图
        out << isdirect;

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

        out<<showlist;
        out<<showmatrix;

        file.close();
        qDebug() << "文件保存完成";
        return true;
    }

    void saveFile() {
        QString fileName = QFileDialog::getSaveFileName(this, "保存文件", "", "可视化文件 (*.wyxgraph)");
        if (!fileName.isEmpty()) {
            if (!fileName.endsWith(".wyxgraph", Qt::CaseInsensitive)) {
                fileName += ".wyxgraph";
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

    //读取是有向图还是无向图
    in >> isdirect;

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

    in >> showlist;
    in >> showmatrix;

    file.close();
    qDebug() << "文件加载完成";
    return true;
}

    void openFile() {
        QString fileName = QFileDialog::getOpenFileName(this, "打开文件", "", "可视化文件 (*.wyxgraph)");
        if (!fileName.isEmpty()) {
            clearall();
            if (loadData(fileName)) {
                QMessageBox::information(this, "成功", "文件读取成功！");



                if (isdirect==0) {
                    optionundirect->setChecked(true);
                }else if (isdirect==1) {
                    optiondirect->setChecked(true);
                }


                showStruct(showlist.toStdString());
                showMatrix(showmatrix.toStdString());
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
    QGraphicsView *structView;
    QGraphicsView *matrixView;
    QGraphicsScene *scene;
    QGraphicsScene *scene2;
    QGraphicsScene *scene3;
    QTextEdit *resultEdit;
    QTextEdit *timeEdit;


    QLabel *startLabel;
    QTextEdit *startEdit;

    QLineEdit *delayEdit;

    QPushButton *savefileButton;
    QPushButton *readfileButton;

    QPushButton *DSLButton;
    QTextEdit *DSLEdit;


    int ItemX;
    int ItemY;
    int arr[100];
    int size;

    Vertex *vertex;
    QList<Vertex *> vertexList;

    Edge *edge;
    QList<Edge *> edgeList;

    QTabWidget *tabWidget;

    QList <StructMatrixRect *> structmatrixlist;
    QList <StructNode *> structnodelist;
    QList <StructEdge *> structedgelist;
    QList <StructArrow *> structarrowlist;
    StructMatrixRect *structmatrix;
    StructNode *structnode;
    StructEdge *structedge;
    StructArrow *structarrow;

    QString showlist;
    QString showmatrix;


    QPushButton *naturalButton;
    QTextEdit *naturalEdit;

    NaturalLanguageToDSL* ntod;
    QString APIkey;

    QButtonGroup * directbuttonGroup;
    QRadioButton *optiondirect;
    QRadioButton *optionundirect;

    int isdirect;

};



#endif //GRAPHWIDGET_H
