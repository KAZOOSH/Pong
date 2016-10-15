/*
 *  TennisRenderer.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - 2016
 *  http://kazoosh.com
 *
 *  created by Max Haferlach - 2016
 */

#pragma once
#include "BasicRenderer.h"
class TennisRenderer :
	public BasicRenderer
{
public:
	TennisRenderer(GameElements* gameElements, string name = "Tennis");
	virtual void begin();
	virtual void render();
private:
	ofImage court;
	ofImage tennis_ball;
};

