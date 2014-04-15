//
//  Plant.h
//  Cocos2d-x
//
//  Created by 李言 on 14-4-15.
//
//

#ifndef __Cocos2d_x__Plant__
#define __Cocos2d_x__Plant__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class Plant:public CCNode{
private:
    CCSprite *m_plant;
    CCSpriteBatchNode *bach;
   
public:
    virtual void fire();
    virtual bool init();
    CREATE_FUNC(Plant);
    void onEnter();
    void onFire(float t);
    
};


#endif /* defined(__Cocos2d_x__Plant__) */
