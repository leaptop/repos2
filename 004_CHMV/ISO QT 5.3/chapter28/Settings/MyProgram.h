// ======================================================================
//  MyProgram.h --
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
#include <QSettings>

class QComboBox;
class QCheckBox;
class QTextEdit;
class QLabel;
 
// ======================================================================
class MyProgram : public QWidget {
Q_OBJECT

private:
    QSettings  m_settings;
    QComboBox* m_pcbo;
    QCheckBox* m_pchk;
    QTextEdit* m_ptxt;
    QLabel*    m_plbl;
    int        m_nCounter;

public:
    MyProgram(QWidget* pwgt = 0);
    virtual ~MyProgram();

    void writeSettings();
    void readSettings ();

public slots:
    void slotCheckBoxClicked  (   );
    void slotComboBoxActivated(int);
};
