#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
// 单例模式：确保一个类只有一个实例，并提供一个全局访问点来访问这个唯一实例
/*
    几个注意点:
    单例类的构造函数为私有；
    提供一个自身的静态私有成员变量；
    提供一个公有的静态工厂方法。
    静态私有成员变量在类内声明，在类外定义。
*/
/*
    优点：
    提供了对唯一实例的受控访问。因为单例类封装了它的唯一实例，所以它可以严格控制客户怎样以及何时访问它。
    此外，单例模式只能生成一个对象，节约了系统资源，可以提高系统性能。
*/
class Singleton{
public:
    static Singleton* getInstance(){
        if (instance == NULL)
            instance = new Singleton();
        return instance;
    };
    void SingletonOperation(){
        cout<<"SingletonOperation"<<endl;
    };
protected:
    static Singleton* instance;
    Singleton(){};
    ~Singleton(){};
};
/*
// Client
Singleton* Singleton::instance=NULL;
int main(){
    Singleton * sg = Singleton::getInstance();
	sg->SingletonOperation();
    return 0;
}
*/

