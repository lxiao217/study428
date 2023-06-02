#include <iostream>
#include <string>
using namespace std;

// 中介者模式
class Person;

// 抽象中介
class Mediator
{
public:
	virtual void setThing() = 0;
	virtual void setA(Person *) = 0;
	virtual void setB(Person *) = 0;
};

// 抽象人
class Person
{
public:
	Person(string name, char sex, int condi, Mediator *mediator)
	{
		m_name = name;
		m_sex = sex;
		m_condi = condi;
		m_mediator = mediator;
	}

	string getName()
	{
		return m_name;
	}

	char getSex()
	{
		return m_sex;
	}

	int getCondi()
	{
		return m_condi;
	}

public:
	virtual void getPater(Person *person) = 0;

protected: // 让子类可以直接使用父类成员变量
	string m_name;
	char m_sex;
	int m_condi;
	Mediator *m_mediator;
};

// 婚姻中介
class MarriageMediator : public Mediator
{
public:
	virtual void setA(Person *man)
	{
		m_man = man;
	}

	virtual void setB(Person *woman)
	{
		m_woman = woman;
	}

	virtual void setThing()
	{
		if (m_man->getSex() == m_woman->getSex())
		{
			cout << "Error: Sex is same" << endl;
		}
		if (m_man->getCondi() == m_woman->getCondi())
		{
			cout << m_man->getName() << " and " << m_woman->getName() << " matches!" << endl;
		}
		else
		{
			cout << m_man->getName() << " and " << m_woman->getName() << " do not match" << endl;
		}
	}

private:
	Person *m_man;
	Person *m_woman;
};

class Woman : public Person
{
public:
	Woman(string name, char sex, int condi, Mediator *m) : Person(name, sex, condi, m) {}

	virtual void getPater(Person *person)
	{
		m_mediator->setA(person);
		m_mediator->setB(this);
		m_mediator->setThing();
	}
};

class Man : public Person
{
public:
	Man(string name, char sex, int condi, Mediator *m) : Person(name, sex, condi, m) {}

	virtual void getPater(Person *person)
	{
		m_mediator->setA(this);
		m_mediator->setB(person);
		m_mediator->setThing();
	}
};

int main()
{
	Mediator *mediator = new MarriageMediator;
	Person *xiaofang = new Woman("Lucy", 'f', 5, mediator);
	Person *zhangsan = new Woman("Jame", 'm', 5, mediator);
	Person *lisi = new Woman("Tom", 'm', 2, mediator);

	// 小芳自己找对象， 偶合度太高， 借用中介者
	xiaofang->getPater(zhangsan);
	xiaofang->getPater(lisi);
}