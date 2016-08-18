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
BasicRules::BasicRules(GameElements* gameElements, string name):AbstractRules(gameElements,name) {
    
}



void BasicRules::update() {
    for(auto&& ball : gameElements->balls){
        //move ball
        ball->update();
        
        //check paddle and/or wall hit
        if (!paddleHittest(ball)){
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
        return true;
    }else if (gameElements->paddleRight.isHit(*ball)) {
        ball->velocity.y = gameElements->paddleRight.getHitzone(*ball);
        ball->velocity.x *= -1;
        return true;
    }
    return false;
}

/**
 * hittest between balls and walls, update score
 */
void BasicRules::wallHittest(Ball* ball){
    //wall left
    if (ball->position.x - ball->radius <= 0) {
        ball->position = ofVec2f( gameElements->getWidth()/2, gameElements->getHeigth()/2);
        gameElements->increasePoints(2);
    }
    //wall right
    else if (ball->position.x + ball->radius >= gameElements->getWidth()) {
        ball->position = ofVec2f( gameElements->getWidth()/2, gameElements->getHeigth()/2);
        gameElements->increasePoints(1);
    }
    
    //wall top
    else if (ball->position.y - ball->radius <= 0) {
        ball->velocity.y *= -1;
    }
    //wall bottom
    else if (ball->position.y + ball->radius >= gameElements->getHeigth()) {
        ball->velocity.y *= -1;
    }
}