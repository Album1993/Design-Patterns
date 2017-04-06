//
//  Lesson8.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/9.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson8_hpp
#define Lesson8_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Stock1{
public:
    void Sell(){ cout<<"stock1 sell\n";};
    void Buy(){ cout<<"stock1 out\n";};
};


class Stock2{
public:
    void Sell(){ cout<<"stock2 sell\n";};
    void Buy(){ cout<<"stock2 out\n";};
};

class Stock3{
public:
    void Sell(){ cout<<"stock3 sell\n";};
    void Buy(){ cout<<"stock3 out\n";};
};


class Fund{
    Stock1 * gu1;
    Stock2 * gu2;
    Stock3 * gu3;
    
    
public:
    Fund(){
        gu1 = new Stock1();
        gu2 = new Stock2();
        gu3 = new Stock3();
    }
    void sell(){
        gu1->Sell();
        gu2->Sell();
        gu3->Sell();
    };
    void buy(){
        gu1->Buy();
        gu2->Buy();
        gu3->Buy();
    }
};




#endif /* Lesson8_hpp */
