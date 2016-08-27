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
#include "Paddle.h"

#define N_LEDS 35

class LedControl {
    
public:
    
    void setup(Paddle* paddle1,Paddle* paddle2, int heightField);
    void update();
    
    ofColor getColor();
    void setColor(ofColor color);
    
    ofParameter<float> pixelPerLed;
    ofParameter<ofColor> color;
    
protected:
    void calculateLeds(Paddle* paddle, vector<ofColor>* colors);
    
private:
    
    vector<ofColor> colors;
    ofxOPC opcClient;
    
    Paddle* paddle1;
    Paddle* paddle2;
    int heightField;
    vector<ofColor> colorsPaddle1,colorsPaddle2;
};

#endif
