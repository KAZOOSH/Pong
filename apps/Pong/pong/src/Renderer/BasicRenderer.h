/*
 *  BasicRenderer.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _BasicRenderer
#define _BasicRenderer

#include "AbstractRenderer.h"


class BasicRenderer : public AbstractRenderer{
    
public:
    
    BasicRenderer(GameElements* gameElements, string name = "", int runtime = 20000);
    virtual void render();
    
protected:
    void drawScore();
    void drawMidLine();
    
    ofTrueTypeFont font;
    
};

#endif
