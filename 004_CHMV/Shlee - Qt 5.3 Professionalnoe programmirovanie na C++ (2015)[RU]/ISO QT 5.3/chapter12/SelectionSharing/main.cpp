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
    QWidget      wgt;

    QStringListModel model;
    model.setStringList(QStringList() << "Item1" << "Item2" << "Item3");

    QTreeView* pTreeView = new QTreeView;
    pTreeView->setModel(&model);

    QListView* pListView = new QListView;
    pListView->setModel(&model);

    QTableView* pTableView = new QTableView;
    pTableView->setModel(&model);

    QItemSelectionModel selection(&model);
    pTreeView->setSelectionModel(&selection);
    pListView->setSelectionModel(&selection);
    pTableView->setSelectionModel(&selection);

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(pTreeView);
    phbxLayout->addWidget(pListView);
    phbxLayout->addWidget(pTableView);
    wgt.setLayout(phbxLayout);

    wgt.show();

    return app.exec();
}

