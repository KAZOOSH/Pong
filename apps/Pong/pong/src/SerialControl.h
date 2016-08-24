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
    
    void onSerialBuffer(const ofx::IO::SerialBufferEventArgs& args);
    void onSerialError(const ofx::IO::SerialBufferErrorEventArgs& args);
    
private:
    ofx::IO::PacketSerialDevice serial;
};

#endif
