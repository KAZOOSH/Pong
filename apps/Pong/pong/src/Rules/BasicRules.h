/*
 *  BasicRules.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _BasicRules
#define _BasicRules

#include "AbstractRules.h"


class BasicRules : public AbstractRules{
    
public:
    
    BasicRules(GameElements* gameElements, string name = "", int durationMode = 20000);
    
    virtual void begin();
    virtual void applyRules();
    
protected:
    bool paddleHittest(Ball* ball);
    void wallHittest(Ball* ball);
    void resetBallSpeed();
    
};

#endif
