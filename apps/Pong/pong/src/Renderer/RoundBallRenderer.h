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

#include "BasicPlaymode.h"


class RoundBallRenderer : public BasicPlaymode{
    
public:
    
    RoundBallRenderer(GameElements* gameElements, string name = "Round Ball");
    virtual void render();
	
};

#endif
