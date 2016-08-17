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

#include "AbstractGameControl.h"

class AbstractRenderer : public AbstractGameControl{
	
  public:
	
	AbstractRenderer(GameElements* gameElements, string name);
	virtual void draw() = 0;
    
    ofEvent<bool> endRenderer;
    
};

#endif