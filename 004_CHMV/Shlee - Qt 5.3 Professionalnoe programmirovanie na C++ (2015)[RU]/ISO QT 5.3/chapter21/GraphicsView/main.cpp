// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.3 Professional programming with C++"
// ======================================================================
//  Copyright (c) 2014 by Max Schlee
//
//  Email : Max.Schlee@neonway.com
//  Blog  : http://www.maxschlee.com
//
//  Social Networks
//  ---------------
//  FaceBook : http://www.facebook.com/mschlee
//  Twitter  : http://twitter.com/Max_Schlee
//  2Look.me : http://2look.me/NW100003
//  Xing     : http://www.xing.com/profile/Max_Schlee
//  vk.com   : https://vk.com/max.schlee
// ======================================================================

#include <QtWidgets>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication   app(argc, argv);
    QGraphicsScene scene(QRectF(-100, -100, 300, 300));
    QGraphicsView  view(&scene);

    QGraphicsRectItem* pRectItem = 
        scene.addRect(QRectF(-30, -30, 120, 80), 
                      QPen(Qt::black), 
                      QBrush(Qt::green)
                     );
    pRectItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsPixmapItem* pPixmapItem = 
        scene.addPixmap(QPixmap(":/haus.jpg"));
    pPixmapItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsTextItem* pTextItem = 
        scene.addText("Move us with your mouse");
    pTextItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsLineItem* pLineItem = 
        scene.addLine(QLineF(-10, -10, -80, -80), QPen(Qt::red, 2));
    pLineItem->setFlags(QGraphicsItem::ItemIsMovable);

    view.show();
  
    return app.exec();
} 
