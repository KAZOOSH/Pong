/*
 *  MultiBallRule.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 16.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _MultiBallRule
#define _MultiBallRule

#include "BasicRules.h"


class MultiBallRule : public BasicRules{
	
  public:
	
	MultiBallRule(GameElements* gameElements, string name = "Multiball");
    virtual void begin();
    virtual void end();
	
};

#endif
