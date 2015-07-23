#ifndef WAR_ABSTR_FACTORY_H
#define WAR_ABSTR_FACTORY_H

#include <QtGui>
#include <QVector>
#include <QString>
#include "warrior.h"



// Abstract basics classes of the warriors
//=====================================================================
class Archer : public Warriors
{
public:
    Archer();
    //virtual void info() = 0;
    virtual ~Archer(){}
};


class Knight : public Warriors
{
public:
    Knight();
    //virtual void info() = 0;
    virtual ~Knight(){}
};


class Machine : public Warriors
{
public:
    Machine();
    //virtual void info() = 0;
    virtual ~Machine(){}
};


class Hero: public Warriors
{
public:
    Hero();
    //virtual void info() = 0;
    virtual ~Hero(){}
};

// Concrete warrior classes of both sides Armies
class HumanArcher : public Archer
{
public:
    HumanArcher();
    //void info();
};


class HumanKnight : public Knight
{
public:
    HumanKnight();
    //void info();
};


class HumanMachine : public Machine
{
public:
    HumanMachine();
    //void info();
};

class HumanHero : public Hero
{
public:
    HumanHero();
    //void info();
};


class OrcArcher : public Archer
{
public:
    OrcArcher();
    //void info();
};


class OrcKnight : public Knight
{
public:
    OrcKnight();
    //void info();
};


class OrcMachine : public Machine
{
public:
    OrcMachine();
    //void info();
};


class OrcHero : public Hero
{
public:
    OrcHero();
    //void info();
};

// abstract factory to create warriors
//=====================================================================
class WarmachineFactory
{
public:
    virtual Archer  *createArcher()  = 0;
    virtual Knight  *createKnight()  = 0;
    virtual Machine *createMachine() = 0;
    virtual Hero    *createHero()    = 0;
    virtual ~WarmachineFactory(){}
};


// humans army create factory
//=====================================================================
class HumanWarFactory : public WarmachineFactory
{
public:
    Archer  *createArcher();
    Knight  *createKnight();
    Machine *createMachine();
    Hero    *createHero();
};


// demons army create factory
//=====================================================================
class OrcWarFactory : public WarmachineFactory
{
public:
    Archer  *createArcher();
    Knight  *createKnight();
    Machine *createMachine();
    Hero    *createHero();
};


// class that extends warriors of the side
//=====================================================================
class Army
{
public:
    QVector<Archer*>  vm;
    QVector<Knight*>  vt;
    QVector<Machine*> vr;
    QVector<Hero*>    vh;

    ~Army();
    //void info();
};


// class that create army of the side
//=====================================================================
class Game
{
public:
    Army *createArmy(WarmachineFactory &factory, int n_arch, int n_knig, int n_mach);
};



#endif // WAR_ABSTR_FACTORY_H
