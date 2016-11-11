#pragma once
#include "BasicRules.h"
class TopSpinRule :
	public BasicRules
{
public:
	TopSpinRule(GameElements* gameElements, string name = "Topspin");
	virtual void begin();
	virtual void end();
	virtual void applyRules();
};

