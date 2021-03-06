/*
 *  TrailRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _TrailRenderer
#define _TrailRenderer

#include "BasicPlaymode.h"


class TrailRenderer : public BasicPlaymode{
    
public:
    
    TrailRenderer(GameElements* gameElements, string name = "Trails");
    virtual void begin();
    virtual void render();
    
private:
    ofFbo fbo;
};

#endif
