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
QWidget* styledWidget(QStyle* pstyle)
{
    QGroupBox*    pgr  = new QGroupBox(pstyle->metaObject()->className());
    QScrollBar*   psbr = new QScrollBar(Qt::Horizontal);
    QCheckBox*    pchk = new QCheckBox("&Check Box");
    QSlider*      psld = new QSlider(Qt::Horizontal);
    QRadioButton* prad = new QRadioButton("&Radio Button");
    QPushButton*  pcmd = new QPushButton("&Push Button");

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;    
    pvbxLayout->addWidget(psbr);
    pvbxLayout->addWidget(pchk);
    pvbxLayout->addWidget(psld);
    pvbxLayout->addWidget(prad);
    pvbxLayout->addWidget(pcmd);
    pgr->setLayout(pvbxLayout);

    QList<QWidget*> pwgtList = pgr->findChildren<QWidget*>();
    foreach(QWidget* pwgt, pwgtList) {
        pwgt->setStyle(pstyle);
    }
    return pgr;
}

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);  
    QWidget      wgt;

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;    
    foreach (QString str, QStyleFactory::keys()) {
        phbxLayout->addWidget(styledWidget(QStyleFactory::create(str)));
    }
    wgt.setLayout(phbxLayout);

    wgt.show();

    return app.exec();
}
