/*
 *  LedControl.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 23.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _LedControl
#define _LedControl

#include "ofMain.h"
#include "ofxOPC.h"

#define N_LEDS 24

class LedControl {
	
  public:
	
	LedControl();
	
	void setup();
	void update();
	void draw();
    
private:
    vector<ofColor> colors;
    ofxOPC opcClient;
	
};

#endif
