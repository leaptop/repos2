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
    QApplication       app(argc, argv);
    QStandardItemModel model(5, 3);

    for (int nTopRow = 0; nTopRow < 5; ++nTopRow) {
        QModelIndex index = model.index(nTopRow, 0);
        model.setData(index, "item" + QString::number(nTopRow + 1));

        model.insertRows(0, 4, index);
        model.insertColumns(0, 3, index);
        for (int nRow = 0; nRow < 4; ++nRow) {
            for (int nCol = 0; nCol < 3; ++nCol) {
                QString strPos = QString("%1,%2").arg(nRow).arg(nCol);
                model.setData(model.index(nRow, nCol, index), strPos);
            }
        }
    }

    QTreeView treeView;
    treeView.setModel(&model);
    treeView.show();

    return app.exec();
}

