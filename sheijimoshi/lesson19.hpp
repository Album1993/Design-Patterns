//
//  lesson19.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/4/6.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef lesson19_hpp
#define lesson19_hpp

#include <iostream>

using namespace std;


class Request {
public:
    string requestType;
    string requestContent;
    int number;

};

class Manager {
protected:
    Manager * superior;
    string name ;
    
    
public:
    Manager(string name):name(name){}
    virtual ~Manager(){};
    void SetSuperior(Manager * superior) {
        this->superior = superior;
    }
    virtual void RequestApplication(Request * request){}
    
};


class CommonManager:public Manager {
    
public:
    CommonManager(string name):Manager(name){}
    void RequestApplication(Request * request){
        if (request->requestType == "请假" && request->number <= 2) {
            cout<<name<<request->requestContent<<request->number<<endl;
        } else {
            if (superior != nullptr) {
                superior->RequestApplication(request);
            }
        }
    }
};

class Majordomo:public Manager {
    
    
public:
    Majordomo(string name):Manager(name){
        superior = NULL;
    }
    void RequestApplication(Request * request){
        if (request->requestType == "请假" && request->number <= 5) {
            cout<<name<<request->requestContent<<request->number<<endl;
        } else {
            if (superior != NULL) {
                superior->RequestApplication(request);
            }
        }
    }
};

class GeneralManager:public Manager {
    
    
public:
    GeneralManager(string name):Manager(name){}
    void RequestApplication(Request * request){
        cout<<"NO"<<endl;
    }
};


#endif /* lesson19_hpp */
