// ======================================================================
//  Drag.h
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
class Drag : public QLabel {
Q_OBJECT
private:
    QPoint m_ptDragPos;

    void startDrag()
    {
        QMimeData* pMimeData = new QMimeData;
        pMimeData->setText(text());

        QDrag* pDrag = new QDrag(this);
        pDrag->setMimeData(pMimeData);
        pDrag->setPixmap(QPixmap(":/img1.png"));
        pDrag->exec(Qt::MoveAction);
    }

protected:
    virtual void mousePressEvent(QMouseEvent* pe)
    {
        if (pe->button() == Qt::LeftButton) {
            m_ptDragPos = pe->pos();
        }
        QWidget::mousePressEvent(pe);
    }

    virtual void mouseMoveEvent (QMouseEvent* pe)
    {
        if (pe->buttons() & Qt::LeftButton) {
            int distance = (pe->pos() - m_ptDragPos).manhattanLength();
            if (distance > QApplication::startDragDistance()) {
                startDrag();
            }
        }
        QWidget::mouseMoveEvent(pe);
    }

public:
    Drag(QWidget* pwgt = 0) : QLabel("This is draggable text", pwgt)
    {
    }
};
