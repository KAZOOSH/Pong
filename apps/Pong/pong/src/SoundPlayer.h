/*
 *  SoundPlayer.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 17.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
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
    
protected:
    bool loadSoundSet(string name);
    
private:
    vector<ofSoundPlayer*> playerList;
    map<GameEvent, ofSoundPlayer*> player;
    
    ofSoundPlayer playMode;
};

#endif