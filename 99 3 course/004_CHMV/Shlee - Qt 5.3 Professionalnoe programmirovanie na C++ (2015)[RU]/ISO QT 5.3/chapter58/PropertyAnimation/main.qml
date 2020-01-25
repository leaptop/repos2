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
    color: "lightgreen"
    width: 300
    height:  300
    Image {
        id: img
        x: 0
        y: 0
        source: "qrc:///happyos.png"
    }
    PropertyAnimation {
        target: img
        properties: "x,y"
        from: 0
        to: 300 - img.height
        duration: 1500
        running: true
        easing.type: Easing.OutExpo
        loops: Animation.Infinite
    }
}
