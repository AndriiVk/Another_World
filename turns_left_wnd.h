#ifndef TURNS_LEFT_WND_H
#define TURNS_LEFT_WND_H

#include <QWidget>
#include <QObject>
#include <QLabel>
#include "battle_scene.h"

class MovesLeft : public QWidget{
    Q_OBJECT
public:
    MovesLeft(QWidget* parent = 0, BattleScene* scn = 0);

private:
    QTextEdit* edt;

protected slots:
    void slot_update_turns_info();
};


#endif // TURNS_LEFT_WND_H
