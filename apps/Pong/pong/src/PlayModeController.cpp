/*
 *  PlayModeController.cpp
 *  emptyExample
 *
 *  Created by Brian Eschrich on 19.08.16
 *  Copyright 2016 __MyCompanyName__. All rights reserved.
 *
 */

#include "PlayModeController.h"


void PlayModeController::setup(GameElements* gameElements,TextRenderer* textRenderer){
    isNextSelectRules = true;
    
    //init rules
    currentRules = 0;
    rules.push_back(new BasicRules(gameElements));
    rules.push_back(new MultiBallRule(gameElements));
    //->add other rules to vector here
    
    //init renderer
    currentRenderer = 0;
    renderer.push_back(new BasicRenderer(gameElements));
    renderer.push_back(new AnaglyphRenderer(gameElements));
    //-> add other renderers to vector here
    
    for (int i=0; i<rules.size(); ++i) {
        ofAddListener(rules[i]->newTextEvent, textRenderer, &TextRenderer::onNewTextElement);
    }
    for (int i=0; i<renderer.size(); ++i) {
        ofAddListener(renderer[i]->newTextEvent, textRenderer, &TextRenderer::onNewTextElement);
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
    setRules(0);
}

/**
 * selects new rules or renderer randomly
 * if Renderer and rules belong together the will selected together
 */
void PlayModeController::shufflePlaymode(){
    if(isNextSelectRules){
        setRules(ofRandom(rules.size()));
        //find corresponding renderer
        for (int i=0; i<renderer.size(); ++i) {
            if(renderer[i]->getName() == rules[currentRules]->getName()){
                setRenderer(i);
            }
        }
    }
    else{
        setRenderer(ofRandom(rules.size()));
        //find corresponding renderer
        for (int i=0; i<renderer.size(); ++i) {
            if(renderer[i]->getName() == renderer[currentRenderer]->getName()){
                setRules(i);
            }
        }
    }
    
    isNextSelectRules = !isNextSelectRules;
}

void PlayModeController::setRenderer(int index){
    if(index < renderer.size()){
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
