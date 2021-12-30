#pragma once

#include <GLFW\glfw3.h>

#include "Player.h"
#include "Ball.h"
#include "Enemy.h"

class Game
{
private:
	GLFWwindow *window;
	Player player;
	Ball ball;
	Enemy enemy;
public:
	double my;
public:
	GLFWwindow* Start(int windowX, int windowY, const char* windowName);
	void Loop();
	void Close();
	void Input();
	void Logic();
	void Draw();
	void GetMouseYPosition(double& y);
};