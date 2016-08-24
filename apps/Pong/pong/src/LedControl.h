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
#include "GameElements.h"

#define N_LEDS 40

class LedControl {
    
public:
    
    void setup(GameElements* gameElements);
    void update();
    
    float pixelPerLed;
    
protected:
    void calculateLeds(Paddle* paddle, vector<ofColor>* colors);
    
private:
    
    vector<ofColor> colors;
    ofxOPC opcClient;
    GameElements* gameElements;
    
    vector<ofColor> colorsPaddle1,colorsPaddle2;
};

#endif
