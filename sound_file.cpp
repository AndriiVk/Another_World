#include "sound_file.h"


Sound::Sound(QWidget *wgt, QString main_sound): QWidget(wgt){
    m_s = main_sound;
    med_obj = new Phonon::MediaObject(this);
    Phonon::AudioOutput*  aud_out = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::VolumeSlider* vol_sld = new Phonon::VolumeSlider;
    Phonon::createPath(med_obj, aud_out);

    vol_sld->setAudioOutput(aud_out);
    vol_sld->setOrientation(Qt::Horizontal);
    vol_sld->setMaximumWidth(150);

    connect(med_obj, SIGNAL(finished()), this, SLOT(play_again()));
    med_obj->setCurrentSource(Phonon::MediaSource(main_sound));
    med_obj->play();

    QHBoxLayout* l_out = new QHBoxLayout;
    l_out->addWidget(vol_sld);
    setLayout(l_out);
}


void Sound::play_again(){
    med_obj->setCurrentSource(Phonon::MediaSource(m_s));
    med_obj->play();
}
