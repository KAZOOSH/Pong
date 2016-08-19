/*
 *  GameObject.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 17.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _GameObject
#define _GameObject

#include "ofMain.h"
#include "GameElements.h"
#include "TextElement.h"

class AbstractGameControl {
public:
    AbstractGameControl(GameElements* gameElements, string name);
    virtual void begin();
    virtual void end() = 0;
    string getName();
    
    ofEvent<TextElement> newTextEvent;
    
protected:
    GameElements* gameElements;
    long startTime;
    string name;
    
    int runTime;
    
};

#endif
