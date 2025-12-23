//
// Created by 王雨轩 on 25-9-26.
//

// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H
//
// #endif //MAINWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGroupBox>
#include <QComboBox>
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
#include "SortWidget.h"
#include "GraphWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr): QMainWindow(parent){

        // 设置窗口标题和大小
        setWindowTitle("数据结构课设——王雨轩");
        resize(1200, 900);

        // 创建中央部件
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        QLabel *apilabel = new QLabel("Deepseek API :");
        apiEdit = new QTextEdit("sk-c9e63545f5f7482bb0c2683f692b2a73");
        apiEdit->setFixedHeight(30);
        QHBoxLayout *apilayout = new QHBoxLayout();
        apilayout->addWidget(apilabel);
        apilayout->addWidget(apiEdit);

        //语音
        QLabel *speechLabel1 = new QLabel("豆包 AppID :");
        speechAppIdEdit = new QLineEdit("2281231201");
        speechAppIdEdit->setFixedHeight(30);

        QLabel *speechLabel2 = new QLabel("豆包 Token :");
        speechTokenEdit = new QLineEdit("ShIvWC6TZIBEZ9yYW5FEp_pzztYe0cpp");
        speechTokenEdit->setFixedHeight(30);

        sendapiButton = new QPushButton("设置");

        apilayout->addWidget(speechLabel1);
        apilayout->addWidget(speechAppIdEdit);
        apilayout->addWidget(speechLabel2);
        apilayout->addWidget(speechTokenEdit);

        //图像识别
        QLabel *qwenLabel = new QLabel("千问API :");
        qwenApiEdit = new QTextEdit("sk-4d61327e7b854942a1e3e89a8e9dbff0");
        qwenApiEdit->setFixedHeight(30);
        apilayout->addWidget(qwenLabel);
        apilayout->addWidget(qwenApiEdit);
        apilayout->addWidget(sendapiButton);


        // 创建选项卡控件
        tabWidget = new QTabWidget(centralWidget);

        // 创建第一个选项卡页面
        tab1 = new SortWidget();

        // 创建第二个选项卡页面
        tab2 = new GraphWidget();


        // 将选项卡添加到选项卡控件
        tabWidget->addTab(tab1, "排序算法演示");
        tabWidget->addTab(tab2, "图形结构演示");



        // 设置中央部件的布局
        QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->addWidget(tabWidget);
        mainLayout->addLayout(apilayout);
        centralWidget->setLayout(mainLayout);

        connect(sendapiButton, QPushButton::clicked, this, &MainWindow::sendAPI);
        connect(this, &MainWindow::sendapi, tab1, &SortWidget::setAPI);
        connect(this, &MainWindow::sendapi, tab2, &GraphWidget::setAPI);
        connect(this, &MainWindow::sendSpeech, tab1, &SortWidget::setSpeechCred);
        connect(this, &MainWindow::sendSpeech, tab2, &GraphWidget::setSpeechCred);
        connect(this, &MainWindow::sendqwenapi, tab2, &GraphWidget::setQwenAPI);
    }

public slots:
    void sendAPI() {
        emit sendapi(apiEdit->toPlainText());
        emit sendSpeech(speechAppIdEdit->text(), speechTokenEdit->text());
        emit sendqwenapi(qwenApiEdit->toPlainText());
    }

signals:
    void sendapi(QString);
    void sendSpeech(QString,QString);
    void sendqwenapi(QString);



private:
    QTabWidget *tabWidget;
    SortWidget *tab1;
    GraphWidget *tab2;

    QTextEdit *apiEdit;
    QPushButton *sendapiButton;

    QLineEdit *speechTokenEdit;
    QLineEdit *speechAppIdEdit;

    QTextEdit *qwenApiEdit;
    QPushButton *sendQwenButton;


};

