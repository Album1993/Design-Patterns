//
//  lesson9.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/9.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef lesson9_hpp
#define lesson9_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class PersonBuilder {
protected:
    string g;
    string p;
    
public:
    PersonBuilder (string graphy,string pen)
    {
        g = graphy;
        p = pen;
    };
    virtual ~PersonBuilder(){};
    virtual void BuildHead(){};
    virtual void BuildBody(){};

};

class PersonThinBuilder:public PersonBuilder {
    
    
public:
    PersonThinBuilder(string graphy,string pen):PersonBuilder(graphy,pen){};
    void BuildHead(){
        cout<<g<< "draw thin head" <<p<< endl;
    };
    
    void BuildBody(){
    cout<<g<< "draw thin body" <<p<< endl;
    };
};


class PersonFatBuilder:public PersonBuilder {
    
public:
    PersonFatBuilder(string graphy,string pen):PersonBuilder(graphy,pen){};
    void BuildHead(){
        cout<<g<< "draw fat head" <<p<< endl;
    };
    
    void BuildBody(){
        cout<<g<< "draw fat body" <<p<< endl;
    };
};



class PersonDirector {
private:
    PersonBuilder * pb;
public:
    PersonDirector(PersonBuilder * pb) {
        this->pb = pb;
    }
    void CreatePerson(){
        (*pb).BuildHead();
        (*pb).BuildBody();
    }
};

#endif /* lesson9_hpp */
