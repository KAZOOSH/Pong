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
    
    fontList[0]->load("font.ttf",50);
    fontList[1]->load("font.ttf",35);
    fontList[2]->load("font.ttf",25);
	
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


//------------------------------------------------------------------
void TextRenderer::draw() {
    
    long now = ofGetElapsedTimeMillis();
    for (auto text:texts) {
        float position = ofMap(now, text.startTime, text.startTime + text.lengthAnimation, 0, 1);
        float scale = ani_ease_bounce.calcCurveAt(position);
        cout << position << "  " <<scale << endl;
        ofPushMatrix();
        ofTranslate(300, 300);
        ofPushMatrix();
        ofScale(scale, scale);
        fontList[text.size]->drawString(text.content, 0, 0);
        ofPopMatrix();
        ofPopMatrix();
    }
	
    for(int i=texts.size()-1 ; i>=0 ; i--){
        if(texts[i].startTime + texts[i].lengthAnimation < now){
            texts.erase(texts.begin() + i);
        }
    }
}

void TextRenderer::onNewTextElement(TextElement& t){
    texts.push_back(t);
}