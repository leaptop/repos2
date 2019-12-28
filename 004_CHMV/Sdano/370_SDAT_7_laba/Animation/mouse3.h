#ifndef MOUSE3_H
#define MOUSE3_H
#include <QGraphicsItem>

class mouse3 : public QGraphicsItem
{
public:
    mouse3();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

protected:
    void advance(int step) override;

private:
    qreal angle;
    qreal speed;
    qreal mouseEyeDirection;
    QColor color;
    void DoCollision();

};

#endif // MOUSE3_H
