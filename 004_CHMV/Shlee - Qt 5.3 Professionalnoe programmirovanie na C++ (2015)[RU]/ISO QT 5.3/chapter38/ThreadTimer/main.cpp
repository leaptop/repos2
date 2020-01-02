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
#include "MyThread.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QLCDNumber   lcd;
    MyThread     thread;
    MyWorker     worker;

    QObject::connect(&worker, SIGNAL(valueChanged(int)), 
                     &lcd,    SLOT(display(int))
                    );

    lcd.setSegmentStyle(QLCDNumber::Filled);
    lcd.display(10);
    lcd.resize(220, 90);
    lcd.show();

    worker.moveToThread(&thread);
    QObject::connect(&worker, SIGNAL(finished()),
                     &thread, SLOT(quit())
                    );
    QObject::connect(&thread, SIGNAL(finished()),
                     &app, SLOT(quit())
                    );

    thread.start();
    worker.doWork();
 
    return app.exec();
}

