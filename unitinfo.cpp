#include "unitinfo.h"
#include "all_defines.h"

#define INFORMATION "  LAST CLICKED UNIT INFORMATION\n\n"

UnitInfo::UnitInfo(QWidget *parent, BattleScene *scn): QWidget(parent){
    QPixmap pix2(INFORM_BACKGROUND);

    edt = new QTextEdit(this);
    QPalette pal1 = edt->palette();
    edt->setTextColor(Qt::yellow);
    pal1.setColor(QPalette::Base, QColor(255, 255, 255, 0));

    edt->setReadOnly(true);
    edt->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 14));
    edt->setPlainText(INFORMATION);
    edt->setPalette(pal1);
    edt->setFixedSize(pix2.width(), pix2.height());

    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(edt->size());
    setAutoFillBackground(true);

    connect(scn, SIGNAL(signal_unit_info_to_wgt(QString)), edt, SLOT(setPlainText(QString)));
    connect(scn, SIGNAL(signal_show_t_i(QString)), edt, SLOT(setPlainText(QString)));
}


void UnitInfo::slot_clear_field(){
    edt->setPlainText("\n\n\n               Click to the Unit");
}
