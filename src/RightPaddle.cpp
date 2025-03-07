#include <glad/glad.h>
#include "RightPaddle.h"
#include <glm/gtc/matrix_transform.hpp>

double paddlePositionY{200.0};

void mouse_callback(GLFWwindow *win, double xpos, double ypos)
{
    static bool firstMouse{true};
    static double lastFrameY{0.0};
    if (firstMouse)
    {
        lastFrameY = ypos;
        firstMouse = false;
    }

    double deltaValue = ypos - lastFrameY;

    // static double initialPosY{0.0};

    paddlePositionY += deltaValue;
    if (paddlePositionY < 0.0)
        paddlePositionY = 0.0;

    else if (paddlePositionY > 450.0)
        paddlePositionY = 450.0;
    lastFrameY = ypos;
}

RightPaddle::RightPaddle(GLFWwindow *window)
    : m_window{window}
{
    glfwSetCursorPosCallback(m_window, mouse_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void RightPaddle::renderPaddle()
{
    glm::mat4 model{1.0f};

    model = glm::translate(model, glm::vec3(785.0f, paddlePositionY, 0.0f));
    model = glm::scale(model, glm::vec3(0.2f, 3.0f, 1.0f));

    m_shader.useProgram();
    m_shader.setMat4("model", model);
}