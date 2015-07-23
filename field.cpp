#include "field.h"
#include "fieldelement.h"
#include "sound_file.h"
#include "startwindow.h"
#include "unitinfo.h"
#include "turns_left_wnd.h"
#include "all_defines.h"


Field::Field(QWidget *parent, int n_arch, int n_knig, int n_mach) : QWidget(parent){
    QWidget* wgt = new QWidget(this);
    QPalette pal1 = wgt->palette();
    pal1.setColor(QPalette::Base, QColor(255, 255, 255, 0));
    wgt->setFixedSize(1350, 750);

    Sound* snd = new Sound(this, SOUND_GAME);

    QPixmap p(HUMAN_CURSOR);
    QCursor cur(p, 0, 0);
    setCursor(cur);

    whose_turn_wgt = new QPushButton;
    whose_turn_wgt->setFixedSize(97, 97);
    QPixmap pix_w(PALADIN_ICON);
    whose_turn_wgt->setIcon(pix_w);
    whose_turn_wgt->setIconSize(pix_w.size());

    scene = new BattleScene(30, 33, 930, 496, n_arch, n_knig, n_mach);
    scene->setBackgroundBrush(QPixmap(LANDSCAPE));

    end_turn  = new QPushButton;
    QPixmap pix(FINISH_TURN_BUTTON);
    end_turn->setIcon(pix);
    end_turn->setIconSize(pix.size());
    end_turn->setFixedSize(pix.width(), pix.height());

    quit  = new QPushButton;
    QPixmap pix1(EXIT_BUTTON);
    quit->setIcon(pix1);
    quit->setIconSize(pix1.size());
    quit->setFixedSize(pix1.width(), pix1.height());

    view = new FieldView;
    view->setScene(scene);
    view->setFixedSize(scene->width()+90, scene->height()+90);
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(QPixmap(FIELD_BACKGROUND)));
    setPalette(pal);


    UnitInfo* uinf = new UnitInfo(this, scene);
    MovesLeft* ml = new MovesLeft(this, scene);

    QGridLayout* qglt = new QGridLayout;
    qglt->setMargin(20);
    qglt->setSpacing(15);

    if(QApplication::desktop()->width() >= 1366){
        qglt->addWidget(ml, 0, 1, Qt::AlignCenter);
        qglt->addWidget(uinf, 1, 0, Qt::AlignTop);
        qglt->addWidget(whose_turn_wgt, 1, 0, Qt::AlignCenter);
        qglt->addWidget(quit, 2, 1, Qt::AlignRight);
        qglt->addWidget(view, 1, 1);
        qglt->addWidget(end_turn, 2, 0, Qt::AlignCenter);
        qglt->addWidget(snd, 2, 1, Qt::AlignCenter);
    }

    else if(QApplication::desktop()->width() < 1366){
        wgt->setFixedSize(1240, 960);
        qglt->addWidget(uinf, 0, 1, Qt::AlignRight);
        qglt->addWidget(ml, 0, 1, Qt::AlignBottom);
        qglt->addWidget(whose_turn_wgt, 0, 1, Qt::AlignLeft);
        qglt->addWidget(quit, 2, 2, Qt::AlignCenter);
        qglt->addWidget(view, 1, 1);
        qglt->addWidget(end_turn, 2, 0, Qt::AlignCenter);
        qglt->addWidget(snd, 2, 1, Qt::AlignCenter);
    }

    wgt->setLayout(qglt);

    QVBoxLayout* main_lo = new QVBoxLayout;
    main_lo->addWidget(wgt);
    setLayout(main_lo);

    setWindowState(Qt::WindowFullScreen);

    connect(scene, SIGNAL(signal_end_turn()), end_turn, SIGNAL(clicked()));
    connect(scene, SIGNAL(signal_dead_humans_army()), this, SLOT(slot_orcs_victory()));
    connect(scene, SIGNAL(signal_dead_orcs_army()), this, SLOT(slot_humans_victory()));
    connect(scene, SIGNAL(signal_change_current_unit_icon()), this, SLOT(slot_change_icon()));
    connect(scene, SIGNAL(signal_press_next_turn_button()), end_turn, SIGNAL(clicked()));
    connect(end_turn, SIGNAL(clicked()), scene, SIGNAL(signal_click_count()));
    connect(end_turn, SIGNAL(clicked()), scene, SIGNAL(signal_move_end()));
    connect(end_turn, SIGNAL(clicked()), scene, SLOT(slot_null_to_turns_summ()));
    connect(end_turn, SIGNAL(clicked()), this, SLOT(slot_change_cursor()));
    connect(end_turn, SIGNAL(clicked()), ml, SLOT(slot_update_turns_info()));
    connect(end_turn, SIGNAL(clicked()), uinf, SLOT(slot_clear_field()));
    connect(quit, SIGNAL(clicked()), snd->med_obj, SLOT(stop()));
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    connect(quit, SIGNAL(clicked()), this, SLOT(slot_start_window()));
}



void Field::slot_change_cursor(){
    if(scene->get_count() % 2 != 0){
        QPixmap p(HUMAN_CURSOR);
        QCursor cur(p, 0, 0);
        setCursor(cur);
    }
    else if(scene->get_count() % 2 == 0){
        QPixmap p(ORC_CURSOR);
        QCursor cur(p, 0, 0);
        setCursor(cur);
    }
}



void Field::slot_change_icon(){
    if(scene->get_count() == 1){
        QPixmap pixhh(PALADIN_ICON);
        whose_turn_wgt->setIcon(pixhh);
        whose_turn_wgt->setIconSize(pixhh.size());
    }
    else if(scene->get_count() == 2){
        QPixmap pixoh(OGRE_ICON);
        whose_turn_wgt->setIcon(pixoh);
        whose_turn_wgt->setIconSize(pixoh.size());
    }
    else if(scene->get_count() == 3){
        QPixmap pix1(ARCHER_ICON);
        whose_turn_wgt->setIcon(pix1);
        whose_turn_wgt->setIconSize(pix1.size());
    }
    else if(scene->get_count() == 4){
        QPixmap pix2(TROLL_ICON);
        whose_turn_wgt->setIcon(pix2);
        whose_turn_wgt->setIconSize(pix2.size());
    }
    else if(scene->get_count() == 5){
        QPixmap pix3(FOOTMAN_ICON);
        whose_turn_wgt->setIcon(pix3);
        whose_turn_wgt->setIconSize(pix3.size());
    }
    else if(scene->get_count() == 6){
        QPixmap pix4(GRUNT_ICON);
        whose_turn_wgt->setIcon(pix4);
        whose_turn_wgt->setIconSize(pix4.size());
    }
    else if(scene->get_count() == 7){
        QPixmap pix5(BALLISTA_ICON);
        whose_turn_wgt->setIcon(pix5);
        whose_turn_wgt->setIconSize(pix5.size());
    }
    else if(scene->get_count() == 8){
        QPixmap pix6(CATAPULT_ICON);
        whose_turn_wgt->setIcon(pix6);
        whose_turn_wgt->setIconSize(pix6.size());
    }
}



void Field::slot_start_window(){
    StartWindow* st_wnd = new StartWindow;
    st_wnd->show();
}



void Field::slot_orcs_victory(){
        vict_wgt = new QDialog;
        QPalette pal;
        QPixmap pix(INFORM_BACKGROUND);
        pal.setBrush(vict_wgt->backgroundRole(), QBrush(pix));

        QLabel* lbl = new QLabel("ORCS WIN");
        QLabel* lbl1 = new QLabel("CONGRATULATIONS!");
        lbl->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 13));
        lbl1->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 15));

        vict_wgt->setWindowFlags(Qt::FramelessWindowHint);
        vict_wgt->setPalette(pal);
        vict_wgt->setFixedSize(pix.width(), pix.height());
        vict_wgt->setModal(true);

        QPushButton* pb_ok = new QPushButton("&OK");
        pb_ok->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 10));

        QGridLayout* glo = new QGridLayout;
        glo->addWidget(lbl1, 0, 0, Qt::AlignCenter);
        glo->addWidget(lbl, 1, 0, Qt::AlignCenter);
        glo->addWidget(pb_ok, 2, 0, Qt::AlignCenter);
        vict_wgt->setLayout(glo);

        QObject::connect(pb_ok, SIGNAL(clicked()), vict_wgt, SLOT(reject()));
        connect(pb_ok, SIGNAL(clicked()), quit, SIGNAL(clicked()));
        vcs->get_Orescue();
        vict_wgt->show();
}



void Field::slot_humans_victory(){
        vict_wgt = new QDialog;
        QPalette pal;
        QPixmap pix(INFORM_BACKGROUND);
        pal.setBrush(vict_wgt->backgroundRole(), QBrush(pix));

        QLabel* lbl = new QLabel("HUMANS WIN");

        QLabel* lbl1 = new QLabel("CONGRATULATIONS!");
        lbl->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 13));
        lbl1->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 15));

        vict_wgt->setWindowFlags(Qt::FramelessWindowHint);
        vict_wgt->setPalette(pal);
        vict_wgt->setFixedSize(pix.width(), pix.height());
        vict_wgt->setModal(true);

        QPushButton* pb_ok = new QPushButton("&OK");
        pb_ok->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 10));

        QGridLayout* glo = new QGridLayout;
        glo->addWidget(lbl1, 0, 0, Qt::AlignCenter);
        glo->addWidget(lbl, 1, 0, Qt::AlignCenter);
        glo->addWidget(pb_ok, 2, 0, Qt::AlignCenter);
        vict_wgt->setLayout(glo);

        QObject::connect(pb_ok, SIGNAL(clicked()), vict_wgt, SLOT(reject()));
        connect(pb_ok, SIGNAL(clicked()), quit, SIGNAL(clicked()));
        vcs->get_Hrescue();
        vict_wgt->show();
}


Field::~Field(){
    delete scene;
    delete view;
    delete end_turn;
    delete whose_turn_wgt;
    delete quit;
    delete vict_wgt;
    delete vcs;
}
