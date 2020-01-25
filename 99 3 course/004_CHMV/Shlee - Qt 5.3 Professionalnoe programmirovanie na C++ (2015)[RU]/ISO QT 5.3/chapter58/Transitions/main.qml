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
    width: 300
    height: 300
    Rectangle {
        id: rect
        width: 100
        height:  100
        color: "magenta"
        state: "State1"
        Text {
            anchors.centerIn: parent
            text: "Click me!"
        }
        MouseArea {
            anchors.fill: rect
            onClicked:
             rect.state = (rect.state == "State1") ? "State2" : "State1"
        }
        states: [
            State {
                name: "State1"
                PropertyChanges {target: rect; x: 0; y: 0}
            },
            State {
                name: "State2"
                PropertyChanges {target: rect; x: 200; y: 200}
            }
        ]
        transitions: [
            Transition {
                from: "State1"; to: "State2"
                PropertyAnimation {
                    target: rect;
                    properties: "x,y";
                    easing.type: Easing.InCirc
                    duration: 1000
                }
            },
            Transition {
                from: "State2"; to: "State1"
                PropertyAnimation {
                    target: rect
                    properties: "x,y";
                    easing.type: Easing.InBounce
                    duration: 1000
                }
            }
        ]
    }
}
