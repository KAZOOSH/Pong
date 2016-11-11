/*
 *  HeliumRule.h
 *  PONG
 *
 *  KAZOOSH!  - open platform for interactive installations - 2016
 *  http://kazoosh.com
 *
 *  created by Max Haferlach - 2016
 */

#pragma once
#include "BasicRules.h"
class HeliumRule :
public BasicRules
{
public:
    HeliumRule(GameElements* gameElements, string name = "Helium");
    virtual void begin();
    virtual void end();
    virtual void applyRules();
};

