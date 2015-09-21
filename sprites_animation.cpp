#include "sprites_animation.h"

Sprite::Sprite(QPixmap pix):mPos(0,0),mCurrentFrame(0){
    mSpriteImage = new QPixmap(pix);
}

void Sprite::draw(QPainter* painter){
    painter->drawPixmap (mPos.x(),mPos.y(), *mSpriteImage, mCurrentFrame, 0, 100,100 );
}

QPoint Sprite::pos() const{
    return mPos;
}

void Sprite::nextFrame(){
    //following variable keeps track which
    //frame to show from sprite sheet
    mCurrentFrame += 100;
    if (mCurrentFrame >= 500 )
        mCurrentFrame = 0;
    mPos.setX(mPos.x() + 10 );
}
