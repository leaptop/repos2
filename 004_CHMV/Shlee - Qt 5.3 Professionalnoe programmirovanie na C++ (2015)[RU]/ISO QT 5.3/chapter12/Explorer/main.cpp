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
    QApplication     app(argc, argv);
    QSplitter        spl(Qt::Horizontal);
    QFileSystemModel model;

    model.setRootPath(QDir::rootPath());

    QTreeView* pTreeView = new QTreeView;
    pTreeView->setModel(&model);

    QTableView* pTableView = new QTableView;
    pTableView->setModel(&model);

    QObject::connect(pTreeView,  SIGNAL(clicked(const QModelIndex&)), 
                     pTableView, SLOT(setRootIndex(const QModelIndex&))
                    );
    QObject::connect(pTableView, SIGNAL(activated(const QModelIndex&)), 
                     pTreeView, SLOT(setCurrentIndex(const QModelIndex&))
                    );
    QObject::connect(pTableView, SIGNAL(activated(const QModelIndex&)), 
                     pTableView,  SLOT(setRootIndex(const QModelIndex&))
                    );

    spl.addWidget(pTreeView);
    spl.addWidget(pTableView);
    spl.show();

    return app.exec();
}
