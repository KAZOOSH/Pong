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
