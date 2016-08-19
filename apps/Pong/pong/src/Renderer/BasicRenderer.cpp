/*
 *  BasicRenderer.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "BasicRenderer.h"


//------------------------------------------------------------------
BasicRenderer::BasicRenderer(GameElements* gameElements, string name):AbstractRenderer(gameElements, name) {
    font.load("font.ttf",70);
    runTime = -1;
}

//------------------------------------------------------------------
void BasicRenderer::render() {
    ofBackground(0);
    
    drawScore();
    
    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    
    for(auto&& ball : gameElements->balls){
        ball->draw();
    }
    
}

void BasicRenderer::drawScore(){
    font.drawString(ofToString(gameElements->getPoints(1)), gameElements->getWidth()*0.25, gameElements->getHeigth()*0.25);
    font.drawString(ofToString(gameElements->getPoints(2)), gameElements->getWidth()*0.75, gameElements->getHeigth()*0.25);
}