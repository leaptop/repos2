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
class NameValidator : public QValidator {
public:
    NameValidator(QObject* parent) : QValidator(parent)
    {
    }

    virtual State validate(QString& str, int&) const
    {
        QRegExp rxp = QRegExp("[0-9]");
        if (str.contains(rxp)) {
            return Invalid;
        }
        return Acceptable;
    }
};


// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget      wgt;

    QLabel* plblText = 
           new QLabel("&Name (The digits will not be accepted!):");

    QLineEdit* ptxt = new QLineEdit;

    NameValidator* pnameValidator = new NameValidator(ptxt);
    ptxt->setValidator(pnameValidator);
    plblText->setBuddy(ptxt);

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;    
    pvbxLayout->addWidget(plblText);
    pvbxLayout->addWidget(ptxt);
    wgt.setLayout(pvbxLayout);
    wgt.show();

    return app.exec();
}
