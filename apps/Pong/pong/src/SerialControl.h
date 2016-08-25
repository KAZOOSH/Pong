/*
 *  SerialControl.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 24.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
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
    void readControl(ofx::IO::SerialDevice& serial, ofEvent<float>& event);
    
private:
    ofx::IO::SerialDevice paddleLeft, paddleRight;
};

#endif
