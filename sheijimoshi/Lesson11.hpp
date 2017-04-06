//
//  Lesson11.hpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/15.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#ifndef Lesson11_hpp
#define Lesson11_hpp

#include <iostream>
using namespace std;

class User_less11{
private:
    int _id;
    string _name;
    
public:
    int ID(){ return _id;}
    void setID(int id){_id = id;}
    string Name(){return _name;}
    void setName(string name){_name = name;}
    
};


class IUser_less11{
public:
    virtual ~IUser_less11(){};
    virtual void Insert(User_less11 * user){};
    virtual User_less11 * GetUser(int id){return nullptr;};
};

class SqlserverUser_less11 : public IUser_less11{
public:
    void Insert(User_less11 * user) {
        cout<<"insert a new line into sql"<<endl;
    }
    
    User_less11 * GetUser(int id){
        cout<<"get a user from sql"<<endl;
        return nullptr;
    }
};

class AccessUser_less11:public IUser_less11 {
    
public:
    void Insert(User_less11 * user) {
        cout<<"insert a new line into access"<<endl;
    }
    
    User_less11 * GetUser(int id){
        cout<<"get a user from access"<<endl;
        return nullptr;
    }
};

class Department_less11{
private:
    int _id;
    string _name;
    
public:
    int ID(){ return _id;}
    void setID(int id){_id = id;}
    string Name(){return _name;}
    void setName(string name){_name = name;}
    
};
class IDepartment_le11 {
    
public:
    ~IDepartment_le11(){};
    virtual void Insert(Department_less11 * d){};
    virtual Department_less11 * GetDepartment(int id){return nullptr;};
};

class SqlserverDepartment_less11 : public IDepartment_le11{
public:
    void Insert(Department_less11 * department) {
        cout<<"insert a new department into sql"<<endl;
    }
    
    Department_less11 * GetDepartment(int id){
        cout<<"get a department from sql"<<endl;
        return nullptr;
    }
};

class AccessDepartment_less11:public IDepartment_le11 {
    
public:
    void Insert(Department_less11 * department) {
        cout<<"insert a new department into access"<<endl;
    }
    
    Department_less11 * GetDepartment(int id){
        cout<<"get a department from access"<<endl;
        return nullptr;
    }
};

class DataAccess {
protected:
    static const string db;
    
public:
    
    static IUser_less11 * CreateUser(){
        IUser_less11 * result = nullptr;
        if (db == "sqlserver") {
            result = new SqlserverUser_less11();
        } else if (db == "access") {
            result = new AccessUser_less11();
        } else {
            
        }
        return result;
    }

    static IDepartment_le11 * CreateDepartment(){
        IDepartment_le11 * result = nullptr;
        if (db == "sqlserver") {
            result = new SqlserverDepartment_less11();
        } else if (db == "access") {
            result = new AccessDepartment_less11();
        }
        return result;
    }
};



#endif /* Lesson11_hpp */
