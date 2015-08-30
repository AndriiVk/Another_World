#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>


class FieldView : public QGraphicsView
{
    Q_OBJECT
public:
    FieldView(QWidget* parent = 0);
    virtual void wheelEvent(QWheelEvent *event);

private:
    int count_wheel_step;
};


#endif // FIELDVIEW_H
