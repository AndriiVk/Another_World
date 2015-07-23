#include "battle_scene.h"
#include "all_defines.h"

const int count_finished_steps_unit = 1;

BattleScene::BattleScene(int x, int y, int w, int h, int n_arch, int n_knig, int n_mach) : QGraphicsScene(x, y, w, h),
    count(1), finished_turns_summ(0){
    Game game;
    HumanWarFactory re_factory;
    OrcWarFactory   em_factory;
    re = game.createArmy(re_factory, n_arch, n_knig, n_mach);
    em = game.createArmy(em_factory, n_arch, n_knig, n_mach);

    generateObstacles();
    generateWalls();
    generateTownhalls();
    generateUnits();

    for(int i=0; i<re->vh.size(); i++){
        re->vh[i]->setFlag(QGraphicsItem::ItemIsSelectable);
        re->vh[i]->setSelected(true);
        re->vh[i]->set_steps(5);
    }

    connect(this, SIGNAL(signal_click_count()), this, SLOT(slot_click_count()));
    connect(this, SIGNAL(signal_move_end()), this, SLOT(slot_move_end()));
    connect(h_townhall, SIGNAL(destroyed()), this, SIGNAL(signal_dead_humans_army()));
    connect(o_townhall, SIGNAL(destroyed()), this, SIGNAL(signal_dead_orcs_army()));
    connect(h_townhall, SIGNAL(signal_show_twn_inf(QString)), this, SIGNAL(signal_show_t_i(QString)));
    connect(o_townhall, SIGNAL(signal_show_twn_inf(QString)), this, SIGNAL(signal_show_t_i(QString)));

    for(int i=0; i<re->vm.size(); ++i)
        connect(re->vm[i], SIGNAL(signal_send_unit_info(QString)), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<re->vt.size(); ++i)
        connect(re->vt[i], SIGNAL(signal_send_unit_info(QString)), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<re->vr.size(); ++i)
        connect(re->vr[i], SIGNAL(signal_send_unit_info(QString)), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<re->vh.size(); ++i)
        connect(re->vh[i], SIGNAL(signal_send_unit_info(QString)), this, SLOT(slot_catch_unit_info(QString)));

    for(int i=0; i<em->vm.size(); ++i)
        connect(em->vm[i], SIGNAL(signal_send_unit_info(QString)), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<em->vt.size(); ++i)
        connect(em->vt[i], SIGNAL(signal_send_unit_info(QString)), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<em->vr.size(); ++i)
        connect(em->vr[i], SIGNAL(signal_send_unit_info(QString)), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<em->vh.size(); ++i)
        connect(em->vh[i], SIGNAL(signal_send_unit_info(QString)), this, SLOT(slot_catch_unit_info(QString)));


    for(int i=0; i<re->vm.size(); ++i)
        disconnect(re->vm[i], SIGNAL(destroyed()), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<re->vt.size(); ++i)
        disconnect(re->vt[i], SIGNAL(destroyed()), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<re->vr.size(); ++i)
        disconnect(re->vr[i], SIGNAL(destroyed()), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<re->vh.size(); ++i)
        disconnect(re->vh[i], SIGNAL(destroyed()), this, SLOT(slot_catch_unit_info(QString)));

    for(int i=0; i<em->vm.size(); ++i)
        disconnect(em->vm[i], SIGNAL(destroyed()), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<em->vt.size(); ++i)
        disconnect(em->vt[i], SIGNAL(destroyed()), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<em->vr.size(); ++i)
        disconnect(em->vr[i], SIGNAL(destroyed()), this, SLOT(slot_catch_unit_info(QString)));
    for(int i=0; i<em->vh.size(); ++i)
        disconnect(em->vh[i], SIGNAL(destroyed()), this, SLOT(slot_catch_unit_info(QString)));



    for(int i=0; i<re->vm.size(); ++i)
        connect(re->vm[i], SIGNAL(signal_moves_left(int)), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<re->vt.size(); ++i)
        connect(re->vt[i], SIGNAL(signal_moves_left(int)), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<re->vr.size(); ++i)
        connect(re->vr[i], SIGNAL(signal_moves_left(int)), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<re->vh.size(); ++i)
        connect(re->vh[i], SIGNAL(signal_moves_left(int)), this, SLOT(slot_moves_left(int)));

    for(int i=0; i<em->vm.size(); ++i)
        connect(em->vm[i], SIGNAL(signal_moves_left(int)), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<em->vt.size(); ++i)
        connect(em->vt[i], SIGNAL(signal_moves_left(int)), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<em->vr.size(); ++i)
        connect(em->vr[i], SIGNAL(signal_moves_left(int)), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<em->vh.size(); ++i)
        connect(em->vh[i], SIGNAL(signal_moves_left(int)), this, SLOT(slot_moves_left(int)));


    for(int i=0; i<re->vm.size(); ++i)
        disconnect(re->vm[i], SIGNAL(destroyed()), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<re->vt.size(); ++i)
        disconnect(re->vt[i], SIGNAL(destroyed()), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<re->vr.size(); ++i)
        disconnect(re->vr[i], SIGNAL(destroyed()), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<re->vh.size(); ++i)
        disconnect(re->vh[i], SIGNAL(destroyed()), this, SLOT(slot_moves_left(int)));

    for(int i=0; i<em->vm.size(); ++i)
        disconnect(em->vm[i], SIGNAL(destroyed()), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<em->vt.size(); ++i)
        disconnect(em->vt[i], SIGNAL(destroyed()), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<em->vr.size(); ++i)
        disconnect(em->vr[i], SIGNAL(destroyed()), this, SLOT(slot_moves_left(int)));
    for(int i=0; i<em->vh.size(); ++i)
        disconnect(em->vh[i], SIGNAL(destroyed()), this, SLOT(slot_moves_left(int)));


    for(int i=0; i<re->vm.size(); ++i)
        connect(re->vm[i], SIGNAL(signal_steps_finished(QString)), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<re->vt.size(); ++i)
        connect(re->vt[i], SIGNAL(signal_steps_finished(QString)), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<re->vr.size(); ++i)
        connect(re->vr[i], SIGNAL(signal_steps_finished(QString)), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<re->vh.size(); ++i)
        connect(re->vh[i], SIGNAL(signal_steps_finished(QString)), this, SLOT(slot_force_have_not_moves(QString)));

    for(int i=0; i<em->vm.size(); ++i)
        connect(em->vm[i], SIGNAL(signal_steps_finished(QString)), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<em->vt.size(); ++i)
        connect(em->vt[i], SIGNAL(signal_steps_finished(QString)), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<em->vr.size(); ++i)
        connect(em->vr[i], SIGNAL(signal_steps_finished(QString)), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<em->vh.size(); ++i)
        connect(em->vh[i], SIGNAL(signal_steps_finished(QString)), this, SLOT(slot_force_have_not_moves(QString)));


    for(int i=0; i<re->vm.size(); ++i)
        disconnect(re->vm[i], SIGNAL(destroyed()), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<re->vt.size(); ++i)
        disconnect(re->vt[i], SIGNAL(destroyed()), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<re->vr.size(); ++i)
        disconnect(re->vr[i], SIGNAL(destroyed()), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<re->vh.size(); ++i)
        disconnect(re->vh[i], SIGNAL(destroyed()), this, SLOT(slot_force_have_not_moves(QString)));

    for(int i=0; i<em->vm.size(); ++i)
        disconnect(em->vm[i], SIGNAL(destroyed()), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<em->vt.size(); ++i)
        disconnect(em->vt[i], SIGNAL(destroyed()), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<em->vr.size(); ++i)
        disconnect(em->vr[i], SIGNAL(destroyed()), this, SLOT(slot_force_have_not_moves(QString)));
    for(int i=0; i<em->vh.size(); ++i)
        disconnect(em->vh[i], SIGNAL(destroyed()), this, SLOT(slot_force_have_not_moves(QString)));
}


BattleScene::~BattleScene(){
    delete re;
    delete em;

    if(h_townhall)
        delete h_townhall;

    if(o_townhall)
        delete o_townhall;
}


void BattleScene::generateUnits()
{
    // Humans Army
    re->vm[0]->setX(186);
    re->vm[0]->setY(186);
    addItem(re->vm[0]);

    for(int i=1; i<re->vm.size(); ++i){
        re->vm[i]->setX(re->vm[i-1]->x()+62);
        re->vm[i]->setY(re->vm[i-1]->y());
        addItem(re->vm[i]);
    }

    re->vt[0]->setX(186);
    re->vt[0]->setY(124);
    addItem(re->vt[0]);

    for(int i=1; i<re->vt.size(); ++i){
        re->vt[i]->setX(re->vt[i-1]->x()+62);
        re->vt[i]->setY(re->vt[i-1]->y());
        addItem(re->vt[i]);
    }

    re->vr[0]->setX(186);
    re->vr[0]->setY(62);
    addItem(re->vr[0]);

    for(int i=1; i<re->vr.size(); ++i){
        re->vr[i]->setX(re->vr[i-1]->x()+62);
        re->vr[i]->setY(re->vr[i-1]->y());
        addItem(re->vr[i]);
    }

    re->vh[0]->setX(62);
    re->vh[0]->setY(186);
    addItem(re->vh[0]);

    // Orcs Army
    em->vm[0]->setX(744);
    em->vm[0]->setY(310);
    addItem(em->vm[0]);

    for(int i=1; i<em->vm.size(); ++i){
        em->vm[i]->setX(em->vm[i-1]->x()-62);
        em->vm[i]->setY(em->vm[i-1]->y());
        addItem(em->vm[i]);
    }

    em->vt[0]->setX(744);
    em->vt[0]->setY(372);
    addItem(em->vt[0]);

    for(int i=1; i<em->vt.size(); ++i){
        em->vt[i]->setX(em->vt[i-1]->x()-62);
        em->vt[i]->setY(em->vt[i-1]->y());
        addItem(em->vt[i]);
    }

    em->vr[0]->setX(744);
    em->vr[0]->setY(434);
    addItem(em->vr[0]);

    for(int i=1; i<em->vr.size(); ++i){
        em->vr[i]->setX(em->vr[i-1]->x()-62);
        em->vr[i]->setY(em->vr[i-1]->y());
        addItem(em->vr[i]);
    }

    em->vh[0]->setX(868);
    em->vh[0]->setY(310);
    addItem(em->vh[0]);
}



void BattleScene::generateWalls()
{
    //add corners
    FieldElement* corner1 = new FieldElement(1);
    corner1->setPos(0, 0);
    addItem(corner1);

    FieldElement* corner2 = new FieldElement(2);
    corner2->setPos(930, 0);
    addItem(corner2);

    FieldElement* corner3 = new FieldElement(3);
    corner3->setPos(930, 496);
    addItem(corner3);

    FieldElement* corner4 = new FieldElement(4);
    corner4->setPos(0, 496);
    addItem(corner4);

    std::vector<FieldElement*> sides1;

    //add north wall
    for(int i=0, d=62; i<14; i++, d=d+62){
        FieldElement* side = new FieldElement(5);
        side->setPos(d, 0);
        sides1.push_back(side);
    }

    //add east wall
    for(int i=0, d=62; i<7; i++, d=d+62){
        FieldElement* side = new FieldElement(6);
        side->setPos(930, d);
        sides1.push_back(side);
    }

    //add south wall
    for(int i=0, d=62; i<14; i++, d=d+62){
        FieldElement* side = new FieldElement(7);
        side->setPos(d, 496);
        sides1.push_back(side);
    }

    //add west wall
    for(int i=0, d=62; i<7; i++, d=d+62){
        FieldElement* side = new FieldElement(8);
        side->setPos(0, d);
        sides1.push_back(side);
    }
    for(int i=0; i<sides1.size(); i++){
        addItem(sides1[i]);
    }
}



void BattleScene::generateObstacles()
{
    std::vector<FieldElement*> obstacles;

    // Humans towers
    FieldElement* h_tower1 = new FieldElement(9);
    h_tower1->setPos(124, 248);
    obstacles.push_back(h_tower1);

    FieldElement* h_tower2 = new FieldElement(9);
    h_tower2->setPos(310, 310);
    obstacles.push_back(h_tower2);

    FieldElement* h_tower3 = new FieldElement(9);
    h_tower3->setPos(434, 62);
    obstacles.push_back(h_tower3);

    // Orcs towers
    FieldElement* o_tower1 = new FieldElement(10);
    o_tower1->setPos(496, 434);
    obstacles.push_back(o_tower1);

    FieldElement* o_tower2 = new FieldElement(10);
    o_tower2->setPos(620, 186);
    obstacles.push_back(o_tower2);

    FieldElement* o_tower3 = new FieldElement(10);
    o_tower3->setPos(806, 248);
    obstacles.push_back(o_tower3);

    // Portal
    FieldElement* portal = new FieldElement(14);
    portal->setPos(434, 186);
    obstacles.push_back(portal);

    // Stones
    for(int i=0, d=434; i<2; i++, d=d+62){
        FieldElement* stone1 = new FieldElement(13);
        stone1->setPos(d, 310);
        obstacles.push_back(stone1);
    }

    for(int i=0; i<obstacles.size(); i++){
        addItem(obstacles[i]);
    }
}



void BattleScene::generateTownhalls(){
    h_townhall = new FieldElement(11);
    h_townhall->setData(2, 200);              //defence
    h_townhall->setData(3, 100);              //health
    h_townhall->setData(4, 1);                //death
    h_townhall->setData(5, HUMANSTOWNHALL);
    h_townhall->setPos(62, 62);
    h_townhall->setFlag(QGraphicsItem::ItemIsFocusable);
    h_townhall->setEnabled(true);
    addItem(h_townhall);

    o_townhall = new FieldElement(12);
    o_townhall->setData(2, 200);              //defence
    o_townhall->setData(3, 100);              //health
    o_townhall->setData(4, 1);                //death
    o_townhall->setData(5, ORCSTOWNHALL);
    o_townhall->setPos(806, 372);
    o_townhall->setFlag(QGraphicsItem::ItemIsFocusable);
    o_townhall->setEnabled(true);
    addItem(o_townhall);
}



void BattleScene::slot_move_end(){
    switch(count){
        case 1:
        check_dead_units();
            if(!em->vr.isEmpty()){
                for(int i=0; i<em->vr.size(); i++){
                    em->vr[i]->setFlag(QGraphicsItem::ItemIsSelectable, false);
                    em->vr[i]->setEnabled(true);
                    em->vr[i]->set_steps(0);
                }
            }
            if(!re->vh.isEmpty()){
                emit signal_change_current_unit_icon();
                for(int i=0; i<re->vh.size(); i++){
                    re->vh[i]->setFlag(QGraphicsItem::ItemIsSelectable, true);
                    re->vh[i]->set_steps(5);
                }
                re->vh[re->vh.size()-1]->setSelected(true);
                break;
            }
            count++;

        case 2:
        check_dead_units();
            if(!re->vh.isEmpty()){
                for(int i=0; i<re->vh.size(); i++){
                    re->vh[i]->setFlag(QGraphicsItem::ItemIsSelectable, false);
                    re->vh[i]->setEnabled(true);
                    re->vh[i]->set_steps(0);
                }
            }
            if(!em->vh.isEmpty()){
                emit signal_change_current_unit_icon();
                for(int i=0; i<em->vh.size(); i++){
                    em->vh[i]->setFlag(QGraphicsItem::ItemIsSelectable, true);
                    em->vh[i]->set_steps(5);
                }
                em->vh[em->vh.size()-1]->setSelected(true);
                break;
            }
            count++;


        case 3:
        check_dead_units();
            if(!em->vh.isEmpty()){
                for(int i=0; i<em->vh.size(); i++){
                    em->vh[i]->setFlag(QGraphicsItem::ItemIsSelectable, false);
                    em->vh[i]->setEnabled(true);
                    em->vh[i]->set_steps(0);
                }
            }
            if(!re->vm.isEmpty()){
                emit signal_change_current_unit_icon();
                for(int i=0; i<re->vm.size(); i++){
                    re->vm[i]->setFlag(QGraphicsItem::ItemIsSelectable, true);
                    re->vm[i]->set_steps(5);
                }
                re->vm[re->vm.size()-1]->setSelected(true);
                break;
            }
            count++;

        case 4:
        check_dead_units();
            if(!re->vm.isEmpty()){
                for(int i=0; i<re->vm.size(); i++){
                    re->vm[i]->setFlag(QGraphicsItem::ItemIsSelectable, false);
                    re->vm[i]->setEnabled(true);
                    re->vm[i]->set_steps(0);
                }
            }
            if(!em->vm.isEmpty()){
                emit signal_change_current_unit_icon();
                for(int i=0; i<em->vm.size(); i++){
                    em->vm[i]->setFlag(QGraphicsItem::ItemIsSelectable, true);
                    em->vm[i]->set_steps(5);
                }
                em->vm[em->vm.size()-1]->setSelected(true);
                break;
            }
            count++;

        case 5:
        check_dead_units();
            if(!em->vm.isEmpty()){
                for(int i=0; i<em->vm.size(); i++){
                    em->vm[i]->setFlag(QGraphicsItem::ItemIsSelectable, false);
                    em->vm[i]->setEnabled(true);
                    em->vm[i]->set_steps(0);
                }
            }
            if(!re->vt.isEmpty()){
                emit signal_change_current_unit_icon();
                for(int i=0; i<re->vt.size(); i++){
                    re->vt[i]->setFlag(QGraphicsItem::ItemIsSelectable, true);
                    re->vt[i]->set_steps(5);
                }
                re->vt[re->vt.size()-1]->setSelected(true);
                break;
            }
            count++;

        case 6:
        check_dead_units();
            if(!re->vt.isEmpty()){
                for(int i=0; i<re->vt.size(); i++){
                    re->vt[i]->setFlag(QGraphicsItem::ItemIsSelectable, false);
                    re->vt[i]->setEnabled(true);
                    re->vt[i]->set_steps(0);
                }
            }
            if(!em->vt.isEmpty()){
                emit signal_change_current_unit_icon();
                for(int i=0; i<em->vt.size(); i++){
                    em->vt[i]->setFlag(QGraphicsItem::ItemIsSelectable, true);
                    em->vt[i]->set_steps(5);
                }
                em->vt[em->vt.size()-1]->setSelected(true);
                break;
            }
            count++;

        case 7:
        check_dead_units();
            if(!em->vt.isEmpty()){
                for(int i=0; i<em->vt.size(); i++){
                    em->vt[i]->setFlag(QGraphicsItem::ItemIsSelectable, false);
                    em->vt[i]->setEnabled(true);
                    em->vt[i]->set_steps(0);
                }
            }
            if(!re->vr.isEmpty()){
                emit signal_change_current_unit_icon();
                for(int i=0; i<re->vr.size(); i++){
                    re->vr[i]->setFlag(QGraphicsItem::ItemIsSelectable, true);
                    re->vr[i]->set_steps(5);
                }
                re->vr[re->vr.size()-1]->setSelected(true);
                break;
            }
            count++;

        case 8:
        check_dead_units();
            if(!re->vr.isEmpty()){
                for(int i=0; i<re->vr.size(); i++){
                    re->vr[i]->setFlag(QGraphicsItem::ItemIsSelectable, false);
                    re->vr[i]->setEnabled(true);
                    re->vr[i]->set_steps(0);
                }
            }
            if(!em->vr.isEmpty()){
                emit signal_change_current_unit_icon();
                for(int i=0; i<em->vr.size(); i++){
                    em->vr[i]->setFlag(QGraphicsItem::ItemIsSelectable, true);
                    em->vr[i]->set_steps(5);
                }
                em->vr[em->vr.size()-1]->setSelected(true);
                break;
            }
            else{
                count = 0;
                emit signal_end_turn();
                break;
            }
            count++;
    }
}


void BattleScene::slot_click_count(){
    count++;
    if(count == 9)
        count = 1;
}



void BattleScene::check_dead_units(){
    for(int i=0; i<re->vm.size(); i++)
        if(re->vm[i]->data(4).toInt() <= 0)
            re->vm.erase(re->vm.begin()+i);
    for(int i=0; i<re->vt.size(); i++)
        if(re->vt[i]->data(4).toInt() <= 0)
            re->vt.erase(re->vt.begin()+i);
    for(int i=0; i<re->vr.size(); i++)
        if(re->vr[i]->data(4).toInt() <= 0)
            re->vr.erase(re->vr.begin()+i);
    for(int i=0; i<re->vh.size(); i++)
        if(re->vh[i]->data(4).toInt() <= 0)
            re->vh.erase(re->vh.begin()+i);

    for(int i=0; i<em->vm.size(); i++)
        if(em->vm[i]->data(4).toInt() <= 0)
            em->vm.erase(em->vm.begin()+i);
    for(int i=0; i<em->vt.size(); i++)
        if(em->vt[i]->data(4).toInt() <= 0)
            em->vt.erase(em->vt.begin()+i);
    for(int i=0; i<em->vr.size(); i++)
        if(em->vr[i]->data(4).toInt() <= 0)
            em->vr.erase(em->vr.begin()+i);
    for(int i=0; i<em->vh.size(); i++)
        if(em->vh[i]->data(4).toInt() <= 0)
            em->vh.erase(em->vh.begin()+i);
}


void BattleScene::slot_catch_unit_info(const QString& str){
    u_info = "  LAST CLICKED UNIT INFORMATION\n\n" + str;

    emit signal_unit_info_to_wgt(u_info);
}



void BattleScene::slot_moves_left(int n){
    QString str;
    str.setNum(n);
    QString m_left = "MOVES: " + str;

    emit signal_unit_moves_left(m_left);
}



void BattleScene::slot_force_have_not_moves(const QString &str){
    finished_turns_summ += count_finished_steps_unit;

    if(str == ELVENARCHER){
        for(int i=0; i<re->vm.size(); i++){
            if(finished_turns_summ == re->vm.size()){
                finished_turns_summ = 0;
                emit signal_press_next_turn_button();
            }
        }
    }
    else if(str == FOOTMAN){
        for(int i=0; i<re->vt.size(); i++){
            if(finished_turns_summ == re->vt.size()){
                finished_turns_summ = 0;
                emit signal_press_next_turn_button();
            }
        }
    }
    else if(str == BALLISTA){
        for(int i=0; i<re->vr.size(); i++){
            if(finished_turns_summ == re->vr.size()){
                finished_turns_summ = 0;
                emit signal_press_next_turn_button();
            }
        }
    }
    else if(str == PALADIN){
        for(int i=0; i<re->vh.size(); i++){
            if(finished_turns_summ == re->vh.size()){
                finished_turns_summ = 0;
                emit signal_press_next_turn_button();
            }
        }
    }

    else if (str == TROLLAXETHROWER){
        for(int i=0; i<em->vm.size(); i++){
            if(finished_turns_summ == em->vm.size()){
                finished_turns_summ = 0;
                emit signal_press_next_turn_button();
            }
        }
    }
    else if(str == GRUNT){
        for(int i=0; i<em->vt.size(); i++){
            if(finished_turns_summ == em->vt.size()){
                finished_turns_summ = 0;
                emit signal_press_next_turn_button();
            }
        }
    }
    else if(str == CATAPULT){
        for(int i=0; i<em->vr.size(); i++){
            if(finished_turns_summ == em->vr.size()){
                finished_turns_summ = 0;
                emit signal_press_next_turn_button();
            }
        }
    }
    else if(str == OGRE){
        for(int i=0; i<em->vh.size(); i++){
            if(finished_turns_summ == em->vh.size()){
                finished_turns_summ = 0;
                emit signal_press_next_turn_button();
            }
        }
    }
}


void BattleScene::slot_null_to_turns_summ(){
    finished_turns_summ = 0;
}
