#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
    �龰���:
    Ա�������������
    �����ܼࡢ�ܲ���Ȩ��׼���ߴ��ݸ��ϼ���׼��
    ���ǲ�ͬ�ȼ��Ĵ�������׼������Ȩ�޴�С��ͬ��
    ��������:����(1 �켰����)->�ܼ�(3 �켰����)->�ܲ�(7 ��Ϊ����)
*/
/*
    �ŵ㣺
    1��������϶ȡ���������ķ����ߺͽ����߽��
    2�����˶���ʹ�ö�����Ҫ֪�����Ľṹ��
    3����ǿ������ָ��ְ�������ԡ�ͨ���ı����ڵĳ�Ա���ߵ������ǵĴ�������̬����������ɾ�����Ρ�
    4�������µ���������ܷ��㡣
*/
// ��������
class IHandler
{
public:
    IHandler() { m_pSuccessor = NULL; }
    virtual ~IHandler() {}
    void SetSuccessor(IHandler *successor) { m_pSuccessor = successor; }
    virtual void HandleRequest(float days) = 0;

protected:
    IHandler *m_pSuccessor;  // �����
};
// ����
class Manager : public IHandler
{
public:
    Manager() {}
    ~Manager() {}
    virtual void HandleRequest(float days) override {
        if (days <= 1) {
            cout << "Manager ��׼�� " << days << " ���" << endl;
        } else {
            m_pSuccessor->HandleRequest(days);
        }
    }
};

// �ܼ�
class Director : public IHandler
{
public:
    Director() {}
    ~Director() {}
    virtual void HandleRequest(float days) override {
        if (days <= 3) {
            cout << "Director ��׼�� " << days << " ���" << endl;
        } else {
            m_pSuccessor->HandleRequest(days);
        }
    }
};

// �ܲ�
class CEO : public IHandler
{
public:
    CEO() {}
    ~CEO() {}
    virtual void HandleRequest(float days) override {
        if (days <= 7) {
            cout << "CEO ��׼�� " << days << " ���" << endl;
        } else {
            cout << "����ų��٣��Ժ󶼱��ϰ���~��" << endl;
        }
    }
};
/*
int main()
{
    IHandler *manager = new Manager();
    IHandler *director = new Director();
    IHandler *ceo = new CEO();

    // ְ���������� -> �ܼ� -> �ܲ�
    manager->SetSuccessor(director);
    director->SetSuccessor(ceo);

    manager->HandleRequest(1);
    manager->HandleRequest(2);
    manager->HandleRequest(5);
    manager->HandleRequest(10);

    delete manager;
    delete director;
    delete ceo;

    getchar();

    return 0;
}*/
