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
#include <QtXmlPatterns>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    if (argc < 3) {
        qDebug() << "usage: XQuery any.xml any.xq";
        return 0;
    }
    QString strQuery = "";
    QFile   xqFile(argv[2]);
    if(xqFile.open(QIODevice::ReadOnly)) {
        strQuery = xqFile.readAll();
        xqFile.close();
    }    
    else {
        qDebug() << "Can't open the file for reading:" << argv[1];
        return 0;
    }

    QFile xmlFile(argv[1]);
    if(xmlFile.open(QIODevice::ReadOnly)) {
        QXmlQuery query;
        query.bindVariable("inputDocument", &xmlFile);
        query.setQuery(strQuery);
        if (!query.isValid()) {
            qDebug() << "The query is invalid";
            return 0;
        }

        QString strOutput;
        if (!query.evaluateTo(&strOutput)) {
            qDebug() << "Can't evaluate the query";
            return 0;
        }

        xmlFile.close();
        qDebug() << strOutput;
    }

    return app.exec();
}
