#ifndef HIT_H
#define HIT_H

#include <QGraphicsItem>
#include <QObject>
#include "voices.h"


class Hit : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Hit(QString direction, QVariant power);
    QGraphicsItem* itemCollidesWith();
    void damageCalculation(QGraphicsItem *obstacle, QVariant power);

private:
    QString dir;
    QVariant power_value;
    Voices vcs;

public slots:
    void moveWeapon();
};

#endif // HIT_H
