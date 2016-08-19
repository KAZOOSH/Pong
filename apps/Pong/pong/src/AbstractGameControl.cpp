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
AbstractGameControl::AbstractGameControl(GameElements* gameElements_, string name_) {
    gameElements = gameElements_;
    name = name_;
    runTime = 15000;
}


void AbstractGameControl::begin(){
    startTime = ofGetElapsedTimeMillis();
}

string AbstractGameControl::getName(){
    return name;
}