#ifndef HELPBROWSER_H//makes a window with help in a .htm file. mainwindow.cpp doesn't
#define HELPBROWSER_H//necessarily has to have any code in itself
#include <QTWidgets>

class HelpBrowser : public QWidget{
    Q_OBJECT
public:
    HelpBrowser(const QString& strPath,
                const QString& strFileName,
                QWidget* pwgt = 0
            ): QWidget(pwgt)
    {
        QPushButton* pcmdBack = new QPushButton("<<");//created widgets of buttons
        QPushButton* pcmdHome = new QPushButton("Home");//and pointers pcmdBack etc
        QPushButton* pcmdForward = new QPushButton(">>");
        QTextBrowser* ptxtBrowser = new QTextBrowser;

        connect(pcmdBack, SIGNAL(clicked()),//connection of signals and slots
                ptxtBrowser, SLOT(home())//apparently these signals and slots
                );//are inherited
        connect(pcmdHome, SIGNAL(clicked()),//configuring logistics inside
                ptxtBrowser, SLOT(home())
                );
        connect(pcmdForward, SIGNAL(clicked()),
                ptxtBrowser, SLOT(forward())
                );
        connect(ptxtBrowser, SIGNAL(backwardAvailable(bool)),
                pcmdBack, SLOT(setEnabled(bool))
                );
        connect(ptxtBrowser, SIGNAL(forwardAvailable(bool)),
                pcmdForward, SLOT(setEnabled(bool))
                );

        ptxtBrowser->setSearchPaths(QStringList()<<strPath);
        ptxtBrowser->setSource(QString(strFileName));

        //Layout setup
        QVBoxLayout* pvbxLayout = new QVBoxLayout;
        QHBoxLayout* phbxLayout = new QHBoxLayout;
        phbxLayout->addWidget(pcmdBack);
        phbxLayout->addWidget(pcmdHome);
        phbxLayout->addWidget(pcmdForward);
        pvbxLayout->addLayout(phbxLayout);//-book's example doesn't work-
        pvbxLayout->addWidget(ptxtBrowser);//no, it works, I just
        setLayout(pvbxLayout);//mixed up words as usual(addWidget instead of addLayout)
    }
};

#endif // HELPBROWSER_H
