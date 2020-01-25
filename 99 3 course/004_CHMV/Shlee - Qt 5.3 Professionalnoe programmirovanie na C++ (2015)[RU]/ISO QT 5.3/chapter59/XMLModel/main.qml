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
    id: mainrect
    color:  "gray"
    width: 200
    height: 360
    Component {
        id: delegate
        Item {
            width: mainrect.width
            height: 70
            Row {
               anchors.verticalCenter: parent.verticalCenter
               Image {
                   width: 64
                   height: 64
                   source: cover
                   smooth: true
               }
               Column {
                   Text {color: "white"; text: artist; font.pointSize: 12}
                   Text {color: "lightblue"; text: album; font.pointSize: 10}
                   Text {color: "yellow"; text: year; font.pointSize: 8}
               }
           }
        }
    }
    ListView {
        focus:  true
        header: Rectangle {
            width: parent.width
            height: 30
            gradient: Gradient {
                GradientStop {position: 0; color: "gray"}
                GradientStop {position: 0.7; color: "black"}
            }
            Text{
                anchors.centerIn: parent;
                color: "gray";
                text: "CDs";
                font.bold: true;
                font.pointSize: 20
            }
        }
        footer: Rectangle {
            width: parent.width
            height: 30
            gradient: Gradient {
                GradientStop {position: 0; color: "gray"}
                GradientStop {position: 0.7; color: "black"}
            }
        }
        highlight: Rectangle {
            width: parent.width
            color: "darkblue"
        }
        anchors.fill: parent
        model: CDs{}
        delegate: delegate
    }
}
