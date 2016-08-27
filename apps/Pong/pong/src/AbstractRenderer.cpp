/*
 *  AbstractRenderer.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
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
