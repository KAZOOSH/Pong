/*
 *  LsdRenderer.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 22.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _LsdRenderer
#define _LsdRenderer

#include "BasicRenderer.h"


class PsyRenderer : public BasicRenderer{
    
public:
    
    PsyRenderer(GameElements* gameElements, string name = "PSY");
    virtual void render();
    
private:
    ofShader shader;
};

#endif
