#ifndef BALL_H
#define BALL_H
#include "Sprite.h"

class Ball: public Sprite
{
    public:
    // Ball(); // Add constructor
    void renderBall();

    private:
    float m_velocityX{10.0f};
    float m_velocityY{7.0f};
    const float SCREEN_WIDTH{800.0f};
    const float SCREEN_HEIGHT{600.0f};
};

#endif