#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// 简单工厂模式（不属于23种设计模式）：
// 需要什么东西， 这个工厂就生产什么东西
// 但是工厂能生产的东西提前固定了。需要生产新的东西，需要改动原来的代码，破坏了开闭原则
// 因此需要下一个模式， 工厂模式

class Fruit
{
public:
	virtual void getFruit() = 0;

protected:
private:
};

class Banan : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am banana" << endl;
	}

protected:
private:
};

class Apple : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am apple" << endl;
	}

protected:
private:
};

// 工厂
class Factory
{
public:
	Fruit *createFruit(const char *str)
	{
		if (strcmp(str, "banana") == 0)
		{
			return new Banan;
		}
		else if (strcmp(str, "apple") == 0)
		{
			return new Apple;
		}
		else
		{
			cout << "error" << endl;
		}
		return NULL;
	}

protected:
private:
};

int main()
{
	Factory *fac = new Factory;
	Fruit *fruit = NULL;

	fruit = fac->createFruit("banan"); // new banan
	fruit->getFruit();
	delete fruit;

	fruit = fac->createFruit("apple"); // new apple
	fruit->getFruit();
	delete fruit;

	delete fac;
}