/*
 *  DoubleSpeedRule.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 22.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _DoubleSpeedRule
#define _DoubleSpeedRule

#include "BasicRules.h"


class DoubleSpeedRule : public BasicRules{
    
public:
    
    DoubleSpeedRule(GameElements* gameElements, string name = "Double Speed");
    virtual void begin();
    
private:
    float speedMultiplicator;
};

#endif
