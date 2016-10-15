/*
 *  Ball.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 06.07.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _Ball
#define _Ball

#include "ofMain.h"

class Ball {
	
  public:
	
	Ball();
	
	void update();
	void draw();
    
    //void setVelocity(ofVec2f velocity);
	void setSpin(int spin);
	int  getSpin();
    
//private:
    float radius;
    ofVec2f position;
    ofVec2f velocity;
	int spin;
    long id;
    
};

#endif
