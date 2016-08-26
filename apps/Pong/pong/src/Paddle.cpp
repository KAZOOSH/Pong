/*
 *  Paddle.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 06.07.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "Paddle.h"

Paddle::Paddle(){
    y = 50;// gameElements->getHeigth()/2;
    height.set("height",100);
    
    isDebug = true;
}

//------------------------------------------------------------------
void Paddle::setup(int x_, int wGame_, int hGame_) {
    x = x_;
    wGame = wGame_;
    hGame = hGame_;
}


//------------------------------------------------------------------
void Paddle::draw() {
    if (isDebug) {
        ofSetColor(255);
        ofDrawRectangle(x-15,y-height*0.5, 30, height);
    }
    
}

void Paddle::addControl(AbstractControl& control){
    if (x == 0) {
        ofAddListener(control.newPositionPaddle1Event, this, &Paddle::onPositionChanged);
    }
    else{
        ofAddListener(control.newPositionPaddle2Event, this, &Paddle::onPositionChanged);
    }
}

void Paddle::onPositionChanged(float& pos){
    y = ofMap(pos ,0 ,1 ,height*.5 ,hGame - height*.5,true);
}

int Paddle::getPosition(){
    return y;
}

/**
 * returns if the paddle is hit by a ball
 */
bool Paddle::isHit(Ball& b){
    if ((x == 0 && b.position.x-b.radius <=0)
        || (x > 0 && b.position.x+b.radius >= wGame)) {
        if(abs(y - b.position.y) <= (height + b.radius)*0.5)
        {
            return true;
        }
    }
    return false;
}

/**
 * returns where the ball hits the paddle as float
 * -5 bottom  0 center  5 top
 */
float Paddle::getHitzone(Ball& b){
    return ofMap(b.position.y, y - height*.5, y + height*.5, -5, 5, true);
}