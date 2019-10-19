#include<stdio.h>
/*
    情景设计：某软件公司要开发一套界面皮肤库。
    不同的皮肤将提供视觉效果不同的按钮、文本框、组合框等界面元素。
    例如春天(Spring)风格的皮肤将提供浅绿色的按钮、绿色边框的文本框和绿色边框的组合框。
    而夏天(Summer)风格的皮肤则提供浅蓝色的按钮、蓝色边框的文本框和蓝色边框的组合框。
*/
/*
    优点：封装了产品的创建，用户不需要知道具体的产品信息，只需要知道工厂信息即可。
    可以支持工厂生成不同类型的产品，相比于工厂方法模式灵活性更强。
    增加新的具体工厂和产品族很方便，无须修改已有系统，符合“开闭原则”。
    此外，抽象工厂模式实现了高内聚低耦合的设计目的。
*/
class Button
{
public:
    virtual void display()=0;
};
class TextField
{
public:
    virtual void display()=0;
};
class ComboBox
{
public:
    virtual void display()=0;
};
// 皮肤工厂父类
class SkinFactory
{
public:
    virtual Button *createButton()=0;
    virtual TextField *createTextField()=0;
    virtual ComboBox *createComboBox()=0;
};
// 元素的具体实现
class SpringButton:public Button
{
public:
    void display(){
        printf("Spring!Button!\n");
    };
};
class SummerButton:public Button
{
public:
    void display(){
        printf("Summer!Button!\n");
    };
};
class SpringTextField:public TextField
{
public:
    void display(){
        printf("Spring!TextField!\n");
    };
};
class SummerTextField:public TextField
{
public:
    void display(){
        printf("Summer!TextField!\n");
    };
};
class SpringComboBox:public ComboBox
{
public:
    void display(){
        printf("Spring!ComboBox!\n");
    };
};
class SummerComboBox:public ComboBox
{
public:
    void display(){
        printf("Summer!ComboBox!\n");
    };
};

// 工厂的具体实现
class SpringSkinFactory:public SkinFactory
{
public:
    Button* createButton(){
        return new SpringButton();
    };
    TextField* createTextField(){
        return new SpringTextField();
    };
    ComboBox* createComboBox(){
        return new SpringComboBox();
    };
};
class SummerSkinFactory:public SkinFactory
{
public:
    Button* createButton(){
        return new SummerButton();
    };
    TextField* createTextField(){
        return new SummerTextField();
    };
    ComboBox* createComboBox(){
        return new SummerComboBox();
    };
};
/*
// Client
int main(){
    SkinFactory* sf1 = new SpringSkinFactory();
    SkinFactory* sf2 = new SummerSkinFactory();
    sf1->createButton()->display();
    sf1->createComboBox()->display();
    sf1->createTextField()->display();
    sf2->createButton()->display();
    sf2->createComboBox()->display();
    sf2->createTextField()->display();
    delete sf1;
    delete sf2;
    return 0;
}
*/
