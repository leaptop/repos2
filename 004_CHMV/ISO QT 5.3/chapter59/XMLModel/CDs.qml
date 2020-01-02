// ======================================================================
//  CDs.qml
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

import QtQuick 2.2
import QtQuick.XmlListModel 2.0

XmlListModel {
    source: "qrc:///CDs.xml"
    query:  "/CDs/CD"
    XmlRole {name: "artist"; query: "artist/string()"}
    XmlRole {name: "album"; query: "album/string()"}
    XmlRole {name: "year"; query: "year/string()"}
    XmlRole {name: "cover"; query: "cover/string()"}
}
