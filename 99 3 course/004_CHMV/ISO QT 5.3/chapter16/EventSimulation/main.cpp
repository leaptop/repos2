// ======================================================================
//  main.cpp
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

#include <QtWidgets>

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app (argc, argv);

    QLineEdit txt("User input: ");
    txt.show();
    txt.resize(300, 20);

    int i;
    for (i = 0; i < Qt::Key_Z - Qt::Key_A + 1; ++i) {
        QChar ch      = 65 + i;
        int   nKey    = Qt::Key_A + i;
        QKeyEvent keyPress(QEvent::KeyPress, nKey, Qt::NoModifier, ch);
        QApplication::sendEvent(&txt, &keyPress);

        QKeyEvent keyRelease(QEvent::KeyRelease, nKey, Qt::NoModifier, ch);
        QApplication::sendEvent(&txt, &keyRelease);
    }

    return app.exec();
}

