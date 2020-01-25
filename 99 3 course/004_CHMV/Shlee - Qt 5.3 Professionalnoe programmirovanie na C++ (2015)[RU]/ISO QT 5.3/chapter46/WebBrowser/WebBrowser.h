// ======================================================================
//  WebBrowser.h - 
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

#include <QWidget>

class QLineEdit;
class QWebView;
class QPushButton;

// =============================================================
class WebBrowser : public QWidget{
Q_OBJECT
private:
    QLineEdit*    m_ptxt;
    QWebView*     m_pwv;
    QPushButton*  m_pcmdBack;
    QPushButton*  m_pcmdForward;

public:
    WebBrowser(QWidget* wgt = 0);

private slots:
    void slotGo      (    );
    void slotFinished(bool);
};


