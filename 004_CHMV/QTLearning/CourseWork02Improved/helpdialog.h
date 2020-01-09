#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include<QtWidgets>
//#include<QtWebEngineWidgets>

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(QWidget *parent = nullptr);
    ~HelpDialog();

private slots:
 //   void  help();

private:
    Ui::HelpDialog *ui;
};

#endif // HELPDIALOG_H


