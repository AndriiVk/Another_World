#ifndef UNITINFO_H
#define UNITINFO_H

#include <QWidget>
#include <QObject>
#include <QLabel>
#include "battle_scene.h"

class UnitInfo : public QWidget{
    Q_OBJECT
public:
    UnitInfo(QWidget* parent = 0, BattleScene* scn = 0);

private:
    QTextEdit* edt;

protected slots:
    void slot_clear_field();
};

#endif // UNITINFO_H
