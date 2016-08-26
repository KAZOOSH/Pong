/*
*  PortalPlayMode.h
*  emptyExample
*
*  Created by Brian Eschrich on 19.08.16
*  Copyright 2016 __MyCompanyName__. All rights reserved.
*
*/

#ifndef _PortalPlayMode
#define _PortalPlayMode

#include "BasicRenderer.h"
#include "BasicRules.h"

#include "ofxGifDecoder.h"
#include "ofxGifFile.h"

class Portal {
public:
	Portal(ofRectangle dimensions);
	ofRectangle dimensions;
	bool portalHittest(Ball* ball);
};

class PortalPlayMode : public BasicRenderer, public BasicRules {

public:

	PortalPlayMode(GameElements* gameElements, string name = "Portals");

	virtual void begin();
	virtual void applyRules();
	virtual void render();

private:
	void updatePortals();
	vector<Portal> portals;
    
    
    ofxGifDecoder decoder;
    ofxGifFile portalImg;

};

#endif
