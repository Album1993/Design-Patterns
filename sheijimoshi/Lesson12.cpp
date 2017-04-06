//
//  Lesson12.cpp
//  sheijimoshi
//
//  Created by akka on 2017/3/20.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#include "Lesson12.hpp"

void ForenoonState::WriteProgram(Work *work) {
    cout<< "it is"<<work->getHour()<<"i want to start work"<<endl;
}

void NoonState::WriteProgram(Work *work) {
    cout<< "it is"<<work->getHour()<<"i want to finish work"<<endl;
}
