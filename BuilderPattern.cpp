#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
// Builder Pattern: Separate the construction of a complex object from its representation
// so that the same construction process can create different representations.
/*
    情景设计：KFC卖套餐，一般包含主食和饮料等组成部分。
    KFC的服务员可以根据顾客的需求生成套餐。
*/
/*
    优点：
    在建造者模式中， 客户端不必知道产品内部组成的细节，将产品本身与产品的创建过程解耦，
    使得相同的创建过程可以创建不同的产品对象。每一个具体建造者都相对独立，
    而与其他的具体建造者无关，因此可以很方便地替换具体建造者或增加新的具体建造者，
    用户使用不同的具体建造者即可得到不同的产品对象。
    符合开闭原则。
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
       cout<<"套餐内容="+meal.getFood()+"+"+meal.getDrink()<<endl;
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
