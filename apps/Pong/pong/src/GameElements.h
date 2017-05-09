/*
 *  GameElements.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _GameElements
#define _GameElements

#include "Ball.h"
#include "Paddle.h"
#include "LedControl.h"


//structs an enums for event handling

/**
 * event to notify the current score
 */
struct PlayerScoreEvent{
    PlayerScoreEvent(int _id, int _points){
        id = _id;
        points = _points;
    };
    int id;
    int points;
};

/**
 * event to notify a game action
 */
enum GameEvent{
    CONTACT_PADDLE1,
    CONTACT_PADDLE2,
    CONTACT_WALL,
    BALL_OUT_P1,
    BALL_OUT_P2,
    P1_WIN,
    P2_WIN,
    START};

/**
 * event to notify a playmode change
 */
struct PlayModeEvent{
    PlayModeEvent(string _name, bool _hasSoundset = false, string _nameSoundset = ""){
        name = _name;
        hasSoundset = _hasSoundset;
        if(_nameSoundset == "") nameSoundset = name;
        else nameSoundset = _nameSoundset;
    };
    
    string name;
    bool hasSoundset;
    string nameSoundset;
};

class GameElements {
    
public:
    GameElements();
    
    int getWidth();
    int getHeigth();
    
    void increasePoints(int player, int amount = 1);
    int getPoints(int player);
    
    int getWinScore();
    
    void resetElements();
    
    void notifyGameEvent(GameEvent e);
    
    ofEvent<GameEvent> newGameEvent; //!< triggered when game event happens
    ofEvent<PlayerScoreEvent> newScoreEvent; //!< triggered when score updated
    ofEvent<PlayModeEvent> newPlayModeEvent; //!< triggered when playmode changed
    
    Paddle paddleLeft, paddleRight; //!< paddles
    Ball ball; //!< balls
    
    ofParameter<float> minBallVelocity, maxBallVelocity;
    ofParameter<int> brightness;
    
    LedControl ledControl;
    
private:
    int widthGame, heightGame;//!< actual game size
    int pointsP1, pointsP2; //!< player score
    int winScore; //!< score needed for win
    
};

#endif
