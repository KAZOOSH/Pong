/*
 *  RoundBallRenderer.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 22.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
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
