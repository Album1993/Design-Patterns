//
//  Lesson6.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/6.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson6_hpp
#define Lesson6_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


class ICloneable{
public:
    ICloneable(){};
    virtual ~ICloneable(){};
    virtual ICloneable * Clone(){return NULL;};
};

class WorkExperience: public ICloneable {
private:
    string workData;
    string company;
public:
    WorkExperience(string workdata,string company):workData(workdata),company(company){};
    ~WorkExperience(){};
    
    string WorkData() {
        return workData;
    }
    
    void setWorkData(string workdata) {
        workData = workdata;
    }
    
    string Company() {
        return company;
    }
    
    void setCompany(string company) {
        this->company = company;
    }
    
    WorkExperience * Clone(){
        WorkExperience * e = new WorkExperience(workData,company);
        return e;
    };
};

class Resume:public ICloneable {
private:
    string name;
    WorkExperience *experience;
public:
    Resume(){}
    Resume(string name,string workdata,string company){
        this->name = name;
        experience = new WorkExperience(workdata,company);
    };
    
    string WorkData() {
        return experience->WorkData();
    }
    
    void setWorkData(string workdata) {
        experience->setWorkData(workdata);
    }
    
    string Company() {
        return experience->Company();
    }
    
    void setCompany(string company) {
        experience->setCompany(company);
    }
    
    Resume * Clone(){
        Resume * resume = new Resume();
        resume->name = name;
        WorkExperience * e = experience->Clone();
        (*resume).experience = e;
        return resume;
    }
    void printResume(){
        cout<< name<<"\t"<<experience->Company()<<"\t"<<experience->WorkData()<<endl;
    }
};


#endif /* Lesson6_hpp */
