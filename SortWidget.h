#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
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
using namespace std;



class SortWidget : public QWidget {
    Q_OBJECT

public:
    SortWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // 创建界面组件

        ///////////////初始化
        ItemX=50;
        ItemY=50;


        /////////////////////////////////////////////////////////////左侧控制区

        //序列输入框
        QLabel *numLabel = new QLabel("序列:");
        numstrEdit = new QTextEdit();
        numstrEdit->setFixedHeight(30);


        //按钮
        QPushButton *sortButton = new QPushButton("排序");
        QPushButton *clearButton = new QPushButton("清除");
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
        controlLayout->setSpacing(20);//设置layout中元素间距
        QGroupBox *controlGroup = new QGroupBox("控制区");

        //序列输入区
        numInputLayout->addWidget(numLabel);
        numInputLayout->addWidget(numstrEdit);
        QGroupBox *numInputGroup = new QGroupBox("序列输入区");
        numInputGroup->setLayout(numInputLayout);
        controlLayout->addWidget(numInputGroup);

        //算法选择区
        chooseLayout->addWidget(chooseLabel);
        chooseLayout->addWidget(chooseBox);
        QGroupBox *chooseGroup = new QGroupBox("算法选择区");
        chooseGroup->setLayout(chooseLayout);
        controlLayout->addWidget(chooseGroup);

        controlLayout->addWidget(sortButton);
        controlLayout->addWidget(clearButton);
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


        ////////////////////////////////////////////////////////////（总）排序算法演示区
        QHBoxLayout *Layout = new QHBoxLayout();
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        QLabel *titleLabel = new QLabel("排序算法演示");
        titleLabel->setAlignment(Qt::AlignCenter);

        Layout->addWidget(controlGroup,1);//拉伸因子
        Layout->addLayout(viewLayout,3);//拉伸因子

        mainLayout->addWidget(titleLabel);
        mainLayout->addLayout(Layout);





        //////////////////////////////////////////////////////////// 连接按钮点击信号到槽函数
        Sort* sort = new Sort();
        connect(sortButton, QPushButton::clicked, this, &SortWidget::submitData);
        connect(sort, &Sort::usingTime, this, &SortWidget::DisplayTime);
        connect(this, &SortWidget::sendData, sort, &Sort::getData);
        connect(sortButton, QPushButton::clicked, this, &SortWidget::creatGraph);
        connect(clearButton, QPushButton::clicked, this, &SortWidget::ClearAll);
        connect(sort, &Sort::numSwap, this, &SortWidget::RectSwap);
        connect(sort, &Sort::setColor, this, &SortWidget::SetRectColor);


    }


signals:
    void sendData(QString,int);


private slots:


    void DisplayTime(QString usingtime) {
        timeEdit->setText(usingtime);
    }

    void submitData() {

        QString numstring = numstrEdit->toPlainText();
        QString chooseType = chooseBox->currentText();
        int sortType=0;
        if (chooseType == "请选择算法") {
            sortType = 0;
        }else if (chooseType == "直接插入排序") {
            sortType = 1;
        }else if (chooseType == "简单选择排序") {
            sortType = 2;
        }else if (chooseType == "快速排序") {
            sortType = 3;
        }
        emit sendData(numstring,sortType);


    }

    void creatGraph() {

         if (!rectList.isEmpty()) {
             ClearRectAndResult();
        }


        //字符串转为数组并获取元素个数
        QString sortstr = numstrEdit->toPlainText();
        int isnum1=0;
        int count=0;
        for (int i = 0; i < sortstr.length(); i++) {
            QChar ch = sortstr.at(i);
            if (ch.isDigit() && isnum1 == 0) {
                count++;
                isnum1=1;
            }else if (!ch.isDigit()){isnum1=0;}
        }

        int isnum2=0;
        size=count;
        for (int i = 0,j=0; i < sortstr.length(); i++) {
            QChar ch2 = sortstr.at(i);
            if (ch2.isDigit() && isnum2 == 0) {
                arr[j]=ch2.digitValue();
                isnum2=1;
            }
            else if (ch2.isDigit() && isnum2 == 1){
                arr[j]=arr[j]*10+ch2.digitValue();
            }
            else if(!ch2.isDigit()){isnum2=0;j++;;}
        }



         //创建图形
         for (int i=0; i < count; i++,ItemX=ItemX+50) {
             // 创建矩形顶点
             rectItem = new QGraphicsRectItem(ItemX, ItemY, 50, 20*arr[i]);
             rectItem->setTransform(QTransform::fromScale(1, -1), true);
             rectList.append(rectItem);
             rectLocation.append(make_pair(ItemX,ItemY));
             scene->addItem(rectList.operator[](i));


             // 创建文本标签
             textItem = new QGraphicsTextItem(QString::number(arr[i]));
             textItem->setPos(ItemX+18,ItemY-90);
             rectLabelsList.append(textItem);
             scene->addItem(rectLabelsList.operator[](i));


         }

        ItemX=50;
        ItemY=50;


    }

    void ClearAll() {

            while (!rectList.isEmpty()) {
                delete rectList.takeAt(0);
            }

            while (!rectLabelsList.isEmpty()) {
                delete rectLabelsList.takeAt(0);
            }

            numstrEdit->clear();
            timeEdit->clear();
            resultEdit->clear();
            rectLocation.clear();


    }

    void RectSwap(int n,int m,int s) {
        int x=rectLocation[m].first,y=rectLocation[m].second;

        if (s==0) {
            ChangeRectAnimation(rectList.operator[](m),n*20,20*arr[m],x,y);
            arr[m]=n;
            rectLabelsList.operator[](m)->setPlainText(QString::number(n));
        }else if (s==1) {
            ChangeRectAnimation(rectList.operator[](m),20*arr[n],20*arr[m],x,y);
            arr[m]=arr[n];
            rectLabelsList.operator[](m)->setPlainText(QString::number(arr[n]));
        }


        Displayresult();
    }

    void SetRectColor(int num,int s) {
        if (s==0) {
            rectList.operator[](num)->setBrush(QBrush(Qt::white));
        }else if (s==1) {
            rectList.operator[](num)->setBrush(QBrush(Qt::green));
        }else if (s==2) {
            rectList.operator[](num)->setBrush(QBrush(Qt::red));
        }

    }


private:
    void ClearRectAndResult() {
        while (!rectList.isEmpty()) {
            delete rectList.takeAt(0);
        }

        while (!rectLabelsList.isEmpty()) {
            delete rectLabelsList.takeAt(0);
        }

        timeEdit->clear();
        resultEdit->clear();
        rectLocation.clear();

    }

    void Displayresult() {
        resultEdit->setText(arrtoqs(arr,size));
    }


private:
    QTextEdit *numstrEdit;
    QTextEdit *resultEdit;
    QGraphicsView *graphView;
    QGraphicsScene *scene;
    QComboBox *chooseBox;
    QTextEdit *timeEdit;
    QList<QGraphicsRectItem*> rectList;
    QList<QGraphicsTextItem*> rectLabelsList;
    QGraphicsRectItem *rectItem;
    QGraphicsTextItem *textItem;
    QList<pair<int,int> > rectLocation;
    int ItemX;
    int ItemY;
    int arr[100];
    int size;
};

#include "main.moc"

#endif //SORTWIDGET_H



// 设置输入验证器，只允许输入数字和小数点
// QDoubleValidator *validator = new QDoubleValidator(this);
// numEdit->setValidator(validator);