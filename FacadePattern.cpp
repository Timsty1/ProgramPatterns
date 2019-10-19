#include<stdio.h>
#include<iostream>
using namespace std;
// Facade Pattern
/*
    �龰��ƣ�
    ��ͼ��������Ի�ͼ�Ρ�
    ��ѡ����״shape������в�ͬ��ͼ�Σ�����˵square,circle��
*/
/*
    �ŵ㣺
    ���Կͻ�����������ϵͳ����������˿ͻ������账��Ķ�����Ŀ����ʹ����ϵͳʹ�������������ס�
    ʵ������ϵͳ��ͻ�֮�������Ϲ�ϵ����ʹ����ϵͳ������仯����Ӱ�쵽�������Ŀͻ��ֻ࣬��Ҫ��������༴�ɡ�
    ֻ���ṩ��һ��������ϵͳ��ͳһ��ڣ�����Ӱ���û�ֱ��ʹ����ϵͳ�ࡣ
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
