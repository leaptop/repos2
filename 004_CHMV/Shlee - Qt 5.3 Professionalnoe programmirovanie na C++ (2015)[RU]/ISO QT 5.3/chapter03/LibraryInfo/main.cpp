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

#include <QtCore>

// ----------------------------------------------------------------------
int main(int, char**)
{
    qDebug() << "Build date:" 
             << QLibraryInfo::buildDate().toString("yyyy-MM-dd");
    qDebug() << "License Products:" 
             << QLibraryInfo::licensedProducts();
    qDebug() << "Licensee:" 
             << QLibraryInfo::licensee();
    qDebug() << "Is Debug Build:" 
             << QLibraryInfo::isDebugBuild();

    qDebug() << "Locations";
    qDebug() << "  Headers:" 
             << QLibraryInfo::location(QLibraryInfo::HeadersPath);
    qDebug() << "  Libraries:" 
             << QLibraryInfo::location(QLibraryInfo::LibrariesPath);
    qDebug() << "  Binaries:" 
             << QLibraryInfo::location(QLibraryInfo::BinariesPath);
    qDebug() << "  Prefix" 
             << QLibraryInfo::location(QLibraryInfo::PrefixPath);
    qDebug() << "  Documentation: " 
             << QLibraryInfo::location(QLibraryInfo::DocumentationPath);
    qDebug() << "  Plugins:" 
             << QLibraryInfo::location(QLibraryInfo::PluginsPath);
    qDebug() << "  Data:" 
             << QLibraryInfo::location(QLibraryInfo::DataPath);
    qDebug() << "  Settings:" 
             << QLibraryInfo::location(QLibraryInfo::SettingsPath);
    qDebug() << "  Examples:" 
             << QLibraryInfo::location(QLibraryInfo::ExamplesPath);
}
