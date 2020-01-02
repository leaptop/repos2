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
    width: 200
    height: 200

    Grid {
        rows: 2
        columns: 2
        anchors.centerIn: parent
        spacing: 10

        Rectangle {
            width: 64; height: 64; color: "red"
        }
        Rectangle {
            width: 64; height: 64;color: "blue"
        }
        Rectangle {
            width: 64; height: 64; color: "green"
        }
        Rectangle {
            width: 64; height: 64; color: "black"
        }
    }
}

