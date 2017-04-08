//
//  lesson21.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/4/8.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef lesson21_hpp
#define lesson21_hpp

#include <iostream>
#include <map>


using namespace std;


class User_lesson21{
private:
public :
    string name;
    User_lesson21(string name):name(name){};
};


class Website {
    
public:
    virtual ~Website(){};
    virtual void Use(User_lesson21 * user){};
};

class ConcreteWebsite: public Website {
private:
    string name;
    
public:
    
    ConcreteWebsite(string name){
        this->name = name;
    }

    void Use(User_lesson21 * user){
        cout<<"website name:"<<name<<" user:"<<user->name<<endl;
    }
};

class WebSiteFactory {
private:
    multimap<string, Website *> flyweights ;
    
public:
    Website * getWebSiteCategory(string key){
        multimap<string, Website *>::iterator it = flyweights.find(key);
        
        if (it == flyweights.end()) {
            flyweights.insert(make_pair(key, new ConcreteWebsite(key)));
        }
        return flyweights.find(key)->second;
    }
    long GetWebSiteCount(){
        return flyweights.size();
    }
    
};


#endif /* lesson21_hpp */
