#include<stdio.h>
#include<iostream>
using namespace std;
// Decorator Pattern
/*
    优点：
    装饰模式与继承关系的目的都是要扩展对象的功能，但是装饰模式可以提供比继承更多的灵活性。
    通过使用不同的具体装饰类以及这些装饰类的排列组合，可以创造出很多不同行为的组合。
    可以使用多个具体装饰类来装饰同一对象，得到功能更为强大的对象。
    具体构件类与具体装饰类可以独立变化，用户可以根据需要增加新的具体构件类和具体装饰类，
    在使用时再对其进行组合，原有代码无须改变，符合“开闭原则”
*/
/*
    情景说明：赛亚人具有战斗天赋，有可能超越极限觉醒成传说中的超级赛亚人
    但是卡卡罗特更加变态，除了超一，他还有超二和超三的形态
    假定卡卡罗特在超一时可以使用瞬间移动
    在超二时可以使用界王拳
    在超三时可以随意凝聚元气弹
    （当然这些设定和原著不符合）
*/
class Transform{
public:
    virtual void fight()=0;
};
class kakaluote:public Transform{
public:
    void fight(){
        cout<<"kakaluote go!"<<endl;
    }
};
class Changer:public Transform{
public:
    Changer(Transform* pt):transform(pt){}
    virtual void fight()=0;
private:
    Transform* transform;
};
class chaoyi:public Changer{
public:
    chaoyi(Transform* pt):Changer(pt){}
    void fight(){
        cout<<"super Saiyan 1 go!"<<endl;
        shunjianyidong();
    }
private:
    void shunjianyidong(){
        cout<<"shunjianyidong !"<<endl;
    }
};
class chaoer:public Changer{
public:
    chaoer(Transform* pt):Changer(pt){}
    void fight(){
        cout<<"super Saiyan 2 go!"<<endl;
        jiewangquan();
    }
private:
    void jiewangquan(){
        cout<<"jiewangquan !"<<endl;
    }
};
class chaosan:public Changer{
public:
    chaosan(Transform* pt):Changer(pt){}
    void fight(){
        cout<<"super Saiyan 3 go!"<<endl;
        yuanqidan();
    }
private:
    void yuanqidan(){
        cout<<"yuanqidan !"<<endl;
    }
};
/*
// Client
int main()
{
    Transform* t = new kakaluote();
    t->fight();
    Transform* t_1 = new chaoyi(t);
    t_1->fight();
    Transform* t_2 = new chaoer(t);
    t_2->fight();
    Transform* t_3 = new chaosan(t);
    t_3->fight();

    Transform* t_4 = new chaosan(t_2);
    t_4->fight();
}
*/
