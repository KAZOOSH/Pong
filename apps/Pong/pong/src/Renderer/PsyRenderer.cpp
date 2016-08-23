/*
 *  LsdRenderer.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 22.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "PsyRenderer.h"


//------------------------------------------------------------------
PsyRenderer::PsyRenderer(GameElements* gameElements, string name):BasicRenderer(gameElements, name) {
    shader.load("shaders/psy");
}


//------------------------------------------------------------------
void PsyRenderer::render() {
    //img.getTextureReference().bind();
    
    shader.begin();
    
    ofPushMatrix();
    
    shader.setUniform2f("dimensions", ofVec2f(gameElements->getWidth(),gameElements->getHeigth()));
    shader.setUniform1f("iGlobalTime", ofGetElapsedTimef());
    shader.setUniform1f("radius", gameElements->balls[0]->radius);
    shader.setUniform2f("b1_pos", gameElements->balls[0]->position);
    
    ofSetColor(128);
    ofDrawRectangle(0, 0, gameElements->getWidth(), gameElements->getHeigth());
    
    ofPopMatrix();
    
    shader.end();
    
    ofSetColor(255);
    drawScore();
    
    // ofSetColor(ofColor::white);
    // img.draw(0, 0);
    
}