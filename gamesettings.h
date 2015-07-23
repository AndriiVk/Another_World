#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include "field.h"


class GameSettings: public QDialog{
    Q_OBJECT

public:
    GameSettings(QWidget* parent=0, QWidget* st_wgt=0);
    ~GameSettings();
    void set_n_arch(int n_a) { n_arch = n_a; }
    void set_n_knig(int n_k) { n_knig = n_k; }
    void set_n_mach(int n_m) { n_mach = n_m; }

    int get_n_arch() { return n_arch; }
    int get_n_knig() { return n_knig; }
    int get_n_mach() { return n_mach; }

private:
    // variables to count
    int n_arch;
    int n_knig;
    int n_mach;
    QRadioButton* archer1;
    QRadioButton* archer2;
    QRadioButton* archer3;
    QRadioButton* knight1;
    QRadioButton* knight2;
    QRadioButton* knight3;
    QRadioButton* machine1;
    QRadioButton* machine2;
    QRadioButton* machine3;
    QCheckBox*    summer;
    QCheckBox*    wasteland;
    QCheckBox*    winter;
    QPushButton*  start_game;
    QPushButton*  close_window;
    QDialog*      wgt_wrn;

signals:
    void close_start_window();
    void stop_play();

protected slots:
    void slot_archers_number();
    void slot_knights_number();
    void slot_machine_number();
    void slot_start_game();
};


#endif // GAMESETTINGS_H
