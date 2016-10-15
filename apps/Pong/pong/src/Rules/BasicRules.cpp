/*
 *  BasicRules.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "BasicRules.h"


//------------------------------------------------------------------
BasicRules::BasicRules(GameElements* gameElements, string name,int durationMode_):AbstractRules(gameElements,name) {
    durationMode = durationMode_;
}

void BasicRules::begin(){
    AbstractRules::begin();
    //set minimum ball velocity
    gameElements->ball.velocity.x > 0 ? gameElements->ball.velocity.x = gameElements->minBallVelocity : gameElements->ball.velocity.x = -gameElements->minBallVelocity;
    
}

void BasicRules::applyRules() {
    //update ball speeds
    float maxV = gameElements->maxBallVelocity - gameElements->minBallVelocity;
    float velocityIncreaseAmt = maxV/20/ofGetFrameRate();
    
    //increase speed on time
    gameElements->ball.velocity.x > 0 ? gameElements->ball.velocity.x += velocityIncreaseAmt : gameElements->ball.velocity.x -= velocityIncreaseAmt;
    if (gameElements->ball.velocity.x > gameElements->maxBallVelocity) {
        gameElements->ball.velocity.x = gameElements->maxBallVelocity;
    }
    
    //move ball
    gameElements->ball.update();
    
    //check paddle and/or wall hit
    if (!paddleHittest(&gameElements->ball)) {
        wallHittest(&gameElements->ball);
    }
}


/**
 * hittest between ball and paddle, update ball direction
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
 * hittest between ball and walls, update score
 */
void BasicRules::wallHittest(Ball* ball){
    
    //wall left, player 2 gets point
    if (ball->position.x - ball->radius <= 0) {
        ball->position = ofVec2f( gameElements->getWidth()/2, gameElements->getHeigth()/2);
        ball->velocity = ofVec2f(ball->velocity.x,0);
        gameElements->increasePoints(2);
        gameElements->notifyGameEvent(BALL_OUT_P1);
        resetBallSpeed();
    }
    //wall right, player 1 gets point
    else if (ball->position.x + ball->radius >= gameElements->getWidth()) {
        ball->position = ofVec2f( gameElements->getWidth()/2, gameElements->getHeigth()/2);
        ball->velocity = ofVec2f(ball->velocity.x,0);
        gameElements->increasePoints(1);
        gameElements->notifyGameEvent(BALL_OUT_P2);
        resetBallSpeed();
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

void BasicRules::resetBallSpeed(){
    int mult = 1;
    if (gameElements->ball.velocity.x > 0) {
        mult = -1;
    }
    gameElements->ball.velocity = ofVec2f(mult*gameElements->minBallVelocity,0);
}