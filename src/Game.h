#ifndef GAME_H
#define GAME_H
#include <GLFW/glfw3.h>
#include "LeftPaddle.h"
#include "RightPaddle.h"
#include "Text.h"
#include "Ball.h"

enum GameState
{
    StartScreen,
    PlayScreen,
    EndScreen,
};

class Game
{
public:
    Game(GLFWwindow *window);
    void render();

private:
    LeftPaddle m_leftPaddle;
    RightPaddle m_rightPaddle;
    Text m_text;
    Ball m_ball;
    GameState m_state;
    GLFWwindow* m_window;
    int m_scorePlayer;
    int m_scoreCPU;
};

#endif