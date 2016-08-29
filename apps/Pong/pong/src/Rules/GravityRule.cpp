#include "GravityRule.h"



GravityRule::GravityRule(GameElements * gameElements, string name):BasicRules(gameElements,name)
{
	//runTime = -1;
}

void GravityRule::begin()
{
	BasicRules::begin();
}

void GravityRule::end()
{
	BasicRules::end();
}

void GravityRule::applyRules()
{
	
    Ball* ball = &gameElements->ball;
		//move ball
		ball->velocity.y = ball->velocity.y + 0.25;
		ball->update();

		//check paddle and/or wall hit
		if (!paddleHittest(ball)) {
			wallHittest(ball);
		}
		else
		{
			ball->velocity.y *= 2;
		}
	
}
