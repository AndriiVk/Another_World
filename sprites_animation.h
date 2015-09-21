#ifndef SPRITES_ANIMATION_H
#define SPRITES_ANIMATION_H

#include "warrior.h"

class Sprite
{
public:
    Sprite(QPixmap pix);
    QPoint pos() const;
    void draw(QPainter* painter);
    void nextFrame();

private:
    QPixmap* mSpriteImage;
    int mCurrentFrame;
    QPoint mPos;
    int mXDir;

};

#endif // SPRITES_ANIMATION_H
