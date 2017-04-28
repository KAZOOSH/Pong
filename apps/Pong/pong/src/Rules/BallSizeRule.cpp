/*
 *  BallSizeRule.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "BallSizeRule.h"


BallSizeRule::BallSizeRule(GameElements* gameElements, string name, float sizeMultiplicator_):BasicPlaymode(gameElements, name,true,false){
    sizeMultiplicator = sizeMultiplicator_;
}


//------------------------------------------------------------------
void BallSizeRule::begin() {
    AbstractGameControl::begin();
    gameElements->ball.radius *= sizeMultiplicator;
    
}

void BallSizeRule::end(){
    AbstractGameControl::end();
    gameElements->ball.radius /= sizeMultiplicator;
    
}
