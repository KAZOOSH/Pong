#include "ofMain.h"
#include "ofApp.h"
#include <stdint.h>

//========================================================================
int main( ){
    ofGLWindowSettings settings;
    settings.width = 1920;
    settings.height = 1080;
    settings.setGLVersion(2,1);
    settings.windowMode = OF_WINDOW;
    ofCreateWindow(settings);
    
    
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp( new ofApp());
    
}
