/*
 *  WallPlayMode.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 19.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _WallPlayMode
#define _WallPlayMode

#include "BasicRenderer.h"
#include "BasicRules.h"

class Wall{
public:
    Wall(ofRectangle dimensions);
    ofRectangle dimensions;
    bool wallHittest(Ball* ball);
};

class WallPlayMode : public BasicRenderer, public BasicRules{
    
public:
    
    WallPlayMode(GameElements* gameElements, string name = "Walls");
    
    virtual void begin();
    virtual void applyRules();
    virtual void render();
    
private:
    void updateWalls();
    vector<Wall> walls;
    
};

#endif
