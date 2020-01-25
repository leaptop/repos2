#include "DocWindowAlexeev.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QColorDialog>

DocWindowAlexeev::DocWindowAlexeev(QWidget* pwgt): QTextEdit(pwgt)
{

}

void DocWindowAlexeev::slotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty()) {
        return;
    }

    QFile file(str);
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();

        m_strFileName = str;
        emit changeWindowTitle(m_strFileName);
    }
}



void DocWindowAlexeev::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(0, m_strFileName);
    if(!str.isEmpty()){
        m_strFileName=str;
        slotSave();
    }
}

void DocWindowAlexeev::slotSave()
{
    if (m_strFileName.isEmpty()) {
        slotSaveAs();
        return;
    }

    QFile file(m_strFileName);

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream(&file) << toPlainText();

        file.close();
        emit changeWindowTitle(m_strFileName);
        QMessageBox::information(this, "Файл сохранён", "Файл успешно сохранён");

    }

}
void DocWindowAlexeev::slotColor()
{
    setTextColor(QColorDialog::getColor());
}

void DocWindowAlexeev::slotDelete()
{
    clear();
}
