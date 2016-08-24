/*
 *  TrailRenderer.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 24.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _TrailRenderer
#define _TrailRenderer

#include "BasicRenderer.h"


class TrailRenderer : public BasicRenderer{
    
public:
    
    TrailRenderer(GameElements* gameElements, string name = "Trails");
    virtual void begin();
    virtual void render();
    
private:
    ofFbo fbo;
};

#endif
