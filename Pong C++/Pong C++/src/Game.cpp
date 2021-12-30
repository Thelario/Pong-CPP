#include "Game.h"

#include <iostream>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    Game* game = (Game*)glfwGetWindowUserPointer(window);
    game->my = ypos;
}

GLFWwindow* Game::Start(int windowX, int windowY, const char *windowName)
{
    /* Initialize the library */
    if (!glfwInit())
        return nullptr;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(windowX, windowY, windowName, NULL, NULL);
    if (!window)
        return nullptr;

    player = Player();
    ball = Ball();
    enemy = Enemy();

    return window;
}

void Game::Loop()
{
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Setting the callbacks
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        Input();

        Logic();

        Draw();
    }
}

void Game::Close()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Game::Input()
{
    // Check for mouse position (only position in the y axis)
    double yPos;
    GetMouseYPosition(yPos);
    player.Move(yPos);
     
    // Check for mouse click (to restart the game)
}

void Game::Logic()
{
    ball.Move();

    enemy.Move(ball.yPos);

    ball.CheckLimits();

    if (ball.CheckGameEnded())
    {
        ball = Ball();
        return;
    }
    
    if (player.CheckBallCollision(ball.xPos, ball.yPos))
        ball.ChangeXSpeed();

    if (enemy.CheckBallCollision(ball.xPos, ball.yPos))
        ball.ChangeXSpeed();
}

void Game::Draw()
{
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    enemy.Draw(); // Draw left paddle

    player.Draw(); // Draw right paddle
    
    ball.Draw(); // Draw ball

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
}

void Game::GetMouseYPosition(double& y)
{
    y = my;
}