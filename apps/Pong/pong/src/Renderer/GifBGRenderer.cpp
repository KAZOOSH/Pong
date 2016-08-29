/*
 *  GifBGRenderer.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 26.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "GifBGRenderer.h"


GifBGRenderer::GifBGRenderer(GameElements* gameElements, string name):BasicRenderer(gameElements, name) {
    ofDirectory dir;
    dir.listDir("images/bg/");
    
    //allocate the vector to have as many ofImages as files
    if( dir.size() ){
        for(int i=0; i<dir.size();++i){
            string path = dir.getPath(i);
            decoder.push_back(new ofxGifDecoder());
            decoder.back()->decode(path);
            
        }
        
    }
    currentScene = 0;
}

void GifBGRenderer::begin(){
    BasicRenderer::begin();
    
    currentScene = ofRandom(decoder.size());
}

void GifBGRenderer::render(){
    ofSetColor(255);
    ofxGifFile bg = decoder[currentScene]->getFile();
    bg.drawFrame(ofGetFrameNum()/4%(bg.getFrames().size()-1), 0,0,gameElements->getWidth(),gameElements->getHeigth());
    
    drawScore();
    drawMidLine();
    
    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    
    gameElements->ball.draw();
    
}

