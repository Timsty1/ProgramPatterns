#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
/*
    中介者模式情景说明：租房
    房东可以把房子信息放到中介。
    房客可以在中介咨询房子信息。
*/
/*
    优点：
    简化了对象之间的交互，将各同事解耦，还可以减少子类生成，
    对于复杂的对象之间的交互，通过引入中介者，可以简化各同事类的设计和实现。
*/
class Person;
class Mediator{
public:
    virtual void send(string message, Person* p)=0;
    virtual void setA(Person* a)=0;
    virtual void setB(Person* b)=0;
};
class Person{
protected:
    Mediator *m_mediator;
public:
    virtual void setMediator(Mediator*)=0;
    virtual void sendMessage(string massage)=0;
    virtual void getMessage(string message)=0;
};
// 房客
class p1:public Person{
public:
    void setMediator(Mediator* m){
        m_mediator = m;
    }
    void sendMessage(string message){
        m_mediator->send(message, this);
    }
    void getMessage(string message){
        cout<<"房客已收到消息！"<<endl;
    }
};
// 房东
class p2:public Person{
public:
    void setMediator(Mediator* m){
        m_mediator = m;
    }
    void sendMessage(string message){
        m_mediator->send(message, this);
    }
    void getMessage(string message){
        cout<<"房东已收到消息！"<<endl;
    }
};
// 房屋中介
class HouseMediator:public Mediator{
private:
    Person* m_pa;
    Person* m_pb;
public:
	void setA(Person *A) { m_pa = A; }
	void setB(Person *B) { m_pb = B; }
	void send(string message, Person *person)
	{
		if(person == m_pa) //租房者给房东发信息
			m_pb->getMessage(message); //房东收到信息
		else
			m_pa->getMessage(message);
	}
};
/*
int main(){
    Mediator *mediator = new HouseMediator();
	Person *person1 = new p1();    //租房者
	Person *person2 = new p2();  //房东
	mediator->setA(person1);
	mediator->setB(person2);
	person1->setMediator(mediator);
	person2->setMediator(mediator);
	person1->sendMessage("我想在海淀区租套房子，价格3800元一个月\n");
	person2->sendMessage("出租房子70平米，3000元一个月\n");
	delete person1; delete person2; delete mediator;
	return 0;
}*/
