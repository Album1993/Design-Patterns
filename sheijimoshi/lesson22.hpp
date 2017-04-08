//
//  lesson22.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/4/8.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef lesson22_hpp
#define lesson22_hpp

#include <iostream>
using namespace std;

class PlayContext{
private:
    string text;
public:
    void setPlaytext(string playtext){
        text = playtext;
    }
    
    string getPlaytext(){
        return text;
    }
};

class Expression {
    
    
public:
    ~Expression(){}
    void Interpret(PlayContext * context) {
        if (context->getPlaytext().length() == 0) {
            return;
        } else {
            string playkey = context->getPlaytext().substr(0,1);
            
            
            context->setPlaytext(context->getPlaytext().substr(2));
           
            string::size_type st;
            double playvalue = stod(context->getPlaytext(),&st);
//             cout<<playkey<<"---"<<playvalue<<"---"<<context->getPlaytext()<<endl;
            string sub = context->getPlaytext().substr(st+1);
//            cout<<"sub:"<<sub<<endl;
            context->setPlaytext(sub);
            Excute(playkey, playvalue);
        }
    }
    virtual void Excute(string key,double value){};
};

class Note:public Expression {
    
public:
    void Excute(string key,double value) {
        string note = "";
        if (key == "C") {
            note = "1";
        } else if(key == "D"){
            note = "2";
        } else if (key == "E") {
            note = "3";
        } else if (key == "F") {
            note = "4";
        } else if (key == "G") {
            note = "5";
        } else if (key == "A") {
            note = "6";
        } else if (key == "B") {
            note = "7";
        }
        cout<<note<<endl;
    }
};


class Scale:public Expression {
    
public:
    void Excute(string key,double value) {
        string scale = "";
        switch (static_cast<int>(value)) {
            case 1:
                scale = "低音";
                break;
            case 2:
                scale = "中音";
                break;
            case 3:
                scale = "高音";
                break;
            default:
                break;
        }
        cout<<scale<<endl;
    }
};

#endif /* lesson22_hpp */
