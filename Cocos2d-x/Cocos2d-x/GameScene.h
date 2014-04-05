//
//  GameScene.h
//  Cocos2d-x
//
//  Created by 李言 on 14-4-5.
//
//

#ifndef __Cocos2d_x__GameScene__
#define __Cocos2d_x__GameScene__
#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

class GameScene:public CCLayer {
public:
    virtual bool init();
    static CCScene *scene();
    CREATE_FUNC(GameScene);
    
};

#endif /* defined(__Cocos2d_x__GameScene__) */
