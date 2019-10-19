#include<stdio.h>
#include<iostream>
#include<map>
#include<stdlib.h>
#include<ctime>
using namespace std;
// FlywightPattern
/*
    ��Ԫģʽ�ŵ㣺
    ��Ԫģʽ���ŵ����������Լ�������ڴ��ж����������ʹ����ͬ��������ƶ������ڴ���ֻ����һ�ݡ�
    ��Ԫģʽ���ⲿ״̬��Զ��������Ҳ���Ӱ�����ڲ�״̬���Ӷ�ʹ����Ԫ��������ڲ�ͬ�Ļ����б�����
*/
/*
    �龰˵����
    CS��Ϸ�о���֮�֡������ڴ�����ɫʱ����ʹ����Ԫģʽ����ʡ�ռ䡣
*/
static string s_playerTypes[2]={"T","CT"};
static string s_weapons[4] = {"ak47","m4a1","awp","knife"};
// player
class Player{
public:
    virtual ~Player(){}
    // weapon
    virtual void assignWeapon(string weapon) = 0;
    virtual void mession()=0;
protected:
    string m_weapon;
    string m_mession;
};
// Terrorist
class Terrorist:public Player{
public:
    Terrorist(){
        m_mession = "plant a bomb!";
    }
    virtual void assignWeapon(string weapon){
        m_weapon = weapon;
    }
    virtual void mession(){
        cout<<"Terrorist with weapon " + m_weapon + "," + " Task is " + m_mession<<endl;
    }
};
class CounterTerrorist:public Player{
public:
    CounterTerrorist(){
        m_mession = "diffuse bomb!";
    }
    virtual void assignWeapon(string weapon){
        m_weapon = weapon;
    }
    virtual void mession(){
        cout<<"Counter Terrorist with weapon " + m_weapon + "," + " Task is " + m_mession << endl;
    }
};
// Factory
// emmm ע��static���ݳ�ԱӦ�������������������ʼ����
class PlayerFactory
{
public:
    static Player* getPlayer(string type){
        Player* p = NULL;
        if (m_map.find(type)!= m_map.end())
            p = m_map[type];
        else{
            if(type=="T"){
                cout<<"create T player"<<endl;
                p = new Terrorist();
            }else if(type == "CT"){
                cout<<"create CT player"<<endl;
                p = new CounterTerrorist();
            }
            else {
                cout<<"Type Error!"<<endl;
            }
            m_map.insert(make_pair(type, p));
        }
        return p;
    }
protected:
    static map<string, Player*> m_map;
};
// Client
/*
map<string, Player*> PlayerFactory::m_map;

int main()
{
    int num_player = 2;
    int num_weapon = 4;
    for(int i=0;i<10;i++){
        // get players and their weapons
        int typeIndex = rand() % num_player;
        int weaponIndex = rand() % num_weapon;
        string type = s_playerTypes[typeIndex];
        string weapon = s_weapons[typeIndex];
        Player *p = PlayerFactory::getPlayer(type);
        p->assignWeapon(weapon);
        p->mession();
    }
    return 0;
}*/

/*
    ������£�
    create CT player
Counter Terrorist with weapon m4a1, Task is diffuse bomb!
create T player
Terrorist with weapon ak47, Task is plant a bomb!
Counter Terrorist with weapon m4a1, Task is diffuse bomb!
Terrorist with weapon ak47, Task is plant a bomb!
Terrorist with weapon ak47, Task is plant a bomb!
Counter Terrorist with weapon m4a1, Task is diffuse bomb!
Counter Terrorist with weapon m4a1, Task is diffuse bomb!
Counter Terrorist with weapon m4a1, Task is diffuse bomb!
Counter Terrorist with weapon m4a1, Task is diffuse bomb!
Counter Terrorist with weapon m4a1, Task is diffuse bomb!

Process returned 0 (0x0)   execution time : 0.095 s
Press any key to continue.
*/
