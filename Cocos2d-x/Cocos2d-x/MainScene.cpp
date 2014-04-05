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
/*精灵*/
    
//    sprite=CCSprite::create("Icon-72.png");
//    
//    sprite->setPosition(CCPointMake(480, 320));
//   // sprite->setAnchorPoint(CCPointMake(1, 1));//锚点 默认是0.5 0.5
//    sprite->setRotation(90);// 旋转
//   // sprite->setScale(2.0);//缩放
//    
//    this->addChild(sprite);
//    
//    
// //   schedule(schedule_selector(MainScene::update));//帧回调
//    schedule(schedule_selector(MainScene::update), 1);//每秒回调一次
/*菜单*/
    CCMenuItemFont *item=CCMenuItemFont::create("开始游戏" , this,menu_selector(MainScene::onMenuItem));
    CCMenu *menu = CCMenu::create(item,NULL);
    this->addChild(menu);
    
    
    return true;
}
void MainScene:: onMenuItem(CCObject *object){
    CCScene *scene=GameScene::scene();
   // GameScene *gamescene=GameScene::create();
    CCDirector::sharedDirector()->replaceScene(scene);
    

}
//void MainScene:: update(float t){
//
//    sprite->setPosition(ccpAdd(sprite->getPosition(), ccp(1, 0)));//每一帧坐标X轴+1
//    sprite->setRotation(sprite->getRotation()+1);
//}

