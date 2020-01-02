// ======================================================================
//  ImageDraw.cpp
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

#include <QtGui>
#include "ImageDraw.h"

// ----------------------------------------------------------------------
ImageDraw::ImageDraw(QWidget* pwgt/*=0*/) : QWidget(pwgt) 
{
}

// ----------------------------------------------------------------------
/*virtual*/ImageDraw::~ImageDraw()
{
}

// ----------------------------------------------------------------------
/*virtual*/ void ImageDraw::paintEvent(QPaintEvent*) 
{
    QImage   img(size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter;

    painter.begin(&img);
    painter.initFrom(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.eraseRect(rect());
    painter.drawEllipse(0, 0, size().width(), size().height());
    painter.end();

    painter.begin(this);
    painter.drawImage(0, 0, img);
    painter.end();
}
