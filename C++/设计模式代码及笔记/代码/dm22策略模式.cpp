#include <iostream>
using namespace std;

// 加密算法 策略模式

// 抽象算法类
class Strategy
{
public:
	virtual void crypt() = 0;
};

class AES : public Strategy
{
public:
	virtual void crypt()
	{
		cout << "AES algorithm" << endl;
	}
};

// 算法的具体实现
class DES : public Strategy
{
public:
	virtual void crypt()
	{
		cout << "DES algorithm" << endl;
	}
};

// 算法的策略
class Context
{
public:
	void setStrategy(Strategy *strategy)
	{
		m_strategy = strategy;
	}

	void myoperator()
	{
		m_strategy->crypt();
	}

private:
	Strategy *m_strategy;
};

int main()
{
	// 客户只负责调用接口，不管新内部实现
	Strategy *strategy1 = new DES();
	Strategy *strategy2 = new AES();

	Context *context = new Context;
	context->setStrategy(strategy1);
	context->myoperator();
}