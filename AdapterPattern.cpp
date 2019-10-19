#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
// Adapter Pattern:
/*
    ��һ���ӿ�ת���ɿͻ�ϣ������һ���ӿڣ�������ģʽʹ�ӿڲ����ݵ���Щ�����һ������
    ������ģʽ�ȿ�����Ϊ��ṹ��ģʽ��Ҳ������Ϊ����ṹ��ģʽ��
*/
/*
    �龰������ȥ��������ʱ����ͬ���ҿ����ṩ���ʲ�ͬ�ĵ�Դ��ڡ�
    �����Ҫ�õ���Դ������ʵ��
*/
/*
    �ŵ㣺
    ��Ŀ���������������ͨ������һ�������������������е��������࣬�������޸�ԭ�д��롣
    ���������͸���Ժ͸����ԣ��������ʵ�ַ�װ�����������У����ڿͻ�������˵��͸���ģ���������������ߵĸ����ԡ�
*/
//�û�Ŀ����
class JapanSocket{
public:
    virtual void charge()=0;
};
class OwnCharge{
public:
    void ChargeWithFeetFlat(){
        cout<<"OwnCharge::ChargeWithFeetFlat!"<<endl;
    }
};
//��Դ������
class PowerAdapter:public JapanSocket{
public:
    PowerAdapter():pCharge(new OwnCharge()){};
    ~PowerAdapter(){
        delete(pCharge);
    }
    void charge(){
        pCharge->ChargeWithFeetFlat();
    }
private:
    OwnCharge* pCharge;
};
/*
//Client
int main()
{
    JapanSocket *pAdapter = new PowerAdapter();
    pAdapter->charge();
    delete(pAdapter);
    return 0;
}
*/
