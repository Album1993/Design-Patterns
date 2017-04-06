//
//  lesson7.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/7.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef lesson7_hpp
#define lesson7_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class TestPaper {
public :
    TestPaper(){};
    ~TestPaper(){};
    void TestQuestion1(){cout<<"question1"<<endl; cout<<Answer1()<<endl;};
    void TestQuestion2(){cout<<"question2"<<endl;cout<<Answer2()<<endl;};
    void TestQuestion3(){cout<<"question3"<<endl;cout<<Answer3()<<endl;};
    
    virtual string Answer1(){return "";};
    virtual string Answer2(){return "";};
    virtual string Answer3(){return "";};
};

class TestPaperA:public TestPaper{
public:
    string Answer1() {return "a";};
    string Answer2() {return "b";};
    string Answer3() {return "c";};
};

class TestPaperB:public TestPaper{
public:
    string Answer1() {return "d";};
    string Answer2() {return "e";};
    string Answer3() {return "f";};
};


#endif /* lesson7_hpp */
