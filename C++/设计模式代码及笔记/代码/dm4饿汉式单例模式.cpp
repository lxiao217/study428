#include <iostream>
using namespace std;

// 饿汉式单例模式：   直接生成实例
class Singelton
{
private:
	Singelton()
	{
		cout << "Constructor" << endl;
	}

protected:
public:
	static Singelton *getInstance()
	{
		return m_sne;
	}

	// 释放内存
	static void freeInstance()
	{
		if (m_sne != NULL)
		{
			delete m_sne;
			m_sne = NULL;
			cout << "free memory!" << endl;
		}
	}

private:
	static Singelton *m_sne;
};

// 静态变量初始化
Singelton *Singelton::m_sne = new Singelton;

void main31()
{
	// 静态函数的调用
	Singelton *p1 = Singelton::getInstance();
	Singelton *p2 = Singelton::getInstance();

	if (p1 == p2)
	{
		cout << "p1 and p2 is same object" << endl;
	}
	else
	{
		cout << "p1 and p2 is different object" << endl;
	}

	Singelton::freeInstance();

	return;
}

int main()
{
	main31();
}