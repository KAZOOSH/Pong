/*
 *  ofApp.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - 2016
 *  http://kazoosh.com
 *
 *  created by Brian Eschrich - 2016
 */

#pragma once

#include "ofMain.h"
#include "ofxQuadWarp.h"

#include "GameElements.h"
#include "PlayModeController.h"
#include "SoundPlayer.h"

#include "TextRenderer.h"

#include "MouseControl.h"
#include "SerialControl.h"

enum Gamestate{
    PLAYERS_PREPARING,
    WAIT_FOR_START,
    RUNNING,
    END
};


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
    void prepareForStart();
    void startGame();
    void drawDebugInformation();
    void changeGameState(Gamestate gamestate);
    
    void initSettings();
    void saveSettings();
    void loadSettings();
    
    ofEvent<TextElement> gameOverEvent;
    
    ofParameter<bool> isSerialControl;
    ofParameter<string> portLeftPaddle, portRightPaddle;
    
    //listeners
    void onPointsChanged(PlayerScoreEvent& e);
    
    void keyPressed(int key);
    
private:
    Gamestate gamestate; //<! current game status
    long lastGamestateChange;
    
    bool showDebugInfos;
    
    ofxQuadWarp warper; //!< mapping tool
    ofFbo gameFbo; //!< game graphics are rendered in fbo
    
    SoundPlayer soundPlayer;//!< manages sounds and plays it
    GameElements elements; //!< balls and paddles, shared over all classes
    PlayModeController playModeController;
    
    TextRenderer* textRenderer;
    
    AbstractControl* mouse;
    //SerialControl mouse;
    
    
    ofParameterGroup settings;
};
