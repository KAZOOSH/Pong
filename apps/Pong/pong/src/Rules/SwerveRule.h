/*
 *  SwerveRule.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - 2016
 *  http://kazoosh.com
 *
 *  created by Max Haferlach - 2016
 */

#pragma once
#include "BasicPlaymode.h"
class SwerveRule :
	public BasicPlaymode
{
public:
	SwerveRule(GameElements* gameElements, string name = "Swerve");
	virtual void begin();
	virtual void end();
	virtual void applyRules();

};

