#include "Player.h"

Player::Player()
{
	yPos = 0;
	xPos = ((0.99  + 1.0) / 2.0) * 800.0; // 796
    height = 0.2f;
    width = 0.02f;
    yCenter = (((yPos / 800.0f) * 2.0f) - 1.0f) * -1.0f;
}

void Player::Draw()
{
    // TODO: Refactor
    // I shouldn't be using a hardcoded integer there (instead I should have a reference to the engine or a global variable, or smth).

    glBegin(GL_QUADS);
    glVertex2f(1.0f, -0.1f + yCenter);
    glVertex2f(1.0f, 0.1f + yCenter);
    glVertex2f(0.98f, 0.1f + yCenter);
    glVertex2f(0.98f, -0.1f + yCenter);
    glEnd();
}

void Player::Move(double yPos)
{
    this->yPos = yPos;
    this->yCenter = (((yPos / 800.0f) * 2.0f) - 1.0f) * -1.0f;
}

bool Player::CheckBallCollision(double ballX, double ballY)
{
    float ballYRecalculated = (((ballY / 800.0f) * 2.0f) - 1.0f) * -1.0f;

    if (ballX <= 10 && ballYRecalculated >= yCenter - 0.1f && ballYRecalculated <= yCenter + 0.1f)
        return true;

    return false;
}