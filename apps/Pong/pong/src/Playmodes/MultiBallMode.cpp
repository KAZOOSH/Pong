/*
 *  MultiBallRule.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "MultiBallMode.h"

MultiBallMode::MultiBallMode(GameElements* gameElements, string name):BasicPlaymode(gameElements, name){
    
}


//------------------------------------------------------------------
void MultiBallMode::begin() {
    BasicPlaymode::begin();
    
    int nBalls = ofRandom(1, 2);
    for (int i=0; i<nBalls; ++i) {
        float vStart = BasicPlaymode::gameElements->minBallVelocity;
        if (ofRandom(-1, 1)<0) {
            vStart *= -1;
        }
        balls.push_back(new Ball(ofVec2f(
                                         BasicPlaymode::gameElements->getWidth()/2,ofRandom(50, BasicPlaymode::gameElements->getHeigth()-50)),
                                 ofVec2f(ofRandom(vStart*0.8, vStart*1.2),0)));
    }
    
    
}

void MultiBallMode::end(){
    balls.clear();
}

void MultiBallMode::applyRules() {
    BasicPlaymode::applyRules();
    
    float maxV = BasicPlaymode::gameElements->maxBallVelocity - BasicPlaymode::gameElements->minBallVelocity;
    float velocityIncreaseAmt = maxV/20/ofGetFrameRate();
    
    for (auto&& ball : balls) {
        //increase speed on time
        ball->velocity.x > 0 ? ball->velocity.x += velocityIncreaseAmt : ball->velocity.x -= velocityIncreaseAmt;
        if (ball->velocity.x > BasicPlaymode::gameElements->maxBallVelocity) {
            ball->velocity.x = BasicPlaymode::gameElements->maxBallVelocity;
        }
        
        //move ball
        ball->update();
        
        //check paddle and/or wall hit
        if (!paddleHittest(ball)) {
            wallHittest(ball);
        }
    }
    
    
}

void MultiBallMode::render(){
    ofBackground(0);
    drawScore();
    drawMidLine();
    
    BasicPlaymode::gameElements->paddleRight.draw();
    BasicPlaymode::gameElements->paddleLeft.draw();
    BasicPlaymode::gameElements->ball.draw();
    
    for(auto&& ball : balls){
        ball->draw();
    }
}