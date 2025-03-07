#ifndef PADDLE_H
#define PADDLE_H
#include "Sprite.h"

class Paddle : public Sprite
{
public:
    Paddle();
    void update(); // Add this method
};

#endif