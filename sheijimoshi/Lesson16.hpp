//
//  Lesson16.hpp
//  sheijimoshi
//
//  Created by akka on 2017/3/31.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson16_hpp
#define Lesson16_hpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//class MyIterator {
//    
//public:
//    virtual int First();
//    virtual int Next();
//    virtual bool IsDone();
//    virtual int CurrentItem();
//    virtual ~MyIterator();
//};
//
//class Aggregate {
//    
//public:
//    virtual MyIterator * CreateInterator();
//    virtual ~Aggregate();
//};

class ConcreteAggregate;

class ConcreteInterator {
    
private:
    ConcreteAggregate * aggregate;
    long current;
//
public:
//
    ConcreteInterator(ConcreteAggregate * aggregate){
        this->aggregate = aggregate;
        current = 0;
    }
//
    ~ConcreteInterator(){};
     int First() ;
     int Next();
     bool IsDone();
     int CurrentItem();
};
//
class ConcreteAggregate {
private:
    vector<int> items;
public:
    ~ConcreteAggregate(){}
    ConcreteInterator * CreateInterator(){
        return new ConcreteInterator(this);
    }
    
    long getCount(){
        return items.size();
//        return 0;
    }
//
    void setItem(int x) {
        items.push_back(x);
    }
    
    void checkItem(){
        cout<<"start"<<endl;
        for (vector<int>::iterator it = items.begin(); it != items.end(); it++) {
            cout<<*it<<endl;
        }
    }
//
    int getItem(long x){
        return items[x];
//        return 0;
    }
//
};
//

//
#endif /* Lesson16_hpp */
