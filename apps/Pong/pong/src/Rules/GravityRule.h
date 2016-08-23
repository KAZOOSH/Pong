#pragma once
#include "BasicRules.h"
class GravityRule :
	public BasicRules
{
public:
	GravityRule(GameElements* gameElements, string name = "Gravity");
	virtual void begin();
	virtual void end();
	virtual void applyRules();
};

