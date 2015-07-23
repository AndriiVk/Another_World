#ifndef WARRIOR_H
#define WARRIOR_H

#include <QtGui>
#include "voices.h"

class Warriors : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Warriors();
    virtual ~Warriors(){}

    void set_steps(int stp)   { steps  = stp; }
    void set_dir(QString dir) { direct = dir; }
    void hitFunction(QString weapon, int xu, int yu, int xd, int yd, int xl, int yl, int xr, int yr);
    void checkTheObstacles(int steps_count, int old_x, int old_y);
    void set_pixmaps(QPixmap g_u, QPixmap g_d, QPixmap g_r, QPixmap g_l, QPixmap h_u, QPixmap h_d,
                     QPixmap h_r, QPixmap h_l, QPixmap w_u, QPixmap w_d, QPixmap w_r, QPixmap w_l);

    int     get_steps()            { return steps; }
    QString get_dir()              { return direct; }
    QPixmap get_go_up_pix()        { return go_up; }
    QPixmap get_go_down_pix()      { return go_down; }
    QPixmap get_go_right_pix()     { return go_right; }
    QPixmap get_go_left_pix()      { return go_left; }
    QPixmap get_hit_up_pix()       { return hit_up; }
    QPixmap get_hit_down_pix()     { return hit_down; }
    QPixmap get_hit_right_pix()    { return hit_right; }
    QPixmap get_hit_left_pix()     { return hit_left; }
    QPixmap get_weapon_up_pix()    { return weapon_up; }
    QPixmap get_weapon_down_pix()  { return weapon_down; }
    QPixmap get_weapon_right_pix() { return weapon_right; }
    QPixmap get_weapon_left_pix()  { return weapon_left; }

    QGraphicsItem *itemCollidesWith();

protected:
    void keyPressEvent(QKeyEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *pe);

private:
    int     steps;
    Voices  vcs;
    QString direct;
    QPixmap go_up;
    QPixmap go_down;
    QPixmap go_right;
    QPixmap go_left;
    QPixmap hit_up;
    QPixmap hit_down;
    QPixmap hit_right;
    QPixmap hit_left;
    QPixmap weapon_up;
    QPixmap weapon_down;
    QPixmap weapon_right;
    QPixmap weapon_left;

signals:
    void signal_send_unit_info(const QString&);
    void signal_moves_left(int);
    void signal_steps_finished(const QString&);
};

#endif // WARRIOR_H
