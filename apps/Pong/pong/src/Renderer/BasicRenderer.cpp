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
BasicRenderer::BasicRenderer(GameElements* gameElements, string name, int durationMode_):AbstractRenderer(gameElements, name) {
    font.load("font.ttf",70);
    durationMode = durationMode_;
}

void BasicRenderer::begin(){
    AbstractRenderer::begin();
    gameElements->ledControl.setColors(ofColor(128));
}

//------------------------------------------------------------------
void BasicRenderer::render() {
    ofBackground(0);
    
    drawScore();
    drawMidLine();
    
    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    gameElements->ball.draw();
    
}


void BasicRenderer::drawScore(){
    font.drawString(ofToString(gameElements->getPoints(1)), gameElements->getWidth()*0.25, gameElements->getHeigth()*0.25);
    font.drawString(ofToString(gameElements->getPoints(2)), gameElements->getWidth()*0.7, gameElements->getHeigth()*0.25);
}

void BasicRenderer::drawMidLine(){
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