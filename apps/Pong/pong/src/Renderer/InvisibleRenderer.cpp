/*
 *  InvisibleRenderer.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "InvisibleRenderer.h"


//------------------------------------------------------------------
InvisibleRenderer::InvisibleRenderer(GameElements* gameElements, string name,int visiblePeriod_, int invisiblePeriod_):BasicPlaymode(gameElements, name,false,true) {
    visiblePeriod = visiblePeriod_;
    invisiblePeriod = invisiblePeriod_;
    isBallVisible = false;
    lastSwitch = 0;
}


//------------------------------------------------------------------
void InvisibleRenderer::render() {
    ofBackground(0);
    
    drawScore();
    drawMidLine();
    
    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    
    ofSetColor(200);
    
    if (isBallVisible) gameElements->ball.draw();
    
    int tPeriod = isBallVisible ? visiblePeriod : invisiblePeriod;
    if(ofGetElapsedTimeMillis() - lastSwitch > tPeriod){
        isBallVisible = !isBallVisible;
        lastSwitch = ofGetElapsedTimeMillis();
    }
}


