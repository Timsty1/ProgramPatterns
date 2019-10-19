#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
// BridgePattern
// 将抽象部分与它的实现部分分离，使它们都可以独立地变化。
/*
    角色介绍：
    Abstraction:抽象类
    RefinedAbstraction:扩充抽象类
    Implementor:实现类
    ConcreteImplementor:具体实现类
*/
/*
    优点：
    分离抽象接口及其实现部分。
    桥接模式有时类似于多继承方案，但是多继承方案违背了类的单一职责原则，
    复用性比较差，而且多继承结构中类的个数非常庞大，桥接模式是比多继承方案更好的解决方法。
    桥接模式提高了系统的可扩充性，在两个变化维度中任意扩展一个维度，都不需要修改原有系统。
*/
class Implementor{
public:
    virtual void operationImp()=0;
};

class ConcreteImplementorA:public Implementor{
public:
    void operationImp(){
        cout<<"ConcreteImplementorA!"<<endl;
    }
};
class ConcreteImplementorB:public Implementor{
public:
    void operationImp(){
        cout<<"ConcreteImplementorB!"<<endl;
    }
};
class Abstraction{
public:
    Abstraction(Implementor* pImp){
        pImp->operationImp();
    }
    virtual void operation()=0;
private:
    Implementor* pImp;
};
class RefinedAbstraction:public Abstraction{
public:
    RefinedAbstraction(Implementor* imp):Abstraction(imp){}
    void operation(){
        cout<<"do something else,and then "<<endl;
    }
};
/*
// Client
int main()
{
    Implementor* pImp = new ConcreteImplementorA();
    Abstraction* pa = new RefinedAbstraction(pImp);
    pa->operation();

    Abstraction * pb = new RefinedAbstraction(new ConcreteImplementorB());
	pb->operation();

	delete pa;
	delete pb;
	return 0;
}
*/
