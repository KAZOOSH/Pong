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

#include "BasicRules.h"
#include "BasicRenderer.h"

class MultiBallMode : public BasicRules, public BasicRenderer{
    
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
