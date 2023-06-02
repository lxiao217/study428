#include <iostream>
using namespace std;

// 单例模式：
/*
创建一个实例对象。
特殊的场合特殊的需求。
例如设计一个国家体制系统， 总统的职位，永远只有一个。
*/

// 懒汉单例： 当客户需要的时候，才创建实例。

class Singelton
{
private:
	Singelton()
	{
		cout << "Constructor!" << endl;
	}

protected:
public:
	static Singelton *getInstance()
	{
		if (m_sne == NULL)
		{
			m_sne = new Singelton;
		}
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
Singelton *Singelton::m_sne = NULL;

int main()
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
}