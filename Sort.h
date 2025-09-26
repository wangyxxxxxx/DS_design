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
#include <chrono>
#include "Tool.h"
using namespace std;

class Sort : public QObject {

    Q_OBJECT

    public:
        Sort() : insertstr(""){}

    public slots:
        void getData(QString datastr,int sortType) {
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

            if (sortType == 1) {insertSort(arr,count);}
            else if (sortType == 2) {selectionSort(arr,count);}
            else if (sortType == 3) {quickSort(arr,count);}

        }

        void insertSort(int arr[],int size) {
            cout<<"insertSort"<<endl;
            //插入排序
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 1; i < size; i++) {

                int key = arr[i];
                int j = i - 1;

                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;

                }

                arr[j + 1] = key;

            }
            auto end = std::chrono::high_resolution_clock::now();
            auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);


            //数组转为字符串并发送信号
            insertstr = arrtoqs(arr,size);
            emit numChanged(insertstr);
            emit usingTime(QString::number(duration_ns.count()));

        }

        void selectionSort(int arr[], int size) {
            cout<<"selectionSort"<<endl;
            auto start = std::chrono::high_resolution_clock::now();

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

            auto end = std::chrono::high_resolution_clock::now();
            auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            insertstr = arrtoqs(arr,size);
            emit numChanged(insertstr);
            emit usingTime(QString::number(duration_ns.count()));
        }

        void quickSort(int arr[], int size) {
            cout<<"quickSort"<<endl;
            auto start = std::chrono::high_resolution_clock::now();

            if (size >= 1) quickSortFunction(arr, 0, size - 1);;

            auto end = std::chrono::high_resolution_clock::now();
            auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

            insertstr = arrtoqs(arr,size);
            emit numChanged(insertstr);
            emit usingTime(QString::number(duration_ns.count()));
        }

    private:
        void quickSortFunction(int arr[], int left, int right) {
            // 递归终止条件
            if (left >= right) {
                return;
            }

            // 选择基准元素（这里选择中间元素）
            int pivot = arr[(left + right) / 2];
            int i = left;
            int j = right;

            // 分区操作
            while (i <= j) {
                // 从左向右找到第一个大于等于基准的元素
                while (arr[i] < pivot) {
                    i++;
                }
                // 从右向左找到第一个小于等于基准的元素
                while (arr[j] > pivot) {
                    j--;
                }

                // 交换元素
                if (i <= j) {
                    std::swap(arr[i], arr[j]);
                    i++;
                    j--;
                }
            }

            // 递归排序左右子数组
            quickSortFunction(arr, left, j);
            quickSortFunction(arr, i, right);
        }


    signals:
        void numChanged(QString str);
        void usingTime(QString time);

    private:
        QString insertstr;

};

#endif //SORT_H