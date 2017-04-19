/*
 *  Paddle.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
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
    
    int getPosition();
	int getSpeed();
    bool isHit(Ball& b);
    float getHitzone(Ball& b);
    
    ofParameter<int> height;
    
    bool isDebug;
    
private:
    int x, y;
	int speed;
    int wGame, hGame;
	
};

#endif
