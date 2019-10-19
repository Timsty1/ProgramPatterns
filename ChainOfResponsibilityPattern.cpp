#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
    情景设计:
    员工发出请假请求。
    经理、总监、总裁有权批准或者传递给上级批准。
    但是不同等级的处理者批准天数的权限大小不同。
    审批流程:经理(1 天及以下)->总监(3 天及以下)->总裁(7 天为界限)
*/
/*
    优点：
    1、降低耦合度。它将请求的发送者和接收者解耦。
    2、简化了对象。使得对象不需要知道链的结构。
    3、增强给对象指派职责的灵活性。通过改变链内的成员或者调动它们的次序，允许动态地新增或者删除责任。
    4、增加新的请求处理类很方便。
*/
// 抽象处理者
class IHandler
{
public:
    IHandler() { m_pSuccessor = NULL; }
    virtual ~IHandler() {}
    void SetSuccessor(IHandler *successor) { m_pSuccessor = successor; }
    virtual void HandleRequest(float days) = 0;

protected:
    IHandler *m_pSuccessor;  // 后继者
};
// 经理
class Manager : public IHandler
{
public:
    Manager() {}
    ~Manager() {}
    virtual void HandleRequest(float days) override {
        if (days <= 1) {
            cout << "Manager 批准了 " << days << " 天假" << endl;
        } else {
            m_pSuccessor->HandleRequest(days);
        }
    }
};

// 总监
class Director : public IHandler
{
public:
    Director() {}
    ~Director() {}
    virtual void HandleRequest(float days) override {
        if (days <= 3) {
            cout << "Director 批准了 " << days << " 天假" << endl;
        } else {
            m_pSuccessor->HandleRequest(days);
        }
    }
};

// 总裁
class CEO : public IHandler
{
public:
    CEO() {}
    ~CEO() {}
    virtual void HandleRequest(float days) override {
        if (days <= 7) {
            cout << "CEO 批准了 " << days << " 天假" << endl;
        } else {
            cout << "给你放长假，以后都别上班了~！" << endl;
        }
    }
};
/*
int main()
{
    IHandler *manager = new Manager();
    IHandler *director = new Director();
    IHandler *ceo = new CEO();

    // 职责链：经理 -> 总监 -> 总裁
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
