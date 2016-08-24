/*
 *  WallPlayMode.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 19.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "WallPlayMode.h"

//WALL
Wall::Wall(ofRectangle dimensions_){
    dimensions = dimensions_;
}

bool Wall::wallHittest(Ball* ball){
    
    int b_x_min = ball->position.x - ball->radius;
    int b_x_max = ball->position.x + ball->radius;
    int b_y_min = ball->position.y - ball->radius;
    int b_y_max = ball->position.y + ball->radius;
    
    int w_x_min = dimensions.x;
    int w_x_max = dimensions.x + dimensions.width;
    int w_y_min = dimensions.y;
    int w_y_max = dimensions.y + dimensions.height;
    
    //edge side
    if (b_x_max >= w_x_min && b_x_max <= w_x_max){
        if((b_y_max >= w_y_min && b_y_max <= w_y_max)||
           (b_y_min >= w_y_min && b_y_min <= w_y_max))
            
        {
            ball->velocity.x *= -1;
            return true;
        }
    }

	if (b_x_min <= w_x_max && b_x_min >= w_x_min) {
		if ((b_y_max >= w_y_min && b_y_max <= w_y_max) ||
			(b_y_min >= w_y_min && b_y_min <= w_y_max))

		{
			ball->velocity.x *= -1;
			return true;
		}
	}

    /*
     //right edge
     if (b_x_min >= w_x_min && b_x_max <= w_x_max
     &&((b_y_min >= w_y_min && b_y_min <= w_x_max)||
     (b_y_max >= w_y_min && b_y_max <= w_x_max))) {
     ball->velocity.x *= -1;
     return true;
     }*/
    
    /*
     if ((ball->position.y + ball->radius >= dimensions.y && ball->position.y + ball->radius <= dimensions.y+ dimensions.height)||
     (ball->position.y - ball->radius <= dimensions.y + dimensions.height + ball->position.y - ball->radius >= dimensions.y)) {
     //right edge
     if (ball->position.x - ball->radius <= dimensions.x + dimensions.width) {
     ball->velocity.x *= -1;
     return true;
     }
     //left edge
     else if (ball->position.x + ball->radius >= dimensions.x) {
     ball->velocity.x *= -1;
     return true;
     }
     }*/
    /*
     if (ball->position.x - ball->radius >= dimensions.x &&
     ball->position.x + ball->radius <= dimensions.x + dimensions.width) {
     //top edge
     if (ball->position.y - ball->radius <= dimensions.y) {
     ball->velocity.y *= -1;
     return true;
     }
     //bottom edge
     else if (ball->position.y + ball->radius >= dimensions.y + dimensions.height) {
     ball->velocity.y *= -1;
     return true;
     }
     }*/
    
    
    return false;
}


//WALL PLAYMODE

WallPlayMode::WallPlayMode(GameElements* gameElements, string name):BasicRenderer(gameElements, name), BasicRules(gameElements, name){
    
    walls.push_back(Wall(ofRectangle(gameElements->getWidth()*0.25, gameElements->getHeigth()*0.5, 10, 10)));
    walls.push_back(Wall(ofRectangle(gameElements->getWidth()*0.5, gameElements->getHeigth()*0.5, 10, 10)));
    walls.push_back(Wall(ofRectangle(gameElements->getWidth()*0.75, gameElements->getHeigth()*0.5, 10, 10)));
}

//------------------------------------------------------------------
void WallPlayMode::begin() {
    BasicRenderer::begin();
    BasicRules::begin();
    updateWalls();
}

void WallPlayMode::updateWalls(){
    GameElements* gameElements = BasicRules::gameElements;
    
    int ySide = ofRandom(ofRandom(gameElements->getHeigth()));
    int wSide = 50;
    int hSide = ofRandom(gameElements->getHeigth()*.1, gameElements->getHeigth()*0.5);
    
    walls[0].dimensions = ofRectangle(gameElements->getWidth()*0.25,ySide,wSide,hSide);
    walls[2].dimensions = ofRectangle(gameElements->getWidth()*0.75,ySide,wSide,hSide);
    
    int yCenter = ofRandom(ofRandom(gameElements->getHeigth()));
	while (yCenter>gameElements->getHeigth()*0.2 && yCenter<gameElements->getHeigth()*0.6) {
		yCenter = ofRandom(ofRandom(gameElements->getHeigth()));
	}
	int wCenter = 50;
    int hCenter = ofRandom(gameElements->getHeigth()*.1, gameElements->getHeigth()*0.2);
    
    walls[1].dimensions = ofRectangle(.5*(gameElements->getWidth()-wCenter),yCenter,wCenter,hCenter);
    
}

//------------------------------------------------------------------
void WallPlayMode::applyRules() {
    BasicRules::applyRules();
    
    for(auto wall:walls){
        for(auto ball:BasicRules::gameElements->balls){
            if(wall.wallHittest(ball)){
                BasicRules::gameElements->notifyGameEvent(CONTACT_WALL);
            }
            
        }
    }
}


//------------------------------------------------------------------
void WallPlayMode::render() {
    BasicRenderer::render();
    
    for(auto wall:walls){
        ofDrawRectangle(wall.dimensions);
    }
}
