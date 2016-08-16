/*
 *  MouseControl.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "MouseControl.h"


//------------------------------------------------------------------
MouseControl::MouseControl():AbstractControl() {
    ofAddListener(ofEvents().mouseMoved,this,&MouseControl::mouseMoved);
	
}

void MouseControl::mouseMoved(ofMouseEventArgs & args){
    
    float yPaddle = ofMap(args.y, 0, ofGetHeight(), 0, 1);
    ofNotifyEvent(newPositionPaddle1Event, yPaddle, this);
    ofNotifyEvent(newPositionPaddle2Event, yPaddle, this);
}

