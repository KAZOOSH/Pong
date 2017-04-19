/*
 *  BallSizeRule.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "BallSizeRule.h"


BallSizeRule::BallSizeRule(GameElements* gameElements, string name, float sizeMultiplicator_):BasicRules(gameElements, name){
    sizeMultiplicator = sizeMultiplicator_;
}


//------------------------------------------------------------------
void BallSizeRule::begin() {
    AbstractRules::begin();
    gameElements->ball.radius *= sizeMultiplicator;
    
}

void BallSizeRule::end(){
    AbstractRules::end();
    gameElements->ball.radius /= sizeMultiplicator;
    
}
