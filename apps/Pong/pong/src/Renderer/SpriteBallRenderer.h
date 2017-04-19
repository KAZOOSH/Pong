/*
 *  SpriteBallRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _SpriteBallRenderer
#define _SpriteBallRenderer

#include "BasicRenderer.h"

/**
 * loads an animated sprite texture as ball
 * each frame should be equal sized and placed in first x, then y direction
 *
 *  sample(on frame number x,y) : 
 *  0 | 1 | 2
 *  ---------
 *  3 | 4 | 5
 *
 *  enter the correct values for framesHorizontal, framesVertical
 */
class SpriteBallRenderer : public BasicRenderer{
    
public:
    
    SpriteBallRenderer(GameElements* gameElements, string name = "Goat Mode", string path = "images/goat.png", int framesHorizontal = 3, int framesVertical = 3);
    virtual void begin();
    virtual void render();
    
private:
    
    ofImage sprite;
    int framesHorizontal,framesVertical;
    int frameWidth, frameHeight;
    
};

#endif
