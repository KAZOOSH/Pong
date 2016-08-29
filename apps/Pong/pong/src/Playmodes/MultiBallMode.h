/*
 *  MultiBallRule.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 16.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _MultiBallMode
#define _MultiBallMode

#include "BasicRules.h"
#include "BasicRenderer.h"

class MultiBallMode : public BasicRules, public BasicRenderer{
    
public:
    
    MultiBallMode(GameElements* gameElements, string name = "Multiball");
    virtual void begin();
    virtual void end();
    
    virtual void applyRules();
    
    virtual void render();
    
private:
    vector<Ball*> balls;
    
};

#endif
