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
        QPainter painter(this);
        QRect    r = rect();
        painter.setFont(QFont("Times", 50, QFont::Normal));
        painter.drawRect(r); 
        painter.drawText(r, Qt::AlignCenter | Qt::TextWordWrap, "Draw Text");
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

    dtw.resize(200, 150);
    dtw.show();

    return app.exec();
}
