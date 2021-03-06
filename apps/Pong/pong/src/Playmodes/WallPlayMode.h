/*
 *  WallPlayMode.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _WallPlayMode
#define _WallPlayMode

#include "BasicPlaymode.h"

class Wall{
public:
    Wall(ofRectangle dimensions);
    ofRectangle dimensions;
    bool wallHittest(Ball* ball);
};

class WallPlayMode : public BasicPlaymode{
    
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
