#include <iostream>
#include <string>
using namespace std;
typedef int Object;
#define SIZE 5

// 迭代器模式，， 类似stl迭代器

// 迭代器抽象类
class MyIterator
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Object CurrentItem() = 0;
};

// 集合抽象类
class Aggregate
{
public:
	virtual Object getItem(int index) = 0;
	virtual int getSize() = 0;
	virtual MyIterator *getIterator() = 0;
};

// 迭具体代器类
// 迭代器中应该持有一个集合的指针（引用），以此通过迭代器访问集合
class ContreteIterator : public MyIterator
{
public:
	ContreteIterator(Aggregate *ag)
	{
		_ag = ag;
		_current = 0;
	}

public:
	virtual void First()
	{
		_current = 0;
	}
	virtual void Next()
	{
		if (_current < _ag->getSize())
			_current++;
	}
	virtual bool IsDone()
	{
		return _current == _ag->getSize();
	}
	virtual Object CurrentItem()
	{
		return _ag->getItem(_current);
	}

private:
	// 当前位置，以及集合
	int _current;
	Aggregate *_ag;
};

// 具体集合类
class ContreteAggregate : public Aggregate
{
public:
	ContreteAggregate()
	{
		for (int i = 0; i < SIZE; i++)
		{
			object[i] = i + 1;
		}
	}

public:
	virtual Object getItem(int index)
	{
		return object[index];
	}
	virtual int getSize()
	{
		return SIZE;
	}
	virtual MyIterator *getIterator()
	{
		return new ContreteIterator(this);
	}

private:
	Object object[SIZE];
};

int main()
{
	Aggregate *arr = new ContreteAggregate;
	MyIterator *it = arr->getIterator();

	for (; !(it->IsDone()); it->Next())
	{
		cout << it->CurrentItem() << " ";
	}

	delete it;
	delete arr;
	cout << endl;
}
