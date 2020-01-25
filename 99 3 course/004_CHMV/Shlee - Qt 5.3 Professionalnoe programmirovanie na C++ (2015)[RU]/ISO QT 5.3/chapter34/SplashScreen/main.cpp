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
void loadModules(QSplashScreen* psplash)
{
    QTime time;
    time.start();

    for (int i = 0; i < 100; ) {
        if (time.elapsed() > 40) {
            time.start();
            ++i;
        }
        psplash->showMessage("Loading modules: " 
                             + QString::number(i) + "%", 
                             Qt::AlignHCenter | Qt::AlignBottom, 
                             Qt::white
                            );
        qApp->processEvents();
    }
}

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication  app(argc, argv);
    QSplashScreen splash(QPixmap(":/splash.png"));

    splash.show();
  
    QLabel lbl("<H1><CENTER>My Application<BR>"
               "Is Ready!</CENTER></H1>"
              );

    loadModules(&splash);

    splash.finish(&lbl);

    lbl.resize(250, 250);
    lbl.show();

    return app.exec();
}
