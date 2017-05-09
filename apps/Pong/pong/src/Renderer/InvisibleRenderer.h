/*
 *  InvisibleRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _InvisibleRenderer
#define _InvisibleRenderer

#include "BasicPlaymode.h"


class InvisibleRenderer : public BasicPlaymode{
    
public:
    
    InvisibleRenderer(GameElements* gameElements, string name = "Invisible Ball",int visiblePeriod = 250, int invisiblePeriod = 100);
    virtual void render();
    
private:
    int visiblePeriod;
    int invisiblePeriod;
    bool isBallVisible;
    long lastSwitch;
};

#endif
