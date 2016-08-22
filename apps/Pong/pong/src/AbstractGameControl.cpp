/*
 *  GameObject.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 17.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "AbstractGameControl.h"


//------------------------------------------------------------------
AbstractGameControl::AbstractGameControl(GameElements* gameElements_, string name_, string type_) {
    gameElements = gameElements_;
    name = name_;
    type = type_;
    runTime = 15000;
}


void AbstractGameControl::begin(){
    startTime = ofGetElapsedTimeMillis();
    
    TextElement t(name,
                  BIG,
                  true,
                  2000);
    ofNotifyEvent(newTextEvent,t);
}

void AbstractGameControl::end(){
    
}

string AbstractGameControl::getName(){
    return name;
}