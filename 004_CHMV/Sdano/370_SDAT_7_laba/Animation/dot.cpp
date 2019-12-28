#include "dot.h"

Dot::Dot()
{
    setPos(mapToParent(160, 55));

}
void Dot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPoint *qpp = new QPoint(50, 50);
    painter->setBrush(QBrush(Qt::red, Qt::SolidPattern));
  painter->drawEllipse(300,300,50,50);
  //painter->setBackground()

}

QRectF Dot::boundingRect() const
{

}
