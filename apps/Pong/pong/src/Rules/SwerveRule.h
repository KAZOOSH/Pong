#pragma once
#include "BasicRules.h"
class SwerveRule :
	public BasicRules
{
public:
	SwerveRule(GameElements* gameElements, string name = "Swerve");
	virtual void begin();
	virtual void end();
	virtual void applyRules();

};

