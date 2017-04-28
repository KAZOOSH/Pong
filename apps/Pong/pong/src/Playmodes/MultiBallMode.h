/*
 *  MultiBallRule.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _MultiBallMode
#define _MultiBallMode

#include "BasicPlaymode.h"

class MultiBallMode : public BasicPlaymode{
    
public:
    
    MultiBallMode(GameElements* gameElements, string name = "Multiball");
    virtual void begin();
    virtual void end();
    
    virtual void applyRules();
    
    virtual void render();
    
private:
    vector<Ball*> balls;
    
};

#endif
