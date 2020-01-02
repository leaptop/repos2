// ======================================================================
//  Calculation.cpp
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

#include "Calculation.h"

// ----------------------------------------------------------------------
Calculation::Calculation(QObject* pobj) : QObject(pobj)
                                        , input(0)
                                        , result(1)
{ 
}

// ----------------------------------------------------------------------
qulonglong Calculation::factorial(const qulonglong& n)
{
    return n ? (n * factorial(n - 1)) : 1;
}

// ----------------------------------------------------------------------
qulonglong Calculation::inputValue() const
{
    return input;
}

// ----------------------------------------------------------------------
void Calculation::setInputValue(const qulonglong& n)
{
    input  = n;
    result = factorial(input);

    emit inputValueChanged(input);
    emit resultValueChanged(result);
}

// ----------------------------------------------------------------------
qulonglong Calculation::resultValue() const
{
    return result;
}
