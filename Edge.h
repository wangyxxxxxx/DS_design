// //
// // Created by 王雨轩 on 25-9-30.
// //
//
#ifndef EDGE_H
#define EDGE_H
#include "Vertex.h"
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QFont>

class Edge : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    Edge(Vertex* startVertex, Vertex* endVertex, int weight, QGraphicsItem* parent = nullptr)
        : QObject(), QGraphicsItemGroup(parent), startVertex(startVertex), endVertex(endVertex), weight(weight)
    {
        // 创建直线
        line = new QGraphicsLineItem(this);
        updatePosition();

        // 设置线条样式
        QPen pen;
        pen.setWidth(3);
        pen.setColor(Qt::black);
        line->setPen(pen);

        // 创建权重文本
        weightText = new QGraphicsTextItem(QString::number(weight), this);
        QFont font = weightText->font();
        font.setPointSize(20);
        font.setBold(true);
        weightText->setFont(font);
        weightText->setDefaultTextColor(Qt::darkRed);

        // 更新文本位置
        updateTextPosition();

        // 连接顶点的位置变化信号
        connect(startVertex, &Vertex::positionChanged, this, &Edge::onVertexPositionChanged);
        connect(endVertex, &Vertex::positionChanged, this, &Edge::onVertexPositionChanged);

        // 设置Z值，确保边在顶点下方
        setZValue(-1);
    }

    // 获取起点顶点
    Vertex* getStartVertex() const { return startVertex; }

    // 获取终点顶点
    Vertex* getEndVertex() const { return endVertex; }

    // 获取权重
    int getWeight() const { return weight; }

    // 设置权重
    void setWeight(int newWeight)
    {
        weight = newWeight;
        weightText->setPlainText(QString::number(weight));
        updateTextPosition();
    }

    // 设置线条样式
    void setLineStyle(const QPen& pen)
    {
        line->setPen(pen);
    }

    // 设置线条颜色
    void setLineColor(const QColor& color)
    {
        QPen pen = line->pen();
        pen.setColor(color);
        line->setPen(pen);
    }

    // 设置线条宽度
    void setLineWidth(int width)
    {
        QPen pen = line->pen();
        pen.setWidth(width);
        line->setPen(pen);
    }

private slots:
    // 当顶点位置变化时更新边的位置
    void onVertexPositionChanged(Vertex* vertex, QPointF newPosition)
    {
        Q_UNUSED(vertex)
        Q_UNUSED(newPosition)
        updatePosition();
        updateTextPosition();
    }

private:
    // 更新边的位置
    void updatePosition()
    {
        QPointF startPos = startVertex->pos();
        QPointF endPos = endVertex->pos();
        line->setLine(startPos.x(), startPos.y(), endPos.x(), endPos.y());
    }

    // 更新权重文本位置
    void updateTextPosition()
    {
        QPointF startPos = startVertex->pos();
        QPointF endPos = endVertex->pos();

        // 计算中点位置
        qreal midX = (startPos.x() + endPos.x()) / 2;
        qreal midY = (startPos.y() + endPos.y()) / 2;

        // 设置文本位置（居中）
        QRectF textRect = weightText->boundingRect();
        weightText->setPos(midX - textRect.width() / 2, midY - textRect.height() / 2);
    }

private:
    Vertex* startVertex;
    Vertex* endVertex;
    int weight;
    QGraphicsLineItem* line;
    QGraphicsTextItem* weightText;
};


#endif //EDGE_H
