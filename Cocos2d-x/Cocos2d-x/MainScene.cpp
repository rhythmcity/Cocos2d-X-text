//
//  MainScene.cpp
//  Cocos2d-x
//
//  Created by 李言 on 14-4-5.
//
//

#include "MainScene.h"
#include "GameScene.h"
CCScene * MainScene::scene(){
    CCScene *scene = CCScene::create();
    MainScene *layer = MainScene::create();
    scene->addChild(layer);
    return scene;

}

bool MainScene::init(){
    if (!CCLayer::init()) {
        return false;
    }
   
    
    CCMenuItemFont *item=CCMenuItemFont ::create("onaction", this, menu_selector(MainScene::onMenuItem));
    CCMenu *menu=CCMenu::create(item,NULL);
    menu->setPosition(ccp(200, 300));
    this->addChild(menu);
    sprite=CCSprite::create("Icon-72.png");
   CCSize winsize= CCDirector::sharedDirector()->getWinSize();
    sprite->setPosition(ccp(300, 300));
    this->addChild(sprite);
    

    
    return true;
}
void MainScene:: onMenuItem(CCObject *object){
    CCMoveTo *to=CCMoveTo::create(3, ccp(900, 300));
    
    CCEaseSineIn *in=CCEaseSineIn::create(to);
    CCDelayTime *delay=CCDelayTime::create(2);
    CCBlink *blink=CCBlink::create(3, 10);
    
   // CCSequence *se=CCSequence::create(in,delay,blink,NULL);
    CCSpawn *sp=CCSpawn ::create(in,blink,NULL);
    sprite->runAction(sp);
    

}
//void MainScene:: update(float t){
//
//    sprite->setPosition(ccpAdd(sprite->getPosition(), ccp(1, 0)));//每一帧坐标X轴+1
//    sprite->setRotation(sprite->getRotation()+1);
//}

