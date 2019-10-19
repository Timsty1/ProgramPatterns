#include<stdio.h>
#include<iostream>
using namespace std;
// Facade Pattern
/*
    情景设计：
    画图工具里可以画图形。
    可选的形状shape里可以有不同的图形，比如说square,circle等
*/
/*
    优点：
    它对客户端屏蔽了子系统组件，减少了客户端所需处理的对象数目，并使得子系统使用起来更加容易。
    实现了子系统与客户之间的松耦合关系，这使得子系统的组件变化不会影响到调用它的客户类，只需要调整外观类即可。
    只是提供了一个访问子系统的统一入口，并不影响用户直接使用子系统类。
*/
class Shape{
public:
    virtual void draw()=0;
};
class Circle:public Shape{
public:
    void draw(){
        cout<<"Circle"<<endl;
    }
};
class Square:public Shape{
public:
    void draw(){
        cout<<"Square"<<endl;
    }
};
class ShapeMaker{
private:
    Shape* s;
public:
    void drewCircle(){
        s=new Circle();
        s->draw();
        delete s;
    }
    void drewSquare(){
        s=new Square();
        s->draw();
        delete s;
    }
};
/*
int main(){
    ShapeMaker* sm = new ShapeMaker();
    sm->drewCircle();
    sm->drewSquare();
    return 0;
}*/
