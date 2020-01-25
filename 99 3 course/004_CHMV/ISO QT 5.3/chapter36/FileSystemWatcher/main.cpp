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
#include "Viewer.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication       app(argc, argv);
    QFileSystemWatcher watcher;
    Viewer             viewer;
 
    QStringList args = app.arguments();
    args.removeFirst();

    watcher.addPaths(args);

    viewer.append("Watching files:" + watcher.files().join(";"));
    viewer.append("Watching dirs:" + watcher.directories().join(";"));
    viewer.show();

    QObject::connect(&watcher, SIGNAL(directoryChanged(const QString&)), 
                     &viewer, SLOT(slotDirectoryChanged(const QString&))
                    );
    QObject::connect(&watcher, SIGNAL(fileChanged(const QString&)), 
                     &viewer, SLOT(slotFileChanged(const QString&))
                    );

    return app.exec();
}
