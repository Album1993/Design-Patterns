
//
//  Lesson3.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/2.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson3_hpp
#define Lesson3_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Person {
    
private:
    string name;
public:
    Person(){};
    Person(string name):name(name){}
    ~Person(){};
    virtual void show(){
        cout<<"装扮的"<<name<<endl;
    }
};

class Finery : public Person {
protected:
    Person * component;
    
public:
    Finery(){};
    void Decorate(Person * componpent_) {
        component = componpent_;
    }
    
    void show() {
        if (component != NULL){
            component->show();
        }
    }
};

class TShirts : public Finery {
    
    
public:
    TShirts(){};
    void show(){
        cout<<"大体恤"<<endl;
        Finery::show();
    }
};

class BigTrouser : public Finery {
    
    
public:
    BigTrouser(){};
    void show(){
        cout<<"垮裤"<<endl;
        Finery::show();
    }
};


#endif /* Lesson3_hpp */
