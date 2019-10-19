#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
// BridgePattern
// �����󲿷�������ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ����ر仯��
/*
    ��ɫ���ܣ�
    Abstraction:������
    RefinedAbstraction:���������
    Implementor:ʵ����
    ConcreteImplementor:����ʵ����
*/
/*
    �ŵ㣺
    �������ӿڼ���ʵ�ֲ��֡�
    �Ž�ģʽ��ʱ�����ڶ�̳з��������Ƕ�̳з���Υ������ĵ�һְ��ԭ��
    �����ԱȽϲ���Ҷ�̳нṹ����ĸ����ǳ��Ӵ��Ž�ģʽ�Ǳȶ�̳з������õĽ��������
    �Ž�ģʽ�����ϵͳ�Ŀ������ԣ��������仯ά����������չһ��ά�ȣ�������Ҫ�޸�ԭ��ϵͳ��
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
