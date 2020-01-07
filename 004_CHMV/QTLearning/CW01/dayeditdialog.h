#ifndef DAYEDITDIALOG_H
#define DAYEDITDIALOG_H

#include <QDialog>

namespace Ui {
class dayEditDialog;
}

//class dayEditDialog : public QDialog
class dayEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit dayEditDialog(QString str, QWidget *parent = nullptr);
    ~dayEditDialog();
    int changedRecord = 0;
    QString anOldText = nullptr;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void needToReloadTable();

private:
    Ui::dayEditDialog *ui;
};

#endif // DAYEDITDIALOG_H
