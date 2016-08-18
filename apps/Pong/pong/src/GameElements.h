/*
 *  GameElements.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 15.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _GameElements
#define _GameElements

#include "Ball.h"
#include "Paddle.h"

struct PlayerScore{
    int id;
    int points;
};

enum GameEvent{
    CONTACT_PADDLE1,
    CONTACT_PADDLE2,
    CONTACT_WALL,
    BALL_OUT_P1,
    BALL_OUT_P2,
    P1_WIN,
    P2_WIN,
    START};

class GameElements {
    
public:
    GameElements();
    
    int getWidth();
    int getHeigth();
    
    void addBall(ofVec2f position, ofVec2f velocity = ofVec2f(-3, 0));
    bool removeBall(long id);
    void removeAllExtraBalls();
    
    void increasePoints(int player, int amount = 1);
    int getPoints(int player);
    
    int getWinScore();
    
    void resetElements();
    
    ofEvent<PlayerScore> scoreEvent;
    
    Paddle paddleLeft, paddleRight; //!< paddles
    vector<Ball*> balls; //!< balls
    
    
private:
    int widthGame, heightGame;//!< actual game size
    int pointsP1, pointsP2; //!< player score
    int winScore; //!< score needed for win
    
};

#endif
