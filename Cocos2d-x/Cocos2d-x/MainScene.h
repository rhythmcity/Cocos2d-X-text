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
#include "Plant.h"

#define FIRE_PB "fire_pb"
using namespace cocos2d;
class Zombie;
class MainScene:public CCLayer{

public:
    void loadSprite();
//    CCSprite *plant;
    CCTMXTiledMap *map;
    void recv_message_fire(CCObject * object);
    virtual bool init();
    static CCScene *scene();
    CREATE_FUNC(MainScene);
    Zombie *zombie;
    ~MainScene();
    CC_SYNTHESIZE_RETAIN(CCArray *,pbArray , pbArray);
    void upData(float t);
    void koZombie(CCSprite *pb ,Zombie *zom);
private:
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent); 

//    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
//    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
//    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

};



#endif /* defined(__Cocos2d_x__MainScene__) */
