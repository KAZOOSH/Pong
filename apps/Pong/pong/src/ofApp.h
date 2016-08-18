#pragma once

#include "ofMain.h"
#include "ofxQuadWarp.h"

#include "GameElements.h"
#include "AbstractRules.h"
#include "BasicRules.h"
#include "MultiBallRule.h"
//-> include other rules here

#include "AbstractRenderer.h"
#include "BasicRenderer.h"
#include "AnaglyphRenderer.h"
//-> include other renderers here

#include "TextRenderer.h"

#include "MouseControl.h"

class ofApp : public ofBaseApp{
	public:
		void setup(); //!< configures App
		void update(); //!< runs every frame, updates game rules
		void draw(); //!< runs every frame, updates rendering
		
    void initWarper();
    void drawWarpedImage();
    
    void setActiveRules(int index);
    void setActiveRenderer(int index);
    
    void restartGame();
    
    //listeners
    void onEndRules(bool& isEnd);
    void onEndRenderer(bool& isEnd);
    void onPointsChanged(PlayerScore& e);
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
private:
    ofxQuadWarp warper; //!< mapping tool
    ofFbo gameFbo; //!< game graphics are rendered in fbo
    
    GameElements elements; //!< balls and paddles, shared over all classes
    
    vector<AbstractRules*> rules; //!< ruleset
    int activeRules;
    
    vector<AbstractRenderer*> renderer; //!< renderer collection
    int activeRenderer;
    
    TextRenderer* textRenderer;
    
    MouseControl mouse;
};
