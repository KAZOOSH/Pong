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

#include "BasicPlaymode.h"


class Portal{
public:
    Portal(ofRectangle dimensions);
    ofRectangle dimensions;
    bool portalHittest(Ball* ball);
};

class PortalPlayMode : public BasicPlaymode {
    
public:
    
    PortalPlayMode(GameElements* gameElements, string name = "Portals");
    
    virtual void begin();
    virtual void applyRules();
    virtual void render();
    
private:
    void updatePortals();
    vector<Portal> portals;
    
    ofImage sprite;
    int framesHorizontal,framesVertical;
    int frameWidth, frameHeight;
};

#endif
