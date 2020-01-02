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
class PainterPathWidget : public QWidget {
protected:
    virtual void paintEvent(QPaintEvent*)
    {
        QPainterPath path;
        QPointF      pt1(width(), height() / 2);
        QPointF      pt2(width() / 2, -height());
        QPointF      pt3(width() / 2, 2 * height());
        QPointF      pt4(0, height() / 2);
        path.moveTo(pt1);
        path.cubicTo(pt2, pt3, pt4);

        QRect rect(width() / 4, height() / 4, width() / 2, height() / 2);
        path.addRect(rect);
        path.addEllipse(rect);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(QPen(Qt::blue, 6));
        painter.drawPath(path);    
    }

public:
    PainterPathWidget(QWidget* pwgt = 0) : QWidget(pwgt)
    {
    }
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    PainterPathWidget wgt;

    wgt.resize(200, 200);
    wgt.show();

    return app.exec();
}
