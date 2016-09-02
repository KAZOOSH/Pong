/*
 *  DoubleSpeedRule.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _DoubleSpeedRule
#define _DoubleSpeedRule

#include "BasicRules.h"


class DoubleSpeedRule : public BasicRules{
    
public:
    
    DoubleSpeedRule(GameElements* gameElements, string name = "Double Speed");
    virtual void begin();
    
private:
    float speedMultiplicator;
};

#endif
