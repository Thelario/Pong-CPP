#include "Ball.h"

Ball::Ball()
{
    xPosInit = 400.0;
    yPosInit = 400.0;

    xPos = xPosInit;
    yPos = yPosInit;

    xSpeed = 0.025;
    ySpeed = 0.05;
}

void Ball::Draw()
{
    float centerY = (((yPos / 800.0f) * 2.0f) - 1.0f) * -1.0f;
    float centerX = (((xPos / 800.0f) * 2.0f) - 1.0f) * -1.0f;

    glBegin(GL_QUADS);
    glVertex2f(-0.015f + centerX, -0.015f + centerY);
    glVertex2f(-0.015f + centerX, 0.015f + centerY);
    glVertex2f(0.015f + centerX, 0.015f + centerY);
    glVertex2f(0.015f + centerX, -0.015f + centerY);
    glEnd();
}

void Ball::Move()
{
    xPos += xSpeed;
    yPos += ySpeed;
}

void Ball::CheckUpperLimit()
{
    if (yPos >= 800)
        ySpeed *= -1.f;
}

void Ball::CheckLowerLimit()
{
    if (yPos <= 0.0f)
        ySpeed *= -1.f;
}