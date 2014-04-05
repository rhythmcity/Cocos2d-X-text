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
    
    CCSprite *bg=CCSprite::create("map.png");
   CCSize winsize= CCDirector::sharedDirector()->getWinSize();
    bg->setPosition(ccp(winsize.width/2, winsize.height/2));
    this->addChild(bg);
    //帧创建
//    CCSpriteFrame *frame=CCSpriteFrame::create("Peashooter1.tiff", CCRectMake(0, 0, 71, 71));
//    CCSprite *plant=CCSprite::createWithSpriteFrame(frame);
//    plant->setPosition(ccp(300, 300));
//    this->addChild(plant);
    //纹理创建
//    CCImage *image = new CCImage();
//    image->autorelease();
//    image->initWithImageFile("Peashooter1.tiff");
//    CCTexture2D *texture= new CCTexture2D();
//    texture->initWithImage(image);
//    CCSprite *plant=CCSprite::createWithTexture(texture);
//    plant->setPosition(ccp(300, 300));
//    this->addChild(plant);
    //帧缓存创建
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Untitled_default.plist");
    CCSpriteFrame *frame= CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("本.png");
    CCSprite *plant=CCSprite ::createWithSpriteFrame(frame);
    plant->setPosition(ccp(300, 300));
    this->addChild(plant);
    CCSpriteFrame *frame1= CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("妙.png");
    CCSprite *plant1=CCSprite ::createWithSpriteFrame(frame1);
    plant1->setPosition(ccp(350, 350));
    this->addChild(plant1);
    
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
//    CCMenuItemFont *item=CCMenuItemFont::create("开始游戏" , this,menu_selector(MainScene::onMenuItem));
//    CCMenu *menu = CCMenu::create(item,NULL);
//    this->addChild(menu);
    
    
    return true;
}
void MainScene:: onMenuItem(CCObject *object){
    CCScene *scene=GameScene::scene();
   // GameScene *gamescene=GameScene::create();
    CCTransitionPageTurn *transtscene=CCTransitionPageTurn::create(2, scene, false);
    CCDirector::sharedDirector()->replaceScene(transtscene);
    

}
//void MainScene:: update(float t){
//
//    sprite->setPosition(ccpAdd(sprite->getPosition(), ccp(1, 0)));//每一帧坐标X轴+1
//    sprite->setRotation(sprite->getRotation()+1);
//}

