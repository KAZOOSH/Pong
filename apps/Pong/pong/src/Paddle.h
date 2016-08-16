/*
 *  Paddle.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 06.07.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _Paddle
#define _Paddle

#include "ofMain.h"
#include "Ball.h"
#include "AbstractControl.h"

class Paddle {
	
  public:
    Paddle();
	
	void setup(int x, int wGame, int hGame);
	void draw();
    void addControl(AbstractControl& control);
    
    void onPositionChanged(float& pos);
    
    bool isHit(Ball& b);
    float getHitzone(Ball& b);
    
    int height;
    
private:
    int x, y;
    int wGame, hGame;
	
};

#endif
