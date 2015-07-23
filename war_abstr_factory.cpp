#include "war_abstr_factory.h"
#include "all_defines.h"


//================ARCHER=============KNIGHT===============MACHINE==============================
Archer::Archer(): Warriors(){}
Knight::Knight(): Warriors(){}
Machine::Machine(): Warriors(){}
Hero::Hero(): Warriors(){}


//===========================CONCRETE==UNITS==================================================
HumanArcher::HumanArcher(){
    set_pixmaps(QPixmap(ARCHER_MOVE_UP), QPixmap(ARCHER_MOVE_DOWN),
                QPixmap(ARCHER_MOVE_RIGHT), QPixmap(ARCHER_MOVE_LEFT),
                QPixmap(ARCHER_HIT_UP), QPixmap(ARCHER_HIT_DOWN),
                QPixmap(ARCHER_HIT_RIGHT), QPixmap(ARCHER_HIT_LEFT),
                QPixmap(ARCHER_WPN_MOVE_UP), QPixmap(ARCHER_WPN_MOVE_DOWN),
                QPixmap(ARCHER_WPN_MOVE_RIGHT), QPixmap(ARCHER_WPN_MOVE_LEFT));
    setEnabled(true);
    set_steps(0);
    setPixmap(get_go_down_pix());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setData(1, 5);              //power
    setData(2, 1);              //defence
    setData(3, 5);              //health
    setData(4, 1);              //death
    setData(5, ELVENARCHER);    //name
}


//void HumanArcher::info(){
//}


HumanKnight::HumanKnight(){
    set_pixmaps(QPixmap(FOOTMAN_MOVE_UP), QPixmap(FOOTMAN_MOVE_DOWN),
                QPixmap(FOOTMAN_MOVE_RIGHT), QPixmap(FOOTMAN_MOVE_LEFT),
                QPixmap(FOOTMAN_HIT_UP), QPixmap(FOOTMAN_HIT_DOWN),
                QPixmap(FOOTMAN_HIT_RIGHT), QPixmap(FOOTMAN_HIT_LEFT),
                QPixmap(FOOTMAN_WPN), QPixmap(FOOTMAN_WPN), QPixmap(FOOTMAN_WPN), QPixmap(FOOTMAN_WPN));
    setEnabled(true);
    set_steps(0);
    setPixmap(get_go_down_pix());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setData(1, 20);             //power
    setData(2, 10);             //defence
    setData(3, 50);             //health
    setData(4, 1);              //death
    setData(5, FOOTMAN);        //name
}


//void HumanKnight::info(){
//}


HumanMachine::HumanMachine(){
    set_pixmaps(QPixmap(BALLISTA_MOVE_UP), QPixmap(BALLISTA_MOVE_DOWN),
                QPixmap(BALLISTA_MOVE_RIGHT), QPixmap(BALLISTA_MOVE_LEFT),
                QPixmap(BALLISTA_HIT_UP), QPixmap(BALLISTA_HIT_DOWN),
                QPixmap(BALLISTA_HIT_RIGHT), QPixmap(BALLISTA_HIT_LEFT),
                QPixmap(BALLISTA_WPN_MOVE_UP), QPixmap(BALLISTA_WPN_MOVE_DOWN),
                QPixmap(BALLISTA_WPN_MOVE_RIGHT), QPixmap(BALLISTA_WPN_MOVE_LEFT));
    setEnabled(true);
    set_steps(0);
    setPixmap(get_go_down_pix());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setData(1, 40);             //power
    setData(2, 5);              //defence
    setData(3, 30);             //health
    setData(4, 1);              //death
    setData(5, BALLISTA);       //name
}


//void HumanMachine::info(){
//}


HumanHero::HumanHero(){
    set_pixmaps(QPixmap(PALADIN_MOVE_UP), QPixmap(PALADIN_MOVE_DOWN),
                QPixmap(PALADIN_MOVE_RIGHT), QPixmap(PALADIN_MOVE_LEFT),
                QPixmap(PALADIN_HIT_UP), QPixmap(PALADIN_HIT_DOWN),
                QPixmap(PALADIN_HIT_RIGHT), QPixmap(PALADIN_HIT_LEFT),
                QPixmap(PALADIN_WPN), QPixmap(PALADIN_WPN), QPixmap(PALADIN_WPN), QPixmap(PALADIN_WPN));
    setEnabled(true);
    set_steps(0);
    setPixmap(get_go_down_pix());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setData(1, 30);             //power
    setData(2, 20);             //defence
    setData(3, 75);             //health
    setData(4, 1);              //death
    setData(5, PALADIN);        //name
}


//void HumanHero::info(){
//}


OrcArcher::OrcArcher(){
    set_pixmaps(QPixmap(TROLL_MOVE_UP), QPixmap(TROLL_MOVE_DOWN),
                QPixmap(TROLL_MOVE_RIGHT), QPixmap(TROLL_MOVE_LEFT),
                QPixmap(TROLL_HIT_UP), QPixmap(TROLL_HIT_DOWN),
                QPixmap(TROLL_HIT_RIGHT), QPixmap(TROLL_HIT_LEFT),
                QPixmap(TROLL_WPN_MOVE_UP), QPixmap(TROLL_WPN_MOVE_DOWN),
                QPixmap(TROLL_WPN_MOVE_RIGHT), QPixmap(TROLL_WPN_MOVE_LEFT));
    setEnabled(true);
    set_steps(0);
    setPixmap(get_go_up_pix());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setData(1, 5);                  //power
    setData(2, 1);                  //defence
    setData(3, 5);                  //health
    setData(4, 1);                  //death
    setData(5, TROLLAXETHROWER);    //name
}


//void OrcArcher::info(){
//}


OrcKnight::OrcKnight(){
    set_pixmaps(QPixmap(GRUNT_MOVE_UP), QPixmap(GRUNT_MOVE_DOWN),
                QPixmap(GRUNT_MOVE_RIGHT), QPixmap(GRUNT_MOVE_LEFT),
                QPixmap(GRUNT_HIT_UP), QPixmap(GRUNT_HIT_DOWN),
                QPixmap(GRUNT_HIT_RIGHT), QPixmap(GRUNT_HIT_LEFT),
                QPixmap(GRUNT_WPN), QPixmap(GRUNT_WPN), QPixmap(GRUNT_WPN), QPixmap(GRUNT_WPN));
    setEnabled(true);
    set_steps(0);
    setPixmap(get_go_up_pix());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setData(1, 20);             //power
    setData(2, 10);             //defence
    setData(3, 50);             //health
    setData(4, 1);              //death
    setData(5, GRUNT);          //name
}


//void OrcKnight::info(){
//}


OrcMachine::OrcMachine(){
    set_pixmaps(QPixmap(CATAPULT_MOVE_UP), QPixmap(CATAPULT_MOVE_DOWN),
                QPixmap(CATAPULT_MOVE_RIGHT), QPixmap(CATAPULT_MOVE_LEFT),
                QPixmap(CATAPULT_HIT_UP), QPixmap(CATAPULT_HIT_DOWN),
                QPixmap(CATAPULT_HIT_RIGHT), QPixmap(CATAPULT_HIT_LEFT),
                QPixmap(CATAPULT_WPN_MOVE_UP), QPixmap(CATAPULT_WPN_MOVE_DOWN),
                QPixmap(CATAPULT_WPN_MOVE_RIGHT), QPixmap(CATAPULT_WPN_MOVE_LEFT));
    setEnabled(true);
    set_steps(0);
    setPixmap(get_go_up_pix());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setData(1, 40);             //power
    setData(2, 5);              //defence
    setData(3, 30);             //health
    setData(4, 1);              //death
    setData(5, CATAPULT);       //name
}


//void OrcMachine::info(){
//}


OrcHero::OrcHero(){
    set_pixmaps(QPixmap(OGRE_MOVE_UP), QPixmap(OGRE_MOVE_DOWN),
                QPixmap(OGRE_MOVE_RIGHT), QPixmap(OGRE_MOVE_LEFT),
                QPixmap(OGRE_HIT_UP), QPixmap(OGRE_HIT_DOWN),
                QPixmap(OGRE_HIT_RIGHT), QPixmap(OGRE_HIT_LEFT),
                QPixmap(OGRE_WPN), QPixmap(OGRE_WPN), QPixmap(OGRE_WPN), QPixmap(OGRE_WPN));
    setEnabled(true);
    set_steps(0);
    setPixmap(get_go_up_pix());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setData(1, 30);             //power
    setData(2, 20);             //defence
    setData(3, 75);             //health
    setData(4, 1);              //death
    setData(5, OGRE);           //name
}


//void OrcHero::info(){
//}



//Create army factories
//=============================================================================================
Archer* HumanWarFactory::createArcher(){
    return new HumanArcher();
}

Knight* HumanWarFactory::createKnight(){
    return new HumanKnight();
}

Machine* HumanWarFactory::createMachine(){
    return new HumanMachine();
}

Hero* HumanWarFactory::createHero(){
    return new HumanHero();
}

Archer* OrcWarFactory::createArcher(){
    return new OrcArcher();
}

Knight* OrcWarFactory::createKnight(){
    return new OrcKnight();
}

Machine* OrcWarFactory::createMachine(){
    return new OrcMachine();
}

Hero* OrcWarFactory::createHero(){
    return new OrcHero();
}




//============================================ARMY=============================================

Army::~Army()
{
    for(int i = 0; i < vm.size(); ++i)
        delete vm[i];
    for(int i = 0; i < vt.size(); ++i)
        delete vt[i];
    for(int i = 0; i < vr.size(); ++i)
        delete vr[i];
}

//void Army::info()
//{
//    for(int i = 0; i < vm.size(); ++i)
//        vm[i]->info();
//    for(int i = 0; i < vt.size(); ++i)
//        vt[i]->info();
//    for(int i = 0; i < vr.size(); ++i)
//        vr[i]->info();
//}



//=============================================GAME============================================
Army* Game::createArmy(WarmachineFactory &factory, int n_arch, int n_knig, int n_mach)
{
    Army *p = new Army;

    for(int i = 0; i < n_arch; ++i)
        p->vm.push_back(factory.createArcher());

    for(int i = 0; i < n_knig; ++i)
        p->vt.push_back(factory.createKnight());

    for(int i = 0; i < n_mach; ++i)
        p->vr.push_back(factory.createMachine());

    for(int i = 0; i < 1; ++i)
        p->vh.push_back(factory.createHero());

    return p;
}









