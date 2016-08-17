/*
 *  TextRenderer.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 17.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _TextRenderer
#define _TextRenderer

#include "AbstractRenderer.h"
#include "TextElement.h"
#include "ofxAnimatableFloat.h"

class TextRenderer : public AbstractRenderer{
    
public:
    
    TextRenderer(GameElements* gameElements, string name = "TextRenderer");
    virtual void draw();
    
    void onNewTextElement(TextElement& t);
    
protected:
    
    map<textSize,ofTrueTypeFont*> fonts;
    vector<ofTrueTypeFont*> fontList;
    
    vector<TextElement> texts;
    
    ofxAnimatableFloat ani_ease_bounce;
};

#endif
