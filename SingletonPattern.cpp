#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
// ����ģʽ��ȷ��һ����ֻ��һ��ʵ�������ṩһ��ȫ�ַ��ʵ����������Ψһʵ��
/*
    ����ע���:
    ������Ĺ��캯��Ϊ˽�У�
    �ṩһ������ľ�̬˽�г�Ա������
    �ṩһ�����еľ�̬����������
    ��̬˽�г�Ա���������������������ⶨ�塣
*/
/*
    �ŵ㣺
    �ṩ�˶�Ψһʵ�����ܿط��ʡ���Ϊ�������װ������Ψһʵ���������������ϸ���ƿͻ������Լ���ʱ��������
    ���⣬����ģʽֻ������һ�����󣬽�Լ��ϵͳ��Դ���������ϵͳ���ܡ�
*/
class Singleton{
public:
    static Singleton* getInstance(){
        if (instance == NULL)
            instance = new Singleton();
        return instance;
    };
    void SingletonOperation(){
        cout<<"SingletonOperation"<<endl;
    };
protected:
    static Singleton* instance;
    Singleton(){};
    ~Singleton(){};
};
/*
// Client
Singleton* Singleton::instance=NULL;
int main(){
    Singleton * sg = Singleton::getInstance();
	sg->SingletonOperation();
    return 0;
}
*/

