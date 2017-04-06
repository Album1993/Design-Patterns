//
//  Lesson13.hpp
//  sheijimoshi
//
//  Created by akka on 2017/3/23.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson13_hpp
#define Lesson13_hpp

#include <iostream>

using namespace std;

class Player {
protected:
    string name;
    
public:
    Player(string name) :name(name){};
    virtual ~Player(){};

    virtual void Attack(){};
    virtual void Defense(){};
};

class Forward:public Player {
    
public:
    Forward(string name) : Player(name){}
    ~Forward(){};
    void Attack(){
        cout<< "forword attck:"<<name<<endl;
    }
    
    void Defense(){
        cout<< "forword defence:"<<name<<endl;
    }
};

class Center:public Player {
    
public:
    Center(string name) : Player(name){}
    ~Center(){};
    void Attack(){
        cout<< "center attck:"<<name<<endl;
    }
    
    void Defense(){
        cout<< "center defence:"<<name<<endl;
    }
    
};

class ForeignCenter {
private:
    string name;
public:
    
    void setname(string name) {this->name = name;}
    string getname(){return this->name;}
    
    void Attack(){
        cout<< " 进攻:"<<name<<endl;
    }
    
    void Defense(){
        cout<< "防守:"<<name<<endl;
    }
};

class Translator : public Player {
private:
    ForeignCenter * wjzf ;
    
public:
    Translator(string name):Player(name){
        wjzf = new ForeignCenter();
        wjzf->setname(name);
    }
    ~Translator(){
        delete wjzf;
    }
    
    void Attack(){
        wjzf->Attack();
    }
    
    void Defense(){
        wjzf->Defense();
    }
};


#endif /* Lesson13_hpp */
