/*
 *  TextRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _TextRenderer
#define _TextRenderer

#include "AbstractRenderer.h"
#include "TextElement.h"
#include "ofxAnimatableFloat.h"

class TextRenderer : public AbstractRenderer{
    
public:
    
    TextRenderer(GameElements* gameElements, string name = "TextRenderer");
    virtual void render();
    
    void onNewTextElement(TextElement& t);
    
protected:
    
    map<textSize,ofTrueTypeFont*> fonts;
    vector<ofTrueTypeFont*> fontList;
    
    vector<TextElement> texts;
    
    ofxAnimatableFloat ani_ease_bounce;
};

#endif
