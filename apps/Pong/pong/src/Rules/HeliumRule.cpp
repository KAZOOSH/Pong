/*
 *  HeliumRule.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - 2016
 *  http://kazoosh.com
 *
 *  created by Max Haferlach - 2016
 */

#include "HeliumRule.h"



HeliumRule::HeliumRule(GameElements * gameElements, string name):BasicRules(gameElements,name)
{
    //runTime = -1;
}

void HeliumRule::begin()
{
    BasicRules::begin();
}

void HeliumRule::end()
{
    BasicRules::end();
}

void HeliumRule::applyRules()
{
    
    Ball* ball = &gameElements->ball;
    //move ball
    ball->velocity.y = ball->velocity.y - 0.25;
    ball->update();
    
    //check paddle and/or wall hit
    if (!paddleHittest(ball)) {
        wallHittest(ball);
    }
    else
    {
        ball->velocity.y *= 2;
    }
    
}
