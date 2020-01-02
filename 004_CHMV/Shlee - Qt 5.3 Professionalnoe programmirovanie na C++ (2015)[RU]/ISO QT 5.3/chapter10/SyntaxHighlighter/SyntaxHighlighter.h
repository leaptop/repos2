// ======================================================================
//  SyntaxHighlighter.h
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

#pragma once

#include <QSyntaxHighlighter>

class QTextDocument;

// ======================================================================
class SyntaxHighlighter: public QSyntaxHighlighter {
Q_OBJECT
private:
    QStringList m_lstKeywords;

protected:
    enum { NormalState = -1, InsideCStyleComment, InsideCString };

    virtual void highlightBlock(const QString&);

    QString getKeyword(int i, const QString& str) const;

public:
    SyntaxHighlighter(QTextDocument* parent = 0);
};
