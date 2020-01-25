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
class Window : public QLabel {
private:
    QPoint  m_ptPosition;

protected:
    virtual void mousePressEvent(QMouseEvent* pe)
    {
        m_ptPosition = pe->pos();
    }

    virtual void mouseMoveEvent(QMouseEvent* pe)
    {
        move(pe->globalPos() - m_ptPosition);
    }

public:
    Window(QWidget* pwgt = 0) 
        : QLabel(pwgt,  Qt::FramelessWindowHint | Qt::Window) 
    {
    }
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Window       win;
    QPixmap      pix(":/images/unixoids.png");

    win.setPixmap(pix);
    win.setMask(pix.mask());
    win.show();

    return app.exec();
}
