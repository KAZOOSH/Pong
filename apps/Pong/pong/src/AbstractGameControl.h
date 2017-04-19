/*
 *  GameObject.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _GameObject
#define _GameObject

#include "ofMain.h"
#include "GameElements.h"
#include "TextElement.h"

class AbstractGameControl {
public:
    AbstractGameControl(GameElements* gameElements, string name, string type);
    virtual void begin();
    virtual void end();
    string getName();
    
    ofEvent<TextElement> newTextEvent;
    ofEvent<string> durationExtendedEvent;
    
protected:
    GameElements* gameElements;
    long startTime;
    string name;
    
    int durationMode;
    
    string type;
    
};

#endif
