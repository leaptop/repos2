// ======================================================================
//  Button.qml
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

BorderImage {
    property alias text: txt.text
    property bool clicked;

    source: "qrc:///button.png"
    width: txt.width + 15
    height: txt.height + 15
    border {left: 15; top: 12; right: 15; bottom: 12}

    Text {
        id: txt
        color:  "white"
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onPressed: {
            parent.source = "qrc:///buttonpressed.png"
            parent.clicked = false
        }
        onReleased: {
            parent.source = "qrc:///button.png"
            parent.clicked = true
        }
    }
}
