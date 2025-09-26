#ifndef SORTWIDGET_H
#define SORTWIDGET_H

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
#include "Graph.h"
#include "Sort.h"
#include "Tool.h"
using namespace std;



class SortWidget : public QWidget {
    Q_OBJECT

public:
    SortWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // 创建界面组件

        /////////////////////////////////////////////////////////////左侧控制区

        //序列输入框
        QLabel *numLabel = new QLabel("输入序列:");
        numstrEdit = new QTextEdit();
        numstrEdit->setFixedHeight(30);
        //按钮
        QPushButton *sortButton = new QPushButton("排序");
        //选择
        chooseBox = new QComboBox();
        QLabel *chooseLabel = new QLabel("算法:");
        chooseBox->addItem("请选择算法");
        chooseBox->addItem("直接插入排序");
        chooseBox->addItem("简单选择排序");
        chooseBox->addItem("快速排序");
        //布局
        QHBoxLayout *numInputLayout = new QHBoxLayout();
        QHBoxLayout *chooseLayout = new QHBoxLayout();
        QVBoxLayout *controlLayout = new QVBoxLayout();
        QGroupBox *controlGroup = new QGroupBox("控制区");
        numInputLayout->addWidget(numLabel);
        numInputLayout->addWidget(numstrEdit);
        controlLayout->addLayout(numInputLayout);

        chooseLayout->addWidget(chooseLabel);
        chooseLayout->addWidget(chooseBox);
        controlLayout->addLayout(chooseLayout);

        controlLayout->addWidget(sortButton);
        controlLayout->addStretch(1);

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
        QVBoxLayout *resultLayout = new QVBoxLayout();
        QLabel *resultLabel = new QLabel("结果:");
        resultEdit = new QTextEdit();
        resultEdit->setFixedHeight(30);
        resultEdit->setReadOnly(true); // 结果框设为只读
        resultLayout->addWidget(resultLabel);
        resultLayout->addWidget(resultEdit);

        viewLayout->addWidget(graphLabel);
        viewLayout->addWidget(graphView);
        viewLayout->addLayout(resultLayout);


        ////////////////////////////////////////////////////////////（总）排序算法演示区
        QHBoxLayout *Layout = new QHBoxLayout();
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        QLabel *titleLabel = new QLabel("排序程序");
        titleLabel->setAlignment(Qt::AlignCenter);
        Layout->addWidget(controlGroup);
        Layout->addLayout(viewLayout);
        mainLayout->addWidget(titleLabel);
        mainLayout->addLayout(Layout);





        //////////////////////////////////////////////////////////// 连接按钮点击信号到槽函数
        Sort* sort = new Sort();
        connect(sortButton, QPushButton::clicked, this, &SortWidget::submitData);
        connect(sort, &Sort::numChanged, this, &SortWidget::Display);
        connect(this, &SortWidget::sendData, sort, &Sort::getData);

    }


signals:
    void sendData(QString);


private slots:
    void Display(QString insertstr) {
        resultEdit->setText(insertstr);
    }
    void submitData() {

        QString numstring = numstrEdit->toPlainText();
        emit sendData(numstring);


    }


private:
    QTextEdit *numstrEdit;
    QTextEdit *resultEdit;
    QGraphicsView *graphView;
    QGraphicsScene *scene;
    QComboBox *chooseBox;
};

#include "main.moc"

#endif //SORTWIDGET_H



// 设置输入验证器，只允许输入数字和小数点
// QDoubleValidator *validator = new QDoubleValidator(this);
// numEdit->setValidator(validator);