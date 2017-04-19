/*
*  PortalPlayMode.h
*  PONG
*
*  KAZOOSH!  - open platform for interactive installations - 2016 
*  http://kazoosh.com 
*
*  created by Max Haferlach - 2016
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
