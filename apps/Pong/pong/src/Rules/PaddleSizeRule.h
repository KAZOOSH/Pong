/*
 *  PaddleSizeRule.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 22.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _PaddleSizeRule
#define _PaddleSizeRule

#include "BasicRules.h"

class PaddleSizeRule : public BasicRules{
    
public:
    
    PaddleSizeRule(GameElements* gameElements, string name, float sizeMultiplicator);
    virtual void begin();
    virtual void end();
    
private:
    float sizeMultiplicator;
};

#endif
