/*
 *  Rule.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "AbstractRules.h"


//------------------------------------------------------------------
AbstractRules::AbstractRules(GameElements* gameElements_) {
    gameElements = gameElements_;
	
}

void AbstractRules::begin(){
    startTime = ofGetElapsedTimeMillis();
}
