#include <iostream>
#include <string>
using namespace std;

// 解释器模式  定义一种语法

// 例如定义 加一解释器 和 减一解释器
class Context
{
public:
	Context(int num)
	{
		m_num = num;
		m_res = num;
	}

public:
	void setNum(int num)
	{
		m_num = num;
	}

	void setRes(int res)
	{
		m_res = res;
	}

	int getNum()
	{
		return m_num;
	}

	int getRes()
	{
		return m_res;
	}

private:
	int m_num;
	int m_res;
};

// 解释器

class Expression
{
public:
	virtual void interpreter(Context *context) = 0;
};

// 自增解释器
class PlusExpression : public Expression
{
public:
	virtual void interpreter(Context *context)
	{
		int num = context->getNum();
		++num;
		context->setNum(num);
		context->setRes(num);
	}
};

// 自减解释器
class MinuExpression : public Expression
{
public:
	virtual void interpreter(Context *context)
	{
		int num = context->getNum();
		--num;
		context->setNum(num);
		context->setRes(num);
	}
};
int main()
{
	Context *context = new Context(100);
	cout << context->getNum() << endl;

	// 解释器
	Expression *exp = new PlusExpression;
	exp->interpreter(context);
	cout << context->getRes() << endl;
	delete exp;

	exp = new MinuExpression;
	exp->interpreter(context);
	cout << context->getRes() << endl;
	delete exp;
	delete context;
}
