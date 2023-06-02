#include <iostream>
using namespace std;

// 设计模式原则2
/* 依赖于抽象接口，不依赖于具体实现，针对接口编程（框架和实现层向中间层靠拢）*/

// 案例 用不同厂商的硬件，组装电脑
// 硬件：内存 cpu 硬盘等
// 让computer框架和 具体厂商 解耦合
// 例如: 一台电脑 可用使用A厂商的CPU 和 B厂商的硬盘 和 C厂商的内存 组装
class HardDisk
{
public:
	virtual void work() = 0;
};

class Memory
{
public:
	virtual void work() = 0;
};

class Cpu
{
public:
	virtual void work() = 0;
};

class Computer
{
public:
	Computer(HardDisk *harddisk, Memory *memory, Cpu *cpu)
	{
		m_harddisk = harddisk;
		m_memory = memory;
		m_cpu = cpu;
	}
	// HardDisk
	// Memory
	// Cpu
public:
	void work()
	{
		m_harddisk->work();
		m_memory->work();
		m_cpu->work();
	}

protected:
private: // 类的组合
	HardDisk *m_harddisk;
	Memory *m_memory;
	Cpu *m_cpu;
};

class InterCpu : public Cpu
{
public:
	void work()
	{
		cout << "I am inter CPU" << endl;
	}
};

class XSDisk : public HardDisk
{
public:
	void work()
	{
		cout << "I am XS disk" << endl;
	}
};

class MMM : public Memory
{
public:
	void work()
	{
		cout << "I am MMM memory" << endl;
	}
};

int main()
{
	HardDisk *hard = NULL;
	Memory *mm = NULL;
	Cpu *cp = NULL;

	hard = new XSDisk;
	mm = new MMM;
	cp = new InterCpu;

	// 组装电脑
	Computer *mycompute = new Computer(hard, mm, cp);
	mycompute->work();

	// 释放内存
	delete cp;
	delete mm;
	delete hard;
}