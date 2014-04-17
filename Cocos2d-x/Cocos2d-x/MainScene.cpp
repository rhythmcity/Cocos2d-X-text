//
//  MainScene.cpp
//  Cocos2d-x
//
//  Created by 李言 on 14-4-5.
//
//

#include "MainScene.h"
#include "GameScene.h"
#include "Zombie.h"

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
    CCNotificationCenter::sharedNotificationCenter()-> addObserver(this, callfuncO_selector(MainScene:: recv_message_fire), FIRE_PB, NULL);
    this->schedule(schedule_selector(MainScene::upData));
    CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
     map=CCTMXTiledMap::create("map.tmx");
    this->addChild(map);

    this->setTouchEnabled(true);
    this->setTouchMode(kCCTouchesOneByOne);
    this->setpbArray(CCArray::create());
    zombie=Zombie::create();
    zombie->setPosition(ccp(900, 300));
    this->addChild(zombie);



    
    return true;
}
void MainScene:: recv_message_fire(CCObject * object){
    this->getpbArray()->addObject(object);
    CCLog("ok");
}
bool MainScene:: ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    CCPoint tilepoint=pTouch->getLocation();
    tilepoint=CCPoint((int)tilepoint.x,(int)tilepoint.y);
    CCTMXLayer *layer=map->layerNamed("map");
    CCSprite *tile= layer->tileAt(CCPointMake((int)tilepoint.x/80,(int)(640-tilepoint.y)/80));
    Plant *plant=Plant::create();
    plant->setPosition(tile->getPosition());
   // tile->runAction(CCFadeOut::create(1));
    if (!tile->getUserData()) {
        CCSize tilesize=tile->getContentSize();
        CCPoint plantpint=ccpAdd(tile->getPosition(), ccp(tilesize.width/2, tilesize.height/2));
        plant->setPosition(plantpint);

          tile->setUserData(plant);
          this->addChild(plant);
    }
  
    

 
  
    return false;
}
void MainScene:: koZombie(CCSprite *pb ,Zombie *zom){
    zombie->reducehp();
    pb->removeFromParentAndCleanup(true);
}
void MainScene:: upData(float t){
    CCArray *pArray= this->getpbArray();
    for (int i = 0; i<pArray ->count(); i++) {
        CCSprite *pb=(CCSprite *)pArray->objectAtIndex(i);
        if (pb->boundingBox().intersectsRect(zombie->boundingBox())) {
            pArray->removeObject(pb);
            this->koZombie(pb, zombie);
        }
    }
}
MainScene ::~MainScene(){

    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, FIRE_PB);
    pbArray->release();
}
