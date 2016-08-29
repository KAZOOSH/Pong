#include "SwerveRule.h"


SwerveRule::SwerveRule(GameElements * gameElements, string name) :BasicRules(gameElements, name)
{
    //runTime = -1;
}


void SwerveRule::begin()
{
    BasicRules::begin();
}

void SwerveRule::end()
{
    BasicRules::end();
}

void SwerveRule::applyRules()
{
    
    
    //move ball
    Ball* ball = &gameElements->ball;
    ball->position.y += cos(ofGetElapsedTimef() * 5) * 4;
    ball->update();
    
    //check paddle and/or wall hit
    if (!paddleHittest(ball)) {
        wallHittest(ball);
    }
    
    
}
