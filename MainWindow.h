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

        // 创建选项卡控件
        tabWidget = new QTabWidget(centralWidget);

        // 创建第一个选项卡页面
        tab1 = new SortWidget();

        // 创建第二个选项卡页面
        tab2 = new QWidget();
        label2 = new QLabel("这是第二个选项卡的页面", tab2);
        QVBoxLayout *layout2 = new QVBoxLayout(tab2);
        layout2->addWidget(label2);
        tab2->setLayout(layout2);

        // 将选项卡添加到选项卡控件
        tabWidget->addTab(tab1, "排序算法演示");
        tabWidget->addTab(tab2, "图形结构演示");

        // 设置中央部件的布局
        QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->addWidget(tabWidget);
        centralWidget->setLayout(mainLayout);

    }



    QTabWidget *tabWidget;
    QWidget *tab1;
    QWidget *tab2;
    //QLabel *label1;
    QLabel *label2;
};

