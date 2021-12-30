#include "Game.h"

int main(void)
{
    Game game;

    GLFWwindow* window = game.Start(800, 800, "Pong");
    if (window == nullptr)
    {
        game.Close();
        return -1;
    }

    game.Loop();

    game.Close();
    return 0;
}