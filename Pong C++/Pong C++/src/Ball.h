#pragma once

#include <GLFW\glfw3.h>

class Ball
{
private:
	double xPos;
	double yPos;

	double xPosInit;
	double yPosInit;

	double xSpeed;
	double ySpeed;
public:
	Ball();

	void Draw();
	void Move();
	void CheckUpperLimit();
	void CheckLowerLimit();
};