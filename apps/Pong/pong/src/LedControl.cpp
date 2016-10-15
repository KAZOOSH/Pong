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
void LedControl::setup(GameElements* gameElements_) {
    opcClient.setup("127.0.0.1", 7890);
    gameElements = gameElements_;
    
    pixelPerLed.set("pixelPerLED",10.0);
    
    for(int i=0; i<N_LEDS; ++i){
        colorsPaddle1.push_back(0);
        colorsPaddle2.push_back(0);
    }
    
    brightness.set("brightness",128);
}


//------------------------------------------------------------------
void LedControl::update() {
    calculateLeds(&gameElements->paddleLeft, &colorsPaddle1);
    calculateLeds(&gameElements->paddleRight, &colorsPaddle2);
    
    // If the client is not connected do not try and send information
    if (!opcClient.isConnected())
    {
        // Will continue to try and reconnect to the Pixel Server
    }
    else
    {
        opcClient.writeChannel(2,colorsPaddle1);
        opcClient.writeChannel(1,colorsPaddle2);
    }
}

uint8_t LedControl::getBrightness(){
    return brightness;
}

void LedControl::setBrightness(uint8_t brightness_){
    brightness = brightness_;
}

void LedControl::calculateLeds(Paddle* paddle, vector<ofColor>* colors){
    float p_absolut = ofMap(paddle->getPosition(),0, gameElements->getHeigth(),0,1);
    int nLedsPaddle = paddle->height / pixelPerLed;
    
    int pixelStart = ofMap(p_absolut, 1,0, 0, N_LEDS - nLedsPaddle);
    
    for(int i=0; i<N_LEDS; ++i){
        if(i < pixelStart || i > pixelStart + nLedsPaddle)
            colors->at(i) = ofColor(0);
        else
            colors->at(i) = ofColor(brightness);
    }
    
}