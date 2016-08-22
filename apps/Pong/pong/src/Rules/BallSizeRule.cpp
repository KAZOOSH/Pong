/*
 *  BallSizeRule.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 22.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "BallSizeRule.h"


BallSizeRule::BallSizeRule(GameElements* gameElements, string name, float sizeMultiplicator_):BasicRules(gameElements, name){
    sizeMultiplicator = sizeMultiplicator_;
}


//------------------------------------------------------------------
void BallSizeRule::begin() {
    AbstractRules::begin();
    for (auto& ball:gameElements->balls) {
        ball->radius *= sizeMultiplicator;
    }
}

void BallSizeRule::end(){
    AbstractRules::end();
    for (auto& ball:gameElements->balls) {
        ball->radius /= sizeMultiplicator;
    }
}