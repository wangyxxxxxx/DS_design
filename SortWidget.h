#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>

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
        QLabel *titleLabel = new QLabel("排序程序");
        titleLabel->setAlignment(Qt::AlignCenter);

        QLabel *numLabel = new QLabel("输入序列:");
        QLabel *resultLabel = new QLabel("结果:");

        numEdit = new QTextEdit();
        resultEdit = new QTextEdit();
        resultEdit->setReadOnly(true); // 结果框设为只读

        // 设置输入验证器，只允许输入数字和小数点
        // QDoubleValidator *validator = new QDoubleValidator(this);
        // numEdit->setValidator(validator);

        QPushButton *calculateButton = new QPushButton("排序");

        // 创建布局
        QVBoxLayout *mainLayout = new QVBoxLayout();
        mainLayout->addWidget(titleLabel);

        QHBoxLayout *numLayout = new QHBoxLayout();
        numLayout->addWidget(numLabel);
        numLayout->addWidget(numEdit);


        QHBoxLayout *resultLayout = new QHBoxLayout();
        resultLayout->addWidget(resultLabel);
        resultLayout->addWidget(resultEdit);

        mainLayout->addLayout(numLayout);
        mainLayout->addWidget(calculateButton);
        mainLayout->addLayout(resultLayout);

        setLayout(mainLayout);
        setWindowTitle("数字相加程序");
        resize(300, 200);



        // 连接按钮点击信号到槽函数
        Sort* sort = new Sort();
        connect(calculateButton, QPushButton::clicked, this, &SortWidget::submitData);
        connect(sort, &Sort::numChanged, this, &SortWidget::Display);
        connect(this, &SortWidget::sendData, sort, &Sort::insertSort);

    }

signals:
    void sendData(QString);


private slots:
    void Display(QString insertstr) {
        resultEdit->setText(insertstr);
    }
    void submitData() {

        QString numstring = numEdit->toPlainText();
        emit sendData(numstring);


    }


private:
    QTextEdit *numEdit;
    QTextEdit *resultEdit;
};

#include "main.moc"

#endif //SORTWIDGET_H