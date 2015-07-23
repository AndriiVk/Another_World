#ifndef PLAYER_H
#define PLAYER_H


#include "war_abstr_factory.h"

class Player{
public:
    Player(Game &game, WarmachineFactory &factory, int &n_arch, int &n_knig, int &n_mach){
        arm = game.createArmy(factory, n_arch, n_knig, n_mach);
    }

private:
    Army* arm;
    int out_of_steps_unit;
};

#endif // PLAYER_H
