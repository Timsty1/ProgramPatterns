#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
    CommandPattern:
    Encapsulate a request as an object,
    thereby letting you parameterize clients with different requests,
    queue or log requests, and support undoable operations.
    �龰��ƣ�
    ���ӻ���Ϊ����Ľ����ߡ�ң����������ķ����ߡ�
    ����ң��������ť���ֱ��Ӧ���ֲ�����
    �򿪵��ӻ����رյ��ӻ����л�Ƶ����
*/
/*
    �ŵ㣺�����ŵ��ǿ��Է����ʵ�ֶ������Undo��Redo��
    ���⣬���ԱȽ����׵����һ��������кͺ�������������µ�������Ժ����׵ؼ��뵽ϵͳ�С�
    ����ϵͳ����϶ȡ�
*/
class Televation{
public:
    void off(){
        cout<<"TV Off!"<<endl;
    };
    void open(){
        cout<<"TV On!"<<endl;
    };
    void changeChannel(){
        cout<<"Change Channel!"<<endl;
    };
};
class Command{
public:
    virtual void execute()=0;
};
class Controller{
public:
    Controller(Command* pC){
        m_command = pC;
    }
    void off(){
        cout<<"Controller ִ�� ";
        cout<<"�رյ��ӻ�"<<endl;
        m_command->execute();
    }
    void open(){
        cout<<"Controller ִ�� ";
        cout<<"�򿪵��ӻ�"<<endl;
        m_command->execute();
    }
    void changeChannel(){
        cout<<"Controller ִ�� ";
        cout<<"�л�Ƶ��"<<endl;
        m_command->execute();
    }
private:
    Command* m_command;
};
class TVOpenCommand:public Command{
public:
    TVOpenCommand(Televation* tv){
        m_tv = tv;
    }
    void execute(){
        m_tv->open();
    }
private:
    Televation* m_tv;
};
class TVOffCommand:public Command{
public:
    TVOffCommand(Televation* tv){
        m_tv = tv;
    }
    void execute(){
        m_tv->off();
    }
private:
    Televation* m_tv;
};
class TVChangeChannel:public Command{
public:
    TVChangeChannel(Televation* tv){
        m_tv = tv;
    }
    void execute(){
        m_tv->changeChannel();
    }
private:
    Televation* m_tv;
};
/*
int main(){
    Televation* tv = new Televation();
    Command *open = new TVOpenCommand(tv);
    Command *off = new TVOffCommand(tv);
    Command *cc = new TVChangeChannel(tv);
    Controller* controller = new Controller(open);
    controller->open();
    delete controller;
    controller = new Controller(cc);
    controller->changeChannel();
    delete controller;
    controller = new Controller(off);
    controller->off();
    delete controller;
    delete cc;
    delete off;
    delete open;
    delete tv;

}

*/
