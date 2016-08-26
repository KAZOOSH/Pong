/*
 *  GifBGRenderer.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 26.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _GifBGRenderer
#define _GifBGRenderer

#include "BasicRenderer.h"

#include "ofxGifDecoder.h"
#include "ofxGifFile.h"

class GifBGRenderer : public BasicRenderer{
    
public:
    
    GifBGRenderer(GameElements* gameElements, string name = "Movie");
    virtual void begin();
    virtual void render();
    
private:
    
    ofxGifDecoder decoder;
    ofxGifFile bg;
};

#endif
