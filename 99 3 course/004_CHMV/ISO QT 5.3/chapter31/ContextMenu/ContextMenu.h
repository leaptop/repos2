// ======================================================================
//  ContextMenu.h
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

#include <QtWidgets>

// ======================================================================
class ContextMenu : public QTextEdit {
Q_OBJECT
private:
    QMenu* m_pmnu;

protected:
    virtual void contextMenuEvent(QContextMenuEvent* pe)
    {
        m_pmnu->exec(pe->globalPos());
    }

public:
    ContextMenu(QWidget* pwgt = 0)
       : QTextEdit(pwgt) 
    {
        setReadOnly(true);
        m_pmnu = new QMenu(this);
        m_pmnu->addAction("&Red");
        m_pmnu->addAction("&Green");
        m_pmnu->addAction("&Blue");
        connect(m_pmnu, 
                SIGNAL(triggered(QAction*)), 
                SLOT(slotActivated(QAction*))
               );
    }

public slots:
    void slotActivated(QAction* pAction)
    {
        QString strColor = pAction->text().remove("&");
        
        setHtml(QString("<BODY BGCOLOR=%1></BODY>").arg(strColor));
    }
};

