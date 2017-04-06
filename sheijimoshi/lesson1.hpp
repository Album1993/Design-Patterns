//
//  lesson1.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/2.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef lesson1_hpp
#define lesson1_hpp

#include <stdio.h>
#include <iostream>


using namespace std;
class Operation {
protected:
    double _numberA;
    double _numberB;
    
public:
    
    virtual ~Operation(){};
    double getNumberA(){ return _numberA;};
    void setNumberA(double A){_numberA = A;};
    double getNumberB(){ return _numberB;};
    void setNumberB(double B){_numberB = B;};
    virtual double getResult(){return 0.0;};
};

class OperationAdd:public Operation {
public:
    double getResult(){
        double result = 0;
        result = _numberA + _numberB;
        return result;
    }
};

class OperationSub:public Operation {
public:
    double getResult(){
        double result = 0;
        result = _numberA - _numberB;
        return result;
    }
};

class OperationMulti:public Operation {
public:
    double getResult(){
        double result = 0;
        result = _numberA * _numberB;
        return result;
    }
};

class OperationDiv:public Operation {
public:
    double getResult()
    {
        if (_numberB == 0) {
            throw "_numberB can't be 0";
        }
        return _numberA / _numberB;
    }
};

class OperationFactory{
public:
    static Operation * createOperate(string operate){
        Operation * oper ;
        if (operate == "+") {
            oper =  new OperationAdd();
        } else if (operate == "-") {
            oper = new  OperationSub();
        } else if (operate == "*") {
            oper = new OperationMulti();
        } else if (operate == "/") {
            oper = new OperationDiv();
        }
        return oper;
    }
};

#endif /* lesson1_hpp */
