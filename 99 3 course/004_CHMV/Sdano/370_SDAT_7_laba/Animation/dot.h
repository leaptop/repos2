#ifndef DOT_H
#define DOT_H

#include <QGraphicsItem>
#include<QPainter>


class Dot : public QGraphicsItem
{
public:
    Dot();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ) ;
    QRectF boundingRect() const;

private:
    qreal angle;
    qreal speed;
};

#endif // DOT_H
