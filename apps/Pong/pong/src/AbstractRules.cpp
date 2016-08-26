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
AbstractRules::AbstractRules(GameElements* gameElements_,string name):AbstractGameControl(gameElements_,name,"Rules") {
    
}

void AbstractRules::update(){
    if (durationMode != -1) {
        if (startTime + durationMode < ofGetElapsedTimeMillis()) {
            ofNotifyEvent(durationExtendedEvent, type);
        }
    }
    applyRules();
}
