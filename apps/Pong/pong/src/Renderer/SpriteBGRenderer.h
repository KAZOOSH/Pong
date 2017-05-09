/*
 *  GifBGRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - http://kazoosh.com 
 *    
 *  created by Brian Eschrich - 2016
 */

#ifndef _SpriteBGRenderer
#define _SpriteBGRenderer

#include "BasicPlaymode.h"


class Sprite{
public:
    Sprite(ofImage img, int nFrames, int framesPerLine);
    void drawFrame(int frameNumber,int x, int y, int width, int height);
    
    ofImage img;
    int nFrames;
    int framesPerLine;
    
    int frameHeight;
    int frameWidth;
};

class SpriteBGRenderer : public BasicPlaymode{
    
public:
    
    SpriteBGRenderer(GameElements* gameElements, string name = "Movie");
    virtual void begin();
    virtual void render();
    
protected:
    void getValuesFromXml();
    
private:
    
    vector<Sprite*> scenes;
    
    int currentScene;
};

#endif
