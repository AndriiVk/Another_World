#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "field.h"
#include "sound_file.h"


class StartWindow: public QWidget{
    Q_OBJECT

public:
    StartWindow(QWidget* wgt = 0);
    ~StartWindow() { delete snd; }

private:
    Sound* snd;

signals:
    void stop_play();

protected slots:
    void slot_start_game();
    void slot_settings_game();
    void slot_show_tutorial();
};

#endif // STARTWINDOW_H
