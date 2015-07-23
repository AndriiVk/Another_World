#include "gamesettings.h"
#include "all_defines.h"

#define N1 "1"
#define N2 "2"
#define N3 "3"
#define ARCHERS_HEAD  "Number of Archers"
#define KNIGHTS_HEAD  "Number of Knights"
#define MACHINES_HEAD "Number of Machines"
#define WARNING       "WARNING!"
#define STD_WRONG_CHS "You don't choose number\n       of some warriors"


GameSettings::GameSettings(QWidget *parent, QWidget *st_wgt): QDialog(parent){
    n_arch=0;
    n_knig=0;
    n_mach=0;

    setWindowFlags(Qt::FramelessWindowHint);
    QPixmap p(SETTINGS_CURSOR);
    QCursor cur(p, 0, 0);
    setCursor(cur);

    QPalette pal;
    QPixmap pix(SETTINGS_BACKGROUND);
    pal.setBrush(this->backgroundRole(), QBrush(pix));
    setPalette(pal);
    setAutoFillBackground(true);
    setFixedSize(pix.width(), pix.height());

    archer1 = new QRadioButton(N1);
    archer2 = new QRadioButton(N2);
    archer3 = new QRadioButton(N3);

    QGroupBox* box1 = new QGroupBox(ARCHERS_HEAD);
    box1->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 15));

    QHBoxLayout* arch_lout = new QHBoxLayout;
    arch_lout->addWidget(archer1);
    arch_lout->addWidget(archer2);
    arch_lout->addWidget(archer3);
    box1->setLayout(arch_lout);


    knight1 = new QRadioButton(N1);
    knight2 = new QRadioButton(N2);
    knight3 = new QRadioButton(N3);

    QGroupBox* box2 = new QGroupBox(KNIGHTS_HEAD);
    box2->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 15));

    QHBoxLayout* knig_lout = new QHBoxLayout;
    knig_lout->addWidget(knight1);
    knig_lout->addWidget(knight2);
    knig_lout->addWidget(knight3);
    box2->setLayout(knig_lout);

    machine1 = new QRadioButton(N1);
    machine2 = new QRadioButton(N2);
    machine3 = new QRadioButton(N3);

    QGroupBox* box3 = new QGroupBox(MACHINES_HEAD);
    box3->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 15));

    QHBoxLayout* mach_lout = new QHBoxLayout;
    mach_lout->addWidget(machine1);
    mach_lout->addWidget(machine2);
    mach_lout->addWidget(machine3);
    box3->setLayout(mach_lout);


    start_game = new QPushButton;
    QPixmap pix1(START_BUTTON);
    start_game->setIcon(pix1);
    start_game->setIconSize(pix1.size());
    start_game->setFixedSize(pix1.width(), pix1.height());

    close_window = new QPushButton;
    QPixmap pix4(EXIT_BUTTON);
    close_window->setIcon(pix4);
    close_window->setIconSize(pix4.size());
    close_window->setFixedSize(pix4.width(), pix4.height());

    QGridLayout* lo = new QGridLayout;
    lo->addWidget(box1, 0, 1);
    lo->addWidget(box2, 1, 1);
    lo->addWidget(box3, 2, 1);
    lo->addWidget(start_game, 3, 0);
    lo->addWidget(close_window, 3, 2);
    setLayout(lo);
    setModal(true);


    connect(archer1, SIGNAL(clicked()), this, SLOT(slot_archers_number()));
    connect(archer2, SIGNAL(clicked()), this, SLOT(slot_archers_number()));
    connect(archer3, SIGNAL(clicked()), this, SLOT(slot_archers_number()));

    connect(knight1, SIGNAL(clicked()), this, SLOT(slot_knights_number()));
    connect(knight2, SIGNAL(clicked()), this, SLOT(slot_knights_number()));
    connect(knight3, SIGNAL(clicked()), this, SLOT(slot_knights_number()));

    connect(machine1, SIGNAL(clicked()), this, SLOT(slot_machine_number()));
    connect(machine2, SIGNAL(clicked()), this, SLOT(slot_machine_number()));
    connect(machine3, SIGNAL(clicked()), this, SLOT(slot_machine_number()));

    connect(start_game, SIGNAL(clicked()), this, SLOT(slot_start_game()));
    connect(start_game, SIGNAL(clicked()), close_window, SIGNAL(clicked()));
    connect(close_window, SIGNAL(clicked()), this, SLOT(reject()));
    connect(this, SIGNAL(close_start_window()), st_wgt, SIGNAL(stop_play()));
    connect(this, SIGNAL(close_start_window()), st_wgt, SLOT(close()));
}


GameSettings::~GameSettings(){
    delete archer1;
    delete archer2;
    delete archer3;
    delete knight1;
    delete knight2;
    delete knight3;
    delete machine1;
    delete machine2;
    delete machine3;
    delete summer;
    delete wasteland;
    delete winter;
    delete start_game;
    delete close_window;
    delete wgt_wrn;
}



void GameSettings::slot_start_game(){
    if(get_n_arch() == 0 || get_n_knig() == 0 || get_n_mach() == 0){

        wgt_wrn = new QDialog;
        QPalette pal;
        QPixmap pix(INFORM_BACKGROUND);
        pal.setBrush(wgt_wrn->backgroundRole(), QBrush(pix));

        QLabel* lbl = new QLabel(STD_WRONG_CHS, wgt_wrn);
        QLabel* lbl1 = new QLabel(WARNING, wgt_wrn);

        lbl->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 15));
        lbl1->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 20));

        wgt_wrn->setWindowFlags(Qt::FramelessWindowHint);
        wgt_wrn->setPalette(pal);
        wgt_wrn->setModal(true);
        wgt_wrn->setFixedSize(pix.width(), pix.height());

        QPushButton* pb_ok = new QPushButton("&OK");
        pb_ok->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 10));
        QGridLayout* glo = new QGridLayout;
        glo->addWidget(lbl1, 0, 0, Qt::AlignCenter);
        glo->addWidget(lbl, 1, 0, Qt::AlignCenter);
        glo->addWidget(pb_ok, 2, 0, Qt::AlignCenter);
        wgt_wrn->setLayout(glo);

        QObject::connect(pb_ok, SIGNAL(clicked()), wgt_wrn, SLOT(reject()));
        wgt_wrn->show();
    }
    else{
        Field* field = new Field(0, get_n_arch(), get_n_knig(), get_n_mach());
        field->show();
        emit close_start_window();
    }
}


void GameSettings::slot_archers_number(){
    if(archer1->isChecked())
        set_n_arch(1);
    else if(archer2->isChecked())
        set_n_arch(2);
    else if(archer3->isChecked())
        set_n_arch(3);
}

void GameSettings::slot_knights_number(){
    if(knight1->isChecked())
        set_n_knig(1);
    else if(knight2->isChecked())
        set_n_knig(2);
    else if(knight3->isChecked())
        set_n_knig(3);
}

void GameSettings::slot_machine_number(){
    if(machine1->isChecked())
        set_n_mach(1);
    else if(machine2->isChecked())
        set_n_mach(2);
    else if(machine3->isChecked())
        set_n_mach(3);
}
