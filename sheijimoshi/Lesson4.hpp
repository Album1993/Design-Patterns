//
//  Lesson4.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/3.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson4_hpp
#define Lesson4_hpp

#include <stdio.h>
#include <iostream>

using namespace std;


class GiveGift {
public:
    virtual ~GiveGift(){};
    virtual void GiveDolls()=0;
    virtual void GiveFlowers()=0;
    virtual void GiveChocolate()=0;
};

class SchoolGirl {
private:
    
    string name;
public:
    string getName(){return  name;}
    void setName(string name_){name = name_;}
};

class Pursuit:GiveGift {
    
private:
    SchoolGirl * mm;
    
public:
    Pursuit(SchoolGirl * mm){
        this->mm = mm;
    }
    
    void GiveDolls() {cout<<"send doll"<<endl;};
    void GiveFlowers() {cout<<"send flower"<<endl;};
    void GiveChocolate(){cout<<"send chocolate"<<endl;};
    
};

class Proxy:GiveGift {
    Pursuit * gg;
    
public:
    Proxy(SchoolGirl * mm) {
        gg = new Pursuit(mm);
    }
    void GiveDolls() {gg->GiveDolls();/* you can do anything you want */};
    void GiveFlowers() {gg->GiveFlowers();};
    void GiveChocolate(){gg->GiveChocolate();};

};

#endif /* Lesson4_hpp */
