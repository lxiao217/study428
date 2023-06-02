#include <iostream>
using namespace std;

// 装饰模式， 功能任意组装

class Car
{
public:
	virtual void show() = 0;
};

// 车都可以跑~
class RunCar : public Car
{
public:
	virtual void show()
	{
		cout << "Run Car" << endl;
	}
};

// 装饰  会游泳的车   会飞的车
class SwimCar : public Car
{
public:
	SwimCar(Car *car)
	{
		m_car = car;
	}
	void swim()
	{
		cout << "Swim + ";
	}
	virtual void show()
	{
		swim();
		m_car->show();
	}

private:
	Car *m_car;
};

class FlyCar : public Car
{
public:
	FlyCar(Car *car)
	{
		m_car = car;
	}
	void fly()
	{
		cout << "Fly + ";
	}
	virtual void show()
	{
		fly();
		m_car->show();
	}

private:
	Car *m_car;
};

int main()
{
	Car *car = NULL;
	car = new RunCar();
	car->show();
	cout << endl;

	FlyCar *f = new FlyCar(car);
	f->show();
	cout << endl;

	SwimCar *s = new SwimCar(car);
	s->show();
	cout << endl;

	SwimCar *sf = new SwimCar(f);
	sf->show();
}