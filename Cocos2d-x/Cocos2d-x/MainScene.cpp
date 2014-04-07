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
    
    ccBezierConfig  bc;
    bc.controlPoint_1=ccp(400, 400);
    bc.controlPoint_2=ccp(800, 200);
    bc.endPosition=ccp(900, 300);
    CCBezierTo *to=CCBezierTo ::create(3, bc);//贝塞尔曲线
    
    
    sprite->runAction(to);
    

}
//void MainScene:: update(float t){
//
//    sprite->setPosition(ccpAdd(sprite->getPosition(), ccp(1, 0)));//每一帧坐标X轴+1
//    sprite->setRotation(sprite->getRotation()+1);
//}

