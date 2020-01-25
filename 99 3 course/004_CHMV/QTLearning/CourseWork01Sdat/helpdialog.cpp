#include "helpdialog.h"
#include "ui_helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);

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

    ptxtBrowser->setSearchPaths(QStringList()<<":/site/Common/helpSite/");
    ptxtBrowser->setSource(QString("index.html"));

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(pcmdBack);
    phbxLayout->addWidget(pcmdHome);
    phbxLayout->addWidget(pcmdForward);
    pvbxLayout->addLayout(phbxLayout);
    pvbxLayout->addWidget(ptxtBrowser);
    setLayout(pvbxLayout);
}

void help(){
    qDebug()<<"help";
}

HelpDialog::~HelpDialog()
{
    delete ui;
}
