#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <stack>
#include <QTimer>
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

            size=count;

            if (sortType == 1) {
                QTimer::singleShot(500, this, &Sort::insertSort);
                iLoop=1;
                start = std::chrono::high_resolution_clock::now();
                insertstr = arrtoqs(arr,size);
                emit numChanged(insertstr);
            }
            else if (sortType == 2) {
                QTimer::singleShot(500, this, &Sort::selectionSort);
                iLoop=0;
                start = std::chrono::high_resolution_clock::now();
                insertstr = arrtoqs(arr,size);
                emit numChanged(insertstr);
            }
            else if (sortType == 3) {
                quickSort();
                insertstr = arrtoqs(arr,size);
                emit numChanged(insertstr);
            }

        }

        void insertSort() {
            cout<<"insertSort"<<endl;
            //插入排序

            if (iLoop>=size) {
                //数组转为字符串并发送信号
                insertstr = arrtoqs(arr,size);
                emit numChanged(insertstr);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                emit usingTime(QString::number(duration.count()));
                return;
            }

            int key = arr[iLoop];
            int j = iLoop - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;

            iLoop++;


            insertstr = arrtoqs(arr,size);
            emit numChanged(insertstr);
            QTimer::singleShot(500, this, &Sort::insertSort);  //循环


        }

        void selectionSort() {
            cout<<"selectionSort"<<endl;

            if (iLoop>=size-1) {
                insertstr = arrtoqs(arr,size);
                emit numChanged(insertstr);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                emit usingTime(QString::number(duration.count()));
                return;
            }
            // 假设当前索引i处的元素是最小的
            int minIndex = iLoop;

            // 在剩余未排序部分中寻找最小元素的索引
            for (int j = iLoop + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            // 将找到的最小元素与当前位置的元素交换
            if (minIndex != iLoop) {
                int temp = arr[iLoop];
                arr[iLoop] = arr[minIndex];
                arr[minIndex] = temp;
            }

            iLoop++;

            insertstr = arrtoqs(arr,size);
            emit numChanged(insertstr);
            QTimer::singleShot(500, this, &Sort::selectionSort);
        }

        void quickSort() {
            cout<<"quickSort"<<endl;
            start = std::chrono::high_resolution_clock::now();

            if (size >= 1) {
                l.push(0);
                h.push(size-1);
                QTimer::singleShot(500, this, &Sort::quickSortFunction);
            }

        }


    private:
    void quickSortFunction() {

        // 取出当前要处理的区间


        if(l.empty()&&h.empty()) {
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            insertstr = arrtoqs(arr,size);
            emit numChanged(insertstr);
            emit usingTime(QString::number(duration.count()));

            cout<<"ok";

            return;
        }

        int low = l.top();
        int high = h.top();
        l.pop();
        h.pop();

            if (low >= high){QTimer::singleShot(500, this, &Sort::quickSortFunction);} // 区间无效，跳过

            // 选择基准元素（这里选择第一个元素）
            int pivot = arr[low];
            int i = low;
            int j = high;

            // 分区操作
            while (i < j) {
                // 从右向左找小于pivot的元素
                while (i < j && arr[j] >= pivot) j--;
                if (i < j) {
                    arr[i] = arr[j];
                    i++;
                }

                // 从左向右找大于pivot的元素
                while (i < j && arr[i] <= pivot) i++;
                if (i < j) {
                    arr[j] = arr[i];
                    j--;
                }
            }

            // 将基准元素放到正确位置
            arr[i] = pivot;

            // 将子区间压入栈中
            if (low < i - 1) {
                l.push(low);
                h.push(i - 1);
            }
            if (i + 1 < high) {
                l.push(i + 1);
                h.push(high);
            }

        insertstr = arrtoqs(arr,size);
        emit numChanged(insertstr);
        QTimer::singleShot(500, this, &Sort::quickSortFunction);
    }


    signals:
        void numChanged(QString str);
        void usingTime(QString time);

    private:
        QString insertstr;
        int size;
        int arr[100];
        int iLoop;
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        stack<int> l;
        stack<int> h;


};

#endif //SORT_H