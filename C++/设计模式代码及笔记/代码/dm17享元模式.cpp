#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	virtual void PrintT() = 0;

protected:
	string m_name;
	int m_age;
};

// 享元对象
class Teacher : public Person
{
public:
	Teacher(string name, int age, string id) : Person(name, age)
	{
		m_id = id;
	}
	virtual void PrintT()
	{
		cout << "name : " << m_name << "  age: "
			 << m_age << "  id:" << m_id << " " << endl;
	}

private:
	string m_id;
};

// 享元工厂  不同的对象创建， 相同的对象返回
class FlyWeightTeacherFactory
{
public:
	FlyWeightTeacherFactory()
	{
		map1.clear();
	}
	~FlyWeightTeacherFactory()
	{
		while (map1.empty()) // 在工厂中创建老师结点， 在工厂中销毁
		{
			Person *tmp = NULL;
			map<string, Person *>::iterator it = map1.begin();
			tmp = it->second;
			map1.erase(it);
			delete tmp;
		}
	}

	Person *GetTeacher(string id)
	{
		Person *tmp = NULL;
		map<string, Person *>::iterator it;
		it = map1.find(id);
		if (it == map1.end()) // 没找到
		{
			string tmpname;
			int tmpage;
			cout << "\nplease input teacher name:";
			cin >> tmpname;

			cout << "\nplease input teacher age:";
			cin >> tmpage;

			tmp = new Teacher(tmpname, tmpage, id);
			map1.insert(pair<string, Person *>(id, tmp));
		}
		else
		{
			tmp = it->second;
		}
		return tmp;
	}

private:
	map<string, Person *> map1;
};

// 享元模式   将所得对象保存起来， 下次获取看对象是否已经存在，
// 存在的话直接获取, 不在的话重新创建
int main()
{
	Person *p1 = NULL;
	Person *p2 = NULL;
	FlyWeightTeacherFactory *fw = new FlyWeightTeacherFactory;
	p1 = fw->GetTeacher("001");
	p1->PrintT();

	p2 = fw->GetTeacher("002");
	p2->PrintT();

	// p1 p2 所得结果相同
	delete fw;
}
