#ifndef RIGHT_PADDLE_H
#define RIGHT_PADDLE_H
#include <GLFW/glfw3.h>
#include "Paddle.h"

class RightPaddle : public Sprite
{
public:
    RightPaddle(GLFWwindow *window);
    void renderPaddle();
private:
    GLFWwindow *m_window;
};

#endif