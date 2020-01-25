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
class WinAPI : public QWidget {
protected:
    virtual bool nativeEvent(const QByteArray& baType, 
                             void* pmessage, 
                             long* result
                            )
    {
        QString str1 = "Windows Version = " 
                       + QString::number(QSysInfo::WindowsVersion);
        QString str2 = "Windows Message";

        WId        id     = effectiveWinId();
        HWND       hWnd   = (HWND)id;
        MSG* pmsg = reinterpret_cast<MSG*>(pmessage);

        switch(pmsg->message) {
        case WM_RBUTTONDOWN:
            ::MessageBox(hWnd, 
                         (const WCHAR*)str1.utf16(), 
                         (const WCHAR*)str2.utf16(),
                         MB_OK | MB_ICONEXCLAMATION
                        );
            break;
        default:
            ;
        }

        return QWidget::nativeEvent(baType, pmessage, result);
    }

    virtual void paintEvent(QPaintEvent*)
    {
        WId        id         = effectiveWinId();
        HWND       hWnd       = (HWND)id;
        HDC        hDC        = ::GetDC(hWnd);
        HBRUSH     hBrush     = ::CreateSolidBrush(RGB(255, 0, 255));
        HBRUSH     hBrushRect = ::CreateSolidBrush(RGB(200, 200, 200));
        HPEN       hPen       = ::CreatePen(PS_SOLID, 2, RGB(0, 0, 128));
        QString    str        = "GDI Drawing";
        TEXTMETRIC tm;             

        ::SelectObject(hDC, hBrushRect);        
        ::Rectangle(hDC, 0, 0, width(), height());
        ::GetTextMetrics(hDC, &tm);
        ::SelectObject(hDC, hBrush);
        ::SelectObject(hDC, hPen);
        ::Ellipse(hDC, 0, 0, width(), height());
        ::TextOut(hDC, 
                  width() / 2 - (tm.tmAveCharWidth * str.length()) / 2, 
                  (height() - tm.tmHeight) / 2, 
                  (const WCHAR*)str.utf16(), 
                  str.length()
                 );
        ::DeleteObject(hBrushRect);
        ::DeleteObject(hBrush);
        ::DeleteObject(hPen);
        ::ReleaseDC(hWnd, hDC);       
    }

    virtual void resizeEvent(QResizeEvent* pe)
    {
        update();
        QWidget::resizeEvent(pe);
    }

public:
    WinAPI(QWidget* pwgt = 0) : QWidget(pwgt) 
    {
        setAutoFillBackground(false);
        setAttribute(Qt::WA_PaintOnScreen, true);
    }

    QPaintEngine* paintEngine() const 
    {
        return 0;
    }
};

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    WinAPI       winAPI;

    winAPI.resize(280, 200);
    winAPI.show();

    return app.exec();
}
