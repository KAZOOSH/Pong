/*
 *  DoubleSpeedRule.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 22.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "DoubleSpeedRule.h"

DoubleSpeedRule::DoubleSpeedRule(GameElements* gameElements, string name):BasicRules(gameElements, name){
    speedMultiplicator = 2.0f;
}


//------------------------------------------------------------------
void DoubleSpeedRule::begin() {
    BasicRules::begin();
    gameElements->ball.velocity *= speedMultiplicator;
    
    
}

