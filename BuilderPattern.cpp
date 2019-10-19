#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
// Builder Pattern: Separate the construction of a complex object from its representation
// so that the same construction process can create different representations.
/*
    �龰��ƣ�KFC���ײͣ�һ�������ʳ�����ϵ���ɲ��֡�
    KFC�ķ���Ա���Ը��ݹ˿͵����������ײ͡�
*/
/*
    �ŵ㣺
    �ڽ�����ģʽ�У� �ͻ��˲���֪����Ʒ�ڲ���ɵ�ϸ�ڣ�����Ʒ�������Ʒ�Ĵ������̽��
    ʹ����ͬ�Ĵ������̿��Դ�����ͬ�Ĳ�Ʒ����ÿһ�����彨���߶���Զ�����
    ���������ľ��彨�����޹أ���˿��Ժܷ�����滻���彨���߻������µľ��彨���ߣ�
    �û�ʹ�ò�ͬ�ľ��彨���߼��ɵõ���ͬ�Ĳ�Ʒ����
    ���Ͽ���ԭ��
*/

class Meal
{
private:
    string food;
    string drink;
public:
    string getDrink(){
        return drink;
    };
    string getFood(){
        return food;
    };
    void setDrink(string s){
        drink = s;
    };
    void setFood(string s){
        food = s;
    };
};
class MealBuilder
{

protected:
    Meal meal;
public:
    virtual void buildDrink()=0;
    virtual void buildFood()=0;
    void getmeal(){
       cout<<"�ײ�����="+meal.getFood()+"+"+meal.getDrink()<<endl;
    };
};
class subMealBuilderA:public MealBuilder
{
    void buildDrink(){
        meal.setDrink("Cola");
    };
    void buildFood(){
        meal.setFood("Hamburger");
    };
};
class subMealBuilderB:public MealBuilder
{
    void buildDrink(){
        meal.setDrink("Juice");
    };
    void buildFood(){
        meal.setFood("ChickenRoll");
    };
};
class KFCWaiter{
private:
    MealBuilder* mb;
public:
    void construct(){
        mb->buildDrink();
        mb->buildFood();
        mb->getmeal();
    }
    void setMealBuilder(MealBuilder *p){
        mb = p;
    }
};
// Client
/*
int main(){
    MealBuilder* mb;
    KFCWaiter* w = new KFCWaiter();
    mb = new subMealBuilderA();
    w->setMealBuilder(mb);
    w->construct();
    delete mb;
    mb = new subMealBuilderB();
    w->setMealBuilder(mb);
    w->construct();
    delete mb;
}
*/
