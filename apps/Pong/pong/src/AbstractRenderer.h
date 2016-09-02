/*
 *  AbstractRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _AbstractRenderer
#define _AbstractRenderer

#include "AbstractGameControl.h"

class AbstractRenderer : public AbstractGameControl{
	
  public:
	
	AbstractRenderer(GameElements* gameElements, string name);
	void draw();
    virtual void render() = 0;
    
};

#endif
