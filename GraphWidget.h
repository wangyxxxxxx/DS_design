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
#include <QDialog>
#include <QTableWidget>
#include <QHeaderView>
#include <QToolTip>
#include <QCursor>
#include <QLabel>
#include <QEvent>
#include <QSet>
#include <QFileDialog>
#include <QMessageBox>
#include "ImageToDSL.h"
#include "GraphStruct.h"
#include "DSLFunctionGraph.h"
#include "NaturalLanguageToDSL.h"
#include "SpeechInput.h"
#include "GifRecorder.h"

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
        chooseBox->addItem("Dijkstra");
        chooseBox->addItem("连通分支");
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

        //打开图片（图片转DSL）
        imageToDSLButton = new QPushButton("图片转DSL");
        fileLayout->addWidget(imageToDSLButton);

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


        //语音
        voiceButton = new QPushButton("按住说话");
        voiceButton->setToolTip("按住开始说，松开停止并转文字");

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
        ButtonLayout->addWidget(voiceButton);

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
        connect(this, &GraphWidget::sendConnectedComponents,adjacencylist, &AdjacencyList::ConnectedComponents);
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

        //迪杰斯特拉
        connect(this,&GraphWidget::sendDijkstra,adjacencylist,&AdjacencyList::Dijkstra);
        connect(adjacencylist,&AdjacencyList::showDijkstraProcess,this,&GraphWidget::showDijkstraTable);

        //语音
        connect(voiceButton, &QPushButton::pressed,  this, &GraphWidget::onVoicePressed);
        connect(voiceButton, &QPushButton::released, this, &GraphWidget::onVoiceReleased);

        //图片转DSL
        imgToDsl = new QwenImageToDSL(this);
        connect(imageToDSLButton, &QPushButton::clicked, this, &GraphWidget::executeImageToDSL);



        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////初始化

        // ===== GIF录制：图演示（复用排序的 GifRecorder）=====
        gifRecorder = new GifRecorder(this);
        // 录制右侧演示区域：包含 Tab 和画布（更直观）
        gifRecorder->setTarget(tabWidget);


        // 悬浮信息窗（自己控制，不会自动消失）
        hoverInfoLabel = new QLabel(nullptr); // 顶层窗体
        hoverInfoLabel->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
        hoverInfoLabel->setAttribute(Qt::WA_ShowWithoutActivating);
        hoverInfoLabel->setAttribute(Qt::WA_TransparentForMouseEvents); // 不抢鼠标，否则 hoverLeave/Enter 会抖
        hoverInfoLabel->setTextFormat(Qt::PlainText);
        hoverInfoLabel->setStyleSheet(
            "QLabel{"
            "color:#000000;"            // ★强制黑字
            "background-color:#ffffe1;"
            "border:1px solid #808080;"
            "padding:6px;"
            "}"
        );

        hoverInfoLabel->hide();

        // 让 viewport 能收到 MouseMove（用于跟随鼠标位置，可选但建议）
        graphView->setMouseTracking(true);
        graphView->viewport()->setMouseTracking(true);
        graphView->viewport()->installEventFilter(this);



    }
    ~GraphWidget() {
        speech.stop();
        if (hoverInfoLabel) { delete hoverInfoLabel; hoverInfoLabel = nullptr; }

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
    void sendDijkstra(QString);
    void sendConnectedComponents();




public slots:

    //图片转DSL
    void setQwenAPI(QString key) {
        QwenAPIkey = key.trimmed();
        if (imgToDsl) imgToDsl->setApiKey(QwenAPIkey);
    }

    void executeImageToDSL() {
        if (QwenAPIkey.trimmed().isEmpty()) {
            QMessageBox::warning(this, "未设置千问API",
                                 "请在主窗口底部“设置 千问API”输入框中填写Key并点击设置。");
            return;
        }

        const QString imgPath = QFileDialog::getOpenFileName(
            this, "选择图片", "", "Images (*.png *.jpg *.jpeg *.bmp)"
        );
        if (imgPath.isEmpty()) return;

        // 可选：给一点上下文，提高识别准确率
        QString ctx;
        ctx += QString("当前图类型：%1\n").arg(isdirect ? "有向图" : "无向图");
        if (!vertexList.isEmpty()) {
            ctx += "当前已有顶点：";
            for (auto* v : vertexList) ctx += v->getNumber() + " ";
            ctx += "\n";
        }

        const QString dsl = imgToDsl->translateImageToDSL(imgPath, ctx);
        DSLEdit->setText(dsl); // 只写入DSL框
    }



    //悬停
    void onVertexHovered(Vertex* v) {
        if (!v) return;
        hoveredVertex = v;

        hoverInfoLabel->setText(buildVertexInfo(v));
        hoverInfoLabel->adjustSize();

        // 显示在鼠标旁边一点的位置
        QPoint pos = QCursor::pos() + QPoint(12, 12);
        hoverInfoLabel->move(pos);
        hoverInfoLabel->show();
        hoverInfoLabel->raise();
    }

    void onVertexUnhovered(Vertex* v) {
        // 只在离开当前悬停节点时隐藏
        if (v && v != hoveredVertex) return;
        hoveredVertex = nullptr;
        if (hoverInfoLabel) hoverInfoLabel->hide();
    }


    bool eventFilter(QObject* obj, QEvent* event) override {
        if (obj == graphView->viewport() && hoverInfoLabel && hoverInfoLabel->isVisible()) {
            if (event->type() == QEvent::MouseMove) {
                // 跟随鼠标（不是必须，但体验更好）
                hoverInfoLabel->move(QCursor::pos() + QPoint(12, 12));
            }
        }
        return QWidget::eventFilter(obj, event);
    }



    void hookVertex(Vertex* v) {
        if (!v) return;
        disconnect(v, nullptr, this, nullptr); // 防止重复连接
        connect(v, &Vertex::hovered, this, &GraphWidget::onVertexHovered);
        connect(v, &Vertex::unhovered, this, &GraphWidget::onVertexUnhovered);
    }


    QString buildVertexInfo(Vertex* v) const {
        if (!v) return {};

        int outDeg = 0, inDeg = 0, deg = 0;
        QStringList outNeighbors, inNeighbors, neighbors;

        // ★ 用于无向图去重：同一对端点（+权重）只算一次
        QSet<QString> seenUndirected;

        for (Edge* e : edgeList) {
            if (!e || !e->getStartVertex() || !e->getEndVertex()) continue;

            Vertex* sv = e->getStartVertex();
            Vertex* tv = e->getEndVertex();

            const QString s = sv->getNumber();
            const QString t = tv->getNumber();
            const int w = e->getWeight();

            if (isdirect == 1) {
                if (sv == v) { outDeg++; outNeighbors << QString("%1(w=%2)").arg(t).arg(w); }
                if (tv == v) { inDeg++;  inNeighbors  << QString("%1(w=%2)").arg(s).arg(w); }
            } else {
                // 无向图：只关心与 v 相连的边
                if (sv != v && tv != v) continue;

                // ★ 生成“无向边 key”（端点排序后 + 权重）
                QString a = s, b = t;
                if (a > b) std::swap(a, b);
                const QString key = QString("%1-%2-%3").arg(a).arg(b).arg(w);

                // ★ 如果这条无向边已经处理过，就跳过（避免显示两次、度数翻倍）
                if (seenUndirected.contains(key)) continue;
                seenUndirected.insert(key);

                // 计算度与邻接显示
                if (sv == v && tv == v) {
                    // 自环：按常规定义度+2（若你希望自环度+1，把 2 改 1）
                    deg += 2;
                    neighbors << QString("%1(w=%2)").arg(t).arg(w);
                } else {
                    deg += 1;
                    const QString other = (sv == v) ? t : s;
                    neighbors << QString("%1(w=%2)").arg(other).arg(w);
                }
            }
        }

        QString info;
        info += QString("节点：%1\n").arg(v->getNumber());

        if (isdirect == 1) {
            const int total = outDeg + inDeg;
            info += QString("出度：%1\n入度：%2\n总度：%3").arg(outDeg).arg(inDeg).arg(total);
            if (!outNeighbors.isEmpty()) info += QString("\n出边：%1").arg(outNeighbors.join(", "));
            if (!inNeighbors.isEmpty())  info += QString("\n入边：%1").arg(inNeighbors.join(", "));
        } else {
            info += QString("度：%1").arg(deg);
            if (!neighbors.isEmpty()) info += QString("\n相邻：%1").arg(neighbors.join(", "));
        }

        return info;
    }




    //语音
    void setSpeechCred(QString appid, QString token) {
        speech.setCredential(appid, token);
    }


    void onVoicePressed() {
        voiceButton->setText("松开结束");

        speech.startHold(
            this,
            [this](const QString& text) {
                naturalEdit->setText(text);       // 松开后填入自然语言输入框
                voiceButton->setText("按住说话");
            },
            [this](const QString& err) {
                voiceButton->setText("按住说话");
                QMessageBox::warning(this, "语音识别失败", err);
            }
        );
    }

    void onVoiceReleased() {
        voiceButton->setText("按住说话");
        speech.stop(true);  // 停止并输出最终文字
    }


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
        }else if (s=="Dijkstra") {
            chooseBox->setCurrentIndex(5);
        }

        startEdit->setText(v);

        traverseGraph();
    }

    void addVertex() {
        int x = QRandomGenerator::global()->bounded(100, 600);
        int y = QRandomGenerator::global()->bounded(100, 400);
        vertex = new Vertex(vertexEdit->text(), x, y);
        hookVertex(vertex);   // ←加这行
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
                if (edgeList[i]->getStartVertex()->getNumber() == edgeEdit1->toPlainText()  &&  edgeList[i]->getEndVertex()->getNumber() == edgeEdit2->toPlainText()) {

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
                if (edgeList[i]->getStartVertex()->getNumber() == edgeEdit1->toPlainText()  &&  edgeList[i]->getEndVertex()->getNumber() == edgeEdit2->toPlainText()) {
                    if (QString::number(edgeList[i]->getWeight()) != edgeWeightEdit->text()) {
                        setWeight(edgeEdit1->toPlainText(),edgeEdit2->toPlainText(),edgeWeightEdit->text().toInt());
                        edgeList[i]->setWeight(edgeWeightEdit->text().toInt());
                    }
                    ifhaveweight++;
                }

                if (edgeList[i]->getStartVertex()->getNumber() == edgeEdit2->toPlainText()  &&  edgeList[i]->getEndVertex()->getNumber() == edgeEdit1->toPlainText()) {
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
            if (edgeList[i]->getStartVertex()->getNumber() == from  &&  edgeList[i]->getEndVertex()->getNumber() == to) {
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

        if (gifRecorder && gifRecorder->isRecording()) {
            gifRecorder->discardTemp();
        }

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
        int stepDelayMs = delayEdit->text().toInt();
        emit sendDelay(stepDelayMs);

        // 没选算法就不录也不跑
        if (chooseBox->currentIndex() <= 0) return;

        // 如果上一次还在录（比如用户连点开始），先停掉旧的
        if (gifRecorder && gifRecorder->isRecording()) {
            gifRecorder->discardTemp();
        }

        // ===== 开始录制 =====
        // 截帧间隔：跟随“演示延时”，但不要太慢/太快
        // 例如 stepDelay=1000ms -> interval=200ms
        int intervalMs = stepDelayMs > 0 ? (stepDelayMs / 5) : 120;
        intervalMs = qBound(50, intervalMs, 250);     // 限制在 50~250ms
        int maxWidth = 900;                            // 输出最大宽度，可按你喜好调

        if (gifRecorder) {
            // 录制右侧演示区（你在构造里 setTarget(tabWidget) 了，这里不必再设）
            gifRecorder->start(intervalMs, maxWidth);
        }


        if (chooseBox->currentText() == "深度优先遍历") {emit sendDFT(startEdit->toPlainText());}
        else if (chooseBox->currentText() == "广度优先遍历"){emit sendBFT(startEdit->toPlainText());}
        else if (chooseBox->currentText() == "Kruskal") {emit sendKruskal(startEdit->toPlainText());}
        else if (chooseBox->currentText() == "Prim") {emit sendPrim(startEdit->toPlainText());}
        else if (chooseBox->currentText() == "Dijkstra") {emit sendDijkstra(startEdit->toPlainText());}
        else if (chooseBox->currentText() == "连通分支") { emit sendConnectedComponents(); }


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

        // ===== 演示结束：停止录制并询问保存 =====
        if (!gifRecorder || !gifRecorder->isRecording()) return;

        gifRecorder->stop();

        auto ret = QMessageBox::question(
            this,
            "保存动画",
            "演示已结束，是否保存为 GIF 动画？",
            QMessageBox::Yes | QMessageBox::No,
            QMessageBox::Yes
        );

        if (ret == QMessageBox::Yes) {
            QString path = QFileDialog::getSaveFileName(
                this,
                "保存 GIF",
                "",
                "GIF (*.gif)"
            );

            if (!path.isEmpty()) {
                if (gifRecorder->saveAs(path)) {
                    QMessageBox::information(this, "成功", "GIF 已保存。");
                } else {
                    QMessageBox::warning(this, "失败", "GIF 保存失败。");
                }
            }
        }

        // 不管保存与否，都清掉临时文件，避免堆积
        gifRecorder->discardTemp();
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

    //迪杰斯特拉
    // 迪杰斯特拉：只弹出一个窗口，运行中不断更新
    void showDijkstraTable(QString tableStr) {
        QStringList blocks = tableStr.split("@", Qt::SkipEmptyParts);
        if (blocks.isEmpty()) return;

        // 列标题（各个顶点名）
        QStringList headers = blocks[0].split(",", Qt::SkipEmptyParts);
        int rowCount = blocks.size() - 1;
        int colCount = headers.size();

        // 1) 第一次收到数据：创建并显示非模态窗口（只创建一次）
        if (!dijkstraDlg) {
            dijkstraDlg = new QDialog(this);
            dijkstraDlg->setWindowTitle("Dijkstra 过程表");
            dijkstraDlg->resize(800, 400);
            dijkstraDlg->setModal(false);
            dijkstraDlg->setAttribute(Qt::WA_DeleteOnClose);

            QVBoxLayout* layout = new QVBoxLayout(dijkstraDlg);
            dijkstraTable = new QTableWidget(dijkstraDlg);
            layout->addWidget(dijkstraTable);
            dijkstraDlg->setLayout(layout);

            // 窗口被关掉后，把指针清空，防止悬空
            connect(dijkstraDlg, &QObject::destroyed, this, [this]() {
                dijkstraDlg = nullptr;
                dijkstraTable = nullptr;
                dijkstraHeaders.clear();
                dijkstraLastRowCount = 0;
            });
        }

        // 2) 如果是新一轮Dijkstra（行数回到更小），清空旧表
        if (rowCount < dijkstraLastRowCount && dijkstraTable) {
            dijkstraTable->clear();
            dijkstraTable->setRowCount(0);
            dijkstraLastRowCount = 0;
        }

        // 3) 如果表头变化（一般是新图/新顶点集），重建表结构
        if (dijkstraHeaders != headers && dijkstraTable) {
            dijkstraHeaders = headers;


            dijkstraTable->clear();
            dijkstraTable->setRowCount(0);
            dijkstraTable->setColumnCount(colCount);
            dijkstraTable->setHorizontalHeaderLabels(headers);
            dijkstraTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            dijkstraTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

            dijkstraLastRowCount = 0;
        }

        if (!dijkstraTable) return;

        // 4) 扩展行数
        if (rowCount > dijkstraTable->rowCount()) {
            dijkstraTable->setRowCount(rowCount);
        }

        // 5) 只增量填充“新增的行”（每确定一个顶点就会多一行）
        for (int i = dijkstraLastRowCount; i < rowCount; ++i) {
            QString block = blocks[i + 1];
            QStringList parts = block.split("#");
            if (parts.isEmpty()) continue;

            QString rowTitle = parts[0];
            QStringList cells;
            if (parts.size() > 1) {
                cells = parts[1].split(",", Qt::SkipEmptyParts);
            }

            dijkstraTable->setVerticalHeaderItem(i, new QTableWidgetItem(rowTitle));

            for (int j = 0; j < qMin(colCount, cells.size()); ++j) {
                QTableWidgetItem* item = dijkstraTable->item(i, j);
                if (!item) {
                    item = new QTableWidgetItem();
                    dijkstraTable->setItem(i, j, item);
                }
                item->setText(cells[j]);
            }
        }
        dijkstraLastRowCount = rowCount;

        // 6) 保证窗口可见且置前（不会重复弹出新窗口）
        if (!dijkstraDlg->isVisible()) dijkstraDlg->show();
        dijkstraDlg->raise();
        dijkstraDlg->activateWindow();
        dijkstraTable->scrollToBottom();

        QCoreApplication::processEvents();
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

        hookVertex(vertex);

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

    //Dijkstra过程表窗口
    QDialog* dijkstraDlg = nullptr;
    QTableWidget* dijkstraTable = nullptr;
    QStringList dijkstraHeaders;
    int dijkstraLastRowCount = 0;

    QPushButton *voiceButton;
    SpeechInput speech;

    GifRecorder* gifRecorder = nullptr;

    //悬停
    QLabel* hoverInfoLabel = nullptr;
    Vertex* hoveredVertex = nullptr;

    //图片识别
    QPushButton* imageToDSLButton = nullptr;
    QwenImageToDSL* imgToDsl = nullptr;
    QString QwenAPIkey;




};



#endif //GRAPHWIDGET_H
