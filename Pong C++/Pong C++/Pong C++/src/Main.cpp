#include <GLFW\glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 800, "Pong", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.1f);
        glVertex2f(-1.0f, 0.1f);
        glVertex2f(-0.98f, 0.1f);
        glVertex2f(-0.98f, -0.1f);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(1.0f, -0.1f);
        glVertex2f(1.0f, 0.1f);
        glVertex2f(0.98f, 0.1f);
        glVertex2f(0.98f, -0.1f);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(-0.015f, -0.015f);
        glVertex2f(-0.015f, 0.015f);
        glVertex2f(0.015f, 0.015f);
        glVertex2f(0.015f, -0.015f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}