//
//  PlaymodeFactory.cpp
//  PONG
//
//  Created by Brian Eschrich on 27.04.17.
//
//

#include "PlaymodeFactory.h"

AbstractGameControl* PlaymodeFactory::make_playMode(string playModeName, GameElements* gameElements)
{
    AbstractGameControl* c = nullptr;
    
    //rules
    if (playModeName == "Double Speed") {
        c = new DoubleSpeedRule(gameElements);
    }
    else if (playModeName == "Small Paddle") {
        c = new PaddleSizeRule(gameElements, "Small Paddle", 0.5);
    }
    else if (playModeName == "Big Paddle") {
        c = new PaddleSizeRule(gameElements, "Big Paddle", 2.0);
    }
    else if (playModeName == "Tiny Ball") {
        c = new BallSizeRule(gameElements, "Tiny Ball", 0.3);
    }
    else if (playModeName == "Gravity") {
        c = new GravityRule(gameElements);
    }
    else if (playModeName == "Swerve") {
        c = new SwerveRule(gameElements);
    }
    else if (playModeName == "Helium") {
        c = new HeliumRule(gameElements);
    }
    //renderers
    else if (playModeName == "Anaglyph") {
        c = new AnaglyphRenderer(gameElements);
    }
    else if (playModeName == "Round Ball") {
        c = new RoundBallRenderer(gameElements);
    }
    else if (playModeName == "PSY") {
        c = new PsyRenderer(gameElements);
    }
    else if (playModeName == "Tennis") {
        c = new TennisRenderer(gameElements);
    }
    else if (playModeName == "Trails") {
        c = new TrailRenderer(gameElements);
    }
    else if (playModeName == "Movie") {
        c = new GifBGRenderer(gameElements);
    }
    else if (playModeName == "Invisible Ball") {
        c = new InvisibleRenderer(gameElements);
    }
    else if (playModeName == "Goat Mode") {
        c = new SpriteBallRenderer(gameElements);
    }
    else if (playModeName == "Dalmatian") {
        c = new SpriteBallRenderer(gameElements,"Dalmatian","images/dalmatian.png",4,2);
    }
    //playmodes
    else if (playModeName == "Walls") {
        c = new WallPlayMode(gameElements);
    }
    else if (playModeName == "Portals") {
        c = new PortalPlayMode(gameElements);
    }
    else if (playModeName == "Multiball") {
        c = new MultiBallMode(gameElements);
    }
    
    if (c != nullptr)
    {
        ofLogNotice(playModeName + " mode created");
    }
    else {
        ofLogError("no playmode named " + playModeName);
    }
    return c;
    
}


