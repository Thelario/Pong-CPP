#include "Engine.h"

#include <iostream>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    Engine* engine = (Engine*)glfwGetWindowUserPointer(window);
    engine->my = ypos;
}

GLFWwindow* Engine::Start(int windowX, int windowY, const char *windowName)
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

void Engine::Loop()
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

void Engine::Close()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Engine::Input()
{
    // Check for mouse position (only position in the y axis)
    double yPos;
    GetMouseYPosition(yPos);
    player.Move(yPos);
     
    // Check for mouse click (to restart the game)
    // Check for scape button, to close the game
}

void Engine::Logic()
{
    // Move the ball
    ball.Move();
    ball.CheckLowerLimit();
    ball.CheckUpperLimit();
    
    // Bounce the ball
    // Move the enemy according to ball
    // Move player according to input
    // Ball bounces
    // Ball goes outside
}

void Engine::Draw()
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

void Engine::GetMouseYPosition(double& y)
{
    y = my;
}