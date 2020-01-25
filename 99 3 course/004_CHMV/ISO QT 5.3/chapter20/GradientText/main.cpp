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
class DrawTextWidget : public QWidget {
protected:
    virtual void paintEvent(QPaintEvent*)
    {
        QLinearGradient gradient(0, 0, 500, 0);
        gradient.setColorAt(0, Qt::red);
        gradient.setColorAt(0.5, Qt::green);
        gradient.setColorAt(1, Qt::blue);

        QPainter painter(this);
        painter.setPen(QPen(gradient, 0));
        painter.setFont(QFont("Times", 50, QFont::Normal));
        painter.drawText(60, 60, "Gradient Text");
    }

public:
    DrawTextWidget(QWidget* pwgt = 0) : QWidget(pwgt)
    {
    }
};


// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    DrawTextWidget dtw;

    dtw.resize(500, 80);
    dtw.show();

    return app.exec();
}
