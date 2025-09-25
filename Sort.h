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

class Sorting : public QObject {

    Q_OBJECT

    public:
        Sorting() : insertstr(""){}

    public slots:
        void insertSort(int data1,int data2,int data3) {

            arr[0]=data1;
            arr[1]=data2;
            arr[2]=data3;

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

            insertstr = arrtoqs(arr,size);
            emit numChanged(insertstr);

        }
        void getnum(int data1,int data2,int data3) {
            arr[0]=data1;
            arr[1]=data2;
            arr[2]=data3;
        }

    signals:
        void numChanged(QString str);

    private:
        QString insertstr;
        int arr[3];

};
