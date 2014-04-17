//
//  Zombie.cpp
//  Cocos2d-x
//
//  Created by 李言 on 14-4-16.
//
//

#include "Zombie.h"
bool Zombie:: init(){

    if (!CCNode::init()) {
        return false;
    }
    HP=100;
    m_sprite=CCSprite::create("Zombie1.tiff");
    CCAnimation *antion=CCAnimation::create();
    CCSpriteFrame *frame;
    for (int i =0; i<22; i++) {
        char* str=new char[255];
        sprintf(str, "Zombie%d.tiff",i+1);
        frame= CCSpriteFrame::create(str,CCRectMake(0,0,166,144));
        antion->addSpriteFrame(frame);
    }
    antion->setDelayPerUnit(0.1);
    antion->setLoops(-1);
    CCAnimate *animate=CCAnimate::create(antion);
    
    

    this->addChild(m_sprite);
    m_sprite->runAction(animate);
    return true;

}
void Zombie::move(float t){
    
    CCMoveBy *bt=CCMoveBy::create(0.5, ccp(-2, 0));
    this ->runAction(bt);

}
void Zombie:: die(){
    this->setVisible(false);
    
}
void Zombie:: reducehp(){
    HP=HP-20;
    if (HP<=0) {
        CCBlink *blink=CCBlink::create(1, 4);
        CCCallFunc *c =CCCallFunc::create(this, callfunc_selector(Zombie::die));
        CCSequence *se=CCSequence::create(blink,c,NULL);
        this->runAction(se);
       
    }

}

void Zombie::onEnter() {
    CCNode::onEnter();

this->schedule(schedule_selector(Zombie::move), 0.1);
}