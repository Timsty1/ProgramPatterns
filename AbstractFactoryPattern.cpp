#include<stdio.h>
/*
    �龰��ƣ�ĳ�����˾Ҫ����һ�׽���Ƥ���⡣
    ��ͬ��Ƥ�����ṩ�Ӿ�Ч����ͬ�İ�ť���ı�����Ͽ�Ƚ���Ԫ�ء�
    ���紺��(Spring)����Ƥ�����ṩǳ��ɫ�İ�ť����ɫ�߿���ı������ɫ�߿����Ͽ�
    ������(Summer)����Ƥ�����ṩǳ��ɫ�İ�ť����ɫ�߿���ı������ɫ�߿����Ͽ�
*/
/*
    �ŵ㣺��װ�˲�Ʒ�Ĵ������û�����Ҫ֪������Ĳ�Ʒ��Ϣ��ֻ��Ҫ֪��������Ϣ���ɡ�
    ����֧�ֹ������ɲ�ͬ���͵Ĳ�Ʒ������ڹ�������ģʽ����Ը�ǿ��
    �����µľ��幤���Ͳ�Ʒ��ܷ��㣬�����޸�����ϵͳ�����ϡ�����ԭ�򡱡�
    ���⣬���󹤳�ģʽʵ���˸��ھ۵���ϵ����Ŀ�ġ�
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
// Ƥ����������
class SkinFactory
{
public:
    virtual Button *createButton()=0;
    virtual TextField *createTextField()=0;
    virtual ComboBox *createComboBox()=0;
};
// Ԫ�صľ���ʵ��
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

// �����ľ���ʵ��
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
