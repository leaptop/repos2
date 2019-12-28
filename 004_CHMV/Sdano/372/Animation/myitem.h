#ifndef MYITEM_H
#define MYITEM_H

#include<QPainter>
#include<QGraphicsItem>
#include <QGraphicsScene>

class MyItem : public QGraphicsItem//наследуем от QGraphicsItem
{
public:
    MyItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);// здесь есть одно удобство: жмёшь правой по методу -> рефакторринг -> добавить реализацию
    //в myitem.cpp
private:
    qreal angle;
    qreal speed;
    void DoCollision();
};

#endif // MYITEM_H
