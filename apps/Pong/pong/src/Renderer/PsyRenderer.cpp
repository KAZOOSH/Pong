/*
 *  LsdRenderer.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "PsyRenderer.h"


//------------------------------------------------------------------
PsyRenderer::PsyRenderer(GameElements* gameElements, string name):BasicPlaymode(gameElements, name,false,true) {
    shader.load("shaders/psy");
}


//------------------------------------------------------------------
void PsyRenderer::render() {
    //img.getTextureReference().bind();
    
    int color = (ofGetElapsedTimeMillis()/200)%2 == 0 ? 30:255;
    gameElements->ledControl.setColors(ofColor(color));
    
    shader.begin();
    
    ofPushMatrix();
    
    shader.setUniform2f("dimensions", ofVec2f(gameElements->getWidth(),gameElements->getHeigth()));
    shader.setUniform1f("iGlobalTime", ofGetElapsedTimef());
    shader.setUniform1f("radius", gameElements->ball.radius);
    shader.setUniform2f("pos", gameElements->ball.position);
    
    ofSetColor(128);
    ofDrawRectangle(0, 0, gameElements->getWidth(), gameElements->getHeigth());
    
    ofPopMatrix();
    
    shader.end();
    
    ofSetColor(255);
    drawScore();
    
    // ofSetColor(ofColor::white);
    // img.draw(0, 0);
    
}