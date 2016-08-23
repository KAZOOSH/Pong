/*
 *  LavooHeart.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 31.05.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "LavooHeart.h"


//------------------------------------------------------------------
void LavooHeart::setup() {
    img.allocate(15, 20, OF_IMAGE_COLOR);
    img.setColor(ofColor(0));
    for(int i=0; i<64*8; ++i){
        colors.push_back(ofColor(0));
    }

}


//------------------------------------------------------------------
void LavooHeart::update() {
	
	
}


//------------------------------------------------------------------
void LavooHeart::draw() {
    img.draw(0, 0,150,200);
    
}

int LavooHeart::getSector(int x, int y){
    if (x>=0 && x<15 && y>=0 && y<20) {
        int index = 20*x + y;
        return coordinate2sector[index];
    }
    return 255;
}

int LavooHeart::getIndex(int x, int y){
    if (x>=0 && x<15 && y>=0 && y<20) {
        int index = 20*x + y;
        return coordinate2index[index];
    }
    return 255;
}

void LavooHeart::setPixels(ofPixels& pix_){
    //set Picture
    pix = pix_;
    pix.resize(15, 20);
    for (int i=0; i<15*20; ++i) {
        if (coordinate2index[i] == 255) {
            pix.setColor(i/20, i%20, ofColor(0));
        }
    }
    img.setFromPixels(pix);
    img.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    updateColors();
}

void LavooHeart::setImage(ofImage& img_)
{
    setPixels(img_.getPixels());
}

void LavooHeart::updateColors(){
    //set channels
    for (int i=0; i<15*20; ++i) {
        ofColor c = pix.getColor(i/20, i%20);
        int index = coordinate2index[i];
        int sector = coordinate2sector[i];
        
        if (index != 255 && sector != 255) {
            colors[sector*64 + index] = c;
        }
    }
    
}

vector <ofColor> LavooHeart::colorData(){
    return colors;
}