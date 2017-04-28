/*
 *  BallSizeRule.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _BallSizeRule
#define _BallSizeRule

#include "BasicPlaymode.h"

class BallSizeRule : public BasicPlaymode{
    
public:
    
    BallSizeRule(GameElements* gameElements, string name, float sizeMultiplicator);
    virtual void begin();
    virtual void end();
    
private:
    float sizeMultiplicator;
};

#endif
