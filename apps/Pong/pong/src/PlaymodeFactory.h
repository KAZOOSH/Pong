//
//  PlaymodeFactory.hpp
//  PONG
//
//  Created by Brian Eschrich on 27.04.17.
//
//

#ifndef PlaymodeFactory_hpp
#define PlaymodeFactory_hpp

#include "ofMain.h"

#include "AbstractGameControl.h"
#include "MultiBallMode.h"
#include "DoubleSpeedRule.h"
#include "PaddleSizeRule.h"
#include "BallSizeRule.h"
#include "GravityRule.h"
#include "SwerveRule.h"
#include "HeliumRule.h"
//-> include other rules here

#include "AnaglyphRenderer.h"
#include "RoundBallRenderer.h"
#include "PsyRenderer.h"
#include "TennisRenderer.h"
#include "TrailRenderer.h"
#include "GifBGRenderer.h"
#include "SpriteBGRenderer.h"
#include "InvisibleRenderer.h"
#include "SpriteBallRenderer.h"
//-> include other renderers here

#include "WallPlayMode.h"
#include "PortalPlayMode.h"
//-> include other playmodes here


class PlaymodeFactory
{
public:
    /// \brief creates module from module settings
    /// settings.name defines the created module, values can be
    /// Double Speed ...
    static AbstractGameControl *make_playMode(string playModeName, GameElements* gameElements);
};

#endif /* PlaymodeFactory_hpp */