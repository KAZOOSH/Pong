/*
 *  PlayModeController.cpp
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#include "PlayModeController.h"


void PlayModeController::setup(GameElements* gameElements,TextRenderer* textRenderer){
    isNextSelectRules = true;
    
    //init rules
    currentRules = 0;
    rules.push_back(new BasicRules(gameElements,"",-1));
    rules.push_back(new DoubleSpeedRule(gameElements));
    rules.push_back(new PaddleSizeRule(gameElements, "Small Paddle", 0.5));
    rules.push_back(new PaddleSizeRule(gameElements, "Big Paddle", 2.0));
    rules.push_back(new BallSizeRule(gameElements, "Tiny Ball", 0.3));
    rules.push_back(new BallSizeRule(gameElements, "Huge Ball", 3.0));
    rules.push_back(new GravityRule(gameElements));
    rules.push_back(new SwerveRule(gameElements));
	rules.push_back(new TopSpinRule(gameElements, "Topspin"));
    //->add other rules to vector here
    
    //init renderer
    currentRenderer = 0;
    renderer.push_back(new BasicRenderer(gameElements,"",-1));
    renderer.push_back(new AnaglyphRenderer(gameElements));
    renderer.push_back(new RoundBallRenderer(gameElements));
    renderer.push_back(new PsyRenderer(gameElements));
    renderer.push_back(new TennisRenderer(gameElements));
    renderer.push_back(new TrailRenderer(gameElements));
    //renderer.push_back(new GifBGRenderer(gameElements));

    //-> add other renderers to vector here
    
    //add playmodes -> add the playmode to renderer and rules
    WallPlayMode* wallPlayMode = new WallPlayMode(gameElements);
	//rules.push_back(wallPlayMode);
	//renderer.push_back(wallPlayMode);
    
    // PortalPlayMode* portalPlayMode = new PortalPlayMode(gameElements);
	//rules.push_back(portalPlayMode);
	//renderer.push_back(portalPlayMode);
    
    MultiBallMode* multiBallMode = new MultiBallMode(gameElements);
    rules.push_back(multiBallMode);
    renderer.push_back(multiBallMode);
    
    for (int i=0; i<rules.size(); ++i) {
        ofAddListener(rules[i]->newTextEvent, textRenderer, &TextRenderer::onNewTextElement);
        ofAddListener(rules[i]->durationExtendedEvent, this, &PlayModeController::onEndMode);
    }
    for (int i=0; i<renderer.size(); ++i) {
        ofAddListener(renderer[i]->newTextEvent, textRenderer, &TextRenderer::onNewTextElement);
        ofAddListener(renderer[i]->durationExtendedEvent, this, &PlayModeController::onEndMode);
    }
}

AbstractRenderer* PlayModeController::getCurrentRenderer(){
    return renderer[currentRenderer];
}

AbstractRules* PlayModeController::getCurrentRules(){
    return rules[currentRules];
}

void PlayModeController::resetStartModes(){
    setRenderer(0);
    setRules(8);
}

/**
 * selects new rules or renderer randomly
 * if Renderer and rules belong together the will selected together
 */
void PlayModeController::shufflePlaymode(){
    if(isNextSelectRules){
        //eliminate game mode
        
        
        for (int i=0; i<renderer.size(); ++i) {
            if(renderer[i]->getName() == rules[currentRules]->getName()){
                setRenderer(0);
            }
        }
        
        setRules(ofRandom(1,rules.size()));
        cout << rules[currentRules]->getName() << endl;
        //find corresponding renderer
        for (int i=0; i<renderer.size(); ++i) {
            if(renderer[i]->getName() == rules[currentRules]->getName()){
                setRenderer(i);
            }
        }
    }
    else{
        //eliminate game mode
        for (int i=0; i<rules.size(); ++i) {
            if(rules[i]->getName() == renderer[currentRenderer]->getName()){
                setRules(0);
            }
        }
        
        setRenderer(ofRandom(1,renderer.size()));
        cout << renderer[currentRenderer]->getName() << endl;
        
        //find corresponding renderer
        for (int i=0; i<rules.size(); ++i) {
            if(rules[i]->getName() == renderer[currentRenderer]->getName()){
                setRules(i);
            }
        }
    }
    
    isNextSelectRules = !isNextSelectRules;
}

/**
 * when special Mode is finished return back to basic mode
 */
void PlayModeController::onEndMode(string& type){
    if (type == "Renderer") {
        setRenderer(0);
    }else if(type == "Rules"){
        setRules(0);
    }
}


void PlayModeController::setRenderer(int index){
    if(index < renderer.size()){
        renderer[currentRenderer]->end();
        currentRenderer = index;
        renderer[currentRenderer]->begin();
    }
}

void PlayModeController::setRenderer(string name){
    for(int i=0;i<renderer.size();++i){
        if(renderer[i]->getName() == name){
            setRenderer(i);
        }
    }
}

void PlayModeController::setRules(int index){
    if(index < rules.size()){
        rules[currentRules]->end();
        currentRules = index;
        rules[currentRules]->begin();
    }
}

void PlayModeController::setRules(string name){
    for(int i=0;i<rules.size();++i){
        if(rules[i]->getName() == name){
            setRules(i);
        }
    }
}
