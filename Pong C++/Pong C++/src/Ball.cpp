#include "Ball.h"

Ball::Ball()
{

}

void Ball::Draw()
{
    glBegin(GL_QUADS);
    glVertex2f(-0.015f, -0.015f);
    glVertex2f(-0.015f, 0.015f);
    glVertex2f(0.015f, 0.015f);
    glVertex2f(0.015f, -0.015f);
    glEnd();
}