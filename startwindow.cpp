#include "startwindow.h"
#include "gamesettings.h"
#include "tutorial.h"
#include "sound_file.h"
#include "all_defines.h"

#define START    "START GAME"
#define SETTINGS "ARMY SETTINGS"
#define TUTORIAL "TUTORIAL"
#define QUIT     "QUIT"


StartWindow::StartWindow(QWidget *wgt): QWidget(wgt){
    QFontDatabase::addApplicationFont(FONT);

    QWidget* main_wgt = new QWidget(this);
    QPalette pal1 = main_wgt->palette();
    pal1.setColor(QPalette::Base, QColor(255, 255, 255, 0));
    main_wgt->setFixedSize(1350, 750);

    QLabel* lbl1 = new QLabel(START, this);
    QLabel* lbl2 = new QLabel(SETTINGS, this);
    QLabel* lbl3 = new QLabel(TUTORIAL, this);
    QLabel* lbl4 = new QLabel(QUIT, this);
    lbl1->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 25));
    lbl2->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 25));
    lbl3->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 25));
    lbl4->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 25));

    QPushButton* start_game = new QPushButton;
    QPixmap pix1(START_BUTTON);
    start_game->setIcon(pix1);
    start_game->setIconSize(pix1.size());
    start_game->setFixedSize(pix1.width(), pix1.height());

    QPushButton* tutorial_game = new QPushButton;
    QPixmap pix2(TUTORIAL_BUTTON);
    tutorial_game->setIcon(pix2);
    tutorial_game->setIconSize(pix2.size());
    tutorial_game->setFixedSize(pix2.width(), pix2.height());

    QPushButton* settings_game = new QPushButton;
    QPixmap pix3(SETTINGS_BUTTON);
    settings_game->setIcon(pix3);
    settings_game->setIconSize(pix3.size());
    settings_game->setFixedSize(pix3.width(), pix3.height());

    QPushButton* quit_game = new QPushButton;
    QPixmap pix4(EXIT_BUTTON);
    quit_game->setIcon(pix4);
    quit_game->setIconSize(pix4.size());
    quit_game->setFixedSize(pix4.width(), pix4.height());

    snd = new Sound(this, SOUND_START);

    setAutoFillBackground(true);
    setWindowState(Qt::WindowFullScreen);
    setWindowFlags(Qt::FramelessWindowHint);

    QGridLayout* vbl = new QGridLayout;
    QPalette pal;

    if(QApplication::desktop()->width() == 1366){
        QPixmap pix_1(START_SCREEN_1366);
        pal.setBrush(this->backgroundRole(), QBrush(pix_1));
        setPalette(pal);
        vbl->setColumnMinimumWidth(2, 750);
        vbl->setRowMinimumHeight(0, 250);
        vbl->setSpacing(15);
        vbl->setMargin(50);
        vbl->addWidget(lbl1, 1, 1, Qt::AlignLeft);
        vbl->addWidget(lbl2, 2, 1, Qt::AlignLeft);
        vbl->addWidget(lbl3, 3, 1, Qt::AlignLeft);
        vbl->addWidget(lbl4, 4, 1, Qt::AlignLeft);
        vbl->addWidget(start_game,    1, 0, Qt::AlignCenter);
        vbl->addWidget(settings_game, 2, 0, Qt::AlignCenter);
        vbl->addWidget(tutorial_game, 3, 0, Qt::AlignCenter);
        vbl->addWidget(quit_game,     4, 0, Qt::AlignCenter);
        vbl->addWidget(snd,           5, 3, Qt::AlignRight);
    }
    else if(QApplication::desktop()->width() < 1366){
        QPixmap pix_1(START_SCREEN_L1366);
        pal.setBrush(this->backgroundRole(), QBrush(pix_1));
        setPalette(pal);
        main_wgt->setFixedSize(1240, 960);
        vbl->setColumnMinimumWidth(2, 700);
        vbl->setRowMinimumHeight(0, 250);
        vbl->setSpacing(15);
        vbl->setMargin(50);
        vbl->addWidget(lbl1, 1, 1, Qt::AlignLeft);
        vbl->addWidget(lbl2, 2, 1, Qt::AlignLeft);
        vbl->addWidget(lbl3, 3, 1, Qt::AlignLeft);
        vbl->addWidget(lbl4, 4, 1, Qt::AlignLeft);
        vbl->addWidget(start_game,    1, 0, Qt::AlignCenter);
        vbl->addWidget(settings_game, 2, 0, Qt::AlignCenter);
        vbl->addWidget(tutorial_game, 3, 0, Qt::AlignCenter);
        vbl->addWidget(quit_game,     4, 0, Qt::AlignCenter);
        vbl->addWidget(snd,           5, 3, Qt::AlignRight);
    }
    else if(QApplication::desktop()->width() > 1366){
        QPixmap pix_3(START_SCREEN_U1366);
        pal.setBrush(this->backgroundRole(), QBrush(pix_3));
        setPalette(pal);
        vbl->setColumnMinimumWidth(2, 750);
        vbl->setRowMinimumHeight(0, 250);
        vbl->setSpacing(15);
        vbl->setMargin(50);
        vbl->addWidget(lbl1, 1, 1, Qt::AlignLeft);
        vbl->addWidget(lbl2, 2, 1, Qt::AlignLeft);
        vbl->addWidget(lbl3, 3, 1, Qt::AlignLeft);
        vbl->addWidget(lbl4, 4, 1, Qt::AlignLeft);
        vbl->addWidget(start_game,    1, 0, Qt::AlignCenter);
        vbl->addWidget(settings_game, 2, 0, Qt::AlignCenter);
        vbl->addWidget(tutorial_game, 3, 0, Qt::AlignCenter);
        vbl->addWidget(quit_game,     4, 0, Qt::AlignCenter);
        vbl->addWidget(snd,           5, 3, Qt::AlignRight);
    }


    main_wgt->setLayout(vbl);

    QVBoxLayout* main_lo = new QVBoxLayout;
    main_lo->addWidget(main_wgt);
    setLayout(main_lo);

    QPixmap p(START_MENU_CURSOR);
    QCursor cur(p, 0, 0);
    setCursor(cur);

    connect(start_game, SIGNAL(clicked()), this, SLOT(slot_start_game()));
    connect(start_game, SIGNAL(clicked()), snd->med_obj, SLOT(stop()));
    connect(start_game, SIGNAL(clicked()), this, SLOT(close()));
    connect(settings_game, SIGNAL(clicked()), this, SLOT(slot_settings_game()));
    connect(tutorial_game, SIGNAL(clicked()), this, SLOT(slot_show_tutorial()));
    connect(quit_game, SIGNAL(clicked()), this, SLOT(close()));
    connect(this, SIGNAL(stop_play()), snd->med_obj, SLOT(stop()));
}



void StartWindow::slot_start_game(){
    Field* field = new Field(0, 3, 2, 1);
    field->show();
}


void StartWindow::slot_settings_game(){
    GameSettings* sttngs = new GameSettings(0, this);
    sttngs->show();
}


void StartWindow::slot_show_tutorial(){
    Tutorial* tutor = new Tutorial;
    tutor->show();
}
