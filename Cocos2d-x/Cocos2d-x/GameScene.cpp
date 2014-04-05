//
//  GameScene.cpp
//  Cocos2d-x
//
//  Created by 李言 on 14-4-5.
//
//

#include "GameScene.h"

CCScene *GameScene:: scene(){
    CCScene *scene=CCScene::create();
    GameScene *layer=GameScene::create();
    scene->addChild(layer);
    return scene;


}



bool GameScene:: init(){
    
    
    if (!CCLayer::init()) {
        return false;
    }
    CCSprite *sprite=CCSprite::create("Icon-72.png");
    CCSize  winsize=CCDirector::sharedDirector()->getWinSize();
    sprite->setPosition(ccp(winsize.width/2, winsize.height/2));
    this->addChild(sprite);
    
    return true;

}