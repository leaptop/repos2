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
    width: 400
    height: 400
    Image {
        id: img
        source: "qrc:///happyos.png"
        smooth: true
        anchors.centerIn: parent
    }

    ParallelAnimation {
        NumberAnimation {
            target: img
            properties: "scale"
            from: 0.1;
            to: 3.0;
            duration: 2000
            easing.type: Easing.InOutCubic
        }
        NumberAnimation {
            target: img
            properties: "opacity"
            from: 1.0
            to: 0;
            duration: 2000
        }
        running: true
        loops: Animation.Infinite
    }
}
