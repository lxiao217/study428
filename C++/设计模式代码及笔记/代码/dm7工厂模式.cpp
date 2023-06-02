#include <iostream>
#include <string>
using namespace std;

// 工厂模式：
// 需要生产什么东西， 就构建与之对应的具体工厂
// 抽象水果类  具体水果类
// 抽象工厂类  具体工厂类

class Fruit
{
public:
	virtual void getFruit() = 0;
};

class Banana : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am banana" << endl;
	}
};

class Apple : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am apple" << endl;
	}
};

// 工厂
class AbFactory
{
public:
	virtual Fruit *createFruit() = 0;
};

class BananaFactory : public AbFactory
{
public:
	Fruit *createFruit()
	{
		return new Banana;
	}
};

class AppleFactory : public AbFactory
{
public:
	Fruit *createFruit()
	{
		return new Apple;
	}
};

int main()
{
	AbFactory *factor = NULL;
	Fruit *fruit = NULL;

	// 想吃什么 用户添加什么工厂， 无需改动原来的代码
	// 实现了客户端和 具体产品 和 具体工厂的 解耦合

	// 生产香蕉
	factor = new BananaFactory;
	fruit = factor->createFruit();
	fruit->getFruit();
	delete fruit;
	delete factor;

	factor = new AppleFactory;
	fruit = factor->createFruit();
	fruit->getFruit();
	delete fruit;
	delete factor;
}