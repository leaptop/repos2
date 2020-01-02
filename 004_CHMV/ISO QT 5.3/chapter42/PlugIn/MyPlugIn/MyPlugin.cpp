// ======================================================================
//  PlugIn.cpp
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
#include "MyPlugin.h"

// ----------------------------------------------------------------------
QString MyPlugin::oddUpper(const QString& str)
{ 
    QString strTemp;

    for (int i = 0; i < str.length(); ++i) {
        strTemp += (i % 2) ? str.at(i) : str.at(i).toUpper();
    }

    return strTemp;
}

// ----------------------------------------------------------------------
/*virtual*/ MyPlugin::~MyPlugin()
{
}

// ----------------------------------------------------------------------
/*virtual*/ QStringList MyPlugin::operations() const
{
    return QStringList() << "oddUpper" << "lower";
}

// ----------------------------------------------------------------------
/*virtual*/ QString MyPlugin::operation(const QString& strText, 
                                        const QString& strOperation
                                       )
{
    QString strTemp;
    if (strOperation == "oddUpper") {
        strTemp = oddUpper(strText);
    }
    else if (strOperation == "lower") {
        strTemp = strText.toLower();
    }
    else {
        qDebug() << "Unsupported operation";
    }
    return strTemp;
}
