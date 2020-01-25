// ======================================================================
//  Viewer.cpp
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

#include "Viewer.h"

// ----------------------------------------------------------------------
Viewer::Viewer(QWidget* pwgt /*=0*/) : QTextEdit(pwgt)
{
    setWindowTitle("File System Watcher");
}

// ----------------------------------------------------------------------
void Viewer::slotDirectoryChanged(const QString& str)
{
    append("Directory changed:" + str);
}

// ----------------------------------------------------------------------
void Viewer::slotFileChanged(const QString& str)
{
    append("File changed:" + str);
}

