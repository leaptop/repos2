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

// ======================================================================
class AddressBookParser : public QXmlDefaultHandler {
private:
    QString m_strText;

public:
    // ------------------------------------------------------------------
    bool startElement(const QString&, 
                      const QString&, 
                      const QString&, 
                      const QXmlAttributes& attrs 
                     )
    {
        for(int i = 0; i < attrs.count(); i++) {
            if(attrs.localName(i) == "number") {
                qDebug() << "Attr:" << attrs.value(i);
            }
        }
        return true;
    }

    // ------------------------------------------------------------------
    bool characters(const QString& strText) 
    {
        m_strText = strText;
        return true;
    }

    // ------------------------------------------------------------------
    bool endElement(const QString&, const QString&, const QString& str)
    {    

        if (str != "contact" && str != "addressbook") {
            qDebug() << "TagName:" << str
                     << "\tText:"  << m_strText;
        }
        return true;
    }                                           

    // ------------------------------------------------------------------
    bool fatalError(const QXmlParseException& exception)
    {
        qDebug() << "Line:"      << exception.lineNumber()
                 << ", Column:"  << exception.columnNumber()
                 << ", Message:" << exception.message();
        return false;
    }
};

// ----------------------------------------------------------------------
int main()
{
    AddressBookParser handler;
    QFile             file("addressbook.xml");
    QXmlInputSource   source(&file);
    QXmlSimpleReader  reader;

    reader.setContentHandler(&handler);
    reader.parse(source);

    return 0;
}
