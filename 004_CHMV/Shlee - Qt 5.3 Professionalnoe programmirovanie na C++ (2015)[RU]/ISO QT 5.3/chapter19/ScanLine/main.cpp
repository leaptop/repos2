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
QImage brightness(const QImage& imgOrig, int n)
{
    QImage imgTemp = imgOrig;
    qint32 nHeight = imgTemp.height();
    qint32 nWidth  = imgTemp.width();

    for (qint32 y = 0; y < nHeight; ++y) {
        QRgb* tempLine = reinterpret_cast<QRgb*>(imgTemp.scanLine(y));

        for (qint32 x = 0; x < nWidth; ++x) {
             int r = qRed(*tempLine) + n;
             int g = qGreen(*tempLine) + n;
             int b = qBlue(*tempLine) + n;
             int a = qAlpha(*tempLine);

             *tempLine++ = qRgba(r > 255 ? 255 : r < 0 ? 0 : r, 
                                 g > 255 ? 255 : g < 0 ? 0 : g, 
                                 b > 255 ? 255 : b < 0 ? 0 : b, 
                                 a
                                );
        }
    }
    
    return imgTemp;
}

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QImage       img(":/happyos.png");
    QWidget      wgt;

    QHBoxLayout* phbx = new QHBoxLayout;
    phbx->setMargin(0);
    phbx->setSpacing(0);

    for (int i = -150; i < 150; i += 50) {
        QLabel* plbl = new QLabel;          
        plbl->setFixedSize(img.size());
        plbl->setPixmap(QPixmap::fromImage(brightness(img, i)));
        phbx->addWidget(plbl);
    }

    wgt.setLayout(phbx);
    wgt.show();

    return app.exec();
}
