#include "Ball.h"

Ball::Ball()
{
    xPosInit = 400.0;
    yPosInit = 400.0;

    xPos = xPosInit;
    yPos = yPosInit;

    xSpeed = 0.05;
    ySpeed = 0.1;

    yCenter = (((yPos / 800.0f) * 2.0f) - 1.0f) * -1.0f;
    xCenter = (((xPos / 800.0f) * 2.0f) - 1.0f) * -1.0f;
}

void Ball::Draw()
{
    glBegin(GL_QUADS);
    glVertex2f(-0.015f + xCenter, -0.015f + yCenter);
    glVertex2f(-0.015f + xCenter, 0.015f + yCenter);
    glVertex2f(0.015f + xCenter, 0.015f + yCenter);
    glVertex2f(0.015f + xCenter, -0.015f + yCenter);
    glEnd();
}

void Ball::Move()
{
    xPos += xSpeed;
    yPos += ySpeed;

    yCenter = (((yPos / 800.0f) * 2.0f) - 1.0f) * -1.0f;
    xCenter = (((xPos / 800.0f) * 2.0f) - 1.0f) * -1.0f;
}

void Ball::CheckLimits()
{
    if (yPos >= 800)
    {
        ySpeed *= -1.f;
        return;
    }

    if (yPos <= 0.0f)
        ySpeed *= -1.f;
}

void Ball::ChangeXSpeed()
{
    xSpeed *= -1.0f;
}