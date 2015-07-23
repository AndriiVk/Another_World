#include "tutorial.h"
#include "all_defines.h"
#include <QFile>

#define FILENAME       "tutorial.txt"
#define CANNOTOPENFILE "Sorry, cannot open file, maybe he was deleted!"
#define CLOSE          "CLOSE"


Tutorial::Tutorial(QWidget *wgt): QDialog(wgt){
    QLabel* text = new QLabel;
    text->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 15));

    QFile file(FILENAME);
    if(!file.open(QIODevice::ReadOnly)){
        text->setText(CANNOTOPENFILE);
    }
    else{
        char ch;
        QString str;

        file.open(QIODevice::ReadOnly);
        for(; !file.atEnd();){
            file.getChar(&ch);
            str += ch;
        }
        text->setText(str);
    }
    file.close();

    QPalette pal;
    QPixmap pix(TUTORIAL_BACKGROUND);
    pal.setBrush(this->backgroundRole(), QBrush(pix));
    setPalette(pal);
    setAutoFillBackground(true);

    QScrollArea* sa = new QScrollArea;
    sa->setFixedSize(1000, 420);
    sa->setWidget(text);

    QPushButton* close = new QPushButton(CLOSE);
    close->setFont(QFont(QFontDatabase::applicationFontFamilies(0).first(), 20));

    QGridLayout* vbl = new QGridLayout;
    vbl->addWidget(sa, 0, 0, Qt::AlignCenter);
    vbl->addWidget(close, 1, 0, Qt::AlignCenter);

    setFixedSize(1010, 500);
    setModal(true);
    setWindowFlags(Qt::FramelessWindowHint);
    this->setLayout(vbl);

    QObject::connect(close, SIGNAL(clicked()), this, SLOT(reject()));
}
