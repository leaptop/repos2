#ifndef SDIPROGRAM_H
#define SDIPROGRAM_H

#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include "DocWindowAlexeev.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SDIProgram; }
QT_END_NAMESPACE

class SDIProgram : public QMainWindow
{
    Q_OBJECT

public:
    SDIProgram(QWidget *pwgt = nullptr): QMainWindow(pwgt)
    {
        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");
        DocWindowAlexeev* pdoc = new DocWindowAlexeev;
        pmnuFile->addAction("&Open...",
                pdoc,
                SLOT(slotLoad()),
                QKeySequence("CTRL+O")
                );
        pmnuFile->addAction("&save",
                            pdoc,
                            SLOT(slotSave()),
                            QKeySequence("CTRL+S")
                            );
        pmnuFile->addAction("&save as",
                            pdoc,
                            SLOT(slotSaveAs()),
                            QKeySequence("CTRL+S+A")
                            );
        pmnuFile->addSeparator();
        pmnuFile->addAction("&Quit", qApp, SLOT(quit()), QKeySequence("CTRL+Q"));
        pmnuFile->addAction("&Del", pdoc, SLOT(slotDelete()), QKeySequence("Del"));

        pmnuHelp->addAction("&About", this, SLOT(slotAbout()), Qt::Key_F1);

        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);
        setCentralWidget(pdoc);

        connect(pdoc, SIGNAL(changeWindowTitle(const QString&)), SLOT(slotChangeWindowTitle(const QString&)));
        statusBar()->showMessage("Ready", 2000);

        pmnuFile->addAction("&Color", pdoc, SLOT(slotColor()));


    }

    ~SDIProgram();

public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "Application", "Alexeev");
    }
    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }
private:
    Ui::SDIProgram *ui;
};
#endif // SDIPROGRAM_H
