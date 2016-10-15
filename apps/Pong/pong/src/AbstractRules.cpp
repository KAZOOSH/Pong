/*
 *  Rule.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
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
