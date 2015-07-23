#include "turns_left_wnd.h"
#define MOVES "MOVES: 5"


MovesLeft::MovesLeft(QWidget *parent, BattleScene *scn): QWidget(parent){

    edt = new QTextEdit(this);
    QPalette pal1 = edt->palette();
    edt->setTextColor(Qt::yellow);
    pal1.setColor(QPalette::Base, QColor(255, 255, 255, 0));

    edt->setReadOnly(true);
    edt->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 14));
    edt->setPlainText(MOVES);
    edt->setPalette(pal1);
    edt->setFixedSize(100, 35);

    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(edt->size());
    setAutoFillBackground(true);

    connect(scn, SIGNAL(signal_unit_moves_left(QString)), edt, SLOT(setPlainText(QString)));
}


void MovesLeft::slot_update_turns_info(){
    edt->setPlainText(MOVES);
}
