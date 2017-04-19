/*
 *  AbstractControl.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _AbstractControl
#define _AbstractControl

#include "ofMain.h"


class AbstractControl {
    
public:
    
    AbstractControl(){};
    virtual void update(){};
    
    ofEvent<float> newPositionPaddle1Event;
    ofEvent<float> newPositionPaddle2Event;
    
};

#endif
