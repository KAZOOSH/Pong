/*
 *  PaddleSizeRule.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 22.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
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