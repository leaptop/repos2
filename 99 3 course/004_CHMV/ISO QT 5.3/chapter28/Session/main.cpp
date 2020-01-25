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
class MyApplication : public QApplication {
public:
    // ------------------------------------------------------------------
    MyApplication(int argc, char** argv)
        : QApplication(argc, argv)
    {
    }

    // ------------------------------------------------------------------
    virtual ~MyApplication()
    {
    }

    // ------------------------------------------------------------------
    virtual void commitData(QSessionManager&) {
        QMessageBox::information(0, 
                                 "Dialog", 
                                 "You are exiting operation system"
                                );
    }
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    MyApplication app(argc, argv);

    QLabel lbl("Exit you'r operation system to see the dialog box", 0);

    lbl.show();

    return app.exec();
}
