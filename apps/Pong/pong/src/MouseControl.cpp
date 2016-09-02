/*
 *  MouseControl.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
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

