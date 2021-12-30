#pragma once

#include <GLFW\glfw3.h>
#include <iostream>

class Player
{
private:
	int yPos;
	int xPos;
	float height;
	float width;
	float yCenter;
public:
	Player();

	void Draw();
	void Move(double yPos);
	bool CheckBallCollision(double ballX, double ballY);
};