/*
 *  MultiBallRule.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 16.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "MultiBallRule.h"

MultiBallRule::MultiBallRule(GameElements* gameElements, string name):BasicRules(gameElements, name){
    
}


//------------------------------------------------------------------
void MultiBallRule::begin() {
    AbstractRules::begin();
    
    int nBalls = ofRandom(2, 4);
    for (int i=0; i<nBalls; ++i) {
        float vStart = gameElements->balls[0]->velocity.x;
        gameElements->addBall(ofVec2f(gameElements->getWidth()/2, ofRandom(50, gameElements->getHeigth()-50)),
                              ofVec2f(ofRandom(vStart*0.8, vStart*1.2),0));
    }
    
    
}

void MultiBallRule::end(){
    gameElements->removeAllExtraBalls();
}