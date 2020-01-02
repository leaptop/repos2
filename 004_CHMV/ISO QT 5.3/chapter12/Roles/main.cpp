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
int main(int argc, char** argv) 
{
    QApplication app(argc, argv);
    QStringList  lst;
    lst << "Linux" << "Windows" << "MacOSX" << "Android";

    QStandardItemModel model(lst.size(), 1);
    for (int i = 0; i < model.rowCount(); ++i) {
        QModelIndex index = model.index(i, 0);
        QString     str   = lst.at(i);
        model.setData(index, str, Qt::DisplayRole);
        model.setData(index, "ToolTip for " + str, Qt::ToolTipRole);
        model.setData(index, QIcon(":/" + str + ".jpg"), Qt::DecorationRole);
    }

    QListView listView;
    listView.setViewMode(QListView::IconMode);
    listView.setModel(&model);
    listView.show();

    return app.exec();
}
