/*
 *  GravityRule.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - 2016
 *  http://kazoosh.com
 *
 *  created by Max Haferlach - 2016
 */

#include "GravityRule.h"



GravityRule::GravityRule(GameElements * gameElements, string name):BasicPlaymode(gameElements,name,true,false)
{
    //runTime = -1;
}

void GravityRule::begin()
{
    BasicPlaymode::begin();
}

void GravityRule::end()
{
    BasicPlaymode::end();
}

void GravityRule::applyRules()
{
    
    Ball* ball = &gameElements->ball;
    //move ball
    ball->velocity.y = ball->velocity.y + 0.25;
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
