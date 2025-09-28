//
// Created by 王雨轩 on 25-9-25.
//

#ifndef TOOL_H
#define TOOL_H
#include <QString>
#include <QGraphicsRectItem>
#include <QEventLoop>

QString arrtoqs(int arr[],int size);
void ChangeRectAnimation(QGraphicsRectItem* trect,int type,int fh,int th,int tx,int ty,int delay);
#endif //TOOL_H
