#pragma once

#include <GLFW\glfw3.h>

class Ball
{
public:
	double xPos;
	double yPos;
private:
	double xPosInit;
	double yPosInit;

	double xSpeed;
	double ySpeed;

	float xCenter;
	float yCenter;
public:
	Ball();

	void Draw();
	void Move();
	void CheckLimits();
	bool CheckGameEnded();
	void ChangeXSpeed();
};