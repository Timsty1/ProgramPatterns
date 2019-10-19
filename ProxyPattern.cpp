#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
    优点：
    代理模式能够协调调用者和被调用者，在一定程度上降低了系统的耦合度。
    远程代理使得客户端可以访问在远程机器上的对象，远程机器可能具有更好的计算性能与处理速度，可以快速响应并处理客户端请求。
    虚拟代理通过使用一个小对象来代表一个大对象，可以减少系统资源的消耗，对系统进行优化并提高运行速度。
    保护代理可以控制对真实对象的使用权限。
*/
/*
    ProxyPattern:
    情景说明：
    虚拟代理经常在系统中被使用。
    如果需要创建一个资源消耗较大的对象
    先创建一个消耗较小的对象来表示
    真正的对象只有在需要时才会被创建
*/
class Subject{
public:
    virtual void request()=0;
};

class RealSubject:public Subject{
public:
    // 这里我没有具体实现申请空间的操作。
    // 实现时可以传入指针为其分配相应空间后返回。
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
