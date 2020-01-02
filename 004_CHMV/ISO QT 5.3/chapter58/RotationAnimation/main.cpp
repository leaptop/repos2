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

#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView> 
#include <QDir>

// ----------------------------------------------------------------------
int main(int argc, char** argv) 
{
    QGuiApplication app(argc,argv);
    QQuickView      view;
    QFileInfo       fi(app.applicationFilePath());

    app.setApplicationName(fi.baseName());

    view.connect(view.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    /*QQmlFileSelector* ps =*/ new QQmlFileSelector(view.engine(), &view);

    view.setSource(QUrl("qrc:///main.qml")); 
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
