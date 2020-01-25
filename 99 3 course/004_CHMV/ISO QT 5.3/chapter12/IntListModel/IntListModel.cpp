// ======================================================================
//  IntListModel.cpp
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
#include "IntListModel.h"

// ----------------------------------------------------------------------
IntListModel::IntListModel(const QList<int>& list, QObject* pobj/*=0*/) 
        : QAbstractListModel(pobj)
        , m_list(list) 
{
}

// ----------------------------------------------------------------------
QVariant IntListModel::data(const QModelIndex& index, int nRole) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    return (nRole == Qt::DisplayRole || nRole == Qt::EditRole) 
           ? m_list.at(index.row()) 
           : QVariant();
}

// ----------------------------------------------------------------------
bool IntListModel::setData(const QModelIndex& index, 
                           const QVariant&    value, 
                           int                nRole
                          )
{
    if (index.isValid() && nRole == Qt::EditRole) {
        m_list.replace(index.row(), value.value<int>());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

// ----------------------------------------------------------------------
int IntListModel::rowCount(const QModelIndex& parent/*=QModelIndex()*/
                          ) const
{
    Q_UNUSED(parent);
    return m_list.size();
}

// ----------------------------------------------------------------------
QVariant IntListModel::headerData(int             nSection, 
                                  Qt::Orientation orientation, 
                                  int             nRole/*=DisplayRole*/
                                 ) const
{
    if (nRole != Qt::DisplayRole) {
        return QVariant();
    }
    return (orientation == Qt::Horizontal) ? QString("Number") 
                                           : QString::number(nSection);
}

// ----------------------------------------------------------------------
Qt::ItemFlags IntListModel::flags(const QModelIndex& index) const
{
    Qt::ItemFlags flags = QAbstractListModel::flags(index);
    return index.isValid() ? (flags | Qt::ItemIsEditable)
                           : flags;
}
