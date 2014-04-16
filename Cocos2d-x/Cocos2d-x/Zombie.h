//
//  Zombie.h
//  Cocos2d-x
//
//  Created by 李言 on 14-4-16.
//
//

#ifndef __Cocos2d_x__Zombie__
#define __Cocos2d_x__Zombie__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class Zombie:public CCNode {
private:
    CCSprite *m_sprite;
    void onEnter();
public:
    virtual bool init();
    CREATE_FUNC(Zombie);
   
    
};
#endif /* defined(__Cocos2d_x__Zombie__) */
