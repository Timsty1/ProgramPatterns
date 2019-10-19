#include<stdio.h>
#include<iostream>
using namespace std;
// Decorator Pattern
/*
    �ŵ㣺
    װ��ģʽ��̳й�ϵ��Ŀ�Ķ���Ҫ��չ����Ĺ��ܣ�����װ��ģʽ�����ṩ�ȼ̳и��������ԡ�
    ͨ��ʹ�ò�ͬ�ľ���װ�����Լ���Щװ�����������ϣ����Դ�����ܶ಻ͬ��Ϊ����ϡ�
    ����ʹ�ö������װ������װ��ͬһ���󣬵õ����ܸ�Ϊǿ��Ķ���
    ���幹���������װ������Զ����仯���û����Ը�����Ҫ�����µľ��幹����;���װ���࣬
    ��ʹ��ʱ�ٶ��������ϣ�ԭ�д�������ı䣬���ϡ�����ԭ��
*/
/*
    �龰˵���������˾���ս���츳���п��ܳ�Խ���޾��ѳɴ�˵�еĳ���������
    ���ǿ������ظ��ӱ�̬�����˳�һ�������г����ͳ�������̬
    �ٶ����������ڳ�һʱ����ʹ��˲���ƶ�
    �ڳ���ʱ����ʹ�ý���ȭ
    �ڳ���ʱ������������Ԫ����
    ����Ȼ��Щ�趨��ԭ�������ϣ�
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
