//
//  Lesson16.cpp
//  sheijimoshi
//
//  Created by akka on 2017/3/31.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#include "Lesson16.hpp"


int ConcreteInterator::Next(){
    int ret = 0;
    current++;
    if (current < aggregate->getCount()) {
        ret = aggregate->getItem(current);
    }
    return ret;
};

int ConcreteInterator::First(){
    long p = 0;
    return aggregate->getItem(p);
//    return 0;
} ;
bool ConcreteInterator::IsDone(){
    return current >= aggregate->getCount() ? true : false;
};
int ConcreteInterator::CurrentItem(){
    return aggregate->getItem(current);
};
