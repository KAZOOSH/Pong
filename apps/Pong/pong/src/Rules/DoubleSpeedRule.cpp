/*
 *  DoubleSpeedRule.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
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

