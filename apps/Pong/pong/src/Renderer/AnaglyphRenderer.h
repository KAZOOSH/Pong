/*
 *  AnaglyphRenderer.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _AnaglyphRenderer
#define _AnaglyphRenderer

#include "BasicRenderer.h"
#include "ofxCameraAnaglyph.h"


class AnaglyphRenderer : public BasicRenderer{
    
public:
    
    AnaglyphRenderer(GameElements* gameElements, string name = "Anaglyph");
    virtual void render();
    
protected:
    void drawAnaglyphElements();
    ofxCameraAnaglyph cam;
};

#endif
