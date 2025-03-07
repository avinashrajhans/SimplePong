#include "Paddle.h"
#include <glm/gtc/matrix_transform.hpp>

extern glm::vec2 ballPos;
float paddleY{0.0f}; // Initialize at top of screen

Paddle::Paddle()
{
    glm::mat4 model{1.0f};
    model = glm::translate(model, glm::vec3(5.0f, 0.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.2f, 3.0f, 1.0f));

    m_shader.useProgram();
    m_shader.setMat4("model", model);
}

void Paddle::update()
{
    float moveSpeed = 5.0f;

    // Calculate new position
    if (paddleY > ballPos.y)
        paddleY -= moveSpeed;

    else if (paddleY < ballPos.y)
        paddleY += moveSpeed;
    
    // Clamp position between 0 and 450

    if (paddleY > 450.0f)
        paddleY = 450.0f;
    else if (paddleY < 0.0f)
        paddleY = 0.0f;
    // Update paddle position
    glm::mat4 model{1.0f};
    model = glm::translate(model, glm::vec3(5.0f, paddleY, 0.0f));
    model = glm::scale(model, glm::vec3(0.2f, 3.0f, 1.0f));

    m_shader.useProgram();
    m_shader.setMat4("model", model);
}