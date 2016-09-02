/*
 *  RoundBallRenderer.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
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
    
    ofDrawCircle(gameElements->ball.position.x, gameElements->ball.position.y, gameElements->ball.radius);
    
	
}


