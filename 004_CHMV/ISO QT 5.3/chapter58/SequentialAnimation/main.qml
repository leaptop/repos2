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
    width: 130
    height: 450
    Image {
        id: img
        source: "qrc:///happyos.png"
        smooth: true
        Text {
            anchors.horizontalCenter: img.horizontalCenter
            anchors.top: img.bottom
            text: "Click me!"
        }
        MouseArea {
            anchors.fill: img
            onClicked: anim.running = true
        }
        SequentialAnimation {
            id: anim
            NumberAnimation {
                target: img
                from: 20
                to: 300
                properties: "y"
                easing.type: Easing.OutBounce
                duration: 1000
            }
            RotationAnimation {
                target: img
                from: 0
                to: 360
                properties: "rotation"
                direction: RotationAnimaion.Clockwise
                duration: 1000
            }
            PauseAnimation {
                duration: 500
            }
            NumberAnimation {
                target: img
                from: 300
                to: 20
                properties: "y"
                easing.type: Easing.OutBack
                duration: 1000
            }
        }
    }
}
