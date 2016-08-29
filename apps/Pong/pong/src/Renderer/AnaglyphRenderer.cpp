/*
 *  AnaglyphRenderer.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "AnaglyphRenderer.h"


//------------------------------------------------------------------
AnaglyphRenderer::AnaglyphRenderer(GameElements* gameElements, string name):BasicRenderer(gameElements, name) {
    
    
    cam.setPosition( 0, 0, 10 );
    cam.lookAt( ofVec3f(0,0,0));
    cam.enableStereo();
    cam.eyeSeparation   = 0.3;
    cam.focalLength     = 100;
    
}

//------------------------------------------------------------------
void AnaglyphRenderer::render() {
    
    ofBackground(0);
    
    drawScore();
    
    if ((ofGetElapsedTimeMillis()/2000)%2) {
        gameElements->ledControl.setColor(ofColor(255,0,0));
    }else{
        gameElements->ledControl.setColor(ofColor(255,0,255));
    }
    
    
    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    
    
    //render anaglyph for every eye
    ofEnableDepthTest();
    cam.beginLeft();
    drawAnaglyphElements();
    
    cam.beginRight();
    drawAnaglyphElements();
    cam.endStereo();
    ofDisableDepthTest();
}

/**
 * convert ball positions to 3d perpective camera
 * seems to be more try and error the real calculating
 */
void AnaglyphRenderer::drawAnaglyphElements(){
    
    ofSetColor(128);
    
    //draw walls
    ofVec3f pWallUp = cam.screenToWorld(ofVec3f(gameElements->getWidth()/2,0));
    ofDrawBox(pWallUp.x,pWallUp.y,-10, 30, 0.4,1);
    
    ofVec3f pWallBottom = cam.screenToWorld(ofVec3f(gameElements->getWidth()/2,gameElements->getHeigth()));
    ofDrawBox(pWallBottom.x,pWallBottom.y,-10, 30, 0.4,1);
    
    //draw grid
    int nHorizontal = 10;
    int nVertical = 10;
    
    for (int i=0; i<nHorizontal; ++i) {
        int py = ofMap(i,0,nHorizontal,pWallBottom.y, pWallUp.y);
        ofDrawLine(pWallUp.x - 15, py, -10.5, pWallUp.x + 15, py , -10.5);
    }
    
    for (int i=0; i<=nVertical; ++i) {
        int px = ofMap(i,0,nVertical,pWallUp.x-15, pWallUp.x+15);
        ofDrawLine(px, pWallBottom.y, -10.5, px, pWallUp.y , -10.5);
    }
    
    
    //draw ball
    
    
    ofSetColor(255);
    
    ofVec3f pBall = cam.screenToWorld(gameElements->ball.position);
    pBall.x *= 0.54;
    pBall.y *= -0.54;
    
    float pz = ofMap(gameElements->ball.position.x, 0, gameElements->getWidth(), 0, PI);
    pz = sin(pz);
    pBall.y *= (pz*0.3+1);
    pz = ofMap(pz, 0, 1, 0, -5);
    
    ofDrawBox(pBall.x,pBall.y,pz, gameElements->ball.radius/45.0, gameElements->ball.radius/45.0,0.1);
    
    
}
