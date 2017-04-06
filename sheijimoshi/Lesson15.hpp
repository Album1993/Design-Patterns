//
//  Lesson15.hpp
//  sheijimoshi
//
//  Created by akka on 2017/3/31.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson15_hpp
#define Lesson15_hpp

#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

inline void coutName(int depth,string name) {
    string dash = "-";
    for (int i = 0; i< depth; i++) {
        cout<<"-";
    }
    cout<<name<<endl;
}

class Company {
protected:
    string name;
    
public:
    Company(string name):name(name) {
        
    }
    
    virtual void Add(Company * c){};
    virtual void Remove(Company * c){};
    virtual void Display(int depth){};
    virtual void LineOfDuty(){};

};

typedef list<Company *> CompanyList;

class ConcreteCompany:public Company {
private:
    CompanyList children ;

public:
    ConcreteCompany (string name):Company(name){}
    void Add(Company * c){ children.push_front(c); };
    void Remove(Company * c){children.remove(c);};
    void Display(int depth){
        cout<< '-' * depth<<"name"<<endl;
        CompanyList::iterator iter;
        
        for (iter = children.begin(); iter != children.end(); iter++) {
            (*iter)->Display(depth + 2);
        }
        
    };
    void LineOfDuty(){
        CompanyList::iterator iter;
        
        for (iter = children.begin(); iter != children.end(); iter++) {
            (*iter)->LineOfDuty();
        }
    }
    
};


class HRDepartment: public Company {
public:
    HRDepartment(string name):Company(name) {}
    void Add(Company * c){  };
    void Remove(Company * c){};
    void Display(int depth){
        coutName(depth,name);
    };
    void LineOfDuty(){
        cout<<name<<"  员工招聘培训管理"<<endl;
    }
};

class FinanceDepartment : public Company {
public:
    FinanceDepartment(string name):Company(name){}
    void Add(Company * c){  };
    void Remove(Company * c){};
    void Display(int depth){
        coutName(depth,name);
    };
    void LineOfDuty(){
        cout<<name<<"  公司财务收支管理"<<endl;
    }
};


#endif /* Lesson15_hpp */
