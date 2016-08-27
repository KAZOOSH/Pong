#pragma once

#include "ofMain.h"
#include "ofxQuadWarp.h"

#include "GameElements.h"
#include "PlayModeController.h"
#include "SoundPlayer.h"

#include "TextRenderer.h"

#include "MouseControl.h"
#include "SerialControl.h"

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
    
    void initSettings();
    void saveSettings();
    void loadSettings();
    
    ofEvent<TextElement> gameOverEvent;
    
    //listeners
    void onPointsChanged(PlayerScoreEvent& e);
    
    void keyPressed(int key);
    
private:
    long tGameFinished;
    bool isInitMessageShown;
    bool isGameRunning;//!< game status
    
    bool isPlayerReady;
    long tPlayerReady;
    
    bool showDebugInfos;
    
    ofxQuadWarp warper; //!< mapping tool
    ofFbo gameFbo; //!< game graphics are rendered in fbo
    
    SoundPlayer soundPlayer;//!< manages sounds and plays it
    GameElements elements; //!< balls and paddles, shared over all classes
    PlayModeController playModeController;
    
    TextRenderer* textRenderer;
    
    MouseControl mouse;
    
    
    
    ofParameterGroup settings;
};
