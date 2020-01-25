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
import QtQuick.Dialogs 1.1

ApplicationWindow {
    width: 200
    height: 100
    visible: true
    title: "Dialogs Demo"

    Button {
        width: parent.width
        height: parent.height
        text: "Click to start a color dialog"
        onClicked: {
            messageDialog.visible = false;
            colorDialog.visible = true;
        }
    }

    ColorDialog {
        id: colorDialog
        visible: false
        modality: Qt.WindowModal
        title: "Select a color"
        color: "blue"
        onAccepted: { 
             messageDialog.informativeText = "Selected color: " + color
             messageDialog.visible = true
        }
    }

    MessageDialog {
        id: messageDialog
        visible: false
        modality: Qt.NonModal
        title: "Message"
    }
}
