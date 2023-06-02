#include <iostream>
using namespace std;

class Subject
{
public:
	virtual void sellbook() = 0;
};
class RealBookStore : public Subject
{
public:
	virtual void sellbook()
	{
		cout << "sell  book" << endl;
	}
};

// 当当网代理实体店卖书
//////继承方式实现：
// class DangDang : public Subject
//{
// public:
//	virtual void sellbook()
//	{
//		Subject *sub = new RealBookStore;
//		//RealBookStore *rb = new RealBookStore;
//		dazhe();
//		sub->sellbook();
//	}
//	void dazhe()
//	{
//		cout << "打折" << endl;
//	}
//
// private:
//	 //Subject *m_sub;
// };

// void main1()
//{
//	Subject *s = new DangDang;
//	s->sellbook();
//	delete s;
//
//	system("pause");
//	return;
// }

////组合方式实现：
class DangDang
{
public:
	DangDang()
	{
		m_sub = new RealBookStore;
	}
	void sellbook()
	{
		// 代理模式： 可实现内部具体逻辑
		// 比如 怎样卖，是否促销，各种活动等等
		dazhe();
		m_sub->sellbook();
	}
	void dazhe()
	{
		cout << "sale " << endl;
	}

private:
	Subject *m_sub;
};

int main()
{
	DangDang d;
	d.sellbook();
}