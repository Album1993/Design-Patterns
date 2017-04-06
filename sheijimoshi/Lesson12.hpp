//
//  Lesson12.hpp
//  sheijimoshi
//
//  Created by akka on 2017/3/20.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson12_hpp
#define Lesson12_hpp

#include <iostream>
using namespace std;
class Work;

class State {
    
public:
    ~State(){};
    virtual void WriteProgram(Work * work){};
};

class ForenoonState: public State {
    
public:
    ~ForenoonState(){};
    void WriteProgram(Work * work);
};

class NoonState:public State {
    
public:
    ~NoonState(){};
    void WriteProgram(Work * work);
};

class Work {
private:
    State  * current;
    double hour;
    
    bool finish = false;
    
public:
    Work(){current = new ForenoonState(); }
    double getHour(){return  hour;}
    void setHour(double hour){this->hour = hour;
        if (hour > 10) {
            current = new NoonState();
        } else {
            current = new ForenoonState();
        }
    }
    bool getFinish(){return  finish;}
    void setFinish(bool finish){this->finish = finish;}
    State *  getState(){return  current;}
    void setState(State * state){this->current = state;}
    
    void WriteProgram(){current->WriteProgram(this);}
};


#endif /* Lesson12_hpp */
