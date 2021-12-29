#include "Player.h"

Player::Player()
{
	yPos = 0.0;
	xPos = 800;
}

void Player::Update()
{

}

void Player::Draw()
{
    // TODO: Refactor
    // I shouldn't be using a hardcoded integer there (instead I should have a reference to the engine or a global variable, or smth).
    // Currently doesn't work, it only increases or decreases its size.

    float center = (((yPos / 800.0f) * 2.0f) - 1.0f) * -1.0f;

    glBegin(GL_QUADS);
    glVertex2f(1.0f, -0.1f + center);
    glVertex2f(1.0f, 0.1f + center);
    glVertex2f(0.98f, 0.1f + center);
    glVertex2f(0.98f, -0.1f + center);
    glEnd();
}

void Player::Move(double yPos)
{
    this->yPos = yPos;
}