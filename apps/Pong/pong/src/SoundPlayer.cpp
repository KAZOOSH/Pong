/*
 *  SoundPlayer.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "SoundPlayer.h"


//------------------------------------------------------------------
void SoundPlayer::setup() {
    //create Player for each sound
    for (int i=0; i<8; ++i) {
        playerList.push_back(new ofSoundPlayer());
    }
    player[CONTACT_PADDLE1] = playerList[0];
    player[CONTACT_PADDLE2] = playerList[1];
    player[CONTACT_WALL] = playerList[2];
    player[BALL_OUT_P1] = playerList[3];
    player[BALL_OUT_P2] = playerList[4];
    player[P1_WIN] = playerList[5];
    player[P2_WIN] = playerList[6];
    player[START] = playerList[7];
    
    loadSoundSet("basic");
    currentSoundSet = "basic";
    
    isModerationMode.set("isModerationMode", true);
}


//------------------------------------------------------------------
void SoundPlayer::update() {
    
}


//------------------------------------------------------------------
void SoundPlayer::draw() {
    
    
}

void SoundPlayer::onGameEvent(GameEvent& event){
    player[event]->play();
}

void SoundPlayer::onPlaymodeChanged(PlayModeEvent& event){
    if (event.name !="" && isModerationMode) {
        playMode.load("sounds/playmodes/" + event.name + ".mp3");
        playMode.play();
    }
    
    if (event.hasSoundset) {
        loadSoundSet(event.nameSoundset);
        currentSoundSet = event.nameSoundset;
    }else if(currentSoundSet != "basic"){
        loadSoundSet("basic");
    }
}

bool SoundPlayer::loadSoundSet(string name){
    player[CONTACT_PADDLE1]->load("sounds/" + name + "/contact_paddle1.mp3");
    player[CONTACT_PADDLE2]->load("sounds/" + name + "/contact_paddle2.mp3");
    player[CONTACT_WALL]->load("sounds/" + name + "/contact_wall.mp3");
    player[BALL_OUT_P1]->load("sounds/" + name + "/ball_out_p1.mp3");
    player[BALL_OUT_P2]->load("sounds/" + name + "/ball_out_p2.mp3");
    player[P1_WIN]->load("sounds/" + name + "/p1_win.mp3");
    player[P2_WIN]->load("sounds/" + name + "/p2_win.mp3");
    player[START]->load("sounds/" + name + "/start.mp3");
    return true;
}