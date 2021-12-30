#include "Enemy.h"

Enemy::Enemy()
{
    xPos = 0;
    yPos = 0;
    yCenter = 0;
}

void Enemy::Draw()
{
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.1f + yCenter);
    glVertex2f(-1.0f, 0.1f + yCenter);
    glVertex2f(-0.98f, 0.1f + yCenter);
    glVertex2f(-0.98f, -0.1f + yCenter);
    glEnd();
}

bool Enemy::CheckBallCollision(double ballX, double ballY)
{
    float ballYRecalculated = (((ballY / 800.0f) * 2.0f) - 1.0f) * -1.0f;

    if (ballX >= 790 && ballYRecalculated >= yCenter - 0.1f && ballYRecalculated <= yCenter + 0.1f)
        return true;

    return false;
}

void Enemy::Move(double ballY)
{
    this->yPos = ballY;
    this->yCenter = (((yPos / 800.0f) * 2.0f) - 1.0f) * -1.0f;
}