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
    height: 100

    Item {
        id: myelement
        property string name: "My Element"
        property int ver: 1
        property real pi: 3.14159
        property bool condition: true
        property url link: "http://www.bhv.com/"
    }

    Text {
        x: 0
        y: 0
        text: myelement.name + "<br>"
              + myelement.ver + "<br>"
              + myelement.pi + "<br>"
              + myelement.condition + "<br>"
              + myelement.link
    }
}
