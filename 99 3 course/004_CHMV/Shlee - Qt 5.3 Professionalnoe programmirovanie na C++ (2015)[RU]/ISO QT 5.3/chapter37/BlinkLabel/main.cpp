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
class BlinkLabel : public QLabel {
private:
    bool    m_bBlink;
    QString m_strText;

protected:
    virtual void timerEvent(QTimerEvent*)
    {
        m_bBlink = !m_bBlink;
        setText(m_bBlink ? m_strText : "");
    }

public:
    BlinkLabel(const QString& strText,
                     int      nInterval = 200,
                     QWidget* pwgt      = 0
              )
        : QLabel(strText, pwgt)
        , m_bBlink(true)
        , m_strText(strText)
    {
        startTimer(nInterval);
    }
};

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app (argc, argv);
    BlinkLabel   lbl("<FONT COLOR = RED><CENTER>Blink</CENTER></FONT>");

    lbl.resize(80, 25);
    lbl.show();

    return app.exec();
}
