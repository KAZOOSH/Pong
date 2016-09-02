/*
 *  SoundPlayer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _SoundPlayer
#define _SoundPlayer

#include "ofMain.h"
#include "GameElements.h"

class SoundPlayer {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void onGameEvent(GameEvent& event);
    void onPlaymodeChanged(PlayModeEvent& event);
    
    ofParameter<bool> isModerationMode;
    
protected:
    bool loadSoundSet(string name);
    
private:
    vector<ofSoundPlayer*> playerList;
    map<GameEvent, ofSoundPlayer*> player;
    string currentSoundSet;
    
    ofSoundPlayer playMode;
};

#endif
