/*
 *  GifBGRenderer.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "SpriteBGRenderer.h"

Sprite::Sprite(ofImage img_, int nFrames_, int framesPerLine_){
    img = img_;
    nFrames = nFrames_;
    framesPerLine = framesPerLine_;
    
    frameWidth = img.getWidth()/framesPerLine;
    int vFrames = ceil((float)nFrames/(float)framesPerLine);
    frameHeight = img.getHeight()/vFrames;
}

void Sprite::drawFrame(int frameNumber,int x, int y, int width, int height){
    img.drawSubsection(x, y, width, height, frameNumber%framesPerLine*frameWidth, frameNumber/framesPerLine*frameHeight, frameWidth, frameHeight);
}



SpriteBGRenderer::SpriteBGRenderer(GameElements* gameElements, string name):BasicPlaymode(gameElements, name,false,true) {
    getValuesFromXml();
    
    currentScene = 0;
}

void SpriteBGRenderer::begin(){
    BasicPlaymode::begin();
    
    currentScene = ofRandom(scenes.size());
}

void SpriteBGRenderer::render(){
    ofSetColor(255);
    scenes[currentScene]->drawFrame(ofGetFrameNum()/4%(scenes[currentScene]->nFrames-1), 0,0,gameElements->getWidth(),gameElements->getHeigth());
    
    drawScore();
    drawMidLine();
    
    gameElements->paddleRight.draw();
    gameElements->paddleLeft.draw();
    
    gameElements->ball.draw();
    
}

void SpriteBGRenderer::getValuesFromXml()
{
    
    string file = "images/spriteBg/images.xml";
    
    ofXml xml;
    if (!xml.load(file)) {
        ofLogError(file + " could not be found.");
    }
    xml.setTo("//images/image[0]");
    do {
        ofImage img;
        img.load("images/spriteBg/" + xml.getAttribute("name"));
        
        Sprite* s = new Sprite(img, ofToInt(xml.getAttribute("nFrames")),
                               ofToInt( xml.getAttribute("framesPerLine")));
        scenes.push_back(s);
        
    }
    while( xml.setToSibling() );
}
