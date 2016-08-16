/*
 *  MouseControl.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _MouseControl
#define _MouseControl

#include "AbstractControl.h"


class MouseControl : public AbstractControl{
	
  public:
	
	MouseControl();
	
    void mouseMoved(ofMouseEventArgs & args);
    
	
};

#endif
