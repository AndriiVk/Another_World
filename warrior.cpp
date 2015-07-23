#include "warrior.h"
#include "weapons_delta.h"
#include "all_defines.h"
#include "hit.h"

const int delta_step = 31;


Warriors::Warriors(){
    setEnabled(false);
    set_steps(0);
    setPixmap(go_right);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setData(0, 100);              //range
    setData(1, 100);              //power
    setData(2, 100);              //defence
    setData(3, 100);              //health
    setData(4, 100);              //death
    setData(5, PALADIN);          //name
}


void Warriors::set_pixmaps(QPixmap g_u, QPixmap g_d, QPixmap g_r, QPixmap g_l, QPixmap h_u,
                           QPixmap h_d, QPixmap h_r, QPixmap h_l, QPixmap w_u, QPixmap w_d,
                           QPixmap w_r, QPixmap w_l){
    go_up        = g_u;
    go_down      = g_d;
    go_right     = g_r;
    go_left      = g_l;
    hit_up       = h_u;
    hit_down     = h_d;
    hit_right    = h_r;
    hit_left     = h_l;
    weapon_up    = w_u;
    weapon_down  = w_d;
    weapon_right = w_r;
    weapon_left  = w_l;
}


QGraphicsItem* Warriors::itemCollidesWith()
{
    QList<QGraphicsItem*> collisions = scene()->collidingItems(this);
    foreach (QGraphicsItem* it, collisions) {
        if (it == this)
            continue;
        return it;
    }
    return NULL;
}


void Warriors::keyPressEvent(QKeyEvent *event){
    int steps_count=0;
    if(this->isSelected()){
        qreal old_x = x();
        qreal old_y = y();
        switch(event->key()){
            case Qt::Key_Left:
                setPos(x()-delta_step, y());
                setPixmap(go_left);
                set_dir( L );
                steps_count = get_steps();
                set_steps(get_steps()-1);
                emit signal_moves_left(get_steps());
                checkTheObstacles(steps_count, old_x, old_y);
                break;
            case Qt::Key_Right:
                setPos(x()+delta_step, y());
                setPixmap(go_right);
                set_dir( R );
                steps_count = get_steps();
                set_steps(get_steps()-1);
                emit signal_moves_left(get_steps());
                checkTheObstacles(steps_count, old_x, old_y);
                break;
            case Qt::Key_Up:
                setPos(x(), y()-delta_step);
                setPixmap(go_up);
                set_dir( U );
                steps_count = get_steps();
                set_steps(get_steps()-1);
                emit signal_moves_left(get_steps());
                checkTheObstacles(steps_count, old_x, old_y);
                break;
            case Qt::Key_Down:
                setPos(x(), y()+delta_step);
                setPixmap(go_down);
                set_dir( D );
                steps_count = get_steps();
                set_steps(get_steps()-1);
                emit signal_moves_left(get_steps());
                checkTheObstacles(steps_count, old_x, old_y);
                break;
            case Qt::Key_Space:
                if(data(5) == ELVENARCHER){
                    vcs.get_Bowfire();
                    hitFunction(ARROW, elven_xu, elven_yu, elven_xd, elven_yd,
                                elven_xl, elven_yl, elven_xr, elven_yr);
                    break;
                }
                else if(data(5) == TROLLAXETHROWER){
                    vcs.get_Axe();
                    hitFunction(ARROW, troll_xu, troll_yu, troll_xd, troll_yd,
                                troll_xl, troll_yl, troll_xr, troll_yr);
                    break;
                }
                else if(data(5) == FOOTMAN || data(5) == PALADIN || data(5) == GRUNT){
                    vcs.get_Sword1();
                    hitFunction(SWORD, knight_xu, knight_yu, knight_xd, knight_yd,
                                knight_xl, knight_yl, knight_xr, knight_yr);
                    break;
                }
                else if(data(5) == OGRE){
                    vcs.get_Fist();
                    hitFunction(FIST, knight_xu, knight_yu, knight_xd, knight_yd,
                                knight_xl, knight_yl, knight_xr, knight_yr);
                    break;
                }
                else if(data(5) == BALLISTA || data(5) == CATAPULT){
                    vcs.get_Catapult();
                    hitFunction(SHELL, machine_xu, machine_yu, machine_xd, machine_yd,
                                machine_xl, machine_yl, machine_xr, machine_yr);
                    break;
                }
        }
        if(!get_steps()){
            setEnabled(false);
            emit signal_steps_finished(data(5).toString());
        }
    }
}



void Warriors::mousePressEvent(QGraphicsSceneMouseEvent *pe){
    if(this->get_steps())
        emit signal_moves_left(get_steps());
    if(pe->button() == Qt::LeftButton){
        QString current_unit =
                "Unit   : " + data(5).toString() + "\n" +
                "Power  : " + data(1).toString() + "\n" +
                "Defense: " + data(2).toString() + "\n" +
                "Health : " + data(3).toString();
        emit signal_send_unit_info(current_unit);
        if(get_steps()){
            if(data(5) == TROLLAXETHROWER){
                vcs.get_Trready();
            }
            else if(data(5) == ELVENARCHER){
                vcs.get_Eready();
            }
            else if(data(5) == BALLISTA || data(5) == CATAPULT){
                vcs.get_Catyessr();
            }
            else if(data(5) == GRUNT){
                vcs.get_OReady();
            }
            else if(data(5) == FOOTMAN){
                vcs.get_Hready();
            }
            else if(data(5) == PALADIN){
                vcs.get_Pkwhat1();
            }
            else if(data(5) == OGRE){
                vcs.get_Ogready();
            }
        }
    }
    update();
}



void Warriors::hitFunction(QString weapon,
                           int xu, int yu, int xd, int yd, int xl, int yl, int xr, int yr){

        Hit* b = new Hit(get_dir(), data(1));
        b->setData(0, weapon);

        if(get_dir() == U){
            setPixmap(hit_up);
            b->setPixmap(weapon_up);
            b->setPos(this->x()+xu, this->y()+yu);
        }
        if(get_dir() == D){
            setPixmap(hit_down);
            b->setPixmap(weapon_down);
            b->setPos(this->x()+xd, this->y()+yd);
        }
        if(get_dir() == L){
            setPixmap(hit_left);
            b->setPixmap(weapon_left);
            b->setPos(this->x()+xl, this->y()+yl);
        }
        if(get_dir() == R){
            setPixmap(hit_right);
            b->setPixmap(weapon_right);
            b->setPos(this->x()+xr, this->y()+yr);
        }
        scene()->addItem(b);

        set_steps(get_steps()-1);
        emit signal_moves_left(get_steps());
}



void Warriors::checkTheObstacles(int steps_count, int old_x, int old_y){
    QGraphicsItem* obstacle = itemCollidesWith();
    if (obstacle) {
        this->setPos(old_x, old_y);
        set_steps(steps_count);
        emit signal_moves_left(steps_count);
    }
}
