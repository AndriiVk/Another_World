#ifndef SOUND_FILE_H
#define SOUND_FILE_H

#include <QtGui>
#include <phonon>

namespace Phonon {
class AudioOutput;
class MediaObject;
class MediaSource;
}

class Sound : public QWidget {
    Q_OBJECT

public:
    Phonon::MediaObject*  med_obj;
    Sound(QWidget* wgt = 0, QString main_sound = "");

    ~Sound() {}

private:
    QString m_s;

protected slots:
    void play_again();

};























#endif // SOUND_FILE_H
