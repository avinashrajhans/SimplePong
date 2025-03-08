#include "LeftPaddle.h"
#include <glm/gtc/matrix_transform.hpp>

extern glm::vec2 ballPos;
float leftPaddleY{0.0f}; // Initialize at top of screen

LeftPaddle::LeftPaddle()
{
    glm::mat4 model{1.0f};
    model = glm::translate(model, glm::vec3(5.0f, 0.0f, 0.0f));
    model = glm::scale(model, glm::vec3(0.2f, 3.0f, 1.0f));

    m_shader.useProgram();
    m_shader.setMat4("model", model);
}

void LeftPaddle::update()
{
    float moveSpeed = 5.0f;

    // Calculate new position
    if (leftPaddleY > ballPos.y)
        leftPaddleY -= moveSpeed;

    else if (leftPaddleY < ballPos.y)
        leftPaddleY += moveSpeed;
    
    // Clamp position between 0 and 450

    if (leftPaddleY > 450.0f)
        leftPaddleY = 450.0f;
    else if (leftPaddleY < 0.0f)
        leftPaddleY = 0.0f;
    // Update paddle position
    glm::mat4 model{1.0f};
    model = glm::translate(model, glm::vec3(5.0f, leftPaddleY, 0.0f));
    model = glm::scale(model, glm::vec3(0.2f, 3.0f, 1.0f));

    m_shader.useProgram();
    m_shader.setMat4("model", model);
}