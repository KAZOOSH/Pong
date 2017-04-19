/*
 *  GravityRule.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - 2016
 *  http://kazoosh.com
 *
 *  created by Max Haferlach - 2016
 */

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

