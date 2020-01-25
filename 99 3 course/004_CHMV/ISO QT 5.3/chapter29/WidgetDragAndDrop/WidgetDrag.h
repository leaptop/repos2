// ======================================================================
//  WidgetDrag.h
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

#include <QDrag>

// ======================================================================
class WidgetMimeData : public QMimeData {
private:
    QWidget* m_pwgt;

public:
    WidgetMimeData() : QMimeData()
    {
    }

    virtual ~WidgetMimeData()
    {
    }

    static QString mimeType()
    {
        return "application/widget";
    }    

    void setWidget(QWidget* pwgt)
    {
        m_pwgt = pwgt;
        setData(mimeType(), QByteArray());
    }

    QWidget* widget() const
    {
        return m_pwgt;
    }
};

// ======================================================================
class WidgetDrag : public QDrag {
public:
    WidgetDrag(QWidget* pwgtDragSource = 0) : QDrag(pwgtDragSource)
    {
    }

    void setWidget(QWidget* pwgt)
    {
         WidgetMimeData* pmd = new WidgetMimeData;
         pmd->setWidget(pwgt);
         setMimeData(pmd);
    }
};

