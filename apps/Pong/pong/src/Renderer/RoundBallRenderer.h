/*
 *  RoundBallRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _RoundBallRenderer
#define _RoundBallRenderer

#include "BasicRenderer.h"


class RoundBallRenderer : public BasicRenderer{
    
public:
    
    RoundBallRenderer(GameElements* gameElements, string name = "Round Ball");
    virtual void render();
	
};

#endif
