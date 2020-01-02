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
    id: rect
    width: 360
    height: 360

    Image {
        id: img
        source: "qrc:///happyos.png"
        x: 10
        y: 10
        smooth: true
        Text {
            anchors.horizontalCenter: img.horizontalCenter
            anchors.top: img.bottom
            text: "Move the mouse!"
        }

        Behavior on x {
            NumberAnimation {
                duration: 1000
                easing.type: Easing.OutBounce
            }
        }
        Behavior on y {
            NumberAnimation {
                duration: 1000
                easing.type: Easing.OutBounce
            }
        }
    }
    MouseArea {
        anchors.fill: rect
        hoverEnabled: true
        onMouseXChanged: img.x = mouseX
        onMouseYChanged: img.y = mouseY
    }
}

