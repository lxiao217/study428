#include <iostream>
using namespace std;

// 外观模式
// 一个客户端操作多个子系统， 其中一个改变了，客户端接口就需要改变
// 故在子系统和客户端之间封装一个中间层。

class SubSystemA
{
public:
	void dothing()
	{
		cout << "A system run!" << endl;
	}
};

class SubSystemB
{
public:
	void dothing()
	{
		cout << "B system run!" << endl;
	}
};

class SubSystemC
{
public:
	void dothing()
	{
		cout << "C system run!" << endl;
	}
};

//--采用外观模式
class Facade
{
public:
	Facade()
	{
		m_subSystemA = new SubSystemA;
		m_subSystemB = new SubSystemB;
		m_subSystemC = new SubSystemC;
	}

	void dothing()
	{
		m_subSystemA->dothing();
		m_subSystemB->dothing();
		m_subSystemC->dothing();
	}

private:
	SubSystemA *m_subSystemA;
	SubSystemB *m_subSystemB;
	SubSystemC *m_subSystemC;
};

// 不合理的客户点与系统的交互方式
void main1()
{
	SubSystemA *a = new SubSystemA;
	SubSystemB *b = new SubSystemB;
	SubSystemC *c = new SubSystemC;
	a->dothing();
	b->dothing();
	c->dothing();

	delete a;
	delete b;
	delete c;
}

void main2()
{
	Facade *facade = new Facade;
	facade->dothing();
	delete facade;
}

int main()
{
	cout << "without facade mode:\n";
	main1(); // not
	cout << "with facade mode:\n";
	main2(); // ok
}