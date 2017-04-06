//
//  lesson18.hpp
//  sheijimoshi
//
//  Created by akka on 2017/4/6.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef lesson18_hpp
#define lesson18_hpp

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Barbecuer {
    
    
public:
    void BakeMutton(){
        cout<<"烤羊肉串"<<endl;
    }
    
    void BakeChickenWing(){
        cout<<"烤鸡翅"<<endl;
    }
    
};

class Command {
protected:
    Barbecuer * receiver;
    
public:
    Command (Barbecuer * receiver) {
        this->receiver = receiver;
    }
    ~Command(){}
    
    virtual void ExcuteCommand(){};
};

class BakeMuttonCommand:public Command {
    
public:

    BakeMuttonCommand(Barbecuer * receiver):Command(receiver){
    
    }
    
    void ExcuteCommand(){
        receiver->BakeMutton();
    }
    
};

class BakeChickenCommand:public Command {
    
public:
    
    BakeChickenCommand(Barbecuer * receiver):Command(receiver){
        
    }
    
    void ExcuteCommand(){
        receiver->BakeChickenWing();
    }
    
};


class Waiter {
private:

    vector<Command *> orders;
    
public:
    void SetOrder(Command * command) {
        orders.push_back(command);
    }
    
    void CancelOrder(Command * command) {
        vector<Command *>::iterator it;
        for ( it = orders.begin(); it != orders.end(); it++) {
            if ((*it ) == (command)) {
                break;
            }
        }
        orders.erase(it);
    }
    
    void Notify(){
        for (vector<Command *>::iterator it = orders.begin(); it != orders.end(); it++) {
            (*it)->ExcuteCommand();
        }
    }
};




#endif /* lesson18_hpp */
