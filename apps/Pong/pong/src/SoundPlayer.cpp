/*
 *  SoundPlayer.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 17.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
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
    
}


//------------------------------------------------------------------
void SoundPlayer::update() {
    
}


//------------------------------------------------------------------
void SoundPlayer::draw() {
    
    
}

void SoundPlayer::onSoundSetChanged(string& name){
    loadSoundSet(name);
}

void SoundPlayer::onGameEvent(GameEvent& event){
    player[event]->play();
}

void SoundPlayer::onPlaymodeChanged(string& name){
    playMode.load("sounds/playmodes/" + name + ".mp3");
    playMode.play();
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
}