#include "myitem.h"

MyItem::MyItem()
{
    //random start rotation
    angle = (qrand() % 360);//задаём случайное число от 0 до 360 для угла
    setRotation(angle);//типа вращает как-то

    //устанавливаем скорость
    speed = 5;//5 пикселей за раз


    int StartX = 0;
    int StartY = 0;
//устанавливаем произвольное положение
    if((qrand()%1))
    {
        StartX = (qrand()% 200);//хватаем произвольную позицию от 0 до 200
        StartY = (qrand() % 200);
    }
    else
    {
        StartX = (qrand( )% -100);//хватаем произвольную позицию от 0 до 200
        StartY = (qrand() % -100);
    }

    setPos(mapToParent(StartX, StartY));

}
//эта штука ограничивает наш объект
QRectF MyItem::boundingRect() const
{
    return QRect(0,0,20,20);//20pixels tall
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();//хватаем boundingRect
    QBrush Brush(Qt::gray);

    //простая проверка столкновений
    if(scene()->collidingItems(this).isEmpty()){//scene говорит нам есть ли коллизия

        //столкновения нет
        Brush.setColor(Qt::green);
    }
    else
    {
        //есть столкновение
        Brush.setColor(Qt::red);

        //устанавливаем новое расположение
        DoCollision();
    }

    painter->fillRect(rec, Brush);
    painter->drawRect(rec);
}

void MyItem::advance(int phase)//в общем адванс - встроенная функция в какую-то из этих библиотек
{
    if(!phase)return;//it may call an advanc function and there is no phase, meaning, it's not doing it, it's just calling it

    QPointF location = this->pos();//хотим понять точку, где этот объект находится
//второй аргумент mapToParent говорит объекту двигаться по игреку(в нашем случае на 5 вниз), но у нас есть еще углы
    //поэтому он также и в стороны двигается
    setPos(mapToParent(0,-(speed)));// передает координаты map в scene; устанавливаем позицию и маппируем её в xyz коорд.систему

}

void MyItem::DoCollision()
{
    //Get a new Position

    //Change the angle with a little randomness
    if(((qrand()%1)))
    {
        setRotation(rotation() + (180 + (qrand() % 10)));//если во что-то ударяемся, то вращаем в противоположную сторону
                    //и добавляем к углу  10
    }
    else
    {
        setRotation(rotation() + (180 + (qrand() % -10)));
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
