/*
 *  Rule.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _Rule
#define _Rule

#include "AbstractGameControl.h"

/**
 * defines a the rule which controls the game physics and point counting
 */
class AbstractRules : public AbstractGameControl{
    
public:
    
    AbstractRules(GameElements* gameElements,string name);
    void update();
    virtual void applyRules() = 0;
};

#endif
