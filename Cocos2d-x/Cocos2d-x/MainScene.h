//
//  MainScene.h
//  Cocos2d-x
//
//  Created by 李言 on 14-4-5.
//
//

#ifndef __Cocos2d_x__MainScene__
#define __Cocos2d_x__MainScene__
#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class MainScene:public CCLayer{

public:
    CCSprite *sprite;
    CCSprite *Zombie;
    CCSprite *PB;
    CCSprite *plant;
    CCRepeatForever *repeat1;
    
    bool islive;
    int beats;
    virtual bool init();
    static CCScene *scene();
    CREATE_FUNC(MainScene);
private:
   // void update(float t);
    void onMenuItem(CCObject *object);
    void finshAction();
    void update(float t);
    void repeat(float t);
    void  newzombie();
    void zombiemove(float t);
 
};



#endif /* defined(__Cocos2d_x__MainScene__) */
