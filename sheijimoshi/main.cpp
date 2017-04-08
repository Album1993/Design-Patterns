//
//  main.cpp
//  sheijimoshi
//
//  Created by 张一鸣 on 2017/3/2.
//  Copyright © 2017年 张一鸣. All rights reserved.
//

#include <stdio.h>
#include "lesson1.hpp"
#include "lesson2.hpp"
#include "Lesson3.hpp"
#include "Lesson4.hpp"
#include "lesson5.hpp"
#include "Lesson6.hpp"
#include "lesson7.hpp"
#include "Lesson8.hpp"
#include "lesson9.hpp"
#include "Lesson10.hpp"
#include "Lesson11.hpp"
#include "Lesson12.hpp"
#include "Lesson13.hpp"
#include "Lesson14.hpp"
#include "Lesson15.hpp"
#include"Lesson16.hpp"
#include "lesson17.hpp"
#include "lesson18.hpp"
#include "lesson19.hpp"
#include "Lesson20.cpp"
#include "lesson21.hpp"
#include "lesson22.hpp"

using namespace std;

void testLesson1();
void testLesson2();
void testLesson3();
void testLesson4();
void testLesson5();
void testLesson6();
void testLesson7();
void testLesson8();
void testLesson9();
void testLesson10();
void testLesson11();
void testLesson12();
void testLesson13();
void testLesson14();
void testLesson15();
void testLesson16();
void testLesson17();
void testLesson18();
void testLesson19();
void testLesson20();
void testLesson21();
void testLesson22();

int main() {
    testLesson22();
}

void testLesson1() {
    float f1 = 5;
    float f2 = 4;
    
    string op = "*";
    
    Operation * operation = OperationFactory::createOperate(op);
    operation->setNumberA(f1);
    operation->setNumberB(f2);
    float result = operation->getResult();
    
    cout<< result << endl;
}

enum {
    cashnornal = 0,
    cashrebate = 1,
    cashreturn = 2
    
};

void testLesson2() {
    CashContext * context = new CashContext(cashreturn);
    double result = context->getResult(500);
    cout<<result<<endl;
}

void testLesson3() {
    Person * person = new Person("小菜");
    TShirts * tshirt = new TShirts();
    BigTrouser * bigtrouser =  new BigTrouser();
    
    tshirt->Decorate(person);
    bigtrouser->Decorate(tshirt);
    bigtrouser->show();
    
}

void testLesson4(){
    SchoolGirl * jiaojiao = new SchoolGirl();
    jiaojiao->setName("脚脚");
    Proxy * dali = new Proxy(jiaojiao);
    dali->GiveDolls();
    dali->GiveFlowers();
    dali->GiveChocolate();
}


enum {
    graduate = 0,
    volunteer = 1
    
};

void testLesson5(){
    //sample factory
    LeiFeng * student1 = SampleFactory::CreateLeiFeng(graduate);
    LeiFeng * student2 = SampleFactory::CreateLeiFeng(graduate);
    LeiFeng * student3 = SampleFactory::CreateLeiFeng(graduate);
    student1->Wash();
    student2->Sweep();
    student3->Wash();
    
    IFactory * factory = new UndergraduateFactory();
    LeiFeng * student = factory->CreateLeiFeng();
    student->BuyRice();
    student->Sweep();
    student->Wash();

}

void testLesson6() {
    Resume * resume = new Resume("zhang","100","akka");
    Resume * resume2 = resume->Clone();
    resume->setCompany("baidu");
    resume->printResume();
    resume2->printResume();
}

void testLesson7(){
    
    TestPaper * studentA = new TestPaperA();
    studentA->TestQuestion1();
    studentA->TestQuestion2();
    studentA->TestQuestion3();
    TestPaper * studentB = new TestPaperB();
    studentB->TestQuestion1();
    studentB->TestQuestion2();
    studentB->TestQuestion3();
}


void testLesson8(){
    Fund * fund = new Fund();
    fund->buy();
    fund->sell();
}

void testLesson9() {
    string pen = "yellow";
    string graphic = "green";
    
    PersonThinBuilder * ptb = new PersonThinBuilder(graphic,pen);
    PersonDirector * pdThin = new PersonDirector(ptb);
    pdThin->CreatePerson();
    PersonFatBuilder * pfb = new PersonFatBuilder(graphic,pen);
    PersonDirector * pdFat = new PersonDirector(pfb);
    pdFat->CreatePerson();
    
}


void testLesson10(){
    Boss * tongzizhe = new Boss();
    
    StockObserver * tongshi1 = new StockObserver("jack",tongzizhe);
    NBAObserver * tongshi2 = new NBAObserver("nancy",tongzizhe);
    
    tongzizhe->Attach(tongshi1);
    tongzizhe->Attach(tongshi2);
    
    tongzizhe->SubjectState("bose come back");
    
    tongzizhe->Notify();

}

void testLesson11(){
    
}

void testLesson12(){
    Work * emergencyProject = new Work();
    emergencyProject->setHour(5);
    emergencyProject->WriteProgram();
    emergencyProject->setHour(30);
    emergencyProject->WriteProgram();
}

void testLesson13(){
    Player * b = new Forward("batier");
    b->Attack();
    
    Player *m = new Translator("yaoming");
    m ->Attack();
}

void testLesson14(){
    GameRole * lixiaoyao = new GameRole();
    lixiaoyao->GetInitState();
    lixiaoyao->StateDisplay();
    
    RoleStateCaretaker * stateAdmin = new RoleStateCaretaker();
    stateAdmin->setMemento(lixiaoyao->SaveState());
    
    lixiaoyao->Fight();
    lixiaoyao->StateDisplay();
    
    lixiaoyao->RecoveryState(stateAdmin->getMemento());
    lixiaoyao->StateDisplay();
    

}

void testLesson15(){
    ConcreteCompany * root = new ConcreteCompany("北京总公司");
    root->Add(new HRDepartment("总公司人力"));
    root->Add(new FinanceDepartment("总公司财务"));
    
    ConcreteCompany * comp = new ConcreteCompany("上海分公司");
    comp->Add(new HRDepartment("上海分人力"));
    comp->Add(new FinanceDepartment("上海分财务"));
    root->Add(comp);
    
    
    ConcreteCompany * comp1 = new ConcreteCompany("南京办事处");
    comp1->Add(new HRDepartment("南京办人力"));
    comp1->Add(new FinanceDepartment("南京办财务"));
    comp->Add(comp1);
    
    ConcreteCompany * comp2 = new ConcreteCompany("杭州办事处");
    comp2->Add(new HRDepartment("杭州办人力"));
    comp2->Add(new FinanceDepartment("杭州办财务"));
    comp->Add(comp2);
    
    cout<< "结构图："<<endl;
    root->Display(1);
    
    cout<<" 指责："<<endl;
    root->LineOfDuty();
    
}

void testLesson16() {
    ConcreteAggregate *  a  = new ConcreteAggregate();
    a->setItem(1);
    a->setItem(2);
    a->setItem(3);
    
    ConcreteInterator * i = new ConcreteInterator(a);
    
    while (!i->IsDone()) {
        cout<<i->CurrentItem()<<endl;
        i->Next();
    }
}



void testLesson17(){
    Abstraction * ab = new RefinedAbstraction();
    ab->setImplementor(new ConcreteImplementA());
    ab->Operation();
    ab->setImplementor(new ConcreteImplementB());
    ab->Operation();
}

void testLesson18(){
    Barbecuer * boy = new  Barbecuer();
    Command * bakeMuttonCommand1 = new BakeMuttonCommand(boy);
    Command * bakeMuttonCommand2 = new BakeMuttonCommand(boy);
    Command * bakeChickenWingCommand1 = new BakeChickenCommand(boy);
    Waiter * girl = new Waiter();
    girl->SetOrder(bakeMuttonCommand1);
    girl->SetOrder(bakeMuttonCommand2);
    girl->SetOrder(bakeChickenWingCommand1);
    girl->CancelOrder(bakeChickenWingCommand1);
    
    girl->Notify();
    
}

void testLesson19(){
    CommonManager * jinli = new CommonManager("jingli");
    Majordomo * zongjian = new Majordomo("zongjian");
    GeneralManager * zongjingli = new GeneralManager("zongjinli");
    
    jinli->SetSuperior(zongjian);
    zongjian->SetSuperior(zongjingli);
    
    
    Request * request = new Request();
    request->requestType = "请假";
    request->requestContent = "小菜请假";
    request->number = 1;
    
    jinli->RequestApplication(request);
    
    Request * request2 = new Request();
    request2->requestType = "请假";
    request2->requestContent = "小菜请假";
    request2->number = 4;
    jinli->RequestApplication(request2);
    
    Request * request3 = new Request();
    request3->requestType = "加薪";
    request3->requestContent = "小菜请求加薪";
    request3->number = 4;
    jinli->RequestApplication(request3);
    
    
}


void testLesson20(){
    UnitedNationsSecurityCouncil * UNSC = new UnitedNationsSecurityCouncil();
    
    USA * c1 = new  USA(UNSC);
    Irap * c2 = new Irap(UNSC);
    
    UNSC->colleague1 = c1;
    UNSC->colleague2 = c2;
    
    c1->Declare("i want you die");
    c2->Declare("i want you go die");
    
}

void testLesson21(){
    WebSiteFactory * f = new WebSiteFactory();
    
    
    Website * fx = f->getWebSiteCategory("production");
    User_lesson21 * user1 = new User_lesson21("z1");
    fx->Use(user1);

    Website* fy = f->getWebSiteCategory("production");
    fy->Use(new User_lesson21("z2"));
    
    Website * fz = f->getWebSiteCategory("blog");
    fz->Use(new User_lesson21("z3"));
    
    cout<<"webcount"<<f->GetWebSiteCount()<<endl;
    
}

void testLesson22(){
    PlayContext * context = new PlayContext();
    context->setPlaytext("O 2 E 0.5 G 0.5 O 3 E 0.5 ");
    Expression * expression = nullptr;
    
    while (context->getPlaytext().length()>0) {
        string str = context->getPlaytext().substr(0,1);
        if (str == "O") {
            expression = new Scale();
        } else {
            expression = new Note();
        }
        expression->Interpret(context);
    }
}


