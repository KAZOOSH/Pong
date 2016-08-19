#pragma once

#include "ofMain.h"
#include "ofxQuadWarp.h"

#include "GameElements.h"
#include "PlayModeController.h"
#include "SoundPlayer.h"
#include "AbstractRules.h"
#include "BasicRules.h"
#include "MultiBallRule.h"
//-> include other rules here

#include "AbstractRenderer.h"
#include "BasicRenderer.h"
#include "AnaglyphRenderer.h"
//-> include other renderers here

#include "TextRenderer.h"

#include "MouseControl.h"

class ofApp : public ofBaseApp{
public:
    void setup(); //!< configures App
    void update(); //!< runs every frame, updates game rules
    void draw(); //!< runs every frame, updates rendering
    
    void initWarper();
    void drawWarpedImage();
    
    void restartGame();
    void endGame(int winner);
    void showInitMessage();
    void startGame();
    
    ofEvent<TextElement> gameOverEvent;
    
    //listeners
    void onEndRules(bool& isEnd);
    void onEndRenderer(bool& isEnd);
    void onPointsChanged(PlayerScoreEvent& e);
    
    void keyPressed(int key);
    
private:
    long tGameFinished;
    bool isInitMessageShown;
    bool isGameRunning;//!< game status
    
    ofxQuadWarp warper; //!< mapping tool
    ofFbo gameFbo; //!< game graphics are rendered in fbo
    
    SoundPlayer soundPlayer;//!< manages sounds and plays it
    GameElements elements; //!< balls and paddles, shared over all classes
    PlayModeController playModeController;
    
    TextRenderer* textRenderer;
    
    MouseControl mouse;
};
