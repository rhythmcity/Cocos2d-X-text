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
    sprite=CCSprite::create("map.png");
   CCSize winsize= CCDirector::sharedDirector()->getWinSize();
    sprite->setPosition(ccp(winsize.width/2, winsize.height/2));
    this->addChild(sprite);
    CCSpriteFrame *frame0=CCSpriteFrame::create("Peashooter1.tiff", CCRect(71*0, 0, 250, 300));
        CCSpriteFrame *frame1=CCSpriteFrame::create("Peashooter2.tiff", CCRect(71*1, 0, 250, 300));
        CCSpriteFrame *frame2=CCSpriteFrame::create("Peashooter3.tiff", CCRect(71*2, 0, 250, 300));
        CCSpriteFrame *frame3=CCSpriteFrame::create("Peashooter4.tiff", CCRect(71*3, 0, 250, 300));
        CCSpriteFrame *frame4=CCSpriteFrame::create("Peashooter5.tiff", CCRect(71*4, 0, 250, 300));
        CCSpriteFrame *frame5=CCSpriteFrame::create("Peashooter6.tiff", CCRect(71*5, 0, 250, 300));
        CCSpriteFrame *frame6=CCSpriteFrame::create("Peashooter7.tiff", CCRect(71*6, 0, 250, 300));
        CCSpriteFrame *frame7=CCSpriteFrame::create("Peashooter8.tiff", CCRect(71*7, 0, 250, 300));
        CCSpriteFrame *frame8=CCSpriteFrame::create("Peashooter9.tiff", CCRect(71*8, 0, 250, 300));
        CCSpriteFrame *frame9=CCSpriteFrame::create("Peashooter10.tiff", CCRect(71*9, 0, 250, 300));
        CCSpriteFrame *frame10=CCSpriteFrame::create("Peashooter11.tiff", CCRect(71*10, 0, 250, 300));
        CCSpriteFrame *frame11=CCSpriteFrame::create("Peashooter12.tiff", CCRect(71*11, 0, 250, 300));
        CCSpriteFrame *frame12=CCSpriteFrame::create("Peashooter13.tiff", CCRect(71*12, 0, 250, 300));
    CCSprite *plant=CCSprite::createWithSpriteFrame(frame0);
    plant->setPosition(ccp(250, 300));
    this->addChild(plant);
//    CCArray *array=CCArray::create();
//    array->addObject(frame0);
//     array->addObject(frame1);
//     array->addObject(frame2);
//     array->addObject(frame3);
//     array->addObject(frame4);
//     array->addObject(frame5);
//     array->addObject(frame6);
//     array->addObject(frame7);
//     array->addObject(frame8);
//     array->addObject(frame9);
//     array->addObject(frame10);
//     array->addObject(frame11);
//     array->addObject(frame12);
//    CCAnimation *antion=CCAnimation::createWithSpriteFrames(array,0.2f);
//  //  CCAnimate *animate=CCAnimate ::initWithAnimation(antion);
//   // CCSequence *seq=CCSequence::create(ani);
//    plant->runAction(animate);


    
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
    CCLog("得瑟完了");

}
//void MainScene:: update(float t){
//
//    sprite->setPosition(ccpAdd(sprite->getPosition(), ccp(1, 0)));//每一帧坐标X轴+1
//    sprite->setRotation(sprite->getRotation()+1);
//}

