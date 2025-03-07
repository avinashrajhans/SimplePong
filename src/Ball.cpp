#include "Ball.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream> // Add this include

extern float paddleY;
extern double paddlePositionY;

glm::vec2 ballPos{0.0f, 275.0f};

// Ball::Ball()
// {
// //     ballPos.x = 0.0f;
// //     ballPos.y = 275.0f;
// }

void Ball::renderBall()
{
    m_shader.useProgram();
    glm::mat4 model{1.0};

    // Update position
    ballPos.x += m_velocityX;
    ballPos.y += m_velocityY;

    // Left paddle collision (assuming paddle width is 0.2f units * scale)
    if (ballPos.x <= 5.0f + 10.0f &&     // Check if ball is at paddle's X position (5.0f) plus some offset
        ballPos.y >= paddleY && // paddle height is 3.0f units (scaled)
        ballPos.y <= paddleY + 150.0f)
    {
        m_velocityX = -m_velocityX;
    }
    // Right paddle collision (ball size is 0.4f units)
    else if (ballPos.x + 20.0f >= 785.0f &&
             ballPos.y <= paddlePositionY + 150.0f &&
             ballPos.y >= paddlePositionY)
    {
        m_velocityX = -m_velocityX;
    }

    if (ballPos.y <= 0.0f || ballPos.y >= SCREEN_HEIGHT)
    {
        m_velocityY = -m_velocityY;
    }

    model = glm::translate(model, glm::vec3(ballPos.x, ballPos.y, 0.0f));
    model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.0f));
    m_shader.setMat4("model", model);
}