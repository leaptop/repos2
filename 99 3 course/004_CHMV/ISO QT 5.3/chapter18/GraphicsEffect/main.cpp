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
QLabel* lbl(QGraphicsEffect* pge)
{
    QLabel* plbl = new QLabel;
    plbl->setPixmap(QPixmap(":/happyos.png"));

    if (pge) {
        plbl->setGraphicsEffect(pge);
    }
    return plbl;
}

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication               app(argc, argv);
    QWidget                    wgt;
    QGraphicsBlurEffect*       pBlur     = new QGraphicsBlurEffect;
    QGraphicsDropShadowEffect* pShadow   = new QGraphicsDropShadowEffect;
    QGraphicsColorizeEffect*   pColorize = new QGraphicsColorizeEffect;

    //Layout Setup
    QFormLayout* pform = new QFormLayout;
    pform->addRow("No Effects", lbl(0));
    pform->addRow("Blur", lbl(pBlur));
    pform->addRow("Drop Shadow", lbl(pShadow));
    pform->addRow("Colorize", lbl(pColorize));
    wgt.setLayout(pform);
  
    wgt.show();

    return app.exec();
}
