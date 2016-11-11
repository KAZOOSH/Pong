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
	Ball* ball = &BasicRules::gameElements->ball;
		float factor = 0;
		//move ball
		if (ball->getinitialSpin() != 0) {
			factor = sin(PI * ((double)ball->getSpin() / (double)ball->getinitialSpin()));
		}
		ofLog(OF_LOG_NOTICE, "factor " + ofToString(factor));

		ball->velocity.y += ofMap(ball->getSpin() * factor, -100, 100, -3, 3, true);
		ball->setSpin(ball->getSpin()*0.97);
		ball->update();



		//check paddle and/or wall hit
		if (!paddleHittest(ball)) {
			wallHittest(ball);
			//wall top
			if (ball->position.y - ball->radius <= 0) {
				ball->velocity.x += ofMap(ball->getSpin(), -100, 100, -5, 5, true);
			}
			//wall bottom
			else if (ball->position.y + ball->radius >= gameElements->getHeigth()) {
				ball->velocity.x += ofMap(ball->getSpin(), -100, 100, -5, 5, true);
			}
		}
		else
		{
			int speed;
			if (gameElements->paddleLeft.isHit(*ball)) {
				speed = gameElements->paddleLeft.getSpeed();
			}
			else if (gameElements->paddleRight.isHit(*ball)) {
				speed = gameElements->paddleRight.getSpeed();
			}
			ball->setSpin(speed);
			ball->setInitialSpin(speed);

			if (speed > 2 || speed < -2) {
				ball->velocity.y = ofMap(speed, -100, 100, -5, 5, true);
			}
			
		}
	
}
