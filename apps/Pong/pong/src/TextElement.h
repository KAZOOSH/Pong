/*
 *  TextElement.h
 *  emptyExample
 *
 *  Created by Brian Eschrich on 17.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _TextElement
#define _TextElement

#include "ofMain.h"

enum textSize{
    BIG, MEDIUM, SMALL
};

class TextElement {
	
  public:
	
    TextElement(string content_,
                textSize size_ = MEDIUM,
                bool hasAnimation_ = true,
                int lengthAnimation_ = 1000){
        content = content_;
        size = size_;
        hasAnimation = hasAnimation_;
        lengthAnimation = lengthAnimation_;
        
        startTime = ofGetElapsedTimeMillis();
    }
	
    string content;
    textSize size;
    bool hasAnimation;
    int lengthAnimation;
	
    long startTime;
};

#endif
