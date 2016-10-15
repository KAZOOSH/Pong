/*
 *  SerialControl.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _SerialControl
#define _SerialControl

#include "ofMain.h"


#include "AbstractControl.h"
#include "ofxSerial.h"

class SerialControl : public AbstractControl{
    
public:
    
    SerialControl();
    void update();
    
private:
    void readControl(ofx::IO::SerialDevice& serial, ofEvent<float>& event, bool invertCoords);
    
private:
    ofx::IO::SerialDevice paddleLeft, paddleRight;
};

#endif
