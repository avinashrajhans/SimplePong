#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Game.h"
// #include <memory>
void processInput(GLFWwindow *win)
{
    if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(win, true);
}

void frameBufferSizeCallback(GLFWwindow *win, int width, int height)
{
    glViewport(0, 0, width, height);
}



int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *win = glfwCreateWindow(800, 600, "My Window", nullptr, nullptr);

    if (!win)
    {
        std::cerr << "Window Creation Failed\n";
        glfwTerminate();
    }

    glfwMakeContextCurrent(win);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "GLAD Loading Failed\n";
        glfwDestroyWindow(win);
        glfwTerminate();
    }

    Game game{win};
    glfwSetFramebufferSizeCallback(win, frameBufferSizeCallback);
    
    // glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // TSeries.textLoading();
    // TSeries.loadCharacters();
    while (!glfwWindowShouldClose(win))
    {
        processInput(win);

        glClearColor(0.0, 0.6, 0.6, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        game.render();
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    glfwDestroyWindow(win);
    glfwTerminate();
}