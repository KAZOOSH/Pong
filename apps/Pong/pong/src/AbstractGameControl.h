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
    AbstractGameControl(GameElements* gameElements, string name, bool isRules, bool isRenderer, int duration = 7500);
    virtual void begin();
    virtual void end();
    string getName();
    
    void draw();
    void update();
    
    bool isRenderer(){return _isRenderer;};
    bool isRules(){return _isRules;};
    
    virtual void applyRules(){ofLogNotice("AbstractGameControl", "you need to implement rules if you want to use them");};
    virtual void render() {ofLogNotice("AbstractGameControl", "you need to implement a render function if you want to use it");};
    
    ofEvent<TextElement> newTextEvent;
    ofEvent<AbstractGameControl> durationExtendedEvent;
    
protected:
    GameElements* gameElements;
    long startTime;
    string name;
    int durationMode;
    string type;
    
private:
    bool _isRenderer;
    bool _isRules;
    
};

#endif
