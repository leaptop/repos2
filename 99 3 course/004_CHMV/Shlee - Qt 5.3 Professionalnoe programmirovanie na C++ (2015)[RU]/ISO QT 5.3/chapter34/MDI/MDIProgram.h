// ======================================================================
//  MDIProgram.h
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

#include <QMainWindow>

class QMenu;
class QMdiArea;
class QSignalMapper;
class DocWindow;

// ======================================================================
class MDIProgram : public QMainWindow {
    Q_OBJECT
private:
    QMdiArea*      m_pma;
    QMenu*         m_pmnuWindows;
    QSignalMapper* m_psigMapper;

    DocWindow* createNewDoc();

public:
    MDIProgram(QWidget* pwgt = 0);

private slots:
    void slotChangeWindowTitle(const QString&);

private slots:
    void slotNewDoc            (        );
    void slotLoad              (        );
    void slotSave              (        );
    void slotSaveAs            (        );
    void slotAbout             (        );
    void slotWindows           (        );
    void slotSetActiveSubWindow(QWidget*);
};
