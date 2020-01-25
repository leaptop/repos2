// ======================================================================
//  MyPlugin.h
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

#pragma once

#include <QObject>
#include "../Application/interfaces.h"

// ======================================================================
class MyPlugin : public QObject, public StringInterface {
Q_OBJECT
Q_INTERFACES(StringInterface)
Q_PLUGIN_METADATA(IID "com.mysoft.Application.StringInterface" FILE "stringinterface.json")

private:
    QString oddUpper(const QString& str);

public:
    virtual ~MyPlugin();

    virtual QStringList operations(                              ) const;
    virtual QString     operation (const QString&, const QString&);
};

