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

Item {
    width: 360
    height: 360
    Rectangle {
        id: redrect;
        color:  "red"
        x: 0
        y: 0
        width: parent.width / 2
        height: parent.height / 2
    }

    Rectangle {
        color: "green";
        x: redrect.width
        y: redrect.height
        width: redrect.width
        height: redrect.height
    }
}
