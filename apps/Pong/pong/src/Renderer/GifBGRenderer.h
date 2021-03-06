/*
 *  GifBGRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _GifBGRenderer
#define _GifBGRenderer

#include "BasicPlaymode.h"

#include "ofxGifDecoder.h"
#include "ofxGifFile.h"

class GifBGRenderer : public BasicPlaymode{
    
public:
    
    GifBGRenderer(GameElements* gameElements, string name = "MovieGif");
    virtual void begin();
    virtual void render();
    
    
private:
    
    vector<ofxGifDecoder*> decoder;
    
    int currentScene;
};

#endif
