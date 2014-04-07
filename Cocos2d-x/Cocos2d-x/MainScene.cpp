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
    sprite->setPosition(ccp(winsize.width/2, winsize.height/2));
    this->addChild(sprite);
    

    
    return true;
}
void MainScene:: onMenuItem(CCObject *object){
     /*动画*/
//    CCHide *hide= CCHide::create();
//    CCFadeTo *to=CCFadeTo::create(2, 100);//  0~255
//    CCFadeOut *out=CCFadeOut ::create(3);
//    CCMoveTo *moveto=CCMoveTo::create(3, ccp(800, sprite->getPositionY()));//移动到什么位置 X ， Y
//    CCMoveBy *moveby=CCMoveBy::create(3, ccp(300, 0));//移动多少位置 X，Y
  //  CCJumpTo *junmto=CCJumpTo::create(2, ccp(sprite->getPositionX()+300, sprite->getPositionY()), 100, 1);//跳到哪
//    CCJumpBy *junmby=CCJumpBy::create(2, ccp(300, 0), 100, 1);//跳多少
    CCPointArray *pointArr=CCPointArray::create(5);
    pointArr->addControlPoint(ccp(0,0));
    pointArr->addControlPoint(ccp(100, 0));
    pointArr->addControlPoint(ccp(100, -50));
    pointArr->addControlPoint(ccp(150, -50));
    pointArr->addControlPoint(ccp(150, 0));
    pointArr->addControlPoint(ccp(250, 0));
    
    CCCardinalSplineBy *by=CCCardinalSplineBy ::create(3, pointArr, 1);//按轨迹移动  tension 张力   1 为 直线运动
    
    
    sprite->runAction(by);
    

}
//void MainScene:: update(float t){
//
//    sprite->setPosition(ccpAdd(sprite->getPosition(), ccp(1, 0)));//每一帧坐标X轴+1
//    sprite->setRotation(sprite->getRotation()+1);
//}

