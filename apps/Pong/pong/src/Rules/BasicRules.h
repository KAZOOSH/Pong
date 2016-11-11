/*
 *  BasicRules.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _BasicRules
#define _BasicRules

#include "AbstractRules.h"


class BasicRules : public AbstractRules{
    
public:
    
    BasicRules(GameElements* gameElements, string name = "", int durationMode = -1);
    
    virtual void begin();
    virtual void applyRules();
    
protected:
    bool paddleHittest(Ball* ball);
    void wallHittest(Ball* ball);
    void resetBallSpeed();
    
};

#endif
