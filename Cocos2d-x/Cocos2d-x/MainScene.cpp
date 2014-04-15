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
    CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
     map=CCTMXTiledMap::create("map.tmx");
    this->addChild(map);

    this->setTouchEnabled(true);
    this->setTouchMode(kCCTouchesOneByOne);
   
  




    
    return true;
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

