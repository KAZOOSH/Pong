#pragma once
#include "BasicRenderer.h"
class TennisRenderer :
	public BasicRenderer
{
public:
	TennisRenderer(GameElements* gameElements, string name = "Tennis");
	virtual void render();
private:
	ofImage court;
	ofImage tennis_ball;
};

