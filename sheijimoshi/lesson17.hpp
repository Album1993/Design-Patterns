//
//  lesson17.hpp
//  sheijimoshi
//
//  Created by akka on 2017/4/4.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef lesson17_hpp
#define lesson17_hpp

#include <iostream>

using namespace std;
class Implementor {
    
public:
    virtual ~Implementor(){};
    virtual void Operation_less17(){};
};

class ConcreteImplementA:public Implementor {
    
public:
    void Operation_less17(){
        cout<<"implement a"<<endl;
    }
};

class ConcreteImplementB:public Implementor {
    
public:
    void Operation_less17(){
        cout<<"implement B"<<endl;
    }
};


class Abstraction {
protected:
    Implementor * implementor;
    
public:
    void setImplementor(Implementor * implementor) {
        this->implementor = implementor;
    }
    
    virtual void Operation(){
        implementor->Operation_less17();
    }
};

class RefinedAbstraction: public Abstraction {
    
public:
    void Operation(){
        implementor->Operation_less17();
    }
};


#endif /* lesson17_hpp */
