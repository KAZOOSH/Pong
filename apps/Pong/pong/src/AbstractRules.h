/*
 *  Rule.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _Rule
#define _Rule

#include "ofMain.h"
#include "GameElements.h"

/**
 * defines a the rule which controls the game physics and point counting
 */
class AbstractRules {
	
  public:
	
	AbstractRules(GameElements* gameElements);
    virtual void begin();
	virtual void update() = 0;
    
    ofEvent<bool> endRules;
    
protected:
    GameElements* gameElements;
    long startTime;
};

#endif
