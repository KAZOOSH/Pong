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

class GameElements {
	
  public:
    GameElements();
    
    int getWidth();
    int getHeigth();
    
    void addBall(ofVec2f position, ofVec2f velocity = ofVec2f(-3, 0));
    bool removeBall(long id);
    void removeAllExtraBalls();
    
    Paddle paddleLeft, paddleRight; //!< paddles
    vector<Ball*> balls; //!< balls
    int pointsP1, pointsP2; //!< player score
    
private:
    int widthGame, heightGame;//!< actual game size
	
	
};

#endif
