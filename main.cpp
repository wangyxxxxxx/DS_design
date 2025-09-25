#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
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


class Calculator : public QWidget {
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr) : QWidget(parent) {
        // 创建界面组件
        QLabel *titleLabel = new QLabel("排序程序");
        titleLabel->setAlignment(Qt::AlignCenter);

        QLabel *num1Label = new QLabel("数字 1:");
        QLabel *num2Label = new QLabel("数字 2:");
        QLabel *num3Label = new QLabel("数字 3:");
        QLabel *resultLabel = new QLabel("结果:");

        num1Edit = new QLineEdit();
        num2Edit = new QLineEdit();
        num3Edit = new QLineEdit();
        resultEdit = new QLineEdit();
        resultEdit->setReadOnly(true); // 结果框设为只读

        // 设置输入验证器，只允许输入数字和小数点
        QDoubleValidator *validator = new QDoubleValidator(this);
        num1Edit->setValidator(validator);
        num2Edit->setValidator(validator);
        num3Edit->setValidator(validator);

        QPushButton *calculateButton = new QPushButton("排序");

        // 创建布局
        QVBoxLayout *mainLayout = new QVBoxLayout();
        mainLayout->addWidget(titleLabel);

        QHBoxLayout *num1Layout = new QHBoxLayout();
        num1Layout->addWidget(num1Label);
        num1Layout->addWidget(num1Edit);

        QHBoxLayout *num2Layout = new QHBoxLayout();
        num2Layout->addWidget(num2Label);
        num2Layout->addWidget(num2Edit);

        QHBoxLayout *num3Layout = new QHBoxLayout();
        num3Layout->addWidget(num3Label);
        num3Layout->addWidget(num3Edit);

        QHBoxLayout *resultLayout = new QHBoxLayout();
        resultLayout->addWidget(resultLabel);
        resultLayout->addWidget(resultEdit);

        mainLayout->addLayout(num1Layout);
        mainLayout->addLayout(num2Layout);
        mainLayout->addLayout(num3Layout);
        mainLayout->addWidget(calculateButton);
        mainLayout->addLayout(resultLayout);

        setLayout(mainLayout);
        setWindowTitle("数字相加程序");
        resize(300, 200);


        Sorting* sss = new Sorting();
        // 连接按钮点击信号到槽函数
        connect(calculateButton, &QPushButton::clicked, sss, &Sorting::insertSort);
        connect(sss, &Sorting::numChanged, this, &Calculator::Display);
    }

private slots:
    void Display(QString insertstr) {
        // // 获取输入值并转换为double类型
        // bool ok1, ok2, ok3;
        // int num1 = num1Edit->text().toDouble(&ok1);
        // int num2 = num2Edit->text().toDouble(&ok2);
        // int num3 = num3Edit->text().toDouble(&ok3);
        //
        // // 检查输入是否有效
        // if (!ok1 || !ok2 || !ok3) {
        //     QMessageBox::warning(this, "输入错误", "请输入有效的数字！");
        //     return;
        // }

        resultEdit->setText(insertstr);
    }


private:
    QLineEdit *num1Edit;
    QLineEdit *num2Edit;
    QLineEdit *num3Edit;
    QLineEdit *resultEdit;
};



#include "main.moc"  // 如果单独保存为.cpp文件需要这一行



int main(int argc, char *argv[]) {

    QApplication a(argc, argv);


    Calculator calculator;
    calculator.show();


    return QApplication::exec();
}