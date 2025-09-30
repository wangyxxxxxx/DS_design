#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <stack>
#include <QTimer>
#include <QApplication>      // 用于创建Qt应用程序对象
#include <QWidget>           // 窗口基类
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
        Sort() : delay(1000){}

    public slots:
        void getData(QString datastr,int sortType,int d) {
            delay = d;
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
            }
            else if (sortType == 2) {
                QTimer::singleShot(500, this, &Sort::selectionSort);
                iLoop=0;
                start = std::chrono::high_resolution_clock::now();
            }
            else if (sortType == 3) {
                quickSort();
            }

        }

        void insertSort() {
                cout<<"insertSort"<<endl;
                //插入排序

                if (iLoop>=size) {
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                    emit setColor(iLoop-1,1);
                    emit usingTime(QString::number(duration.count()));
                    qDebug()<<"后端直接插入序结果："<<arrtoqs(arr,size);
                    return;
                }

                emit setColor(iLoop-1,1);
                emit setColor(iLoop,2);

                int i;

                for (i = iLoop-1; i >=0; i--) {
                    if (arr[iLoop] >= arr[i]) {
                        break;
                    }
                }

                i++;

                if (i!=iLoop){
                    int temp = arr[i];
                    arr[i]=arr[iLoop];
                    emit setColor(i,3);
                    emit numSwap(iLoop,i,1,1);

                    emit setColor(iLoop,1);

                    int j;
                    for (j = iLoop; j > i+1; j--) {

                        arr[j]=arr[j-1];
                        emit numSwap(j-1,j,1,1);

                    }


                    arr[i+1]=temp;
                    emit numSwap(temp,i+1,0,1);

                    emit setColor(i,1);

                }


                iLoop++;
                QTimer::singleShot(delay, this, &Sort::insertSort);

            }

        void selectionSort() {
            cout<<"selectionSort"<<endl;

            if (iLoop>=size-1) {
                emit setColor(size-1,1);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                emit usingTime(QString::number(duration.count()));
                qDebug()<<"后端简单选择排序结果："<<arrtoqs(arr,size);
                return;
            }
            // 假设当前索引i处的元素是最小的
            int minIndex = iLoop;
            int lminIndex = minIndex;

            // 在剩余未排序部分中寻找最小元素的索引
            for (int j = iLoop; j < size; j++) {
                emit setColor(j,2);
                if (j!=iLoop) {emit setColor(j-1,0);}

                if (arr[j] < arr[minIndex] || minIndex==j) {
                    lminIndex = minIndex;
                    minIndex = j;
                }


                emit setColor(lminIndex,0);
                emit setColor(minIndex,2);

                // 非阻塞延时
                QEventLoop loop;
                QTimer::singleShot(delay, &loop, &QEventLoop::quit);
                loop.exec();
                // 处理事件，保持UI响应
                QCoreApplication::processEvents();

            }

            if (iLoop!=size-1 && minIndex != size-1){emit setColor(size-1,0);}

            // 将找到的最小元素与当前位置的元素交换
            if (minIndex != iLoop) {
                int temp = arr[iLoop];
                arr[iLoop] = arr[minIndex];
                emit numSwap(minIndex,iLoop,1,1);
                arr[minIndex] = temp;
                emit numSwap(temp,minIndex,0,1);

            }

            emit setColor(minIndex,0);
            emit setColor(iLoop,1);

            iLoop++;


            QTimer::singleShot(delay, this, &Sort::selectionSort);
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

        void quickSortFunction() {

                qDebug()<<"后端快速排序结果："<<arrtoqs(arr,size);

                // 取出当前要处理的区间

                if(l.empty()&&h.empty()) {
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

                    emit usingTime(QString::number(duration.count()));
                    qDebug()<<"后端快速排序结果："<<arrtoqs(arr,size);

                    return;
                }

                int low = l.top();
                int high = h.top();
                l.pop();
                h.pop();

                if (low >= high){QTimer::singleShot(0, this, &Sort::quickSortFunction);} // 区间无效，跳过

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
                        emit numSwap(j,i,1,1);
                        i++;
                    }

                    // 从左向右找大于pivot的元素
                    while (i < j && arr[i] <= pivot) i++;
                    if (i < j) {
                        arr[j] = arr[i];
                        emit numSwap(i,j,1,1);
                        j--;
                    }
                }

                // 将基准元素放到正确位置
                arr[i] = pivot;
                emit numSwap(pivot,i,0,1);

                // 将子区间压入栈中
                if (low < i - 1) {
                    l.push(low);
                    h.push(i - 1);
                }
                if (i + 1 < high) {
                    l.push(i + 1);
                    h.push(high);
                }


                QTimer::singleShot(delay, this, &Sort::quickSortFunction);
            }

        void SetDelay(int d) {
            delay=d;
        }





    signals:
        void numSwap(int n, int m,int s,int type);
        void usingTime(QString time);
        void setColor(int num,int s);

    private:
        int size;
        int arr[100];
        int iLoop;
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        stack<int> l;
        stack<int> h;
        int delay;


};

#endif //SORT_H