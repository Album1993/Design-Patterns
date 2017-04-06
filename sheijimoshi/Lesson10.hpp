//
//  Lesson10.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/13.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson10_hpp
#define Lesson10_hpp

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class Subject;

class Observer {
protected:
    string name;
    Subject * sub;
    
public:
    Observer(string name,Subject * sub):name(name),sub(sub){};
    ~Observer(){};
    virtual void Update(){};
};

class Subject {
    
public:
    virtual void Attach(Observer * observer){};
    virtual void Detach(Observer * observer){};
    virtual void Notify(){};
    virtual string getSubjectState(){ return nullptr;};
    virtual void SubjectState(string substate){};
};

class Boss:public Subject {
    
private:
    list<Observer *> observers;
    string action;
    
    
public:
    void Attach(Observer * observer){
        observers.push_back(observer);
    }
    
    void Detach(Observer * observer) {
        observers.remove(observer);
    }
    
    void Notify() {
        list<Observer *>::iterator itor;
        itor = observers.begin();
        while (itor != observers.end()) {
            (*(*itor)).Update();
            itor++;
        }
    }
    string getSubjectState(){ return action;}
    
    void SubjectState(string substate){action = substate;};
    
};

class StockObserver:public Observer {
    
public:
    StockObserver (string name,Subject * sub):Observer(name,sub){};
    void Update(){
        cout<<sub->getSubjectState()<<name<<"close stock website,back work"<<endl;
    }
};

class NBAObserver:public Observer {
    
public:
    NBAObserver(string name,Subject * sub):Observer(name,sub){};
    void Update(){
        cout<<sub->getSubjectState()<<name<<"close nba website,back work"<<endl;
    }
};


#endif /* Lesson10_hpp */
