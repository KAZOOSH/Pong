/*
 *  AnaglyphRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _AnaglyphRenderer
#define _AnaglyphRenderer

#include "BasicPlaymode.h"
#include "ofxCameraAnaglyph.h"


class AnaglyphRenderer : public BasicPlaymode{
    
public:
    
    AnaglyphRenderer(GameElements* gameElements, string name = "Anaglyph");
    virtual void render();
    
protected:
    void drawAnaglyphElements();
    ofxCameraAnaglyph cam;
};

#endif
