/*
 *  PlayModeController.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _PlayModeController
#define _PlayModeController

#include "ofMain.h"
#include "GameElements.h"
#include "TextRenderer.h"

#include "AbstractGameControl.h"
#include "BasicPlaymode.h"

#include "PlaymodeFactory.h"


/**
 * controls and switches the playmodes
 */
class PlayModeController {
    
public:
    void setup(GameElements* gameElements, TextRenderer* textRenderer);
    
    AbstractGameControl* getCurrentRenderer();
    AbstractGameControl* getCurrentRules();
    
    void resetStartModes();
    void shufflePlaymode();
    
    //listener
    void onEndMode(AbstractGameControl& c);
    
    //for testing
    void setPlaymode(string name);
    
protected:
    void addBasicPlaymodes();
    void initPlaymodesFromXml(string path = "playmodes.xml");
    void addPlaymode(string name);
    
    void setRenderer(AbstractGameControl* r);
    void setRules(AbstractGameControl* r);
    void setPlaymode(AbstractGameControl* r);
    
private:
    map<string,AbstractGameControl*> playmodes;
    vector<AbstractGameControl*> v_playmodes;
    vector<string> shufflePlaymodeSet;
    
    AbstractGameControl* currentRules;
    AbstractGameControl* currentRenderer;
    
    BasicPlaymode* basicPlaymode;
    
    GameElements* gameElements;
};

#endif
