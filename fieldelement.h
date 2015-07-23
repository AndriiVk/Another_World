#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H

#include <QtGui>
#include <QObject>
#include "voices.h"

class FieldElement : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    FieldElement(int wn);
    QGraphicsItem* itemCollidesWith();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *pe);

private:
    int wall_number;
    Voices vcs;

signals:
    void signal_show_twn_inf(const QString& str);
};


#endif // FIELDELEMENT_H
