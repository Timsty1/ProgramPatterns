#include<stdio.h>
/*
    �ŵ㣺
    �ڹ�������ģʽ�У������������������ͻ�����Ҫ�Ĳ�Ʒ��ͬʱ����ͻ����������־����Ʒ�ཫ��ʵ������һϸ�ڣ�
    �û�ֻ��Ҫ���������Ʒ��Ӧ�Ĺ�����������Ĵ���ϸ�ڣ���������֪�������Ʒ���������
    ʹ�ù�������ģʽ����һ���ŵ�����ϵͳ�м����²�Ʒʱ�������޸ĳ��󹤳��ͳ����Ʒ�ṩ�Ľӿڣ�
    �����޸Ŀͻ��ˣ�Ҳ�����޸������ľ��幤���;����Ʒ����ֻҪ���һ�����幤���;����Ʒ�Ϳ����ˡ�
    ������ϵͳ�Ŀ���չ��Ҳ�ͱ�÷ǳ��ã���ȫ���ϡ�����ԭ�򡱡�
*/
// factory method pattern:����һ�����ڴ�������Ľӿڣ������������������һ����ʵ����
// ģʽ��ɣ�
// �����ƷProduct�������ƷConcreteProduct
// ���󹤳�Factory�����幤��ConcreteFactory
/*
1)���󹤳���ɫ�� ���ǹ�������ģʽ�ĺ��ģ�����Ӧ�ó����޹ء��Ǿ��幤����ɫ����ʵ�ֵĽӿڻ��߱���̳еĸ��ࡣ
2)���幤����ɫ�������к;���ҵ���߼��йصĴ��롣��Ӧ�ó�������Դ�����Ӧ�ľ����Ʒ�Ķ���
3)�����Ʒ��ɫ�����Ǿ����Ʒ�̳еĸ��������ʵ�ֵĽӿڡ�
4)�����Ʒ��ɫ�����幤����ɫ�������Ķ�����Ǵ˽�ɫ��ʵ����
*/

// ��Ʒ����
class Product
{
    public: virtual void show()=0;
};
// ��������
class Factory
{
    public: virtual Product *factoryMethod()=0;
};
// �����ƷA
class ConcreteProductA:public Product{
    public:void show(){
        printf("�������˲�ƷA��\n");
    };
};
// �����ƷB
class ConcreteProductB:public Product{
    public:void show(){
        printf("�������˲�ƷB��\n");
    };
};
// ����A��-����A���Ʒ
class ConcreteFactoryA:public Factory{
    public: Product *factoryMethod(){
        return new ConcreteProductA();
    };
};
// ����B��-����B���Ʒ
class ConcreteFactoryB:public Factory{
    public: Product *factoryMethod(){
        return new ConcreteProductB();
    };
};
// ������������
/*
int main(){
    //�ͻ�Ҫ��ƷA
    Factory *FA = new ConcreteFactoryA();
    FA->factoryMethod()->show();
    //�ͻ���Ҫ��ƷB
    Factory *FB = new ConcreteFactoryB();
    FB->factoryMethod()->show();
    delete FA;
    delete FB;
    return 0;
}*/
