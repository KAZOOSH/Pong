/*
 *  AbstractRenderer.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _AbstractRenderer
#define _AbstractRenderer

#include "ofMain.h"
#include "GameElements.h"

class AbstractRenderer {
	
  public:
	
	AbstractRenderer(GameElements* gameElements);
    virtual void begin(){};
	virtual void draw() = 0;
    
    ofEvent<bool> endRenderer;
    
protected:
    GameElements* gameElements;
    long startTime;
};

#endif
