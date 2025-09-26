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
        void getData(QString datastr) {
            //将字符串转为数组
            int isnum1=0;
            int count=0;
            for (int i = 0; i < datastr.length(); i++) {
                QChar ch = datastr.at(i);
                if (ch.isDigit() && isnum1 == 0) {
                    count++;
                    isnum1=1;
                }else if (!ch.isDigit()){isnum1=0;}
            }

            int isnum2=0;
            int arr[count];
            for (int i = 0,j=0; i < datastr.length(); i++) {
                QChar ch2 = datastr.at(i);
                if (ch2.isDigit() && isnum2 == 0) {
                    arr[j]=ch2.digitValue();
                    isnum2=1;
                }
                else if (ch2.isDigit() && isnum2 == 1){
                    arr[j]=arr[j]*10+ch2.digitValue();
                }
                else if(!ch2.isDigit()){isnum2=0;j++;;}
            }

            selectionSort(arr,count);
        }

        void insertSort(int arr[],int size) {

            //插入排序

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

        void selectionSort(int arr[], int size) {

            for (int i = 0; i < size - 1; i++) {
                // 假设当前索引i处的元素是最小的
                int minIndex = i;

                // 在剩余未排序部分中寻找最小元素的索引
                for (int j = i + 1; j < size; j++) {
                    if (arr[j] < arr[minIndex]) {
                        minIndex = j;
                    }
                }

                // 将找到的最小元素与当前位置的元素交换
                if (minIndex != i) {
                    int temp = arr[i];
                    arr[i] = arr[minIndex];
                    arr[minIndex] = temp;
                }
            }

            insertstr = arrtoqs(arr,size);
            emit numChanged(insertstr);
        }


    signals:
        void numChanged(QString str);

    private:
        QString insertstr;

};

#endif //SORT_H