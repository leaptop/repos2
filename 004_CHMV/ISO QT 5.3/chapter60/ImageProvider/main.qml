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
    title: qsTr("Image Brightness")
    width: controls.width
    height: controls.height
    visible: true

    Column {
        id: controls
        Image {
            id: img
            source: "image://brightness/Alina.png;" + sld.brightnessValue
        }
        Slider {
            id: sld
            width: img.width
            value: 0.75
            stepSize: 0.01
            property int brightnessValue: (value * 255 - 127)
        }
        Text {
            width: img.width
            text: "<h1>Brightness:" + sld.brightnessValue + "</h1>"
        }
    }
}
