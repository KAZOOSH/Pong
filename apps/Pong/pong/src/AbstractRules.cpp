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
AbstractRules::AbstractRules(GameElements* gameElements_,string name):AbstractGameControl(gameElements_,name) {
    
}

void AbstractRules::update(){
    if (runTime != -1) {
        if (startTime + runTime < ofGetElapsedTimeMillis()) {
            end();
        }
    }
    applyRules();
}

void AbstractRules::end(){
    bool endState = true;
    ofNotifyEvent(endRules, endState);
}