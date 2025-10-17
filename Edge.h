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
#include <QDataStream>
#include <QDebug>

class Edge : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    Edge(Vertex* startVertex, Vertex* endVertex, int weight, bool hasArrow, QGraphicsItem* parent = nullptr)
        : QObject(), QGraphicsItemGroup(parent), startVertex(startVertex), endVertex(endVertex), weight(weight), hasArrow(hasArrow)
    {
        // 创建直线
        line = new QGraphicsPathItem(this);
        updatePosition();

        // 设置线条样式
        QPen pen;
        pen.setWidth(3);
        pen.setColor(Qt::black);
        pen.setCapStyle(Qt::RoundCap);
        pen.setJoinStyle(Qt::RoundJoin);
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

    void setArrowEnabled(bool enabled)
    {
        if (hasArrow != enabled) {
            hasArrow = enabled;
            updatePosition(); // 重新绘制边
        }
    }

    ////////////////文件
    Edge() : QObject(), QGraphicsItemGroup(), startVertex(nullptr), endVertex(nullptr),
             weight(0), hasArrow(false), line(nullptr), weightText(nullptr) {}
    friend QDataStream &operator<<(QDataStream &out, const Edge &edge);
    friend QDataStream &operator>>(QDataStream &in, Edge &edge);
    // 添加辅助方法用于设置顶点指针
    void setVertices(Vertex* start, Vertex* end) {
        startVertex = start;
        endVertex = end;

        // 重新连接信号
        if (startVertex && endVertex) {
            connect(startVertex, &Vertex::positionChanged, this, &Edge::onVertexPositionChanged);
            connect(endVertex, &Vertex::positionChanged, this, &Edge::onVertexPositionChanged);
            updatePosition();
            updateTextPosition();
        }
    }
    QString getStartVertexNumber() const { return startVertexNumber; }
    QString getEndVertexNumber() const { return endVertexNumber; }

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

        // 计算箭头方向
        QPointF direction = endPos - startPos;
        qreal length = qSqrt(direction.x() * direction.x() + direction.y() * direction.y());

        // 如果长度为零，则不绘制
        if (length == 0) {
            line->setPath(QPainterPath());
            return;
        }

        // 归一化方向向量
        direction /= length;

        // 考虑顶点半径，避免箭头与顶点重叠
        qreal vertexRadius = 20.0;
        QPointF adjustedStart = startPos + direction * vertexRadius;
        QPointF adjustedEnd = endPos - direction * vertexRadius;

        // 创建路径
        QPainterPath path;

        if (hasArrow) {
            // 绘制带箭头的边

            // 更新长度
            length = qSqrt(direction.x() * direction.x() + direction.y() * direction.y());

            // 箭头参数
            qreal arrowSize = 15.0;
            qreal arrowAngle = M_PI / 6; // 箭头角度（30度）

            // 绘制主线
            path.moveTo(adjustedStart);
            path.lineTo(adjustedEnd);

            // 计算箭头尖端位置
            QPointF arrowTip = adjustedEnd;

            // 计算箭头两侧点
            QPointF perpendicular(-direction.y(), direction.x()); // 垂直方向

            QPointF arrowPoint1 = arrowTip - direction * arrowSize + perpendicular * arrowSize * qTan(arrowAngle);
            QPointF arrowPoint2 = arrowTip - direction * arrowSize - perpendicular * arrowSize * qTan(arrowAngle);

            // 绘制箭头
            path.moveTo(arrowTip);
            path.lineTo(arrowPoint1);
            path.moveTo(arrowTip);
            path.lineTo(arrowPoint2);
        } else {
            // 绘制普通直线
            path.moveTo(adjustedStart);
            path.lineTo(adjustedEnd);
        }

        line->setPath(path);
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
    bool hasArrow; // 是否显示箭头
    QGraphicsPathItem* line;
    QGraphicsTextItem* weightText;

    // 用于反序列化
    QString startVertexNumber;
    QString endVertexNumber;
};





// 在类定义后添加序列化操作符的实现
// 在 Edge.h 中
inline QDataStream &operator<<(QDataStream &out, const Edge &edge) {
    if (edge.startVertex && edge.endVertex) {
        qDebug() << "序列化边:" << edge.startVertex->getNumber() << "->" << edge.endVertex->getNumber() << "权重:" << edge.weight;
        out << edge.startVertex->getNumber();
        out << edge.endVertex->getNumber();
        out << edge.weight;
        out << edge.hasArrow;
        qDebug() << "序列化边完成，数据流状态:" << out.status();
    } else {
        qDebug() << "序列化边失败: 顶点指针为空";
    }
    return out;
}

inline QDataStream &operator>>(QDataStream &in, Edge &edge) {
    in >> edge.startVertexNumber;
    in >> edge.endVertexNumber;
    in >> edge.weight;
    in >> edge.hasArrow;
    qDebug() << "反序列化边:" << edge.startVertexNumber << "->" << edge.endVertexNumber << "权重:" << edge.weight;
    qDebug() << "反序列化边完成，数据流状态:" << in.status();

    // 创建图形项（顶点指针稍后设置）
    edge.line = new QGraphicsPathItem(&edge);
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::black);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    edge.line->setPen(pen);

    edge.weightText = new QGraphicsTextItem(QString::number(edge.weight), &edge);
    QFont font = edge.weightText->font();
    font.setPointSize(20);
    font.setBold(true);
    edge.weightText->setFont(font);
    edge.weightText->setDefaultTextColor(Qt::darkRed);

    edge.setZValue(-1);

    return in;
}


#endif //EDGE_H
