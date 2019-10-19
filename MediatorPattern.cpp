#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
/*
    �н���ģʽ�龰˵�����ⷿ
    �������԰ѷ�����Ϣ�ŵ��н顣
    ���Ϳ������н���ѯ������Ϣ��
*/
/*
    �ŵ㣺
    ���˶���֮��Ľ���������ͬ�½�������Լ����������ɣ�
    ���ڸ��ӵĶ���֮��Ľ�����ͨ�������н��ߣ����Լ򻯸�ͬ�������ƺ�ʵ�֡�
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
// ����
class p1:public Person{
public:
    void setMediator(Mediator* m){
        m_mediator = m;
    }
    void sendMessage(string message){
        m_mediator->send(message, this);
    }
    void getMessage(string message){
        cout<<"�������յ���Ϣ��"<<endl;
    }
};
// ����
class p2:public Person{
public:
    void setMediator(Mediator* m){
        m_mediator = m;
    }
    void sendMessage(string message){
        m_mediator->send(message, this);
    }
    void getMessage(string message){
        cout<<"�������յ���Ϣ��"<<endl;
    }
};
// �����н�
class HouseMediator:public Mediator{
private:
    Person* m_pa;
    Person* m_pb;
public:
	void setA(Person *A) { m_pa = A; }
	void setB(Person *B) { m_pb = B; }
	void send(string message, Person *person)
	{
		if(person == m_pa) //�ⷿ�߸���������Ϣ
			m_pb->getMessage(message); //�����յ���Ϣ
		else
			m_pa->getMessage(message);
	}
};
/*
int main(){
    Mediator *mediator = new HouseMediator();
	Person *person1 = new p1();    //�ⷿ��
	Person *person2 = new p2();  //����
	mediator->setA(person1);
	mediator->setB(person2);
	person1->setMediator(mediator);
	person2->setMediator(mediator);
	person1->sendMessage("�����ں��������׷��ӣ��۸�3800Ԫһ����\n");
	person2->sendMessage("���ⷿ��70ƽ�ף�3000Ԫһ����\n");
	delete person1; delete person2; delete mediator;
	return 0;
}*/
