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

#include <QtCore>
#include <QtConcurrent/QtConcurrent>

// ----------------------------------------------------------------------
QString myToUpper(const QString& str)
{
    return str.toUpper();
}

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
 
    QStringList lst(QStringList() << "one" << "two" << "three");
    QFuture<QString> future = 
         QtConcurrent::mapped(lst.begin(), lst.end(), myToUpper);

    future.waitForFinished();
    qDebug() << future.results();

    return 0;
}


