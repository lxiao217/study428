#include <iostream>
#include <string>
#include <list>

using namespace std;

// 访问者模式
// 访问者可以访问公园的某部分
// 管理者可以访问整个公园

class Park;
// 抽象访问者
class Visitor
{
public:
	virtual void Visit(Park *park) = 0;
};

// 抽象公园 接收访问
class Park
{
public:
	virtual void Accept(Visitor *visitor) = 0;
};

class VisitorA : public Visitor
{
public:
	virtual void Visit(Park *park)
	{
		cout << "A visit park section A" << endl; // park->getName();
	}
};

class VisitorB : public Visitor
{
public:
	virtual void Visit(Park *park)
	{
		// park->Accept(this);
		cout << "B visit park section B" << endl;
	}
};

class ParkA : public Park
{
public:
	virtual void Accept(Visitor *visitor)
	{
		visitor->Visit(this);
	}

private:
};

class ParkB : public Park
{
public:
	virtual void Accept(Visitor *visitor)
	{
		visitor->Visit(this);
	}

private:
};

// 整个公园
class AllPark : public Park
{
public:
	AllPark()
	{
		m_list.clear();
	}

	void setAllPark(Park *park)
	{
		m_list.push_back(park);
	}

	virtual void Accept(Visitor *v)
	{
		// list存的是公园的各个部分， 遍历每个部分调用自己的accpet函数
		for (list<Park *>::iterator it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->Accept(v);
		}
	}

private:
	list<Park *> m_list;
};

// 管理者
class ManagerVisitor : public Visitor
{
public:
	virtual void Visit(Park *park)
	{
		cout << "Visit All park" << endl; // park->getName();
	}
};

void main01()
{
	Visitor *visitor = new VisitorA;
	Park *park = new ParkA;

	park->Accept(visitor);

	delete park;
	delete visitor;
}
void main02()
{
	Visitor *manager = new ManagerVisitor;
	Park *parka = new ParkA;
	Park *parkb = new ParkB;
	AllPark *parkall = new AllPark;

	// 将公园各个部分放入整个公园 setAllPark() 。 但是这个函数是继承后的新的成员， 所以父类只能是AllPark

	parkall->setAllPark(parka);
	parkall->setAllPark(parkb);

	// 整个公园接收管理者访问。
	parkall->Accept(manager);

	// delete
}
int main()
{
	main01();
	main02();
}
