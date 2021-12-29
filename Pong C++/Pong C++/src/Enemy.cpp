#include "Enemy.h"

Enemy::Enemy()
{

}

void Enemy::Draw()
{
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(-1.0f, 0.1f);
    glVertex2f(-0.98f, 0.1f);
    glVertex2f(-0.98f, -0.1f);
    glEnd();
}