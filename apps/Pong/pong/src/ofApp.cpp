#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSeedRandom();
    ofSetFrameRate( 60 );
    isGameRunning = false;
    isInitMessageShown = false;
    tGameFinished = 0;
    
    //init controls
    elements.paddleLeft.addControl(mouse);
    elements.paddleRight.addControl(mouse);
    
    
    //init warper
    initWarper();
    
    
    textRenderer = new TextRenderer(&elements);
    playModeController.setup(&elements,textRenderer);
    
    ofAddListener(gameOverEvent, textRenderer, &TextRenderer::onNewTextElement);
    
    //init soundPlayer
    soundPlayer.setup();
    
    ledControl.setup(&elements);
    
    //register listeners
    ofAddListener(elements.newScoreEvent, this, &ofApp::onPointsChanged);
    ofAddListener(elements.newGameEvent, &soundPlayer, &SoundPlayer::onGameEvent);
    ofAddListener(elements.newPlayModeEvent, &soundPlayer, &SoundPlayer::onPlaymodeChanged);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    
    
    //init message
    if(!isInitMessageShown){
        if (ofGetElapsedTimeMillis() - tGameFinished > 4000) {
            restartGame();
            showInitMessage();
            
        }
    }
    
    if(!isGameRunning){
        if (ofGetElapsedTimeMillis() - tGameFinished > 7000) {
            startGame();
        }
    }
    else {
        playModeController.getCurrentRules()->update();
    }
    
    mouse.update();
    ledControl.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //render game view in fbo
    gameFbo.begin();
    playModeController.getCurrentRenderer()->draw();
    textRenderer->render();
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

/**
 * resets all elements
 */
void ofApp::restartGame(){
    playModeController.resetStartModes();
    elements.resetElements();
    
}

/**
 * notify events to start fireworks ;)
 */
void ofApp::endGame(int winner){
    isGameRunning = false;
    isInitMessageShown = false;
    
    tGameFinished = ofGetElapsedTimeMillis();
    
    string text = "Player ";
    text += ofToString(winner);
    text += " wins!";
    
    TextElement t(text,
                  MEDIUM,
                  true,
                  4000,
                  ofColor(255),
                  true);
    ofNotifyEvent(gameOverEvent, t);
    
    GameEvent g = P1_WIN;
    if (winner == 2) g = P2_WIN;
    
    ofNotifyEvent(elements.newGameEvent, g);
    
    
}

void ofApp::showInitMessage(){
    TextElement t("Paddles up!",
                  MEDIUM,
                  true,
                  2000);
    ofNotifyEvent(gameOverEvent, t);
    isInitMessageShown = true;
}

/**
 * checks if paddles are ready to start game
 */
void ofApp::startGame(){
    
    if(elements.paddleLeft.getPosition() < 10 &&
       elements.paddleRight.getPosition() < 10){
        
        TextElement t("GO!",
                      BIG,
                      true,
                      1500);
        ofNotifyEvent(gameOverEvent, t);
        
        GameEvent g = START;
        ofNotifyEvent(elements.newGameEvent, g);
        isGameRunning = true;
    }
}

void ofApp::onPointsChanged(PlayerScoreEvent& e){
    if (e.points >= elements.getWinScore()){
        endGame(e.id);
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
    
    if(key == 'p') {
        playModeController.shufflePlaymode();
    }
    
    if(key == '2') {
        playModeController.setRenderer("Trails");
        //playModeController.setRules("Walls");
    }
    if(key == '3') {
        playModeController.setRules("Huge Ball");
    }
}

