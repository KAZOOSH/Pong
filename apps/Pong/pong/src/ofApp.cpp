#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSeedRandom();
    ofSetFrameRate( 60 );
    
    //init controls
    elements.paddleLeft.addControl(mouse);
    elements.paddleRight.addControl(mouse);
    
    //init rules
    activeRules = 0;
    rules.push_back(new BasicRules(&elements));
    rules.push_back(new MultiBallRule(&elements));
    //->add other rules to vector here
    
    //init renderer
    activeRenderer = 0;
    renderer.push_back(new BasicRenderer(&elements));
    renderer.push_back(new AnaglyphRenderer(&elements));
    //-> add other renderers to vector here
    
    //init warper
    initWarper();
    
    textRenderer = new TextRenderer(&elements);
    for (int i=0; i<rules.size(); ++i) {
        ofAddListener(rules[i]->newTextEvent, textRenderer, &TextRenderer::onNewTextElement);
    }
    for (int i=0; i<renderer.size(); ++i) {
        ofAddListener(renderer[i]->newTextEvent, textRenderer, &TextRenderer::onNewTextElement);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    rules[activeRules]->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //render game view in fbo
    gameFbo.begin();
    renderer[activeRenderer]->draw();
    textRenderer->draw();
    gameFbo.end();
    
    //warp fbo on screen
    drawWarpedImage();

}

/**
 * Setups the warper
 */
void ofApp::initWarper(){
    int x = (ofGetWidth() - elements.getWidth()) * 0.5;       // center on screen.
    int y = (ofGetHeight() - elements.getHeigth()) * 0.5;     // center on screen.
    int w = elements.getWidth();
    int h = elements.getHeigth();
    
    gameFbo.allocate(elements.getWidth(), elements.getHeigth());
    
    warper.setSourceRect(ofRectangle(0, 0, w, h));              // this is the source rectangle which is the size of the image and located at ( 0, 0 )
    warper.setTopLeftCornerPosition(ofPoint(x, y));             // this is position of the quad warp corners, centering the image on the screen.
    warper.setTopRightCornerPosition(ofPoint(x + w, y));        // this is position of the quad warp corners, centering the image on the screen.
    warper.setBottomLeftCornerPosition(ofPoint(x, y + h));      // this is position of the quad warp corners, centering the image on the screen.
    warper.setBottomRightCornerPosition(ofPoint(x + w, y + h)); // this is position of the quad warp corners, centering the image on the screen.
    warper.setup();
    warper.load(); // reload last saved changes.
    
    warper.hide();
}

/**
 * draw warped fbo on screen
 */
void ofApp::drawWarpedImage(){
    //======================== get our quad warp matrix.
    
    ofMatrix4x4 mat = warper.getMatrix();
    
    //======================== use the matrix to transform our fbo.
    
    ofPushMatrix();
    ofMultMatrix(mat);
    gameFbo.draw(0, 0);
    ofPopMatrix();
    
    //======================== draw quad warp ui.
    
    ofSetColor(ofColor::magenta);
    warper.drawQuadOutline();
    
    ofSetColor(ofColor::yellow);
    warper.drawCorners();
    
    ofSetColor(ofColor::magenta);
    warper.drawHighlightedCorner();
    
    ofSetColor(ofColor::red);
    warper.drawSelectedCorner();
    
    ofSetColor(ofColor::white);
}

void ofApp::setActiveRules(int index){
    activeRules = index;
    rules[activeRules]->begin();
}

void ofApp::setActiveRenderer(int index){
    activeRenderer = index;
    renderer[activeRenderer]->begin();
}

/**
 * when special Rule is finished return back to basic rules
 */
void ofApp::onEndRules(bool& isEnd){
    if (isEnd) {
        activeRules = 0;
    }
}

/**
 * when special Renderer is finished return back to basic renderer
 */
void ofApp::onEndRenderer(bool& isEnd){
    if (isEnd) {
        activeRenderer = 0;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's' || key == 'S') {
        warper.toggleShow();
    }
    
    if(key == 'l' || key == 'L') {
        warper.load();
    }
    
    if(key == 'h' || key == 'H') {
        warper.save();
    }
    
    if(key == '1') {
        setActiveRules(1);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}