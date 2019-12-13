#ifndef INPUTDIALOG_ALEXEEV_H
#define INPUTDIALOG_ALEXEEV_H
#include <QDialog>
#include <QLineEdit>

class QLineEdit;

class InputDialog_Alexeev: public QDialog
{
    Q_OBJECT
private:
    QLineEdit * m_ptxtFirstName;
    QLineEdit * m_ptxtLastName;
public:
    InputDialog_Alexeev(QWidget* pwgt =0);

    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_ALEXEEV_H
