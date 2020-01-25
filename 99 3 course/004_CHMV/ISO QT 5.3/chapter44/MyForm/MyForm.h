// ======================================================================
//  MyForm.h
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

#pragma once

#include "ui_MyForm.h"

// ======================================================================
class MyForm : public QWidget, public Ui::MyForm {
    Q_OBJECT

public:
    MyForm(QWidget* pwgt = 0) : QWidget(pwgt)
    {
        setupUi(this);

        connect(m_cmdReset, SIGNAL(clicked()), SLOT(slotReset()));
    }

public slots:
    void slotReset()
    {
        m_sld->setValue(0);
        m_lcd->display(0);
    }
};

