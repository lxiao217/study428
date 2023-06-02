#include <iostream>
using namespace std;

// 不同的车  安装  不同的发动机
// 两个集合  两个抽象
class Engine
{
public:
	virtual void InstallEngine() = 0;
};

// 不同的发动机
class cc550 : public Engine
{
public:
	virtual void InstallEngine()
	{
		cout << "I am cc550" << endl;
	}
};

class cc440 : public Engine
{
public:
	virtual void InstallEngine()
	{
		cout << "I am cc440" << endl;
	}
};

// 车配置上不同的发动机  然后进行安装
class Car
{
public:
	Car(Engine *engine)
	{
		m_engine = engine;
	}
	// 安装发动机
	virtual void install() = 0;

protected:
	Engine *m_engine;
};

// 宝马
class BMW : public Car
{
public:
	BMW(Engine *engine) : Car(engine)
	{
		;
	}
	void install()
	{
		cout << "BMW ";
		// 基类受保护方式， 此处可以调用
		m_engine->InstallEngine();
	}

private:
	// Engine *mm_engine;  //可有可无
};

int main()
{
	Car *car = NULL;
	Engine *engine = NULL;

	engine = new cc440;
	car = new BMW(engine);
	car->install();
}