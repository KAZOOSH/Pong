/*
 *  PaddleSizeRule.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "PaddleSizeRule.h"


PaddleSizeRule::PaddleSizeRule(GameElements* gameElements, string name, float sizeMultiplicator_):BasicRules(gameElements, name){
    sizeMultiplicator = sizeMultiplicator_;
}


//------------------------------------------------------------------
void PaddleSizeRule::begin() {
    AbstractRules::begin();
    gameElements->paddleLeft.height *= sizeMultiplicator;
    gameElements->paddleRight.height *= sizeMultiplicator;
}

void PaddleSizeRule::end(){
    AbstractRules::end();
    gameElements->paddleLeft.height /= sizeMultiplicator;
    gameElements->paddleRight.height /= sizeMultiplicator;
}