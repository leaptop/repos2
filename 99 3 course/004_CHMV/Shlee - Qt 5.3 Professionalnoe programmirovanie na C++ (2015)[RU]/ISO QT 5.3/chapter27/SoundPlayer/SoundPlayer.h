// ======================================================================
//  SoundPlayer.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.3 Professional programming with C++"
// ======================================================================
//  Copyright (c) 2014 by Max Schlee
//
//  Email : Max.Schlee@neonway.com
//  Blog  : http://www.maxschlee.com
//
//  Social Networks
//  ---------------
//  FaceBook : http://www.facebook.com/mschlee
//  Twitter  : http://twitter.com/Max_Schlee
//  2Look.me : http://2look.me/NW100003
//  Xing     : http://www.xing.com/profile/Max_Schlee
//  vk.com   : https://vk.com/max.schlee
// ======================================================================

#pragma once
#include <QWidget>
#include <QMediaPlayer>

class QPushButton;
class QSlider;
class QLabel;
class QVBoxLayout;

// ======================================================================
class SoundPlayer : public QWidget {
    Q_OBJECT
protected:
    QMediaPlayer* m_pmp;
    QVBoxLayout*  m_pvbxMainLayout;

private:
    QPushButton*  m_pcmdPlay;
    QPushButton*  m_pcmdStop;
    QSlider*      m_psldPosition;
    QLabel*       m_plblCurrent;
    QLabel*       m_plblRemain;

    QString msecsToString(qint64 n);

public:
    SoundPlayer(QWidget* pwgt = 0);

private slots:
    void slotOpen             (                   );
    void slotPlay             (                   );
    void slotSetSliderPosition(qint64             );
    void slotSetMediaPosition (int                );
    void slotSetDuration      (qint64             );
    void slotStatusChanged    (QMediaPlayer::State);
};
