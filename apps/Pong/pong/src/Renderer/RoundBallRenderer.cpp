/*
 *  RoundBallRenderer.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 22.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "RoundBallRenderer.h"


//------------------------------------------------------------------
RoundBallRenderer::RoundBallRenderer(GameElements* gameElements, string name):BasicRenderer(gameElements, name) {
}


//------------------------------------------------------------------
void RoundBallRenderer::render() {
    ofBackground(0);
    
    drawScore();
	drawMidLine();

    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    
    ofSetColor(200);
    
    for(auto&& ball : gameElements->balls){
        float r = ball->radius;
        ofDrawCircle(ball->position.x, ball->position.y, r);
    }
	
}


