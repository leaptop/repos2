#ifndef alexeev_H
#define alexeev_H

#include <QWidget>
#include <QAbstractButton>

namespace Ui {
class alexeev;
}

class alexeev : public QWidget
{
    Q_OBJECT

public:
    explicit alexeev(QWidget *parent = nullptr);
    ~alexeev();

private:
    Ui::alexeev *ui;
public slots:
    void recieveData(QString str);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_buttonBox_accepted();
};

#endif // alexeev_H
