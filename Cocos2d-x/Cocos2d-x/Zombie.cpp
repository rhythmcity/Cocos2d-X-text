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
    return true;

}

void Zombie::onEnter() {
    CCNode::onEnter();


}