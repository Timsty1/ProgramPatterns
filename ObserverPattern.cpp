#include<stdio.h>
#include<string>
#include<iostream>
#include<list>
using namespace std;
/*
    优点：
    观察者模式可以实现表示层和数据逻辑层的分离，并定义了稳定的消息更新传递机制，
    抽象了更新接口，使得可以有各种各样不同的表示层作为具体观察者角色。
    观察者模式在观察目标和观察者之间建立一个抽象的耦合。
    观察者模式符合“开闭原则”的要求。
*/
/*
    世界上最大的同性交友网站github已经进入了很多人的视野，很多人在上面发blog。
    如果有用户关注了一个博主，该博主发blog后用户会收到提醒。
*/
class Observer
{
public:
	Observer() {};
	virtual ~Observer() {};
	virtual void Update() {};
};

class Blog
{
public:
	Blog() {}
	virtual ~Blog() {}
	void Notify()
	{
		for (auto ob : observers)
			ob->Update();
	}
	void Attach(Observer* observer)
	{
		observers.push_back(observer);
	}
	void Detach(Observer* observer)
	{
		observers.remove(observer);
	}
	virtual string GetStatus()
	{
		return m_status;
	}
	virtual void SetStatus(string status)
	{
		m_status = status;
	}
private:
	list<Observer*> observers;
protected:
	string m_status; //子类可以访问
};

class GithubBlog : public Blog
{
public:
	GithubBlog(string name) : blogname(name) {}
	~GithubBlog() {}
	string GetStatus() { return m_status; }
	void SetStatus(string status)
	{
		m_status = "GithubBlog-" + blogname + " 通知 " + status;
		this->Notify();
	}

private:
	string blogname;
};

class SomeObserver : public Observer
{
public:
	SomeObserver(string name, Blog* blog) :
		_name(name),
		_blog(blog) {}
	~SomeObserver() {}
	void Update()
	{
		string status = _blog->GetStatus();
		cout << "用户：" << _name << " " << status << endl;
	}

private:
	string _name;
	Blog* _blog;
};
/*
int main()
{
	Blog *tecblog = new GithubBlog("p1");
	Observer *user1 = new SomeObserver("o1", tecblog);
	tecblog->Attach(user1);
	Observer *user2 = new SomeObserver("o2", tecblog);
	tecblog->Attach(user2);
	tecblog->SetStatus("ObserverPattern");
	//tecblog->Notify();
	delete tecblog;
	delete user1;
	delete user2;
	return 0;
}
*/
