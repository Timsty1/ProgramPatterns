#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
    �ŵ㣺
    ����ģʽ�ܹ�Э�������ߺͱ������ߣ���һ���̶��Ͻ�����ϵͳ����϶ȡ�
    Զ�̴���ʹ�ÿͻ��˿��Է�����Զ�̻����ϵĶ���Զ�̻������ܾ��и��õļ��������봦���ٶȣ����Կ�����Ӧ������ͻ�������
    �������ͨ��ʹ��һ��С����������һ������󣬿��Լ���ϵͳ��Դ�����ģ���ϵͳ�����Ż�����������ٶȡ�
    ����������Կ��ƶ���ʵ�����ʹ��Ȩ�ޡ�
*/
/*
    ProxyPattern:
    �龰˵����
    �����������ϵͳ�б�ʹ�á�
    �����Ҫ����һ����Դ���Ľϴ�Ķ���
    �ȴ���һ�����Ľ�С�Ķ�������ʾ
    �����Ķ���ֻ������Ҫʱ�Żᱻ����
*/
class Subject{
public:
    virtual void request()=0;
};

class RealSubject:public Subject{
public:
    // ������û�о���ʵ������ռ�Ĳ�����
    // ʵ��ʱ���Դ���ָ��Ϊ�������Ӧ�ռ�󷵻ء�
    void request(){
        cout<<"real subject has been executed!"<<endl;
        cout<<"space has been allocated!"<<endl;
    }
};

class Proxy:public Subject{
public:
    Proxy(){
        m_rs = new RealSubject();
    }
    virtual ~Proxy(){
        delete m_rs;
    }
    void request(){
        preRequest();
        m_rs->request();
        afterRequest();
    }
private:
    void preRequest(){
        cout<<"Prerequest"<<endl;
    }
    void afterRequest(){
        cout<<"Afterrequest"<<endl;
    }
    RealSubject* m_rs;
};
/*
int main(){
    Proxy m_p;
    m_p.request();

    return 0;
}
*/
