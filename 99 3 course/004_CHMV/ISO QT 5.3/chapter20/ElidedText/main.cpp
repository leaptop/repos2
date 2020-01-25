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
class ElidedText : public QWidget {
protected:
    virtual void paintEvent(QPaintEvent*)
    {
        QString  str = "This is a long text. Please, resize the window";
        QString  strElided = 
            fontMetrics().elidedText(str, Qt::ElideMiddle, width());
        QPainter painter(this);
        painter.drawText(rect(), strElided);
    }

public:
    ElidedText(QWidget* pwgt = 0) : QWidget(pwgt)
    {
    }    
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ElidedText   et;
    et.resize(200, 20);
    et.show();

    return app.exec();
}
