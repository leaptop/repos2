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
    QTabWidget   tab;
    QStringList  lst;

    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach(QString str, lst) {
        tab.addTab(new QLabel(str, &tab), QPixmap(":/" + str + ".jpg"), str);
    }
                                                                
    tab.resize(360, 100);
    tab.show();

    return app.exec();
}
