//
//  lesson5.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/3.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef lesson5_hpp
#define lesson5_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class LeiFeng {
    
public:
    void Sweep(){cout<<"sweep"<<endl;}
    void Wash(){cout<<"wash"<<endl;}
    void BuyRice(){cout<<"byerice"<<endl;}
    
};

class Undergraduate:public LeiFeng {
};

class Volunteer: public LeiFeng {
};

class SampleFactory {
public:
    static LeiFeng * CreateLeiFeng(int type)
    {
        LeiFeng * result = NULL;
        switch (type) {
            case 1:
                result = new Undergraduate();
                break;
                case 2:
                result = new Volunteer();
                break;
            default:
                break;
        }
        return  result;
    }
};


class IFactory {
    
public:
    virtual ~IFactory(){};
    virtual LeiFeng * CreateLeiFeng() = 0;
};

class UndergraduateFactory:public IFactory {
    
public:
    LeiFeng * CreateLeiFeng(){
        return new Undergraduate();
    }
};

class VolunteerFactory:public IFactory{
    
public:
    LeiFeng * CreateLeiFeng(){
        return new Volunteer();
    }
};

#endif /* lesson5_hpp */
