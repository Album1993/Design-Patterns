//
//  Lesson23.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/4/8.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson23_hpp
#define Lesson23_hpp

#include <stdio.h>
#include <list>
#include <algorithm>

#include <iostream>
using namespace std;

class Man;
class Woman;

class Action{
public:
    
    ~Action(){}
    virtual void GetManConclusion(Man * concreteElementA){};
    virtual void GetWomanConclusion(Woman * concreteElementB){};
    
};

class Person_23{
public:
    virtual ~Person_23(){};
    virtual void Accept(Action * visitor){};
    
};

class Success: public Action {
    
public:
    void GetManConclusion(Man * concreteElementA){
        cout<<"su man"<<endl;
    }
    void GetWomanConclusion(Woman * concreteElementB){
        cout<<"su wo"<<endl;
    }
};

class Failing: public Action {

public:
    void GetManConclusion(Man * concreteElementA){
        cout<<"fi man"<<endl;
    }
    void GetWomanConclusion(Woman * concreteElementB){
        cout<<"fi wo"<<endl;
    }
};


class Man:public Person_23 {
    
public:
    void Accept(Action * visitor) {
        visitor->GetManConclusion(this);
    }
    
};

class Woman:public Person_23 {
    
public:
    void Accept(Action * visitor) {
        visitor->GetWomanConclusion(this);
    }
};

class ObjectStructure {
private:
    list<Person_23 *>elements;
    
public:
    void Attach(Person_23 * person){
        elements.push_back(person);
    }
    
    void Display(Action * visitor) {
        
        list<Person_23 *>::iterator it = elements.begin();
        for (; it != elements.end(); it++) {
            (*it)->Accept(visitor);
        }
        
    }
    
};
#endif /* Lesson23_hpp */
