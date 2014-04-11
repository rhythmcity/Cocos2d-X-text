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
   
    
//    CCMenuItemFont *item=CCMenuItemFont ::create("onaction", this, menu_selector(MainScene::onMenuItem));
//    CCMenu *menu=CCMenu::create(item,NULL);
//    menu->setPosition(ccp(200, 300));
//    this->addChild(menu);
    sprite=CCSprite::create("map.png");
  
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("PlantAndZombie.plist");
    
   CCSize winsize= CCDirector::sharedDirector()->getWinSize();
    sprite->setPosition(ccp(winsize.width/2, winsize.height/2));
    this->addChild(sprite);
    CCSpriteBatchNode *bach=CCSpriteBatchNode::create("PlantAndZombie.png");
    this->addChild(bach);
    CCSpriteFrame *frame;
    CCArray *array=CCArray::create();
    for (int i =0; i<12; i++) {
        char* str=new char[255];
        sprintf(str, "Peashooter%d.tiff",i+1);
        frame= CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
        array->addObject(frame);
    }
    CCSprite *plant=CCSprite ::createWithSpriteFrame(frame);
    plant->setPosition(ccp(300, 300));
    bach->addChild(plant);
    CCAnimation *antion=CCAnimation::createWithSpriteFrames(array,0.1f);
    CCAnimate *animate=CCAnimate::create(antion);
    CCRepeatForever *repeat=CCRepeatForever::create(animate);
    plant->runAction(repeat);
    
    CCSpriteFrame *frame1;
    CCArray *array1=CCArray::create();
    for (int i =0; i<21; i++) {
        char* str=new char[255];
        sprintf(str, "Zombie%d.tiff",i+1);
        frame1= CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
        array1->addObject(frame1);
    }
    Zombie=CCSprite ::createWithSpriteFrame(frame1);
    Zombie->setPosition(ccp(800, 300));
    bach->addChild(Zombie);
    CCAnimation *antion1=CCAnimation::createWithSpriteFrames(array1,0.2f);
    CCAnimate *animate1=CCAnimate::create(antion1);
    CCRepeatForever *repeat1=CCRepeatForever::create(animate1);
     schedule(schedule_selector(MainScene::update),0.5);//每秒回调一次
    Zombie->runAction(repeat1);



    
    return true;
}
void MainScene:: onMenuItem(CCObject *object){
    CCMoveTo *to=CCMoveTo::create(3, ccp(900, 300));
    
    CCEaseSineIn *in=CCEaseSineIn::create(to);
    CCDelayTime *delay=CCDelayTime::create(2);
    CCBlink *blink=CCBlink::create(3, 10);
    
   //
    CCSpawn *sp=CCSpawn ::create(in,blink,NULL);
    CCCallFunc *call=CCCallFunc::create(this, callfunc_selector(MainScene::finshAction));
    CCSequence *se=CCSequence::create(sp,call,NULL);
    sprite->runAction(se);


}
void MainScene:: finshAction(){
   
    Zombie->setPosition(ccp(Zombie->getPosition().x-1, 300));
}
void MainScene:: update(float t){

    Zombie->setPosition(ccpAdd(Zombie->getPosition(), ccp(-1, 0)));//每一帧坐标X轴+1
//    sprite->setRotation(sprite->getRotation()+1);
}

