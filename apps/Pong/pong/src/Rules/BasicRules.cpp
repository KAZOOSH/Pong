/*
 *  BasicRules.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "BasicRules.h"


//------------------------------------------------------------------
BasicRules::BasicRules(GameElements* gameElements, string name,int runtime_):AbstractRules(gameElements,name) {
    runTime = runtime_;
}



void BasicRules::applyRules() {
		for (auto&& ball : gameElements->balls) {
			//move ball
			ball->update();

			//check paddle and/or wall hit
			if (!paddleHittest(ball)) {
				wallHittest(ball);
			}
		}
    
    
}

/**
 * hittest between balls and paddle, update ball direction
 */
bool BasicRules::paddleHittest(Ball* ball){
    if (gameElements->paddleLeft.isHit(*ball)) {
        ball->velocity.y = gameElements->paddleLeft.getHitzone(*ball);
        ball->velocity.x *= -1;
        gameElements->notifyGameEvent(CONTACT_PADDLE1);
        return true;
    }else if (gameElements->paddleRight.isHit(*ball)) {
        ball->velocity.y = gameElements->paddleRight.getHitzone(*ball);
        ball->velocity.x *= -1;
        gameElements->notifyGameEvent(CONTACT_PADDLE2);
        return true;
    }
    return false;
}

/**
 * hittest between balls and walls, update score
 */
void BasicRules::wallHittest(Ball* ball){
    
    //wall left, player 2 gets point
    if (ball->position.x - ball->radius <= 0) {
        ball->position = ofVec2f( gameElements->getWidth()/2, gameElements->getHeigth()/2);
        gameElements->increasePoints(2);
        gameElements->notifyGameEvent(BALL_OUT_P1);
    }
    //wall right, player 1 gets point
    else if (ball->position.x + ball->radius >= gameElements->getWidth()) {
        ball->position = ofVec2f( gameElements->getWidth()/2, gameElements->getHeigth()/2);
        gameElements->increasePoints(1);
        gameElements->notifyGameEvent(BALL_OUT_P2);
    }
    
    //wall top
    else if (ball->position.y - ball->radius <= 0) {
        ball->velocity.y *= -1;
		ball->position.y = ball->radius;
        gameElements->notifyGameEvent(CONTACT_WALL);
    }
    //wall bottom
    else if (ball->position.y + ball->radius >= gameElements->getHeigth()) {
        ball->velocity.y *= -1;
		ball->position.y = gameElements->getHeigth() - ball->radius;
        gameElements->notifyGameEvent(CONTACT_WALL);
    }
}