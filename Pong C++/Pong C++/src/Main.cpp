#include "Engine.h"

int main(void)
{
    Engine engine;

    GLFWwindow* window = engine.Start(800, 800, "Pong");
    if (window == nullptr)
    {
        engine.Close();
        return -1;
    }

    engine.Loop();

    engine.Close();
    return 0;
}