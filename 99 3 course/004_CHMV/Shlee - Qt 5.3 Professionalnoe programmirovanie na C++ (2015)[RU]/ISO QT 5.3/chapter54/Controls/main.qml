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
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 200
    height: 75
    title: "Controls"

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem {
                text: "Quit"
                onTriggered: Qt.quit();
            }
        }
    }

    ProgressBar {
        x: 0
        y: 0
        width: parent.width
        height: parent.height / 2
        value: slider.value
    }
    Slider {
        id: slider
        x: 0
        y: parent.height / 2
        width: parent.width
        height: parent.height / 2
        value: 0.75
        tickmarksEnabled: true
        stepSize: 0.1
    }
}
