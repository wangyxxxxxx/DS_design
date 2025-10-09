//
// Created by 王雨轩 on 25-9-30.
//

#ifndef VERTEX_H
#define VERTEX_H

#include <QString>
#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsItemGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QBrush>
#include <QColor>
#include <QRandomGenerator>
#include <QFont>

class Vertex : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    Vertex(QString number, qreal x, qreal y): QObject(), QGraphicsItemGroup()
    {
        vertexNumber = number;
        vertexX = x;
        vertexY = y;
        // 创建圆形
        circle = new QGraphicsEllipseItem(-25, -25, 50, 50, this);
        circle->setBrush(QBrush(Qt::white)); // 蓝色填充
        color="white";

        // 创建文本项显示编号
        text = new QGraphicsTextItem(number, this);
        QFont font = text->font();
        font.setPointSize(12);
        font.setBold(true);
        text->setFont(font);
        text->setDefaultTextColor(Qt::black);

        // 居中文本
        QRectF textRect = text->boundingRect();
        text->setPos(-textRect.width()/2, -textRect.height()/2);

        // 设置位置
        setPos(x, y);

        // 启用拖动和选择
        setFlag(QGraphicsItem::ItemIsMovable, true);
        setFlag(QGraphicsItem::ItemIsSelectable, true);

        //监听
        setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    }


signals:
    void positionChanged(Vertex* vertex, QPointF newPosition);
//监听顶点是否移动
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override
    {
        if (change == ItemPositionHasChanged) {
            emit positionChanged(this, value.toPointF());
        }
        return QGraphicsItemGroup::itemChange(change, value);
    }

public:
    QString getNumber() {
        return vertexNumber;
    }
    int getX() {
        return vertexX;
    }
    int getY() {
        return vertexY;
    }
    void setColor(QString color) {
        if (color == "white") {
            circle->setBrush(QBrush(Qt::white));
            color="white";
        }else if (color == "green") {
            circle->setBrush(QBrush(Qt::green));
            color="green";
        }else if (color == "red") {
            circle->setBrush(QBrush(Qt::red));
            color="red";
        }

    }

    QString getColor() {
        return color;
    }


private:
    QGraphicsEllipseItem *circle;
    QGraphicsTextItem *text;
    QString vertexNumber;
    int vertexX;
    int vertexY;
    QString color;
};


#endif //VERTEX_H
