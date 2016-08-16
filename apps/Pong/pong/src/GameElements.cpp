/*
 *  GameElements.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 16.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "GameElements.h"

GameElements::GameElements(){
    //setup game size
    widthGame = 1500;
    heightGame = 1080;
    
    paddleLeft.setup(0, widthGame, heightGame);
    paddleRight.setup(widthGame-1, widthGame, heightGame);
    
    addBall(ofVec2f(widthGame/2, heightGame/2));
}

int GameElements::getWidth(){
    return widthGame;
}

int GameElements::getHeigth(){
    return heightGame;
}

/**
 * adds ball to game
 */
void GameElements::addBall(ofVec2f position, ofVec2f velocity){
    balls.push_back(new Ball());
    balls.back()->velocity = velocity;
    balls.back()->position = position;
}

/**
 * remove Ball with specific id from game
 */
bool GameElements::removeBall(long id){
    int index = -1;
    for (int i= 0; i<balls.size(); ++i) {
        if(balls[i]->id == id) index = i;
    }
    if (index!=-1){
        balls.erase(balls.begin() + index);
        return true;
    }
    ofLogWarning("GameElements::removeBall -> id not found");
    return false;
}

/**
 * removes all balls but the first one from game
 */
void GameElements::removeAllExtraBalls(){
    for (int i= balls.size()-1; i>=1; --i) {
        balls.pop_back();
    }
}

