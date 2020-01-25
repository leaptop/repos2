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
    state: "State2"
    Text {
        id: txt
        anchors.centerIn: parent
    }
    states: [
        State {
            name: "State1"
            PropertyChanges {
                target: rect
                color: "lightgreen"
                width: 150
                height: 60
            }
            PropertyChanges {
                target: txt
                text: "State2: Click Me!"
            }
        },
        State {
            name: "State2"
            PropertyChanges {
                target: rect
                color: "yellow"
                width: 200
                height: 120
            }
            PropertyChanges {
                target: txt
                text: "State1: Click Me!"
            }
        }
    ]

    MouseArea {
        anchors.fill: parent
        onClicked:
            parent.state = (parent.state == "State1") ? "State2" : "State1"
    }
}
