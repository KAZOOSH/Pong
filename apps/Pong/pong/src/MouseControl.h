/*
 *  MouseControl.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
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
