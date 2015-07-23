#include "fieldelement.h"
#include "voices.h"
#include "all_defines.h"


FieldElement::FieldElement(int wn){
    switch(wn){
        case 1:
            setPixmap(QPixmap(WALLCORNER1));
            break;
        case 2:
            setPixmap(QPixmap(WALLCORNER2));
            break;
        case 3:
            setPixmap(QPixmap(WALLCORNER3));
            break;
        case 4:
            setPixmap(QPixmap(WALLCORNER4));
            break;
        case 5:
            setPixmap(QPixmap(WALLSIDE1));
            break;
        case 6:
            setPixmap(QPixmap(WALLSIDE2));
            break;
        case 7:
            setPixmap(QPixmap(WALLSIDE3));
            break;
        case 8:
            setPixmap(QPixmap(WALLSIDE4));
            break;
        case 9:
            setPixmap(QPixmap(HUMANSTOWER));
            break;
        case 10:
            setPixmap(QPixmap(ORCSTOWER));
            break;
        case 11:
            setPixmap(QPixmap(H_TOWNHALL));
            break;
        case 12:
            setPixmap(QPixmap(O_TOWNHALL));
            break;
        case 13:
            setPixmap(QPixmap(STONE));
            break;
        case 14:
            setPixmap(QPixmap(PORTAL));
            break;
    }
}



QGraphicsItem* FieldElement::itemCollidesWith(){
    QList<QGraphicsItem*> collisions = scene()->collidingItems(this);
    foreach (QGraphicsItem* it, collisions) {
        if (it == this)
            continue;
        return it;
    }
    return NULL;
}




void FieldElement::mousePressEvent(QGraphicsSceneMouseEvent *pe){
    if(pe->button() == Qt::LeftButton){
        QString string =
                "SELECTED TOWNHALL INFORMATION\n\nBuilding : " + data(5).toString() +
                "\nDefense  : " + data(2).toString() +
                "\nSettlers : " + data(3).toString();

        emit signal_show_twn_inf(string);

        if(data(5) == HUMANSTOWNHALL)
            vcs.get_Exorcism();
        if(data(5) == ORCSTOWNHALL)
            vcs.get_Iokilrog();
    }
    update();
}
