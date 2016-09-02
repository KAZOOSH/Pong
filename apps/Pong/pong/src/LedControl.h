/*
 *  LedControl.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _LedControl
#define _LedControl

#include "ofMain.h"
#include "ofxOPC.h"
#include "Paddle.h"

#define N_LEDS 35 //<! total number of physical LEDs

/**
 * Led panel components
 */
struct LedPanel{
    Paddle* paddle; //!< virtual paddle
    vector<ofColor> colors; //!< colors of active leds
    vector<ofColor> colorBuffer; //!< all colors of LED, including inactive LEDs
    int nActiveLeds; //!< number of active LEDs on Panel
};


/**
 * controles the LED panels via opc client (Fadecandy)
 * https://github.com/scanlime/fadecandy
 */
class LedControl {
    
public:
    
    void setup(Paddle* paddle1,Paddle* paddle2, int heightField);
    void update();
    
    vector<ofColor> getColorsPaddle1();
    vector<ofColor> getColorsPaddle2();
    void setColors(ofColor color, int panel = 0);
    void setColors(vector<ofColor> colors, int panel = 0);
    void setColorsPaddle1(vector<ofColor> colors);
    void setColorsPaddle2(vector<ofColor> colors);
    
    ofParameter<float> pixelPerLed;
    
    //listener
    void onPaddle1HeightChanged(int& height);
    void onPaddle2HeightChanged(int& height);
    void onPixelPerLedChanged(float& height);
    
protected:
    void calculateLeds(LedPanel& panel);
    void setColors(vector<ofColor> inColors, vector<ofColor>& paddleColors);
    void updateColors(LedPanel& panel);
    
private:
    ofxOPC opcClient;//!< client that communictes with fadecandy
    int heightField;//!< total height of the court
    LedPanel panel1,panel2; //!< panels
    
    
    
};

#endif
