/*
 *  BasicRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _BasicRenderer
#define _BasicRenderer

#include "AbstractRenderer.h"


class BasicRenderer : public AbstractRenderer{
    
public:
    
    BasicRenderer(GameElements* gameElements, string name = "", int durationMode = 20000);
    virtual void render();
protected:
    void begin();
    void drawScore();
    void drawMidLine();
    
    ofTrueTypeFont font;
    
};

#endif
