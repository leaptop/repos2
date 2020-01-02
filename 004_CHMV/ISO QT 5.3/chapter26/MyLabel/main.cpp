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

// ======================================================================
class MyLabel : public QLabel {
public:
    MyLabel(QWidget* pwgt = 0) : QLabel(pwgt)
    {
    }

    virtual void paintEvent(QPaintEvent*)
    {
        QStylePainter      painter(this);
        QStyleOptionButton option;

        option.initFrom(this);
        option.text = "This is a label";

        painter.drawControl(QStyle::CE_PushButton, option);
    }
};

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication  app(argc, argv);  
    MyLabel       lbl;

    lbl.resize(100, 50);
    lbl.show();

    return app.exec();
}
