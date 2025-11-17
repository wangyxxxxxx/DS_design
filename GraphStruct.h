//
// Created by 王雨轩 on 25-11-17.
//

#ifndef GRAPHSTRUCT_H
#define GRAPHSTRUCT_H
#include <QGraphicsRectItem>
#include <qtmetamacros.h>
#include <QPainterPath>
#include <QPen>
#include <cmath>


class StructNode : public QObject, public QGraphicsItemGroup{
    Q_OBJECT

private:
    QGraphicsRectItem * structRect1;
    QGraphicsRectItem * structRect2;
    QGraphicsTextItem *text;
    int x;
    int y;
    QString num;

public:
    ~StructNode(){}
    StructNode(int X,int Y,QString number) {
        x=X;
        y=Y;
        num=number;
        structRect1 = new QGraphicsRectItem(0,0,50,50,this);
        structRect2 = new QGraphicsRectItem(50,0,50,50,this);
        structRect1->setBrush(QBrush(Qt::white));
        structRect2->setBrush(QBrush(Qt::white));

        // 创建文本项显示编号
        text = new QGraphicsTextItem(number, structRect1 );
        QFont font = text->font();
        font.setPointSize(12);
        font.setBold(true);
        text->setFont(font);
        text->setDefaultTextColor(Qt::black);

        // 居中文本
        QRectF textRect = text->boundingRect();
        text->setPos(25 - textRect.width()/2, 25 - textRect.height()/2);

        setPos(x, y);

    }

};

class StructEdge : public QObject, public QGraphicsItemGroup{
    Q_OBJECT

private:
    QGraphicsRectItem * structRect1;
    QGraphicsRectItem * structRect2;
    QGraphicsRectItem * structRect3;
    QGraphicsTextItem *text1;
    QGraphicsTextItem *text2;
    int x;
    int y;
    QString num;

public:
    ~StructEdge(){}
    StructEdge(int X,int Y,QString number, QString weight) {
        x=X;
        y=Y;
        num=number;
        structRect1 = new QGraphicsRectItem(0,0,50,50,this);
        structRect2 = new QGraphicsRectItem(50,0,50,50,this);
        structRect3 = new QGraphicsRectItem(100,0,50,50,this);
        structRect1->setBrush(QBrush(Qt::white));
        structRect2->setBrush(QBrush(Qt::white));
        structRect3->setBrush(QBrush(Qt::white));

        // 创建文本项显示编号
        text1 = new QGraphicsTextItem(number, structRect1 );
        QFont font = text1->font();
        font.setPointSize(12);
        font.setBold(true);
        text1->setFont(font);
        text1->setDefaultTextColor(Qt::black);

        // 居中文本
        QRectF textRect = text1->boundingRect();
        text1->setPos(25 - textRect.width()/2, 25 - textRect.height()/2);


        // 创建文本项显示编号
        text2 = new QGraphicsTextItem(weight, structRect2 );
        QFont font2 = text2->font();
        font2.setPointSize(12);
        font2.setBold(true);
        text2->setFont(font2);
        text2->setDefaultTextColor(Qt::black);

        // 居中文本
        QRectF textRect2 = text2->boundingRect();
        text2->setPos(75 - textRect2.width()/2, 25 - textRect2.height()/2);


        setPos(x, y);

    }

};

class StructArrow : public QObject, public QGraphicsItemGroup {
    Q_OBJECT
private:
    QGraphicsPathItem * line;
    int x;
    int y;
public:
    ~StructArrow() {}
    StructArrow(int fromx,int tox,int Y)
    {
        x = fromx;
        y = Y;

        // 创建路径项，使用组作为父项
        line = new QGraphicsPathItem(this);

        // 创建路径 - 使用相对坐标（相对于组的位置）
        QPainterPath path;

        // 绘制主线 - 从(0,0)到(tox-fromx, 0)
        path.moveTo(0, 25);  // 从中间高度开始
        path.lineTo(tox - fromx, 25);  // 到中间高度结束

        // 绘制箭头
        int arrowSize = 8;
        int length = tox - fromx;

        if (length >= 0) {
            // 向右的箭头
            path.moveTo(length, 25);
            path.lineTo(length - arrowSize, 25 - arrowSize/2);
            path.moveTo(length, 25);
            path.lineTo(length - arrowSize, 25 + arrowSize/2);
        } else {
            // 向左的箭头
            path.moveTo(length, 25);
            path.lineTo(length + arrowSize, 25 - arrowSize/2);
            path.moveTo(length, 25);
            path.lineTo(length + arrowSize, 25 + arrowSize/2);
        }

        // 设置路径
        line->setPath(path);

        // 设置样式
        QPen pen(Qt::black);
        pen.setWidth(2);
        pen.setCapStyle(Qt::FlatCap);
        line->setPen(pen);

        // 关键：将整个组移动到起始位置
        setPos(fromx, Y);
    }
};

#endif //GRAPHSTRUCT_H
