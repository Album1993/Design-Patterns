//
//  lesson2.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/2.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef lesson2_hpp
#define lesson2_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class CashSuper {
    
public:
    virtual ~CashSuper(){};
    virtual double acceptCash(double money){return 0;};
};

class CashNormal:public CashSuper {
    
public:
    double acceptCash(double money){return  money;};
};

class CashRebate:public CashSuper {
private:
    double moneyRebate = 1.0;
    
public:
    CashRebate(double moneyRebate):moneyRebate(moneyRebate){};
    double acceptCash(double money){return  money * moneyRebate;};
};


class CashReturn:public CashSuper {
private :
    double moneyCondition = 0.0;
    double moneyReturn = 0.0;
    
public:
    CashReturn(double moneyCondition,double moneyReturn) :moneyCondition(moneyCondition),moneyReturn(moneyReturn) {};
    
    double acceptCash(double money){
        double result = money;
        if (money >= moneyCondition) {
            result = money - int (money / moneyCondition) * moneyReturn;
        }
        return result;
    };
};

class CashFactory {
    
public:
    static CashSuper * createCashAccept(int type)
    {
        CashSuper * cs = NULL;
        switch (type) {
            case 0:
                cs = new CashNormal();
                break;
            case 1:
                cs = new CashReturn(300,100);
                break;
            case 2:
                cs = new CashRebate(0.8);
                break;
            default:
                break;
        }
        return cs;
    }
};

class CashContext {
private:
    CashSuper * cs;
    
public:
    CashContext(int type) {
        cs = CashFactory::createCashAccept(type);
    }
    double getResult(double money)
    {
        return cs->acceptCash(money);
    }
};

#endif /* lesson2_hpp */
