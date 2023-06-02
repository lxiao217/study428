#include <iostream>
#include <string>
using namespace std;

// 抽象水果类  具体水果类
// 抽象工厂类  具体工厂类
// 具体工厂可以生产多个水果。  new 多个
// 例如北方工厂可以生产北方香蕉和苹果   南方工厂生产南方水果

// 问题： 这个工厂生产的产品族是固定的。 比如：不论什么工厂只能生产苹果和香蕉

class Fruit
{
public:
	virtual void getFruit() = 0;
};

class AbFactory
{
public:
	// virtual Fruit *createFruit() = 0;
	virtual Fruit *createBanana() = 0;
	virtual Fruit *createApple() = 0;
};

class SourthBanana : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am Sourth Banana" << endl;
	}
};

class SourthApple : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am Sourth Apple" << endl;
	}
};

class NorthBanana : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am North Banana" << endl;
	}
};

class NorthApple : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am North Apple" << endl;
	}
};

class SourthFactory : public AbFactory
{
public:
	virtual Fruit *createBanana()
	{
		return new SourthBanana;
	}
	virtual Fruit *createApple()
	{
		return new SourthApple;
	}
};

class NorthFactory : public AbFactory
{
public:
	virtual Fruit *createBanana()
	{
		return new NorthBanana;
	}
	virtual Fruit *createApple()
	{
		return new NorthApple;
	}
};

int main()
{
	AbFactory *factor = NULL;
	Fruit *fruit = NULL;

	// 吃南方水果
	factor = new SourthFactory;
	fruit = factor->createApple();
	fruit->getFruit();
	delete fruit;
	fruit = factor->createBanana();
	fruit->getFruit();
	delete fruit;
	delete factor;

	// 想吃北方水果， 只需要new一个北方生产工厂就ok  其他代码不需改变
	factor = new NorthFactory;
	fruit = factor->createApple();
	fruit->getFruit();
	delete fruit;
	fruit = factor->createBanana();
	fruit->getFruit();
	delete fruit;
	delete factor;
}