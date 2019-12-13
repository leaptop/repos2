#ifndef MYSQUARE_H
#define MYSQUARE_H
#include<QPainter>
#include <QGraphicsItem>
#include<QDebug>

class MySquare : public QGraphicsItem    //inheriting from QGraphicsItem
{
public:
    MySquare();

    QRectF boundingRect() const;//the bounding rectangle is the outermost edges of the object
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
    bool Pressed;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) ;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) ;

};

#endif // MYSQUARE_H
