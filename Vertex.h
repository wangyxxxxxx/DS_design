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
    Vertex() : QObject(), QGraphicsItemGroup(), circle(nullptr), text(nullptr), vertexX(0), vertexY(0) {}
    Vertex(QString number, qreal x, qreal y): QObject(), QGraphicsItemGroup()
    {
        vertexNumber = number;
        vertexX = x;
        vertexY = y;
        // 创建圆形
        circle = new QGraphicsEllipseItem(-25, -25, 50, 50, this);
        circle->setBrush(QBrush(Qt::white));
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

    friend QDataStream &operator<<(QDataStream &out, const Vertex &vertex);
    friend QDataStream &operator>>(QDataStream &in, Vertex &vertex);


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
    QString getNumber() const  {
        return vertexNumber;
    }
    int getX()const {
        return vertexX;
    }
    int getY()const {
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

    QString getColor()const {
        return color;
    }




private:
    QGraphicsEllipseItem *circle;
    QGraphicsTextItem *text;
    QString vertexNumber;
    qreal vertexX;
    qreal vertexY;
    QString color;
};





// 在 Vertex.h 中
inline QDataStream &operator<<(QDataStream &out, const Vertex &vertex) {
    qDebug() << "序列化顶点:" << vertex.getNumber() << "位置:" << vertex.vertexX << vertex.vertexY << "颜色:" << vertex.color;
    out << vertex.vertexNumber;
    out << vertex.vertexX;
    out << vertex.vertexY;
    out << vertex.color;
    qDebug() << "序列化顶点完成，数据流状态:" << out.status();
    return out;
}

inline QDataStream &operator>>(QDataStream &in, Vertex &vertex) {
    in >> vertex.vertexNumber;
    in >> vertex.vertexX;
    in >> vertex.vertexY;
    in >> vertex.color;
    qDebug() << "反序列化顶点:" << vertex.vertexNumber << "位置:" << vertex.vertexX << vertex.vertexY << "颜色:" << vertex.color;
    qDebug() << "反序列化顶点完成，数据流状态:" << in.status();

    // 重新创建图形项
    vertex.circle = new QGraphicsEllipseItem(-25, -25, 50, 50, &vertex);
    if (vertex.color == "white") {
        vertex.circle->setBrush(QBrush(Qt::white));
    } else if (vertex.color == "green") {
        vertex.circle->setBrush(QBrush(Qt::green));
    } else if (vertex.color == "red") {
        vertex.circle->setBrush(QBrush(Qt::red));
    }

    vertex.text = new QGraphicsTextItem(vertex.vertexNumber, &vertex);
    QFont font = vertex.text->font();
    font.setPointSize(12);
    font.setBold(true);
    vertex.text->setFont(font);
    vertex.text->setDefaultTextColor(Qt::black);

    QRectF textRect = vertex.text->boundingRect();
    vertex.text->setPos(-textRect.width()/2, -textRect.height()/2);
    vertex.setPos(vertex.vertexX, vertex.vertexY);

    vertex.setFlag(QGraphicsItem::ItemIsMovable, true);
    vertex.setFlag(QGraphicsItem::ItemIsSelectable, true);
    vertex.setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    return in;
}

#endif //VERTEX_H
