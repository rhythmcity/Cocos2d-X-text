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
#define ZOMBIE_DIE "zombie_die"
using namespace cocos2d;
class Zombie:public CCNode {
private:
    int HP;
    CCSprite *m_sprite;
    void onEnter();
    void move(float t);
    void die();
    
public:
    void reducehp();
    virtual bool init();
    CREATE_FUNC(Zombie);
   
    
};
#endif /* defined(__Cocos2d_x__Zombie__) */
