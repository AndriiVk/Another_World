#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QGraphicsView>


class FieldView : public QGraphicsView
{
    Q_OBJECT
public:
    FieldView(QWidget* parent = 0);
};


#endif // FIELDVIEW_H
