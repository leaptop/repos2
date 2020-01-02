// ======================================================================
//  IntListModel.h
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

#include <QAbstractListModel>

// ======================================================================
class IntListModel : public QAbstractListModel {
Q_OBJECT
private:
    QList<int> m_list;

public:
    IntListModel(const QList<int>& list, QObject* pobj = 0); 

    QVariant data(const QModelIndex& index, int nRole) const;

    bool setData(const QModelIndex& index, 
                 const QVariant&    value, 
                 int                nRole
                );

    int rowCount(const QModelIndex& parent = QModelIndex()) const;

    QVariant headerData(int             nSection, 
                        Qt::Orientation orientation, 
                        int             nRole = Qt::DisplayRole
                       ) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
};
