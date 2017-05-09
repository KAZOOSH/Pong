/*
 *  PortalPlayMode.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Max Haferlach - 2016
 */

#include "PortalPlayMode.h"

//Portal
Portal::Portal(ofRectangle dimensions_){
    dimensions = dimensions_;
}

bool Portal::portalHittest(Ball* ball) {
    
    int b_x_min = ball->position.x - ball->radius;
    int b_x_max = ball->position.x + ball->radius;
    int b_y_min = ball->position.y - ball->radius;
    int b_y_max = ball->position.y + ball->radius;
    
    int w_x_min = dimensions.x;
    int w_x_max = dimensions.x + dimensions.width;
    int w_y_min = dimensions.y;
    int w_y_max = dimensions.y + dimensions.height;
    
    //edge side
    if (b_x_max >= w_x_min && b_x_max <= w_x_max) {
        if ((b_y_max >= w_y_min && b_y_max <= w_y_max) ||
            (b_y_min >= w_y_min && b_y_min <= w_y_max))
            
        {
            return true;
        }
    }
    
    if (b_x_min <= w_x_max && b_x_min >= w_x_min) {
        if ((b_y_max >= w_y_min && b_y_max <= w_y_max) ||
            (b_y_min >= w_y_min && b_y_min <= w_y_max))
            
        {
            return true;
        }
    }
    
    
    return false;
}


//Portal PLAYMODE

PortalPlayMode::PortalPlayMode(GameElements* gameElements, string name) : BasicPlaymode(gameElements, name,true,true) {
    
    portals.push_back(Portal(ofRectangle(gameElements->getWidth()*0.25, gameElements->getHeigth()*0.5, 10, 10)));
    portals.push_back(Portal(ofRectangle(gameElements->getWidth()*0.5, gameElements->getHeigth()*0.5, 10, 10)));
    
    
    sprite.load("images/portal.png");
    framesHorizontal = 3;
    framesVertical = 3;
    
    frameWidth = sprite.getWidth()/framesHorizontal;
    frameHeight = sprite.getHeight()/framesVertical;
    
    //decoder.decode("images/portal.gif");
    // portalImg = decoder.getFile();
    
}

//------------------------------------------------------------------
void PortalPlayMode::begin() {
    BasicPlaymode::begin();
    updatePortals();
}

void PortalPlayMode::updatePortals() {
    GameElements* gameElements = BasicPlaymode::gameElements;
    
    int wFirst = 100;
    int hFirst = 100;
    int xFirst = ofRandom(gameElements->getWidth()*.1, gameElements->getWidth()*0.4);
    int yFirst = ofRandom(hFirst,gameElements->getHeigth() - hFirst);
    
    portals[0].dimensions = ofRectangle(xFirst, yFirst, wFirst, hFirst);
    
    int wSecond = 100;
    int hSecond = 100;
    int xSecond = ofRandom(gameElements->getWidth()*.6, gameElements->getWidth()*0.9);
    int ySecond = ofRandom(hSecond,gameElements->getHeigth()-hSecond);
    
    portals[1].dimensions = ofRectangle(xSecond, ySecond, wSecond, hSecond);
    
}

//------------------------------------------------------------------
void PortalPlayMode::applyRules() {
    BasicPlaymode::applyRules();
    
    int new_x;
    int new_y;
    
    int ct_portal = 0;
    
    Ball* ball = &BasicPlaymode::gameElements->ball;
    
    new_x = ball->position.x;
    new_y = ball->position.y;
    for (auto portal : portals) {
        if (portal.portalHittest(ball)) {
            BasicPlaymode::gameElements->notifyGameEvent(CONTACT_WALL);
            if (ct_portal == 0) {
                if (ball->velocity.x > 0) {
                    new_x = portals[1].dimensions.x + portals[1].dimensions.width*1.01 + ball->radius;
                }
                else {
                    new_x = portals[1].dimensions.x - portals[1].dimensions.width*0.01 - ball->radius;
                }
                new_y += portals[1].dimensions.y-portals[0].dimensions.y;
            }
            else {
                if (ball->velocity.x > 0) {
                    new_x = portals[0].dimensions.x + portals[0].dimensions.width*1.01 + ball->radius;
                }
                else {
                    new_x = portals[0].dimensions.x - portals[0].dimensions.width*0.01 - ball->radius;
                }
                new_y += portals[0].dimensions.y - portals[1].dimensions.y;
            }
            
        }
        ct_portal++;
    }		
    ball->position.x = new_x;
    ball->position.y = new_y;
    
    
}


//------------------------------------------------------------------
void PortalPlayMode::render() {
    BasicPlaymode::render();
    
    
    BasicPlaymode::gameElements->ledControl.setColors(ofColor(192,0,255));
    
    for (auto portal : portals) {
        ofPushMatrix();
        ofTranslate(portal.dimensions.x, portal.dimensions.y);
        ofPushMatrix();
        int frame = (ofGetFrameNum()/3)%(framesHorizontal*framesVertical);
        float mult = 1;
        sprite.drawSubsection(-portal.dimensions.width*mult, -portal.dimensions.height*mult, portal.dimensions.width*2*mult, portal.dimensions.height*2*mult, frame%framesHorizontal*frameWidth, frame/framesHorizontal*frameHeight, frameWidth, frameHeight);
        ofPopMatrix();
        ofPopMatrix();
    }
    
    
}
