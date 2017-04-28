/*
 *  SpriteBallRenderer.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "SpriteBallRenderer.h"


SpriteBallRenderer::SpriteBallRenderer(GameElements* gameElements, string name,string path,int framesHorizontal_, int framesVertical_):BasicPlaymode(gameElements, name,false,true) {
    
    sprite.load(path);
    framesHorizontal = framesHorizontal_;
    framesVertical = framesVertical_;
    
    frameWidth = sprite.getWidth()/framesHorizontal;
    frameHeight = sprite.getHeight()/framesVertical;
}

void SpriteBallRenderer::begin(){
    BasicPlaymode::begin();
    
}

void SpriteBallRenderer::render(){
    
    ofBackground(0);
    drawScore();
    drawMidLine();
    
    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    
    ofSetColor(255);
    
    
    ofPushMatrix();
    ofTranslate(gameElements->ball.position.x, gameElements->ball.position.y);
    ofPushMatrix();
    int scale = 1;
    if (gameElements->ball.velocity.x < 0) scale = -1;
    ofScale(scale, 1);
    int frame = (ofGetFrameNum()/3)%(framesHorizontal*framesVertical);
    float mult = 2;
    sprite.drawSubsection(-gameElements->ball.radius*mult, -gameElements->ball.radius*mult, gameElements->ball.radius*2*mult, gameElements->ball.radius*2*mult, frame%framesHorizontal*frameWidth, frame/framesHorizontal*frameHeight, frameWidth, frameHeight);
    
    
    ofPopMatrix();
    ofPopMatrix();
    
}

