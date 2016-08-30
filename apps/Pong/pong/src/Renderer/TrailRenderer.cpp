/*
 *  TrailRenderer.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 24.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "TrailRenderer.h"


TrailRenderer::TrailRenderer(GameElements* gameElements, string name):BasicRenderer(gameElements, name) {
    fbo.allocate(gameElements->getWidth(), gameElements->getHeigth(), GL_RGBA32F_ARB);
}

void TrailRenderer::begin(){
    BasicRenderer::begin();
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
}

void TrailRenderer::render(){
    
    ofEnableAlphaBlending();
    ofBackground(0);
    
    fbo.begin();
    ofFill();
    ofSetColor(255,255,255, 10);
    ofDrawRectangle(0, 0, gameElements->getWidth(), gameElements->getHeigth());
    gameElements->ball.draw();
    fbo.end();
    
    drawScore();
    drawMidLine();
    
    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    
    fbo.draw(0, 0);
    
    int color = (ofGetElapsedTimeMillis()/2000)%512;
    if (color>255) {
        color = 512 - color;
    }
    gameElements->ledControl.setColors(ofColor(color));
}
