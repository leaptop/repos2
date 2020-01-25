#ifndef DOCWINDOWALEXEEV_H
#define DOCWINDOWALEXEEV_H
#include <QTextEdit>
#include <QFileDialog>
#include <QTextStream>


class DocWindowAlexeev : public QTextEdit{
    Q_OBJECT
private:
    QString m_strFileName;

public:
    DocWindowAlexeev(QWidget* pwgt = 0);
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotColor();
    void slotDelete();
};

#endif // DOCWINDOWALEXEEV_H
