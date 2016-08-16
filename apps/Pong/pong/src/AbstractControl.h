/*
 *  AbstractControl.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _AbstractControl
#define _AbstractControl

#include "ofMain.h"


class AbstractControl {
	
  public:
	
    AbstractControl(){};
	
    ofEvent<float> newPositionPaddle1Event;
    ofEvent<float> newPositionPaddle2Event;
	
};

#endif
