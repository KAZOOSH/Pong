/*
 *  AbstractRenderer.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "AbstractRenderer.h"


//------------------------------------------------------------------
AbstractRenderer::AbstractRenderer(GameElements* gameElements_, string name):AbstractGameControl(gameElements_,name,"Renderer") {
    
}

void AbstractRenderer::draw(){
    if (durationMode != -1) {
        if (startTime + durationMode < ofGetElapsedTimeMillis()) {
            ofNotifyEvent(durationExtendedEvent, type);
        }
    }
    render();
}
