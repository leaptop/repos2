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
    width: 200
    height: 200
    ColorAnimation on color {
        from: Qt.rgba(1, 0.5, 0, 1)
        to: Qt.rgba(0.5, 0, 1, 1)
        duration: 1500
        running: true
        loops: Animation.Infinite
    }
}
