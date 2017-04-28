/*
 *  BasicRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _BasicPlaymode
#define _BasicPlaymode

#include "AbstractGameControl.h"


class BasicPlaymode : public AbstractGameControl{
    
public:
    
    BasicPlaymode(GameElements* gameElements, string name = "", bool isRules = true, bool isRenderer = true, int durationMode = 20000);
    void begin();
    virtual void render();
    virtual void applyRules();
    
protected:
    
    void drawScore();
    void drawMidLine();
    
    ofTrueTypeFont font;
    
    
    bool paddleHittest(Ball* ball);
    void wallHittest(Ball* ball);
    void resetBallSpeed();
    
};

#endif
