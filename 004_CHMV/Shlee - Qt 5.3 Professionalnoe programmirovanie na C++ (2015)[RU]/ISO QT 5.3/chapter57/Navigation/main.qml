// ======================================================================
//  main.qml
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

Rectangle {
    width: 300
    height: 300
    color:  focus ? "red" : "lightgreen"
    KeyNavigation.tab: childrect

    Rectangle {
        id: childrect
        width: 150
        height: 150
        anchors.centerIn: parent
        color:  focus ? "red" : "lightgreen"
        KeyNavigation.tab: parent
        focus: true

        Text {
            anchors.centerIn: parent
            text: "Press TAB"
        }
    }
}
