/*
 *  LedControl.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 23.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "LedControl.h"


//------------------------------------------------------------------
void LedControl::setup(Paddle* paddle1_,Paddle* paddle2_,int heightField_) {
    opcClient.setup("127.0.0.1", 7890);
    paddle1 = paddle1_;
    paddle2 = paddle2_;
    heightField = heightField_;
    
    pixelPerLed.set("pixelPerLED",10.0);
    
    for(int i=0; i<N_LEDS; ++i){
        colorsPaddle1.push_back(0);
        colorsPaddle2.push_back(0);
    }
    
    color.set("color",ofColor(128));
}


//------------------------------------------------------------------
void LedControl::update() {
    calculateLeds(paddle1, &colorsPaddle1);
    calculateLeds(paddle2, &colorsPaddle2);
    
    // If the client is not connected do not try and send information
    if (!opcClient.isConnected())
    {
        // Will continue to try and reconnect to the Pixel Server
    }
    else
    {
        opcClient.writeChannel(1,colorsPaddle1);
        opcClient.writeChannel(2,colorsPaddle2);
    }
}

ofColor LedControl::getColor(){
    return color;
}

void LedControl::setColor(ofColor color_){
    color = color_;
}

void LedControl::calculateLeds(Paddle* paddle, vector<ofColor>* colors){
    float p_absolut = ofMap(paddle->getPosition(),0, heightField,0,1);
    int nLedsPaddle = paddle->height / pixelPerLed;
    
    int pixelStart = ofMap(p_absolut, 1,0, 0, N_LEDS - nLedsPaddle);
    
    for(int i=0; i<N_LEDS; ++i){
        if(i < pixelStart || i > pixelStart + nLedsPaddle)
            colors->at(i) = ofColor(0);
        else
            colors->at(i) = color;
    }
    
}