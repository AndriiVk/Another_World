#include <QGraphicsScene>
#include <QTimer>
#include "hit.h"
#include "all_defines.h"

Hit::Hit(QString direction, QVariant power){
    setData(0, SWORD);
    dir = direction;
    power_value = power;
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(moveWeapon()));
    timer->start(50);
}


void Hit::moveWeapon(){
    if(data(0) == ARROW || data(0) == SHELL){
        if(dir == R){
            setPos(x()+10, y());
        }
        else if(dir == L){
            setPos(x()-10, y());
        }
        else if(dir == U){
            setPos(x(), y()-10);
        }
        else if(dir == D){
            setPos(x(), y()+10);
        }
        QGraphicsItem* obstacle = itemCollidesWith();
        if (obstacle){
            damageCalculation(obstacle, power_value);
            delete this;
        }
    }
    else if(data(0) == SWORD || data(0) == FIST){
        if(dir == R){
            setPos(x()+15, y());
        }
        else if(dir == L){
            setPos(x()-15, y());
        }
        else if(dir == U){
            setPos(x(), y()-15);
        }
        else if(dir == D){
            setPos(x(), y()+15);
        }
        QGraphicsItem* obstacle = itemCollidesWith();
        if (obstacle){
            damageCalculation(obstacle, power_value);
            delete this;
        }
        else
            delete this;
    }
}




QGraphicsItem* Hit::itemCollidesWith()
{
    QList<QGraphicsItem*> collisions = scene()->collidingItems(this);
    foreach (QGraphicsItem* it, collisions) {
        if (it == this)
            continue;
        return it;
    }
    return NULL;
}


void Hit::damageCalculation(QGraphicsItem* obstacle, QVariant power){
    if(obstacle->data(5) == ELVENARCHER    || obstacle->data(5) == TROLLAXETHROWER ||
       obstacle->data(5) == FOOTMAN        || obstacle->data(5) == GRUNT           ||
       obstacle->data(5) == BALLISTA       || obstacle->data(5) == CATAPULT        ||
       obstacle->data(5) == HUMANSTOWNHALL || obstacle->data(5) == ORCSTOWNHALL    ||
       obstacle->data(5) == PALADIN        || obstacle->data(5) == OGRE){

        obstacle->setData(2, obstacle->data(2).toInt() - power.toInt());

        if(obstacle->data(2).toInt() < 0){
            obstacle->setData(3, obstacle->data(3).toInt() + obstacle->data(2).toInt());
            obstacle->setData(4, obstacle->data(3));
            obstacle->setData(2, 0);
        }
        else{
            obstacle->setData(4, obstacle->data(3).toInt() + obstacle->data(2).toInt());
        }

        if(obstacle->data(4).toInt() <= 0){
            if(obstacle->data(5) == TROLLAXETHROWER || obstacle->data(5) == GRUNT || obstacle->data(5) == OGRE){
                vcs.get_Odead();
            }
            if(obstacle->data(5) == ELVENARCHER || obstacle->data(5) == FOOTMAN || obstacle->data(5) == PALADIN){
                vcs.get_Hdead();
            }
            if(obstacle->data(5) == BALLISTA || obstacle->data(5) == CATAPULT){
                vcs.get_Explode();
            }

            obstacle->hide();
            if(obstacle->data(5) == HUMANSTOWNHALL){
                vcs.get_Bldexpl2();
                delete obstacle;
            }
            if(obstacle->data(5) == ORCSTOWNHALL){
                vcs.get_Bldexpl2();
                delete obstacle;
            }
        }
        else{
            if(obstacle->data(5) == TROLLAXETHROWER || obstacle->data(5) == GRUNT
                    || obstacle->data(5) == CATAPULT || obstacle->data(5) == OGRE)
                vcs.get_Ohelp1();
            if(obstacle->data(5) == ELVENARCHER || obstacle->data(5) == FOOTMAN
                    || obstacle->data(5) == BALLISTA || obstacle->data(5) == PALADIN)
                vcs.get_Hhelp1();
            if(obstacle->data(5) == HUMANSTOWNHALL)
                vcs.get_Hhelp2();
            if(obstacle->data(5) == ORCSTOWNHALL)
                vcs.get_Ohelp2();
        }
    }
    else
        if(data(0) == FIST){
            vcs.get_Fist();
        }
        if(data(0) == ARROW){
            vcs.get_Bowhit();
        }
        if(data(0) == SHELL){
            vcs.get_Explode();
        }
        if(data(0) == SWORD){
            vcs.get_Sword1();
        }
}
