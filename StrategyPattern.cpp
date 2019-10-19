#include<stdio.h>
#include<iostream>
using namespace std;
/*
    优点：
    策略模式提供了对“开闭原则”的完美支持，用户可以在不修改原有系统的基础上选择算法或行为，也可以灵活地增加新的算法或行为。
    策略模式提供了管理相关的算法族的办法。策略模式提供了可以替换继承关系的办法。
*/
/*
    情景设计：
    当输入俩值a、b
    可以根据需要执行加操作或者乘操作
*/
class Stratege{
public:
    virtual void algorithm(int ,int )=0;
};
class add:public Stratege{
public:
    void algorithm(int a,int b){
        cout<<a+b<<endl;
    }
};
class mul:public Stratege{
public:
    void algorithm(int a,int b){
        cout<<a*b<<endl;
    }
};
class Context{
private:
    Stratege *s;
public:
    void setStrategy(Stratege* p){
        s=p;
    }
    void algorithm(int a, int b){
        s->algorithm(a,b);
    }
};
/*
int main(){
    Stratege* s=new add();
    Context* c = new Context();
    c->setStrategy(s);
    c->algorithm(5,5);
    delete s;
    s = new mul();
    c->setStrategy(s);
    c->algorithm(5,5);
    delete s;
    delete c;
    return 0;
}
*/
