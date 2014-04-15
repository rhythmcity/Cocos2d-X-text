//
//  Plant.cpp
//  Cocos2d-x
//
//  Created by 李言 on 14-4-15.
//
//

#include "Plant.h"
bool Plant:: init(){

    if (!CCNode::init()) {
        return false;
    }
   // CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("PlantAndZombie.plist");
    bach=CCSpriteBatchNode::create("Peashooter1.tiff");
    this->addChild(bach);
    
    CCSpriteFrame *frame;
  //  CCArray *array=CCArray::create();
    m_plant=CCSprite::create("Peashooter1.tiff");
    CCAnimation *antion=CCAnimation::create();
    
    for (int i =0; i<12; i++) {
        char* str=new char[255];
        sprintf(str, "Peashooter%d.tiff",i+1);
        frame= CCSpriteFrame::create(str,CCRectMake(0,0,71,71));
        antion->addSpriteFrame(frame);
    }
    antion->setDelayPerUnit(0.1);
    antion->setLoops(-1);
    CCAnimate *animate=CCAnimate::create(antion);

    m_plant->runAction(animate);
    this->addChild(m_plant);
    return true;
}
void Plant::fire()
{
    CCSprite *pb=CCSprite ::create("PB01.png");
    pb->setPosition(ccpAdd(this->getPosition(),ccp(30,20)));
    this->getParent()->addChild(pb);
    CCMoveBy *by=CCMoveBy ::create(3, ccp(960, 0));
    pb->runAction(by);
}
void Plant:: onFire(float t){
    this->fire();

}
void Plant::onEnter(){
    CCNode::onEnter();
    this->schedule(schedule_selector(Plant::onFire), 1);

}