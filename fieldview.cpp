#include "fieldview.h"

FieldView::FieldView(QWidget *parent) : QGraphicsView(parent), count_wheel_step(0)
{
}


void FieldView::wheelEvent(QWheelEvent *event){
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;
    if(event->delta() > 0){
        count_wheel_step += 1;
        if(count_wheel_step > 3){
            count_wheel_step = 3;
            event->ignore();
        }
        else
            scale(scaleFactor, scaleFactor);
    }
    else{
        count_wheel_step -= 1;
        if(count_wheel_step < -3){
            count_wheel_step = -3;
            event->ignore();
        }
        else
            scale(1/scaleFactor, 1/scaleFactor);
    }
}
