#include <iostream>
using namespace std;

// 设计模式原则1

// 案例 银行员工业务
class BankWorker
{
public:
	void save()
	{
		cout << "存款" << endl;
	}
	void moveM()
	{
		cout << "转账" << endl;
	}

	void jiaofei()
	{
		cout << "交费" << endl;
	}
};

// 将类BankWorker拆解，  拆解为一个抽象类和许多具体类
// 纯虚函数的类是抽象类
class AbBankWorker
{
public:
	virtual void dothing() = 0;
};

// 业务员
class SaveBanker : public AbBankWorker
{
public:
	virtual void dothing()
	{
		cout << "存款1" << endl;
	}
};

class MoveBanker : public AbBankWorker
{
public:
	virtual void dothing()
	{
		cout << "转账" << endl;
	}
};

class JiaofeiBanker : public AbBankWorker
{
public:
	virtual void dothing()
	{
		cout << "交费" << endl;
	}
};

// 框架  传父类对象 执行父类函数
// 多态  传子类对象 执行子类函数
void howdo(AbBankWorker *bw)
{
	bw->dothing();
}

class pichuli : public MoveBanker
{
public:
	virtual void dothing()
	{
		cout << "批操作转账" << endl;
	}
};

void main01()
{
	/*银行员工， 一个员工干多种业务 ×*/
	/*一个员工只做一种业务的业务员 √*/

	// 再增加新的功能， 需要修改原代码， 不可取
	// 构建抽象层
	BankWorker *bw = new BankWorker;
	bw->jiaofei();
	bw->moveM();
	bw->save();
	getchar();
}

void main02()
{
	// 多态 父类指针指向子类对象
	// AbBankWorker *bw = new MoveBanker;
	AbBankWorker *bw = NULL;
	bw = new MoveBanker;
	howdo(bw);
	delete bw;

	bw = new SaveBanker;
	howdo(bw);
	delete bw;

	bw = new pichuli;
	howdo(bw);
	delete bw;
	return;
}

int main()
{
	// main01();
	main02();

	/*
	指针：
		父类指针可以指向子类对象  反之可行
	对象：
		子类对象可以赋值给父类对象（切割） 反之不行
	*/
}
