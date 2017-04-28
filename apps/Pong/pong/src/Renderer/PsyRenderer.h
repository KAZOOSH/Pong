/*
 *  LsdRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _LsdRenderer
#define _LsdRenderer

#include "BasicPlaymode.h"


class PsyRenderer : public BasicPlaymode{
    
public:
    
    PsyRenderer(GameElements* gameElements, string name = "PSY");
    virtual void render();
    
private:
    ofShader shader;
};

#endif
