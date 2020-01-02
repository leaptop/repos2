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
import QtQuick.Layouts 1.1
import com.myinc.Calculation 1.0

ApplicationWindow {
    title: "Factorial Calculation"
    width: 250
    height: 80
    visible: true

    Calculation {
        id: calc
    }
    
    ColumnLayout {
        anchors.fill: parent
        RowLayout { // 1. call of an invokable method
            SpinBox {
                id: sbx
                value: 0
            }
            Text {
                text: "Result:" + calc.factorial(sbx.value)
            }
        }
        RowLayout { // 2. using of the properties
            SpinBox {
                value: 0
                onValueChanged: calc.input = value
            }
            Text {
                text: "Result:" + calc.result
            }
        }
    }
}


// 3. alternative solution
/*ApplicationWindow {
    title: "Factorial Calculation"
    width: 250
    height: 40
    visible: true

    Calculation {
        input: sbx.value
        onResultValueChanged: txt.text = "Result:" + result
    }
    RowLayout {
       SpinBox {
           id: sbx
           value: 0
       }
       Text {
           id: txt
       }
   }
}
*/
