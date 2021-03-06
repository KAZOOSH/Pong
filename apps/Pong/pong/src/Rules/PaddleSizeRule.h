/*
 *  PaddleSizeRule.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _PaddleSizeRule
#define _PaddleSizeRule

#include "BasicPlaymode.h"

class PaddleSizeRule : public BasicPlaymode{
    
public:
    
    PaddleSizeRule(GameElements* gameElements, string name, float sizeMultiplicator);
    virtual void begin();
    virtual void end();
    
private:
    float sizeMultiplicator;
};

#endif
