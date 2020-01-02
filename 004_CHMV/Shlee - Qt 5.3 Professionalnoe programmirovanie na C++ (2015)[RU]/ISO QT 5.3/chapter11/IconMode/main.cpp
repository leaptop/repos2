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
    QListWidget      lwg;
    QListWidgetItem* pitem = 0;
    QStringList      lst;

    lwg.setIconSize(QSize(48, 48));
    lwg.setSelectionMode(QAbstractItemView::MultiSelection);
    lwg.setViewMode(QListView::IconMode);
    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach(QString str, lst) {
        pitem = new QListWidgetItem(str, &lwg);    
        pitem->setIcon(QPixmap(":/" + str + ".jpg"));
        pitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | 
                        Qt::ItemIsEditable | Qt::ItemIsDragEnabled);

    }
    lwg.resize(150, 150);
    lwg.show();

    return app.exec();
}
