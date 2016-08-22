/*
 *  BallSizeRule.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 22.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _BallSizeRule
#define _BallSizeRule

#include "BasicRules.h"

class BallSizeRule : public BasicRules{
    
public:
    
    BallSizeRule(GameElements* gameElements, string name, float sizeMultiplicator);
    virtual void begin();
    virtual void end();
    
private:
    float sizeMultiplicator;
};

#endif
