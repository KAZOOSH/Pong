/*
 *  TextRenderer.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 17.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "TextRenderer.h"


//------------------------------------------------------------------
TextRenderer::TextRenderer(GameElements* gameElements, string name):AbstractRenderer(gameElements, name) {
    //load fonts
    for(int i=0; i<3; ++i){
        fontList.push_back(new ofTrueTypeFont());
    }
    
    fontList[0]->load("font.ttf",70);
    fontList[1]->load("font.ttf",45);
    fontList[2]->load("font.ttf",30);
    
    fonts[BIG] = fontList[0];
    fonts[MEDIUM] = fontList[1];
    fonts[SMALL] = fontList[2];
    
    //set initial position
    ani_ease_bounce.reset( 0.0f );
    ani_ease_bounce.setRepeatType(LOOP_BACK_AND_FORTH);
    ani_ease_bounce.setCurve(EASE_IN_OUT_BOUNCE);
    ani_ease_bounce.animateTo( 1.0f );
    ani_ease_bounce.setDuration(1);
}

/**
 * render all texts
 */
void TextRenderer::render() {
    long now = ofGetElapsedTimeMillis();
    for (auto text:texts) {
        //draw bg
        if(text.hasBG){
            ofSetColor(0, 0, 0,128);
            ofDrawRectangle(0, 0, gameElements->getWidth(), gameElements->getHeigth());
        }
        //max fade-in time 2 seconds
        int fadeInTime = text.lengthAnimation;
        if( text.lengthAnimation >= 2000) fadeInTime = 2000;
        
        //get animation position
        float playPosition = ofMap(now, text.startTime, text.startTime + fadeInTime, 0, 1);
        float scale = ani_ease_bounce.calcCurveAt(playPosition)*2;
        
        //transform text to center and draw
        ofPushMatrix();
        ofVec2f size(fontList[text.size]->getStringBoundingBox(text.content, 0, 0).getWidth(),
                     fontList[text.size]->getStringBoundingBox(text.content, 0, 0).getHeight());
        size *= scale;
        ofTranslate((gameElements->getWidth() - size.x)*0.5,
                    (gameElements->getHeigth() - size.y)*0.5);
        ofPushMatrix();
        ofScale(scale, scale);
        ofSetColor(text.textColor);
        fontList[text.size]->drawString(text.content, 0, 0);
        ofPopMatrix();
        ofPopMatrix();
    }
    
    //delete old texts
    for(int i=texts.size()-1 ; i>=0 ; i--){
        if(texts[i].startTime + texts[i].lengthAnimation < now){
            texts.erase(texts.begin() + i);
        }
    }
}

void TextRenderer::onNewTextElement(TextElement& t){
    texts.push_back(t);
}