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
    setup(ofVec2f(0,0),ofVec2f(0,0));
}

Ball::Ball(ofVec2f position_, ofVec2f velocity_){
    setup(position_,velocity_);
}

void Ball::setup(ofVec2f position_, ofVec2f velocity_){
    position = position_;
    velocity = velocity_;
    radius = 25;
    id = ofGetElapsedTimeMicros();
    
    isBallSpawning = false;
    ani_spawn.reset( 0.0f );
    ani_spawn.setRepeatType(LOOP);
    ani_spawn.setCurve(BLINK_2);
    ani_spawn.animateTo( 1.0f );
    ani_spawn.setDuration(1);
    
    spawnTime = 1000;
}


//------------------------------------------------------------------
void Ball::update() {
    if(!isBallSpawning) position += velocity;
    else if (ofGetElapsedTimeMillis() - startBallSpawn > spawnTime){
        isBallSpawning = false;
    }
}

//------------------------------------------------------------------
void Ball::draw() {
    if(isBallSpawning){
        drawSpawn();
    }
    else {
        ofSetColor(200);
        ofDrawRectangle(position.x - radius, position.y - radius, radius*2, radius*2);
    }
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

float Ball::getRadius(){
    return radius;
}

void Ball::drawSpawn(){
    float t = ofMap(ofGetElapsedTimeMillis(),startBallSpawn,startBallSpawn + spawnTime,0,1);
    float r = ani_spawn.calcCurveAt(t) * radius;
    ofDrawRectangle(position.x - r, position.y -r, r*2, r*2);
}

void Ball::spawnBall(){
    isBallSpawning = true;
    startBallSpawn = ofGetElapsedTimeMillis();
}

/*
 void Ball::setVelocity(ofVec2f velocity_){
 velocity = velocity_;
 }*/