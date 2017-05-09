/*
 *  PlayModeController.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "PlayModeController.h"


void PlayModeController::setup(GameElements* gameElements_,TextRenderer* textRenderer){
    
    ofSeedRandom();
    
    gameElements = gameElements_;
    
    //init rules
    basicPlaymode =  new BasicPlaymode(gameElements,"",true,true,-1);
    
    initPlaymodesFromXml();
    
    for (auto& p:v_playmodes) {
        ofAddListener(p->newTextEvent, textRenderer, &TextRenderer::onNewTextElement);
        ofAddListener(p->durationExtendedEvent, this, &PlayModeController::onEndMode);
    }
    
    for (auto& p:v_playmodes) {
        shufflePlaymodeSet.push_back(p->getName());
    }
    random_shuffle(shufflePlaymodeSet.begin(), shufflePlaymodeSet.end());
    
    resetStartModes();
}

AbstractGameControl* PlayModeController::getCurrentRenderer(){
    return currentRenderer;
}

AbstractGameControl* PlayModeController::getCurrentRules(){
    return currentRules;
}

void PlayModeController::resetStartModes(){
    setPlaymode(basicPlaymode);
}

/**
 * selects new rules or renderer randomly
 * if Renderer and rules belong together the will selected together
 */
void PlayModeController::shufflePlaymode(){
    
    string newModeName = shufflePlaymodeSet[0];
    
    setPlaymode(newModeName);
    
    int i = ofFind(shufflePlaymodeSet, newModeName);
    shufflePlaymodeSet.erase(shufflePlaymodeSet.begin() + i);
    if (shufflePlaymodeSet.size() == 0) {
        for (auto& p:playmodes) {
            shufflePlaymodeSet.push_back(p.first);
        }
        random_shuffle(shufflePlaymodeSet.begin(), shufflePlaymodeSet.end());
    }
}

/**
 * when special Mode is finished return back to basic mode
 */
void PlayModeController::onEndMode(AbstractGameControl& c){
    if (c.isRenderer() && c.isRules()) {
        setPlaymode(basicPlaymode);
    }
    else if (c.isRenderer()) {
        setRenderer(basicPlaymode);
    }
    else if(c.isRules()){
        setRules(basicPlaymode);
        
    }
    
}

void PlayModeController::setPlaymode(string name){
    AbstractGameControl* nMode = playmodes[name];
    
    if(nMode == nullptr){
        ofLogError("PlayModeController", name + " mode das not exist");
    }
    else{
        if (nMode->isRules() && nMode->isRenderer()) {
            setPlaymode(nMode);
        }
        else if (nMode->isRules()) {
            if (currentRenderer->isRules()) setRenderer(basicPlaymode);
            setRules(nMode);
        }
        else if (nMode->isRenderer()) {
            if (currentRules->isRenderer()) setRules(basicPlaymode);
            setRenderer(nMode);
        }
    }
}

void PlayModeController::initPlaymodesFromXml(string path){
    ofXml xml;
    xml.load(path);
    xml.setTo("playmodes");
    if(xml.exists("playmode"))
    {
        // This gets the first stroke (notice the [0], it's just like an array)
        xml.setTo("playmode[0]");
        do {
            addPlaymode(xml.getValue<string>(""));
        }
        while( xml.setToSibling() ); // go to the next STROKE
    }
}

void PlayModeController::addPlaymode(string name){
    AbstractGameControl* g =  PlaymodeFactory::make_playMode(name, gameElements);
    if (g != nullptr) {
        v_playmodes.push_back(g);
        playmodes.insert(pair<string, AbstractGameControl*>(name,v_playmodes.back()));
    }
}

//todo renderer restart fix

void PlayModeController::setRenderer(AbstractGameControl* r){
    
    if(currentRenderer != nullptr){
        currentRenderer->end();
    }
    currentRenderer = r;
    currentRenderer->begin();
    
}

void PlayModeController::setRules(AbstractGameControl* r){
    bool isResetRenderer = false;
    if (currentRules != nullptr){
        currentRules->end();
    }
    currentRules = r;
    currentRules->begin();
    
}

void PlayModeController::setPlaymode(AbstractGameControl* r){
    if (currentRules != nullptr) currentRules->end();
    currentRules = r;
    if(currentRenderer != nullptr) currentRenderer->end();
    currentRenderer = r;
    currentRules->begin();
}

