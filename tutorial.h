#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QtGui>

class Tutorial : public QDialog{
public:
    Tutorial(QWidget* wgt=0);

private:
    QString str;
};

#endif // TUTORIAL_H
