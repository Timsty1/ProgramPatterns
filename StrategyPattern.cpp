#include<stdio.h>
#include<iostream>
using namespace std;
/*
    �ŵ㣺
    ����ģʽ�ṩ�˶ԡ�����ԭ�򡱵�����֧�֣��û������ڲ��޸�ԭ��ϵͳ�Ļ�����ѡ���㷨����Ϊ��Ҳ�������������µ��㷨����Ϊ��
    ����ģʽ�ṩ�˹�����ص��㷨��İ취������ģʽ�ṩ�˿����滻�̳й�ϵ�İ취��
*/
/*
    �龰��ƣ�
    ��������ֵa��b
    ���Ը�����Ҫִ�мӲ������߳˲���
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
