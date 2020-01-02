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
import QtQuick.Layouts 1.1

Item {
    width: 320
    height: 240

    RowLayout {
        anchors.fill: parent
        anchors.margins: 10

        spacing: 10
        Rectangle {
            Layout.fillHeight: true
            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;
            color: "red"
        }
        Rectangle {
            Layout.fillWidth: true
            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;
            color: "blue"
        }
        Rectangle {
            Layout.fillHeight: true
            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;
            color: "green"
        }
    }
}
