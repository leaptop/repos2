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
    color: "gray"
    width: 450
    height: 170
    Component {
        id: delegate
        Item {
            width: item.width
            height: item.height
            Column {
                id: item
                Image {
                    width: 90
                    height: 90
                    source: cover
                    smooth: true
                }
                Text {color: "white"; text: artist; font.pointSize: 12}
                Text {color: "lightblue"; text: album; font.pointSize: 10}
                Text {color: "yellow"; text: year; font.pointSize: 8}
            }
        }
    }
    Path {
        id: itemsPath
        startX: 0
        startY: 80
        PathLine {x: 500; y: 80}
    }
    PathView {
        id: itemsView
        anchors.fill: parent
        model: CDs {}
        delegate: delegate
        path: itemsPath
        pathItemCount: 4
    }
}

