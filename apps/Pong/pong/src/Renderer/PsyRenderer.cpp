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
    
#ifdef TARGET_OPENGLES
    bg.load("images/psy-bg.png");
    ball.load("images/psy-ball.png");
    ballSmall.load("images/psy-ball-small.png");
#else
    shader.load("shaders/gl2/psy");
#endif
}


//------------------------------------------------------------------
void PsyRenderer::render() {
    
#ifdef TARGET_OPENGLES
    int wStart = ((int)ofGetElapsedTimef())%8;
    for (int x =0; x<4; x++) {
        for (int y =0; y<3; y++) {
            bg.draw(x*512,y*512);
        }
    }
    
    float t = ofGetElapsedTimef();
    float x = gameElements->ball.position.x;
    float y = gameElements->ball.position.y;
    float r = gameElements->ball.radius;
    ball.draw(x-r,y-r,r*2,r*2 );
    ballSmall.draw(x + r*cos(t), y + r*sin(t),r,r);
#else
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
#endif   
    ofSetColor(255);
    drawScore();
    
    // ofSetColor(ofColor::white);
    // img.draw(0, 0);
    
}