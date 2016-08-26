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
    
}

void GifBGRenderer::begin(){
    ofDirectory dir;
    
    dir.listDir("images/bg/");
    
    //allocate the vector to have as many ofImages as files
    if( dir.size() ){
        string path = dir.getPath(ofRandom(dir.size()));
        decoder.decode(path);
        bg = decoder.getFile();
    }
    
}

void GifBGRenderer::render(){
    ofSetColor(255);
    bg.drawFrame(ofGetFrameNum()/4%(bg.getFrames().size()-1), 0,0,gameElements->getWidth(),gameElements->getHeigth());
    
    drawScore();
    drawMidLine();
    
    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    
    for(auto&& ball : gameElements->balls){
        ball->draw();
    }
}