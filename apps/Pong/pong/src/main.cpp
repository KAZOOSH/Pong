/*
 *  main.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - 2016
 *  http://kazoosh.com
 *
 *  created by Brian Eschrich - 2016
 */

#include "ofMain.h"
#include "ofApp.h"
#include <stdint.h>

//========================================================================
int main( ){
#ifdef TARGET_OPENGLES
    ofSetupOpenGL(1920,1080, OF_WINDOW);
#else 
    ofGLWindowSettings settings;
    settings.width = 1920;
    settings.height = 1080;
    settings.setGLVersion(2,1);
    settings.windowMode = OF_WINDOW;
    ofCreateWindow(settings);
#endif
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp( new ofApp());
    
}
