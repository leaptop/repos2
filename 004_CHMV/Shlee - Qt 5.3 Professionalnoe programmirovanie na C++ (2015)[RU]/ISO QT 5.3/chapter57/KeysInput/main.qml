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
    width: 200
    height: 100
    Text {
        x: 20;
        y: 20;
        text: "Move this text<br>(use the cursor-keys)"
        horizontalAlignment: Text.AlignHCenter
        Keys.onLeftPressed: x -= 3
        Keys.onRightPressed: x += 3
        Keys.onDownPressed: y += 3
        Keys.onUpPressed: y -= 3
        focus:  true
    }
}
