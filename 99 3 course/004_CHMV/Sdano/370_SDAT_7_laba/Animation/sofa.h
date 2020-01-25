#ifndef SOFA_H
#define SOFA_H

#include<QPainter>
#include<QGraphicsItem>
#include <QGraphicsScene>
class sofa : public QGraphicsItem
{
public:
    sofa();

    // QGraphicsItem interface
public:
    void advance(int phase);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    bool collidesWithPath(const QPainterPath &path, Qt::ItemSelectionMode mode) const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath *qpp;
    QRectF *sofo;


protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SOFA_H
