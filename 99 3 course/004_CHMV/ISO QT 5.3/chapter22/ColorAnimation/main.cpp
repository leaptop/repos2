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
    QApplication app(argc, argv);
    QLabel       lbl;  

    lbl.setPixmap(QPixmap(":/happyos.png"));
    
    QGraphicsColorizeEffect effect;
    lbl.setGraphicsEffect(&effect);

    QPropertyAnimation anim(&effect, "color");
    anim.setStartValue(QColor(Qt::gray));
    anim.setKeyValueAt(0.25f, QColor(Qt::green));
    anim.setKeyValueAt(0.5f, QColor(Qt::blue));
    anim.setKeyValueAt(0.75f, QColor(Qt::red));
    anim.setEndValue(QColor(Qt::black));
    anim.setDuration(3000);
    anim.setLoopCount(-1);
    anim.start();

    lbl.show();

    return app.exec();
}

