/*
 *  Ball.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _Ball
#define _Ball

#include "ofMain.h"

class Ball {
	
  public:
	
	Ball();
    Ball(ofVec2f position, ofVec2f velocity);
	
	void update();
	void draw();
    
    //void setVelocity(ofVec2f velocity);
	void setSpin(int spin);
	void setInitialSpin(int spin);
	int  getSpin();
	int  getinitialSpin();
	

	//private:
    float radius;
    ofVec2f position;
    ofVec2f velocity;
	int spin;
	int initialSpin;
    long id;
    
};

#endif
