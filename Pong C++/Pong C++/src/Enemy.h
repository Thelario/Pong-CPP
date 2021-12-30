#pragma once

#include <GLFW\glfw3.h>

class Enemy
{
private:
	float yCenter;
	float xPos;
	float yPos;
public:
	Enemy();

	void Draw();
	void Move(double ballY);
	bool CheckBallCollision(double ballX, double ballY);
};