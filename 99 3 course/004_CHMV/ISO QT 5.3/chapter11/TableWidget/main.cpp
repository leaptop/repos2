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
    const int n = 3;

    QApplication      app(argc, argv);
    QTableWidget      tbl(n, n);
    QTableWidgetItem* ptwi = 0;
    QStringList       lst;

    lst << "First" << "Second" << "Third";
    tbl.setHorizontalHeaderLabels(lst);
    tbl.setVerticalHeaderLabels(lst);

    for (int i  = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ptwi = new QTableWidgetItem(QString("%1,%2").arg(i).arg(j));
            tbl.setItem(i, j, ptwi);
        }
    }
    tbl.resize(370, 135);
    tbl.show();

    return app.exec();
}
