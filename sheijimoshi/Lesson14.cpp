//
//  Lesson14.cpp
//  sheijimoshi
//
//  Created by akka on 2017/3/31.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#include "Lesson14.hpp"

RoleStateMemento * GameRole::SaveState() {
    return new RoleStateMemento(vit,attack,def);
}

void GameRole::RecoveryState(RoleStateMemento *memento) {
    this->vit = memento->getVitality();
    this->attack = memento->getAttack();
    this->def = memento->getDefence();
}
