#include<stdio.h>
/*
    优点：
    在工厂方法模式中，工厂方法用来创建客户所需要的产品，同时还向客户隐藏了哪种具体产品类将被实例化这一细节，
    用户只需要关心所需产品对应的工厂，无须关心创建细节，甚至无须知道具体产品类的类名。
    使用工厂方法模式的另一个优点是在系统中加入新产品时，无须修改抽象工厂和抽象产品提供的接口，
    无须修改客户端，也无须修改其他的具体工厂和具体产品，而只要添加一个具体工厂和具体产品就可以了。
    这样，系统的可扩展性也就变得非常好，完全符合“开闭原则”。
*/
// factory method pattern:定义一个用于创建对象的接口，但是让子类决定将哪一个类实例化
// 模式组成：
// 抽象产品Product，具体产品ConcreteProduct
// 抽象工厂Factory，具体工厂ConcreteFactory
/*
1)抽象工厂角色： 这是工厂方法模式的核心，它与应用程序无关。是具体工厂角色必须实现的接口或者必须继承的父类。
2)具体工厂角色：它含有和具体业务逻辑有关的代码。由应用程序调用以创建对应的具体产品的对象。
3)抽象产品角色：它是具体产品继承的父类或者是实现的接口。
4)具体产品角色：具体工厂角色所创建的对象就是此角色的实例。
*/

// 产品父类
class Product
{
    public: virtual void show()=0;
};
// 工厂父类
class Factory
{
    public: virtual Product *factoryMethod()=0;
};
// 具体产品A
class ConcreteProductA:public Product{
    public:void show(){
        printf("生产出了产品A！\n");
    };
};
// 具体产品B
class ConcreteProductB:public Product{
    public:void show(){
        printf("生产出了产品B！\n");
    };
};
// 工厂A类-生产A类产品
class ConcreteFactoryA:public Factory{
    public: Product *factoryMethod(){
        return new ConcreteProductA();
    };
};
// 工厂B类-生产B类产品
class ConcreteFactoryB:public Factory{
    public: Product *factoryMethod(){
        return new ConcreteProductB();
    };
};
// 生产工作流程
/*
int main(){
    //客户要产品A
    Factory *FA = new ConcreteFactoryA();
    FA->factoryMethod()->show();
    //客户想要产品B
    Factory *FB = new ConcreteFactoryB();
    FB->factoryMethod()->show();
    delete FA;
    delete FB;
    return 0;
}*/
