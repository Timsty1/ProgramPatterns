#include<stdio.h>
#include<string>
#include<iostream>
#include<list>
using namespace std;
/*
    �ŵ㣺
    �۲���ģʽ����ʵ�ֱ�ʾ��������߼���ķ��룬���������ȶ�����Ϣ���´��ݻ��ƣ�
    �����˸��½ӿڣ�ʹ�ÿ����и��ָ�����ͬ�ı�ʾ����Ϊ����۲��߽�ɫ��
    �۲���ģʽ�ڹ۲�Ŀ��͹۲���֮�佨��һ���������ϡ�
    �۲���ģʽ���ϡ�����ԭ�򡱵�Ҫ��
*/
/*
    ����������ͬ�Խ�����վgithub�Ѿ������˺ܶ��˵���Ұ���ܶ��������淢blog��
    ������û���ע��һ���������ò�����blog���û����յ����ѡ�
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
	string m_status; //������Է���
};

class GithubBlog : public Blog
{
public:
	GithubBlog(string name) : blogname(name) {}
	~GithubBlog() {}
	string GetStatus() { return m_status; }
	void SetStatus(string status)
	{
		m_status = "GithubBlog-" + blogname + " ֪ͨ " + status;
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
		cout << "�û���" << _name << " " << status << endl;
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
