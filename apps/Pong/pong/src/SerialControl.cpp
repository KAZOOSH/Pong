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
        bool success = paddleLeft.setup(devicesInfo[0], 115200);
        
        if(success)
        {
            ofLogNotice("ofApp::setup") << "Successfully setup paddle left " << devicesInfo[0];
        }
        else
        {
            ofLogNotice("ofApp::setup") << "Unable to setup paddle left " << devicesInfo[0];
        }
        
        success = paddleRight.setup(devicesInfo[1], 115200);
        
        if(success)
        {
            ofLogNotice("ofApp::setup") << "Successfully setup paddle right " << devicesInfo[0];
        }
        else
        {
            ofLogNotice("ofApp::setup") << "Unable to setup paddle right " << devicesInfo[0];
        }
        
    }
    else
    {
        ofLogNotice("ofApp::setup") << "No devices connected.";
    }
    
    
    
}



void SerialControl::update(){
    try
    {
        readControl(paddleLeft, newPositionPaddle1Event);
        readControl(paddleLeft, newPositionPaddle2Event);
        
    }catch (const std::exception& exc)
    {
        ofLogError("ofApp::update") << exc.what();
    }
}

void SerialControl::readControl(ofx::IO::SerialDevice& serial, ofEvent<float>& event){
    uint8_t buffer[100];
    
    serial.writeByte('0');
    
    while (serial.available() > 0)
    {
        // read all bytes (to prevent input queuing)
        // however, only the first byte will be parsed
        std::size_t sz = serial.readBytes(buffer, 100);
        
        int16_t value;
        value = (buffer[0] << 8) + buffer[1];
        
        float yPaddle = ofMap(value, -1024, 1024, 0, 1);
        ofNotifyEvent(event, yPaddle, this);
        
    }
    
}