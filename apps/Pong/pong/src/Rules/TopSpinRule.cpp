#include "TopSpinRule.h"


TopSpinRule::TopSpinRule(GameElements * gameElements, string name):BasicRules(gameElements,name)
{
	//runTime = -1;
}

void TopSpinRule::begin()
{
	BasicRules::begin();
}

void TopSpinRule::end()
{
	BasicRules::end();
}

void TopSpinRule::applyRules()
{
	

	for (auto&& ball : gameElements->balls) {
		//move ball
		ball->velocity.y = ball->velocity.y + ball->velocity.y  * ball->getSpin();
		ball->setSpin(ball->getSpin()*0.97);
		ball->update();

		//wall top
		if (ball->position.y - ball->radius <= 0) {
			ball->velocity.x = ball->velocity.x + (ball->velocity.x * ball->getSpin());
		}
		//wall bottom
		else if (ball->position.y + ball->radius >= gameElements->getHeigth()) {
			ball->velocity.x = ball->velocity.x + (ball->velocity.x  * ball->getSpin());
		}

		//check paddle and/or wall hit
		if (!paddleHittest(ball)) {
			wallHittest(ball);
		}
		else
		{

			if (gameElements->paddleLeft.isHit(*ball)) {
				ball->setSpin(ofMap(gameElements->paddleLeft.getSpeed(), -10, 10, -5, 5));
			}
			if (gameElements->paddleRight.isHit(*ball)) {
				ball->setSpin(ofMap(gameElements->paddleRight.getSpeed(), -10, 10, -5, 5));
			}
		}
	}
}
