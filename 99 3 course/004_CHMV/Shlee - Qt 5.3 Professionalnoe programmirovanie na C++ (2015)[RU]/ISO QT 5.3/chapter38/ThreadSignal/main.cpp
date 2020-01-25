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

// ======================================================================
class MyThread : public QThread {
Q_OBJECT

public:
    void run()
    {
        for (int i = 0; i <= 100; ++i) {
            usleep(100000);       
            emit progress(i);
        }
    }

signals:
    void progress(int);
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QProgressBar prb;
    MyThread     thread;

    QObject::connect(&thread, SIGNAL(progress(int)), 
                     &prb,    SLOT(setValue(int))
                    );

    prb.show();

    thread.start();
 
    return app.exec();
}

#include "main.moc"
