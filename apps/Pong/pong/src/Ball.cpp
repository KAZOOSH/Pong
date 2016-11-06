/*
 *  Ball.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "Ball.h"

Ball::Ball(){
    position = ofVec2f(0,0);
    velocity = ofVec2f(0,0);
    radius = 25;
	spin = 0;
	initialSpin = 0;
    id = ofGetElapsedTimeMicros();
}

Ball::Ball(ofVec2f position_, ofVec2f velocity_){
    position = position_;
    velocity = velocity_;
    radius = 25;
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

void Ball::setInitialSpin(int spin_) {
	initialSpin = spin_;
}

int  Ball::getSpin() {
	return spin;
}

int  Ball::getinitialSpin() {
	return initialSpin;
}

/*
 void Ball::setVelocity(ofVec2f velocity_){
 velocity = velocity_;
 }*/