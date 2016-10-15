/*
 *  Ball.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 06.07.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "Ball.h"

Ball::Ball(){
    position = ofVec2f(0,0);
    velocity = ofVec2f(0,0);
    radius = 25;
	spin = 0;
    id = ofGetElapsedTimeMicros();
}


//------------------------------------------------------------------
void Ball::update() {
    position += velocity;
    
}


//------------------------------------------------------------------
void Ball::draw() {
    ofSetColor(200);
    ofDrawRectangle(position.x - radius, position.y - radius, radius*2, radius*2);
}

void Ball::setSpin(int spin_) {
	spin = spin_;
}
int  Ball::getSpin() {
	return spin;
}

/*
 void Ball::setVelocity(ofVec2f velocity_){
 velocity = velocity_;
 }*/