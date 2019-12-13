#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "auth.h"
#include "ui_auth.h"
#include <QPixmap>

void MainWindow::About_Lab1()
{
    auth *dg = new auth();
    dg->show();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_2,SIGNAL(triggered()),this,SLOT(About_Lab1()));

    QAction* pactOpen = new QAction("file open action", 0);
        pactOpen->setText("&Открыть");
        pactOpen->setShortcut(QKeySequence("CTRL+O"));
        pactOpen->setToolTip("Открытие документа");
        pactOpen->setStatusTip("Открыть файл");
        pactOpen->setWhatsThis("Открыть файл");
        connect(pactOpen, SIGNAL(triggered()), SLOT(slotOpen()));
        QMenu* pmnuFile = new QMenu("&Файл");
        pmnuFile->addAction(pactOpen);
        menuBar()->addMenu(pmnuFile);

        QAction* pactSave = new QAction("file save action", 0);
        pactSave->setText("&Сохранить");
        pactSave->setShortcut(QKeySequence("CTRL+S"));
        pactSave->setToolTip("Сохранение документа");
        pactSave->setStatusTip("Сохранить файл");
        pactSave->setWhatsThis("сохранить файл");
        connect(pactSave, SIGNAL(triggered()), SLOT(slotSave()));
        pmnuFile->addAction(pactSave);
        menuBar()->addMenu(pmnuFile);

        QAction* pactClear = new QAction("file clear action", 0);
        pactClear->setText("&Очистить");
        pactClear->setShortcut(QKeySequence("CTRL+U"));
        pactClear->setToolTip("Очистка документа");
        pactClear->setStatusTip("Очистить файл");
        pactClear->setWhatsThis("Очистить файл");
        connect(pactClear, SIGNAL(triggered()), SLOT(slotClear()));
        pmnuFile->addAction(pactClear);
        menuBar()->addMenu(pmnuFile);
        //ui->mainToolBar->addAction(pactOpen);
        //ui->mainToolBar->addAction(pactSave);
       // ui->mainToolBar->addAction(pactClear);
}

MainWindow::~MainWindow()
{
    delete ui;
}

