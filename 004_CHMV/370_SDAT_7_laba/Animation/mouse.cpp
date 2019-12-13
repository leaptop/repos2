#include "mouse.h"
#include "myitem.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>
#include <qmath.h>

const qreal Pi = M_PI;
const qreal TwoPi = 2 * M_PI;

static qreal normalizeAngle(qreal angle)//adjusts the angle variable between 0 and TwoPi
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

//! [0]
Mouse::Mouse(int ii)//constructor?
    : angle(0), speed(0), mouseEyeDirection(0),//adjusting the variables in the mouse.h
      //the next thingie, declared in the mouse.h creates a random color like r g b a, where a is the alpha-channel (transparency).
      color(QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256))
{ //random start rotation
    angle = (qrand() % 360);//задаём случайное число от 0 до 360 для угла
    setRotation(angle);//типа вращает как-то

    //устанавливаем скорость
    speed = 5;//5 пикселей за раз


    int StartX =500 ;
    int StartY =500 ;
//устанавливаем произвольное положение
    if((qrand()%1))
    {
        StartX = (qrand()% 20);//хватаем произвольную позицию от 0 до 200
        StartY = (qrand() % 20);
    }
    else
    {
        StartX = (qrand()% -10);//хватаем произвольную позицию от 0 до 200
        StartY = (qrand() % -10);
    }

   // setPos(mapToParent(StartX, StartY));
    setPos(mapToParent(300+ii*30, 200+ii*30));

   // setRotation(QRandomGenerator::global()->bounded(360 * 16));
}
//! [0]

//! [1]
QRectF Mouse::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}
//! [1]

//! [2]
QPainterPath Mouse::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}
//! [2]

//! [3]
void Mouse::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body
    painter->setBrush(color);
    painter->drawEllipse(-10, -20, 20, 40);

    // Eyes
    painter->setBrush(Qt::white);
    painter->drawEllipse(-10, -17, 8, 8);
    painter->drawEllipse(2, -17, 8, 8);

    // Nose
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(-2, -22, 4, 4));

    // Pupils
    painter->drawEllipse(QRectF(-8.0 + mouseEyeDirection, -17, 4, 4));
    painter->drawEllipse(QRectF(4.0 + mouseEyeDirection, -17, 4, 4));

    // Ears
    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
    painter->drawEllipse(-17, -12, 16, 16);
    painter->drawEllipse(1, -12, 16, 16);

    // Tail
    QPainterPath path(QPointF(0, 20));
    path.cubicTo(-5, 22, -5, 22, 0, 25);
    path.cubicTo(5, 27, 5, 32, 0, 30);
    path.cubicTo(-5, 32, -5, 42, 0, 35);
    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path);


    QRectF rec = boundingRect();//хватаем boundingRect
    QBrush Brush(Qt::gray);

    //простая проверка столкновений
    if(scene()->collidingItems(this).isEmpty()){//scene говорит нам есть ли коллизия

        //столкновения нет
      //  Brush.setColor(Qt::green);
    }
    else
    {
        //есть столкновение
        //Brush.setColor(Qt::red);

        //устанавливаем новое расположение
        DoCollision();
    }

    //painter->fillRect(rec, Brush);//эта штука заполняет boundingRect Brush-ем
    //painter->drawRect(rec);//эта штука рисует контур boundingRect-а

}
//! [3]

//! [4]
void Mouse::advance(int step)
{
    if (!step)
        return;
//! [4]
    // Don't move too far away
//! [5]
    QLineF lineToCenter(QPointF(0, 0), mapFromScene(0, 0));
    if (lineToCenter.length() > 150) {
        qreal angleToCenter = std::atan2(lineToCenter.dy(), lineToCenter.dx());
        angleToCenter = normalizeAngle((Pi - angleToCenter) + Pi / 2);

        if (angleToCenter < Pi && angleToCenter > Pi / 4) {
            // Rotate left
            angle += (angle < -Pi / 2) ? 0.25 : -0.25;
        } else if (angleToCenter >= Pi && angleToCenter < (Pi + Pi / 2 + Pi / 4)) {
            // Rotate right
            angle += (angle < Pi / 2) ? 0.25 : -0.25;
        }
    } else if (::sin(angle) < 0) {
        angle += 0.25;
    } else if (::sin(angle) > 0) {
        angle -= 0.25;
//! [5] //! [6]
    }
//! [6]

    // Try not to crash with any other mice
//! [7]
    const QList<QGraphicsItem *> dangerMice = scene()->items(QPolygonF()
                           << mapToScene(0, 0)
                           << mapToScene(-30, -50)
                           << mapToScene(30, -50));

    for (const QGraphicsItem *item : dangerMice) {
        if (item == this)
            continue;

        QLineF lineToMouse(QPointF(0, 0), mapFromItem(item, 0, 0));
        qreal angleToMouse = std::atan2(lineToMouse.dy(), lineToMouse.dx());
        angleToMouse = normalizeAngle((Pi - angleToMouse) + Pi / 2);

        if (angleToMouse >= 0 && angleToMouse < Pi / 2) {
            // Rotate right
            angle += 0.5;
        } else if (angleToMouse <= TwoPi && angleToMouse > (TwoPi - Pi / 2)) {
            // Rotate left
            angle -= 0.5;
//! [7] //! [8]
        }
//! [8] //! [9]
    }
//! [9]

    // Add some random movement
//! [10]
    if (dangerMice.size() > 1 && QRandomGenerator::global()->bounded(10) == 0) {
        if (QRandomGenerator::global()->bounded(1))
            angle += QRandomGenerator::global()->bounded(1 / 500.0);
        else
            angle -= QRandomGenerator::global()->bounded(1 / 500.0);
    }
//! [10]

//! [11]
    speed += (-50 + QRandomGenerator::global()->bounded(100)) / 100.0;

    qreal dx = ::sin(angle) * 10;
    mouseEyeDirection = (qAbs(dx / 5) < 1) ? 0 : dx / 5;

    setRotation(rotation() + dx);
    setPos(mapToParent(0, -(3 + sin(speed) * 3)));
}

void Mouse::DoCollision()
{
    //Get a new Position

    //Change the angle with a little randomness
    if(((qrand()%1)))
    {
        setRotation(rotation() + (18 + (qrand() % 10)));//если во что-то ударяемся, то вращаем в противоположную сторону
                    //и добавляем к углу  10
    }
    else
    {
        setRotation(rotation() + (18 + (qrand() % -10)));
    }

    //see if the new position is in bounds
    //проверяем является ли это boundingRectangle-ом
    //проверяем куда же оно движется. +2 надо, чтобы оттолкнуть от объекта, с которым сейчас сталкивается
    QPointF newpoint = mapToParent(-(boundingRect().width()), -(boundingRect().width() +2));

    if(!scene()->sceneRect().contains((newpoint)))//если sceneRect не содержит newpoint , то нам надо что-то сделать
         //типа взяли пробу newpoint выше, проверили, содержится ли она на сцене
    {
        //Move it back in bounds
        newpoint = mapToParent(0,0);
    }
    else
    {
       //set the new position
        setPos(newpoint);

    }
}
//! [11]
