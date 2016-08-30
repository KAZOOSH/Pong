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
    heightField = heightField_;
    pixelPerLed.set("pixelPerLED",10.0);
    
    
    panel1.paddle = paddle1_;
    panel2.paddle = paddle2_;
    
    for(int i=0; i<N_LEDS; ++i){
        panel1.colorBuffer.push_back(0);
        panel2.colorBuffer.push_back(0);
    }
    setColors(ofColor(128));
    
    panel1.paddle->height.addListener(this, &LedControl::onPaddle1HeightChanged);
    panel2.paddle->height.addListener(this, &LedControl::onPaddle2HeightChanged);
    
}

/**
 * updating the leds, should be called every frame
 */
//------------------------------------------------------------------
void LedControl::update() {
    calculateLeds(panel1);
    calculateLeds(panel2);
    
    // If the client is not connected do not try and send information
    if (!opcClient.isConnected())
    {
        // Will continue to try and reconnect to the Pixel Server
    }
    else
    {
        opcClient.writeChannel(1,panel1.colorBuffer);
        opcClient.writeChannel(2,panel2.colorBuffer);
    }
}

/*
 * returns an array of the active leds on panel1
 */
vector<ofColor> LedControl::getColorsPaddle1(){
    return panel1.colors;
}

/*
 * returns an array of the active leds
 */
vector<ofColor> LedControl::getColorsPaddle2(){
    return panel2.colors;
}

/*
 * sets paddle with a solid color
 * paddle can be 0 - both  1 - left  2 - right
 */
void LedControl::setColors(ofColor color_, int panel){
    vector<ofColor> colors;
    
    if (panel == 0 || panel == 1) {
        for (int i=0; i<panel1.nActiveLeds; ++i) {
            colors.push_back(color_);
        }
        setColorsPaddle1(colors);
        
    }
    else if (panel == 0 || panel == 2) {
        for (int i=0; i<panel2.nActiveLeds; ++i) {
            colors.push_back(color_);
        }
        setColorsPaddle2(colors);
    }
}

/**
 * sets an array of colors on paddle
 */
void LedControl::setColorsPaddle1(vector<ofColor> colors){
    setColors(colors, panel1.colors);
}

/**
 * sets an array of colors on paddle
 */
void LedControl::setColorsPaddle2(vector<ofColor> colors){
    setColors(colors, panel2.colors);
}

/**
 * calculates colorBuffer
 */
void LedControl::calculateLeds(LedPanel& panel){
    //clear color buffer
    for (int i=0; i<panel.colorBuffer.size(); ++i) {
        panel.colorBuffer[i] = ofColor(0);
    }
    float p_absolut = ofMap(panel.paddle->getPosition(),0, heightField,0,1);
    
    int pixelStart = ofMap(p_absolut, 1,0, 0, N_LEDS - panel.nActiveLeds);
    
    for(int i=0; i<N_LEDS; ++i){
        if(i < pixelStart || i > pixelStart + panel.nActiveLeds)
            panel.colorBuffer[i] = ofColor(0);
        else
            panel.colorBuffer[i] = panel.colors[i-pixelStart];
    }
    
}

void LedControl::setColors(vector<ofColor> inColors, vector<ofColor>& paddleColors){
    for (int i=0; i<paddleColors.size(); ++i) {
        if (i<inColors.size()) {
            paddleColors[i] = inColors[i];
        }
    }
    
}

void LedControl::onPaddle1HeightChanged(int& height){
    updateColors(panel1);
}

void LedControl::onPaddle2HeightChanged(int& height){
    updateColors(panel2);
}

void LedControl::onPixelPerLedChanged(float& height){
    updateColors(panel1);
    updateColors(panel2);
}

void LedControl::updateColors(LedPanel& panel){
    panel.nActiveLeds = panel.paddle->height / pixelPerLed;
    ofColor newColor = panel.colors.back();
    panel.colors.resize(panel.nActiveLeds,newColor);
}

