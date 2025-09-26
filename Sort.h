#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <QApplication>      // 用于创建Qt应用程序对象
#include <QWidget>           // 窗口基类
#include <QPushButton>       // 按钮控件
#include <QLabel>            // 文本标签控件
#include <QVBoxLayout>       // 垂直布局管理器
#include <QObject>           // Qt对象基类（信号槽的基础）
#include <QString>
#include <string>
#include <windows.h>
#include "Tool.h"
using namespace std;

class Sort : public QObject {

    Q_OBJECT

    public:
        Sort() : insertstr(""){}

    public slots:
        void insertSort(QString datastr) {

            //将字符串转为数组
            int count=0;
            for (int i = 0; i < datastr.length(); i++) {
                QChar ch = datastr.at(i);

                if (ch.isDigit()) {
                    count++;
                }
            }

            int arr[count];
            for (int i = 0,j=0; i < datastr.length(); i++) {
                QChar ch2 = datastr.at(i);
                if (ch2.isDigit()) {
                    arr[j]=ch2.digitValue();
                    j++;
                }
            }

            //插入排序
            int size = sizeof(arr) / sizeof(arr[0]);

            for (int i = 1; i < size; i++) {

                int key = arr[i];
                int j = i - 1;

                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;

                }

                arr[j + 1] = key;

            }
            //数组转为字符串并发送信号
            insertstr = arrtoqs(arr,size);
            emit numChanged(insertstr);

        }


    signals:
        void numChanged(QString str);

    private:
        QString insertstr;
        //int arr[3];

};

#endif //SORT_H