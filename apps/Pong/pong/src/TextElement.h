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
                int lengthAnimation_ = 1000,
                ofColor textColor_ = ofColor(255),
                bool hasBG_ = false){
        content = content_;
        size = size_;
        hasAnimation = hasAnimation_;
        lengthAnimation = lengthAnimation_;
        textColor = textColor_;
        hasBG = hasBG_;
        
        startTime = ofGetElapsedTimeMillis();
    }
    
    string content; //!< the text
    textSize size; //!< textsize
    ofColor textColor;
    bool hasAnimation; //!< play text with animation
    int lengthAnimation; //!< length of animation
    
    long startTime;//!< text creation time
    
    bool hasBG;//!< Background (for important messages)
};

#endif
