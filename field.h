#ifndef FIELD_H
#define FIELD_H

#include <QtGui>
#include <QGraphicsScene>
#include "war_abstr_factory.h"
#include "fieldelement.h"
#include "battle_scene.h"
#include "fieldview.h"
#include "voices.h"


class Field : public QWidget{
    Q_OBJECT
public:
    Field(QWidget *parent = 0, int n_arch = 0, int n_knig=0, int n_mach=0);
    ~Field();

private:
    BattleScene* scene;
    FieldView*   view;
    QPushButton* end_turn;
    QPushButton* whose_turn_wgt;
    QPushButton* quit;
    QDialog*     vict_wgt;
    Voices*      vcs;

signals:
    void victory_signal();

public slots:
    // Change cursor after turn end
    void slot_change_cursor();

    // Change current unit icon after each turn
    void slot_change_icon();

    // Create start window
    void slot_start_window();

    // Check is the one of armies empty
    void slot_orcs_victory();
    void slot_humans_victory();
};


#endif // FIELD_H
