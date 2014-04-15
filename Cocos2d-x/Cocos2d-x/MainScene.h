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
using namespace cocos2d;
class MainScene:public CCLayer{

public:
    void loadSprite();
//    CCSprite *plant;
    CCTMXTiledMap *map;
    
    virtual bool init();
    static CCScene *scene();
    CREATE_FUNC(MainScene);
private:
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent); 

//    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
//    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
//    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

};



#endif /* defined(__Cocos2d_x__MainScene__) */
