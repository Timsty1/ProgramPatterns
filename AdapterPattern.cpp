#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
// Adapter Pattern:
/*
    将一个接口转换成客户希望的另一个接口，适配器模式使接口不兼容的那些类可以一起工作。
    适配器模式既可以作为类结构型模式，也可以作为对象结构型模式。
*/
/*
    情景描述：去国外旅游时，不同国家可能提供功率不同的电源插口。
    因此需要用到电源配适器实现
*/
/*
    优点：
    将目标类和适配者类解耦，通过引入一个适配器类来重用现有的适配者类，而无须修改原有代码。
    增加了类的透明性和复用性，将具体的实现封装在适配者类中，对于客户端类来说是透明的，而且提高了适配者的复用性。
*/
//用户目标类
class JapanSocket{
public:
    virtual void charge()=0;
};
class OwnCharge{
public:
    void ChargeWithFeetFlat(){
        cout<<"OwnCharge::ChargeWithFeetFlat!"<<endl;
    }
};
//电源配适器
class PowerAdapter:public JapanSocket{
public:
    PowerAdapter():pCharge(new OwnCharge()){};
    ~PowerAdapter(){
        delete(pCharge);
    }
    void charge(){
        pCharge->ChargeWithFeetFlat();
    }
private:
    OwnCharge* pCharge;
};
/*
//Client
int main()
{
    JapanSocket *pAdapter = new PowerAdapter();
    pAdapter->charge();
    delete(pAdapter);
    return 0;
}
*/
