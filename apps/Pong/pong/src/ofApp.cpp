#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSeedRandom();
    ofSetFrameRate( 60 );
    isGameRunning = false;
    isInitMessageShown = false;
    tGameFinished = 0;
    showDebugInfos = false;
    isPlayerReady = false;
    
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
    
    initSettings();
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
            prepareForStart();
        }
        if (isPlayerReady) {
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
    ofBackground(0);
    gameFbo.begin();
    playModeController.getCurrentRenderer()->draw();
    textRenderer->render();
    
    if (showDebugInfos) {
        drawDebugInformation();
    }
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
    tPlayerReady = false;
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
void ofApp::prepareForStart(){
    if(elements.paddleLeft.getPosition() < elements.paddleLeft.height*1.5  &&
       elements.paddleRight.getPosition() < elements.paddleRight.height*1.5){
        
        TextElement t("GO!",
                      BIG,
                      true,
                      1500);
        ofNotifyEvent(gameOverEvent, t);
        isPlayerReady = true;
        tPlayerReady = ofGetElapsedTimeMillis();
    }
}

void ofApp::startGame(){
    if( ofGetElapsedTimeMillis() - tPlayerReady > 1500){
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

void ofApp::drawDebugInformation(){
    ofPushMatrix();
    ofPushStyle();
    ofSetColor(255,0,0);
    
    int ty = 20;
    
    ofTranslate(50, 50);
    ofDrawBitmapString("Debug Information (d - show/hide)", 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("=================================", 0, 0);
    
    ofTranslate(0, ty);
    ofTranslate(0, ty);
    ofDrawBitmapString("General", 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("toggle PlayMode (p)", 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("current Rules: " + playModeController.getCurrentRules()->getName(), 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("current Renderer: " + playModeController.getCurrentRenderer()->getName(), 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("toggle Fullscreen (f)", 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("save settings (s)", 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("load settings (a)", 0, 0);
    ofTranslate(0, ty);
    string isModeration = soundPlayer.isModerationMode ? "true":"false";
    ofDrawBitmapString("ModerationMode: " + isModeration + " (m - toggle)", 0, 0);
    
    ofTranslate(0, ty);
    ofTranslate(0, ty);
    ofDrawBitmapString("Warper", 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("toggle Show (w)", 0, 0);
    ofTranslate(0, ty);
    
    ofTranslate(0, ty);
    ofTranslate(0, ty);
    ofDrawBitmapString("Ball", 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("Velocity: " + ofToString(abs(elements.balls[0]->velocity.x)), 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("MinVelocity: " + ofToString(abs(elements.minBallVelocity),1) + " -+ (i,o)", 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("MaxVelocity: " + ofToString(abs(elements.maxBallVelocity),1) + " -+ (k,l)", 0, 0);
    
    ofTranslate(0, ty);
    ofTranslate(0, ty);
    ofDrawBitmapString("Paddle", 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("Brightness: " + ofToString(ledControl.brightness) + " -+ (DOWN,UP)", 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("PixelPerLed: " + ofToString(ledControl.pixelPerLed) + " -+ (LEFT,RIGHT)", 0, 0);
    ofTranslate(0, ty);
    ofDrawBitmapString("PaddleSize: " + ofToString(elements.paddleLeft.height) + " -+ (-,+)", 0, 0);
    ofTranslate(0, ty);
    string tPaddle = elements.paddleLeft.isDebug ? "true":"false";
    ofDrawBitmapString("DebugPaddle: " + tPaddle + " (# - show/hide)", 0, 0);
    
    ofPopStyle();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f') {
        ofToggleFullscreen();
    }
    
    if(key == 'd') {
        showDebugInfos = !showDebugInfos;
    }
    
    if(key == 'w') {
        warper.toggleShow();
    }
    
    if(key == 'a' ) {
        loadSettings();
    }
    
    if(key == 's' ) {
        saveSettings();
    }
    
    if(key == 'p') {
        playModeController.shufflePlaymode();
    }
    if(key == '1') {
        playModeController.setRenderer("Movie");
    }
    
    if(key == OF_KEY_UP) {
        ledControl.setBrightness(ledControl.getBrightness()+1);
    }
    if(key == OF_KEY_DOWN) {
        ledControl.setBrightness(ledControl.getBrightness()-1);
    }
    if(key == OF_KEY_RIGHT) {
        ledControl.pixelPerLed++;
    }
    if(key == OF_KEY_LEFT) {
        ledControl.pixelPerLed--;
    }
    if(key == '+') {
        elements.paddleLeft.height++;
        elements.paddleRight.height++;
    }
    if(key == '-') {
        elements.paddleLeft.height--;
        elements.paddleRight.height--;
    }
    
    if(key == '#'){
        elements.paddleLeft.isDebug = !elements.paddleLeft.isDebug;
        elements.paddleRight.isDebug = !elements.paddleRight.isDebug;
    }
    
    if(key == 'i') {
        elements.minBallVelocity--;
    }
    if(key == 'o') {
        elements.minBallVelocity++;
    }
    if(key == 'k') {
        elements.maxBallVelocity--;
    }
    if(key == 'l') {
        elements.maxBallVelocity++;
    }
    
    if(key == 'm') {
        soundPlayer.isModerationMode = !soundPlayer.isModerationMode;
    }
}

void ofApp::initSettings(){
    settings.add(soundPlayer.isModerationMode);
    settings.add(elements.minBallVelocity);
    settings.add(elements.maxBallVelocity);
    settings.add(ledControl.brightness);
    settings.add(ledControl.pixelPerLed);
    settings.add(elements.paddleLeft.height);
    settings.add(elements.paddleRight.height);
    
    loadSettings();
}

void ofApp::saveSettings(){
    ofXml xml;
    xml.serialize(settings);
    xml.save("settings.xml");
    warper.save();
}

void ofApp::loadSettings(){
    ofXml xml;
    xml.load("settings.xml");
    xml.deserialize(settings);
    warper.load();
}

