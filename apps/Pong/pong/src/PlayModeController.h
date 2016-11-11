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

#include "AbstractRules.h"
#include "BasicRules.h"
#include "MultiBallMode.h"
#include "DoubleSpeedRule.h"
#include "PaddleSizeRule.h"
#include "BallSizeRule.h"
#include "GravityRule.h"
#include "SwerveRule.h"
#include "HeliumRule.h"
//-> include other rules here

#include "AbstractRenderer.h"
#include "BasicRenderer.h"
#include "AnaglyphRenderer.h"
#include "RoundBallRenderer.h"
#include "PsyRenderer.h"
#include "TennisRenderer.h"
#include "TrailRenderer.h"
#include "GifBGRenderer.h"
#include "InvisibleRenderer.h"
#include "SpriteBallRenderer.h"
//-> include other renderers here

#include "WallPlayMode.h"
#include "PortalPlayMode.h"
//-> include other playmodes here

/**
 * controls and switches the playmodes
 */
class PlayModeController {
    
public:
    void setup(GameElements* gameElements, TextRenderer* textRenderer);
    
    AbstractRenderer* getCurrentRenderer();
    AbstractRules* getCurrentRules();
    
    void resetStartModes();
    void shufflePlaymode();
    
    //listener
    void onEndMode(string& type);
    
    //for testing
    void setRenderer(int index);
    void setRenderer(string name);
    void setRules(int index);
    void setRules(string name);
    
private:
    vector<AbstractRules*> rules; //!< rule set
    int currentRules;
    
    vector<AbstractRenderer*> renderer; //!< renderer collection
    int currentRenderer;
    
    bool isNextSelectRules; //!<switch between rules and renderer every time
};

#endif
