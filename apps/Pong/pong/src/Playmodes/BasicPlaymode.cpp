/*
 *  BasicRenderer.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "BasicPlaymode.h"


//------------------------------------------------------------------
BasicPlaymode::BasicPlaymode(GameElements* gameElements, string name, bool isRules, bool isRenderer,int durationMode_):AbstractGameControl(gameElements, name, isRules, isRenderer,durationMode_) {
    font.load("font.ttf",70);
}

void BasicPlaymode::begin(){
    AbstractGameControl::begin();
    if (isRenderer()) {
        beginRender();
    }
    if(isRules()){
        beginRules();
    }
}

//------------------------------------------------------------------
void BasicPlaymode::render() {
    ofBackground(0);
    gameElements->ledControl.setColors(ofColor(255));
    
    drawScore();
    drawMidLine();
    
    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    
    gameElements->ball.draw();
    
    
}


void BasicPlaymode::drawScore(){
    font.drawString(ofToString(gameElements->getPoints(1)), gameElements->getWidth()*0.25, gameElements->getHeigth()*0.25);
    font.drawString(ofToString(gameElements->getPoints(2)), gameElements->getWidth()*0.7, gameElements->getHeigth()*0.25);
}

void BasicPlaymode::drawMidLine(){
    int wLine = 10;
    int hLine = 50;
    int spaceLine = 30;
    
    int nLines = gameElements->getHeigth()/(hLine+spaceLine)+1;
    
    ofPushMatrix();
    ofTranslate((gameElements->getWidth()-wLine)*.5, 0);
    for (int i=0; i<nLines; ++i) {
        ofDrawRectangle(0, 0, wLine, hLine);
        ofTranslate(0, hLine+spaceLine);
    }
    ofPopMatrix();
}

void BasicPlaymode::applyRules() {
    
    
    //update ball speeds
    float maxV = gameElements->maxBallVelocity - gameElements->minBallVelocity;
    float velocityIncreaseAmt = maxV/20/ofGetFrameRate();
    
    //increase speed on time
    gameElements->ball.velocity.x > 0 ? gameElements->ball.velocity.x += velocityIncreaseAmt : gameElements->ball.velocity.x -= velocityIncreaseAmt;
    if (gameElements->ball.velocity.x > gameElements->maxBallVelocity) {
        gameElements->ball.velocity.x = gameElements->maxBallVelocity;
    }
    
    //add spin
    Ball* ball = &BasicPlaymode::gameElements->ball;
    float factor = 0;
    //move ball
    if (ball->getinitialSpin() != 0) {
        factor = sin(PI * ((double)ball->getSpin() / (double)ball->getinitialSpin()));
    }
    
    ball->velocity.y += ofMap(ball->getSpin() * factor, -100, 100, -3, 3, true);
    ball->setSpin(ball->getSpin()*0.97);
    ball->update();
    
    //move ball
    gameElements->ball.update();
    
    //check paddle and/or wall hit
    if (!paddleHittest(ball)) {
        wallHittest(ball);
    }
    
}


/**
 * hittest between ball and paddle, update ball direction
 */
bool BasicPlaymode::paddleHittest(Ball* ball){
    bool isHit = false;
    int speed;
    if (gameElements->paddleLeft.isHit(*ball)) {
        ball->velocity.y = gameElements->paddleLeft.getHitzone(*ball);
        gameElements->notifyGameEvent(CONTACT_PADDLE1);
        speed = gameElements->paddleLeft.getSpeed();
        isHit = true;
    }else if (gameElements->paddleRight.isHit(*ball)) {
        ball->velocity.y = gameElements->paddleRight.getHitzone(*ball);
        gameElements->notifyGameEvent(CONTACT_PADDLE2);
        speed = gameElements->paddleRight.getSpeed();
        isHit = true;
    }
    
    if (isHit){
        ball->velocity.x *= -1;
        ball->setSpin(speed);
        ball->setInitialSpin(speed);
        if (speed > 2 || speed < -2) {
            ball->velocity.y = ofMap(speed, -100, 100, -5, 5, true);
        }
        return true;
    }
    return false;
}

/**
 * hittest between ball and walls, update score
 */
void BasicPlaymode::wallHittest(Ball* ball){
    
    //wall left, player 2 gets point
    if (ball->position.x - ball->radius <= 0) {
        ball->position = ofVec2f( gameElements->getWidth()/2, gameElements->getHeigth()/2);
        ball->velocity = ofVec2f(ball->velocity.x,0);
        gameElements->increasePoints(2);
        gameElements->notifyGameEvent(BALL_OUT_P1);
        ball->spawnBall();
        resetBallSpeed();
    }
    //wall right, player 1 gets point
    else if (ball->position.x + ball->radius >= gameElements->getWidth()) {
        ball->position = ofVec2f( gameElements->getWidth()/2, gameElements->getHeigth()/2);
        ball->velocity = ofVec2f(ball->velocity.x,0);
        gameElements->increasePoints(1);
        gameElements->notifyGameEvent(BALL_OUT_P2);
        ball->spawnBall();
        resetBallSpeed();
    }
    
    //wall top
    else if (ball->position.y - ball->radius <= 0) {
        ball->velocity.y *= -1;
        ball->position.y = ball->radius;
        ball->velocity.x += ofMap(ball->getSpin(), -100, 100, -5, 5, true);
        gameElements->notifyGameEvent(CONTACT_WALL);
    }
    //wall bottom
    else if (ball->position.y + ball->radius >= gameElements->getHeigth()) {
        ball->velocity.y *= -1;
        ball->position.y = gameElements->getHeigth() - ball->radius;
        ball->velocity.x += ofMap(ball->getSpin(), -100, 100, -5, 5, true);
        gameElements->notifyGameEvent(CONTACT_WALL);
    }
}

void BasicPlaymode::resetBallSpeed(){
    int mult = 1;
    if (gameElements->ball.velocity.x > 0) {
        mult = -1;
    }
    gameElements->ball.velocity = ofVec2f(mult*gameElements->minBallVelocity,0);
}

void BasicPlaymode::beginRender(){
    gameElements->ledControl.setColors(ofColor(128));
}

void BasicPlaymode::beginRules(){
    //set minimum ball velocity
    gameElements->ball.velocity.x > 0 ? gameElements->ball.velocity.x = gameElements->minBallVelocity : gameElements->ball.velocity.x = -gameElements->minBallVelocity;
}

