#include "sofa.h"

sofa::sofa()
{
    int StartX = 300;
   int  StartY = 300;

   setPos(mapToParent(StartX, StartY));
}


void sofa::advance(int phase)
{
}

QRectF sofa::boundingRect() const
{ return QRect(0,0,100,50);//20pixels tall
}

QPainterPath sofa::shape() const
{
     QPainterPath *qpp = new QPainterPath();


}

bool sofa::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
}

bool sofa::collidesWithPath(const QPainterPath &path, Qt::ItemSelectionMode mode) const
{
}

void sofa::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF sofo = boundingRect();
    QBrush Brush(Qt::gray);
    painter->fillRect(sofo, Brush);
    painter->drawRect(sofo);
}

void sofa::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
}

void sofa::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
}

void sofa::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
}

void sofa::dropEvent(QGraphicsSceneDragDropEvent *event)
{
}

void sofa::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
}

void sofa::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}

void sofa::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}
