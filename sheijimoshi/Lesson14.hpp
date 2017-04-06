//
//  Lesson14.hpp
//  sheijimoshi
//
//  Created by akka on 2017/3/31.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson14_hpp
#define Lesson14_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class RoleStateMemento;

class GameRole {
private :
    int vit;
    int attack;
    int def;
    
public:
    void setVitality(int vitality){vit = vitality;}
    void setDefence(int defence){def = defence;}
    void setAttack(int attack) {this->attack = attack;}
    
    int getVitality(){return vit;}
    int getDefence(){return def;}
    int getAttack(){return attack;}
    
    void StateDisplay(){
        cout<<"current state:"<<endl;
        cout<<"vitality"<<vit<<endl;
        cout<<"attack"<<attack<<endl;
        cout<<"defence"<<def<<endl;
    }
    
    RoleStateMemento * SaveState();
    void RecoveryState(RoleStateMemento * memento);
    
    void GetInitState(){
        vit = 100;
        attack = 100;
        def = 100;
    }
    void Fight(){
        vit = 0;
        attack = 0;
        def = 0;

    }
};

class RoleStateMemento {
    
private :
    int vit;
    int attack;
    int def;
    
public:
    RoleStateMemento(int vit,int attack ,int def):vit(vit),attack(attack),def(def){}
    int getVitality(){return vit;}
    int getDefence(){return def;}
    int getAttack(){return attack;}
};

class RoleStateCaretaker {
private:
    RoleStateMemento * memento;
public:
    void setMemento (RoleStateMemento * memento){this->memento = memento;}
    RoleStateMemento * getMemento(){return memento;}
};

#endif /* Lesson14_hpp */
