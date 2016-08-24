/*
 *  SerialControl.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 24.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "SerialControl.h"

SerialControl::SerialControl():AbstractControl() {
    
    std::vector<ofx::IO::SerialDeviceInfo> devicesInfo = ofx::IO::SerialDeviceUtils::listDevices();
    
    ofLogNotice("ofApp::setup") << "Connected Devices: ";
    
    for (std::size_t i = 0; i < devicesInfo.size(); ++i)
    {
        ofLogNotice("ofApp::setup") << "\t" << devicesInfo[i];
    }
    
    if (!devicesInfo.empty())
    {
        // Connect to the first matching device.
        bool success = serial.setup(devicesInfo[0], 115200);
        
        if(success)
        {
            serial.registerAllEvents(this);
            ofLogNotice("ofApp::setup") << "Successfully setup paddle " << devicesInfo[0];
        }
        else
        {
            ofLogNotice("ofApp::setup") << "Unable to setup paddle " << devicesInfo[0];
        }
        
    }
    else
    {
        ofLogNotice("ofApp::setup") << "No devices connected.";
    }
    
    
    
}

void SerialControl::onSerialBuffer(const ofx::IO::SerialBufferEventArgs& args){
    
    float p1 = ofMap(args.getBuffer()[0], 0, 255, 0, 1);
    float p2 = ofMap(args.getBuffer()[1], 0, 255, 0, 1);
    ofNotifyEvent(newPositionPaddle1Event, p1, this);
    ofNotifyEvent(newPositionPaddle2Event, p2, this);
}

void SerialControl::onSerialError(const ofx::IO::SerialBufferErrorEventArgs& args)
{
    
}