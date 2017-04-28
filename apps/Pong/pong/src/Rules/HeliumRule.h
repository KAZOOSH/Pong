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
#include "BasicPlaymode.h"
class HeliumRule :
public BasicPlaymode
{
public:
    HeliumRule(GameElements* gameElements, string name = "Helium");
    virtual void begin();
    virtual void end();
    virtual void applyRules();
};

