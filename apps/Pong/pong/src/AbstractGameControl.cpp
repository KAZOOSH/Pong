/*
 *  GameObject.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "AbstractGameControl.h"


//------------------------------------------------------------------
AbstractGameControl::AbstractGameControl(GameElements* gameElements_, string name_, bool isRules_, bool isRenderer_) {
    gameElements = gameElements_;
    name = name_;
    durationMode = 15000;
    _isRules = isRules_;
    _isRenderer = isRenderer_;
}

void AbstractGameControl::update(){
    if (durationMode != -1) {
        if (startTime + durationMode < ofGetElapsedTimeMillis()) {
            ofNotifyEvent(durationExtendedEvent, *this);
        }
    }
    applyRules();
}

void AbstractGameControl::draw(){
    if (durationMode != -1) {
        if (startTime + durationMode < ofGetElapsedTimeMillis()) {
            ofNotifyEvent(durationExtendedEvent, *this);
        }
    }
    render();
}

void AbstractGameControl::begin(){
    startTime = ofGetElapsedTimeMillis();
    
    textSize t_size = BIG;
    if (name.size()>10) {
        t_size = MEDIUM;
    }
    
    TextElement t(name,
                  t_size,
                  true,
                  2000);
    ofNotifyEvent(newTextEvent,t);
    
    //notify game event
    PlayModeEvent e = PlayModeEvent(name);
    ofNotifyEvent(gameElements->newPlayModeEvent, e);
}

void AbstractGameControl::end(){
    if (name.size()>0) {
        textSize t_size = BIG;
        if (name.size()>10) {
            t_size = MEDIUM;
        }
        
        TextElement t(name + " end",
                      t_size,
                      true,
                      500);
        ofNotifyEvent(newTextEvent,t);
    }
}

string AbstractGameControl::getName(){
    return name;
}