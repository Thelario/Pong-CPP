#pragma once

#include "vec2.h"

class Ball
{
public:
	vec2 position;
	vec2 speed;

	Ball();
	~Ball();

	void CheckHitLeftPaddle(float paddleY);
	void CheckHitRightPaddle(float paddleY);
};