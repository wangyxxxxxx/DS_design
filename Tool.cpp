//
// Created by 王雨轩 on 25-9-25.
//

#include "Tool.h"
#include <iostream>
#include <QString>
#include <QGraphicsRectItem>
#include <windows.h>
#include <QTimer>
#include <QEventLoop>
#include <QCoreApplication>

using namespace std;

QString arrtoqs(int arr[],int size) {
    QString result;

    for (int i = 0; i < size; i++) {
        if (i > 0) result += ", ";  // 添加分隔符
        result += QString::number(arr[i]);
    }

    result += "\n";

    return result;
}

void ChangeRectAnimation(QGraphicsRectItem* trect,int fh,int th,int tx,int ty){

    int nowh=th;

    for (int i = 0; i < 9; i++) {
        nowh=nowh+(fh-th)/10;
        trect->setRect(tx, ty, 50, nowh);
        trect->update();

        // 非阻塞延时
        QEventLoop loop;
        QTimer::singleShot(30, &loop, &QEventLoop::quit);
        loop.exec();
        // 处理事件，保持UI响应
        QCoreApplication::processEvents();

    }
    trect->setRect(tx, ty, 50, fh);
    trect->update();

}




