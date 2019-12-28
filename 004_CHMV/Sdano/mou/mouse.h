#ifndef MOUSE_H
#define MOUSE_H

#include <QGraphicsItem>

//! [0]
class Mouse : public QGraphicsItem
{
public:
    Mouse();

    QRectF boundingRect() const override;//does something with numbers. Returns QRectF. Bounding means surrounding apparently
    QPainterPath shape() const override;//QPainterPath creates something like a container for shapes
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,//For performance reasons, the access to the member variables is direct (i.e., using the . or -> operator). This low-level feel makes the structures straightforward to use and emphasizes that these are simply parameters.
               //For an example demonstrating how style options can be used, see the Styles example.
               QWidget *widget) override;

protected:
    void advance(int step) override;

private:
    qreal angle;
    qreal speed;
    qreal mouseEyeDirection;
    QColor color;
};
//! [0]

#endif
