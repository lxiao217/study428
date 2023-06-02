#include <iostream>
using namespace std;

class CarHandle
{
public:
	virtual void HandleCar() = 0;
	CarHandle *setNextHandle(CarHandle *handle)
	{
		m_handle = handle;
		return m_handle;
	}

protected:
	CarHandle *m_handle; // 下一个处理单元
};

class HeadHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "make head" << endl;
		// 造完自己的部分， 把任务交给下一个处理器
		if (m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};

class BodyHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "make body" << endl;
		if (m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};

class TailHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "make tail" << endl;
		if (m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};

int main()
{
	CarHandle *headHandle = new HeadHandle;
	CarHandle *bodyHandle = new BodyHandle;
	CarHandle *tailHandle = new TailHandle;

	// 任务的处理关系
	headHandle->setNextHandle(bodyHandle);
	bodyHandle->setNextHandle(tailHandle);
	tailHandle->setNextHandle(NULL);

	headHandle->HandleCar();
}