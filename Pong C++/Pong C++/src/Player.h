#pragma once

#include <GLFW\glfw3.h>
#include <iostream>

class Player
{
private:
	double yPos;
	double xPos;
public:
	Player();

	void Update();
	void Draw();
	void Move(double yPos);
};