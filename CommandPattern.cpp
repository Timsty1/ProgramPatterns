#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
    CommandPattern:
    Encapsulate a request as an object,
    thereby letting you parameterize clients with different requests,
    queue or log requests, and support undoable operations.
    情景设计：
    电视机作为请求的接收者。遥控器是请求的发送者。
    假设遥控器有仨按钮，分别对应三种操作：
    打开电视机、关闭电视机、切换频道。
*/
/*
    优点：最大的优点是可以方便地实现对请求的Undo和Redo。
    此外，可以比较容易地设计一个命令队列和宏命令（组合命令），新的命令可以很容易地加入到系统中。
    降低系统的耦合度。
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
        cout<<"Controller 执行 ";
        cout<<"关闭电视机"<<endl;
        m_command->execute();
    }
    void open(){
        cout<<"Controller 执行 ";
        cout<<"打开电视机"<<endl;
        m_command->execute();
    }
    void changeChannel(){
        cout<<"Controller 执行 ";
        cout<<"切换频道"<<endl;
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
