#include "Game.h"
#include <GLFW/glfw3.h>
#include <string>

Game::Game(GLFWwindow* window)
:m_leftPaddle{}
,m_rightPaddle{window}
,m_text{}
,m_ball{}
,m_state{GameState::StartScreen}
,m_window{window}
,m_scorePlayer{0}
,m_scoreCPU{0}
{
}

void Game::render()
{
    // Get ball position from Ball class
    extern glm::vec2 ballPos;

    switch(m_state)
    {
        case GameState::StartScreen:
            m_text.renderText("Press Space to start", 250, 300);
            if (glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS)
            {
                m_state = GameState::PlayScreen;
            }
            break;

        case GameState::PlayScreen:
            m_text.renderText("CPU", 175, 50);
            m_text.renderText("You", 525, 50);
            m_text.renderText("-", 375, 100);
            m_text.renderText(std::to_string(m_scoreCPU), 195, 100);
            m_text.renderText(std::to_string(m_scorePlayer), 555, 100);

            // Check for scoring
            if (ballPos.x <= -20.0f)
            {
                m_scorePlayer++;
                ballPos = glm::vec2(400.0f, 300.0f);
                if (m_scorePlayer >= 5)
                    m_state = GameState::EndScreen;
            }
            else if (ballPos.x >= 800.0f)
            {
                m_scoreCPU++;
                ballPos = glm::vec2(400.0f, 300.0f);
                if (m_scoreCPU >= 5)
                    m_state = GameState::EndScreen;
            }

            m_leftPaddle.draw();
            m_leftPaddle.update();
            m_rightPaddle.renderPaddle();
            m_rightPaddle.draw();
            m_ball.renderBall();
            m_ball.draw();
            break;

        case GameState::EndScreen:
            if (m_scorePlayer >= 5)
                m_text.renderText("You Win!", 300, 300);
            else
                m_text.renderText("CPU Won!", 300, 300);
                m_text.renderText("Press Esc to exit", 200, 350);
            break;
    }
}