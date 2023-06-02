#include <iostream>
using namespace std;

// 业务逻辑提前被处理好（方法之间的调用关系），
// 子类只需要处理方法的具体实现

class MakeCar
{
public:
	virtual void MakeHead() = 0;
	virtual void MakeBody() = 0;
	virtual void MakeTail() = 0;

	// 模版函数
	void Make()
	{
		MakeTail();
		MakeBody();
		MakeHead();
	}

private:
};

class Jeep : public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "jeep head" << endl;
	}

	virtual void MakeTail()
	{

		cout << "jeep tail" << endl;
	}

	virtual void MakeBody()
	{
		cout << "jeep body" << endl;
	}
};

int main()
{
	MakeCar *makecar = NULL;
	makecar = new Jeep;
	makecar->Make();

	delete makecar;
}