/*
 *  PaddleSizeRule.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "PaddleSizeRule.h"


PaddleSizeRule::PaddleSizeRule(GameElements* gameElements, string name, float sizeMultiplicator_):BasicPlaymode(gameElements, name,true,false){
    sizeMultiplicator = sizeMultiplicator_;
}


//------------------------------------------------------------------
void PaddleSizeRule::begin() {
    AbstractGameControl::begin();
    gameElements->paddleLeft.height *= sizeMultiplicator;
    gameElements->paddleRight.height *= sizeMultiplicator;
}

void PaddleSizeRule::end(){
    AbstractGameControl::end();
    gameElements->paddleLeft.height /= sizeMultiplicator;
    gameElements->paddleRight.height /= sizeMultiplicator;
}