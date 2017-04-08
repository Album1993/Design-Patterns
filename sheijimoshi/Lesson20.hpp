//
//  Lesson20.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/4/7.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson20_hpp
#define Lesson20_hpp

#include <iostream>

using namespace std;

class Country;

class UnitedNations {
    
public:
    virtual ~UnitedNations(){}
    virtual void Declare(string message,Country * colleague){};
};

class Country {
protected:
    UnitedNations * mediator;
    
public:
    Country(UnitedNations * mediator){
        this->mediator = mediator;
    }
};

class USA:public Country {
    
public:
    USA(UnitedNations * mediator):Country(mediator){
    }
    
    void Declare(string message){
        mediator->Declare(message, this);
    }
    
    void GetMessage(string message) {
        cout<<"usa get message:"<<message<<endl;
    }
};


class Irap : public Country {
    
    
public:
    Irap(UnitedNations * mediator) : Country(mediator) {
    }
    
    void Declare(string message) {
        mediator->Declare(message, this);
    }
    
    void GetMessage(string message) {
        cout<<"irap get message :"<<message<<endl;
    }
};

class UnitedNationsSecurityCouncil:public UnitedNations {
    
public:
    USA * colleague1;
    Irap * colleague2;

    void Declare(string message,Country * colleague){
        if(colleague == colleague1) {
            colleague2->GetMessage(message);
        }else {
            colleague1->GetMessage(message);
        }
    }
};



#endif /* Lesson20_hpp */
