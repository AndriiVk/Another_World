#ifndef BATTLE_SCENE_H
#define BATTLE_SCENE_H

#include <QGraphicsScene>
#include "fieldelement.h"
#include "war_abstr_factory.h"


class BattleScene : public QGraphicsScene{
    Q_OBJECT
public:
    BattleScene(int x=0, int y=0, int w=0, int h=0, int n_arch=0, int n_knig=0, int n_mach=0);
    ~BattleScene();

    // Place units to the scene.
    void generateUnits();

    // Place walls to the scene.
    void generateWalls();

    // Place trees to the scene.
    void generateObstacles();

    // Place townhalls of sides.
    void generateTownhalls();

    // Clean all dead units at the start of turn
    void check_dead_units();

    int get_count()  { return count;  }
    QString get_u_info() { return u_info; }

private:
    Army* re;
    Army* em;
    FieldElement* h_townhall;
    FieldElement* o_townhall;
    QString u_info;
    int finished_turns_summ;
    int count;  // Count which group of units is turn

signals:
    void signal_dead_humans_army();
    void signal_dead_orcs_army();
    void signal_click_count();
    void signal_move_end();
    void signal_end_turn();
    void signal_change_current_unit_icon();
    void signal_show_t_i(const QString& str);
    void signal_unit_info_to_wgt(const QString& str);
    void signal_unit_moves_left(const QString& str);
    void signal_press_next_turn_button();

public slots:
    // Connected with button "end_turn". Finish turn of units group.
    void slot_move_end();

    // Connected with button "end_turn". Count number of groups, which turn.
    void slot_click_count();

    // Catch unit information
    void slot_catch_unit_info(const QString& str);

    // Catch number of turn
    void slot_moves_left(int n);

    // Summ all signals from units, that have not any steps. If all units in force get steps 0 -> emit signal
    // that clicked next turn button
    void slot_force_have_not_moves(const QString& str);

    // Place NULL to the finished_turns_summ when pressed end_turn button before all units in current force
    // use all of their moves
    void slot_null_to_turns_summ();
};

#endif // BATTLE_SCENE_H
