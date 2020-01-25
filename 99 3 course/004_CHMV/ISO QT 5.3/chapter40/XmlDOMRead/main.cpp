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

#include <QtXml>

// ----------------------------------------------------------------------
void traverseNode(const QDomNode& node)
{
   QDomNode domNode = node.firstChild();
   while(!domNode.isNull()) {
       if(domNode.isElement()) {
          QDomElement domElement = domNode.toElement();
          if(!domElement.isNull()) {
              if(domElement.tagName() == "contact") {
                  qDebug() << "Attr: "
                           << domElement.attribute("number", "");
              }
              else {
                  qDebug() << "TagName: " << domElement.tagName() 
                           << "\tText: " << domElement.text(); 
             }
          }
       }
       traverseNode(domNode);
       domNode = domNode.nextSibling();
    }
}

// ----------------------------------------------------------------------
int main()
{
    QDomDocument domDoc;
    QFile        file("addressbook.xml");

    if(file.open(QIODevice::ReadOnly)) {
        if(domDoc.setContent(&file)) {
            QDomElement domElement= domDoc.documentElement();
            traverseNode(domElement);
        }
        file.close();
    }

    return 0;
}
