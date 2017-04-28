/*
 *  TennisRenderer.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - 2016
 *  http://kazoosh.com
 *
 *  created by Max Haferlach - 2016
 */

#include "TennisRenderer.h"

TennisRenderer::TennisRenderer(GameElements * gameElements, string name) :BasicPlaymode(gameElements, name,false,true) {
    court.load("images/court.jpg");
    tennis_ball.load("images/tennis_ball.png");
}

void TennisRenderer::begin()
{
    PlayModeEvent e = PlayModeEvent(name,true,"tennis");
    ofNotifyEvent(gameElements->newPlayModeEvent, e);
}

void TennisRenderer::render() {
    court.draw(0, 0, gameElements->getWidth(),gameElements->getHeigth());
    
    drawScore();
    
    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    
    
    Ball* ball = &gameElements->ball;
    float r = ball->radius;
    ofPushMatrix();
    ofTranslate(ball->position.x, ball->position.y);
    ofPushMatrix();
				ofRotate(ofGetElapsedTimef()*300);
				tennis_ball.draw(-r,-r, 2*r, 2*r);
    ofPopMatrix();
    ofPopMatrix();
    
    
}
