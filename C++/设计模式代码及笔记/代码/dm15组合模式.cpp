#include <iostream>
#include <string>
#include <list>
using namespace std;

// 组合模式
// 目录树
// 单一对象和组合对象使用一致性的接口

class IFile
{
public:
	virtual void display() = 0;
	virtual int add(IFile *ifile) = 0;
	virtual int remove(IFile *ifile) = 0;
	virtual list<IFile *> *getChild() = 0;
};

// 文件类
class File : public IFile
{
public:
	File(string name)
	{
		m_name = name;
	}
	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)
	{
		return -1;
	}
	virtual int remove(IFile *ifile)
	{
		return -1;
	}
	virtual list<IFile *> *getChild()
	{
		return NULL;
	}

private:
	string m_name;
};

// 目录类
class Dir : public IFile
{
public:
	Dir(string name)
	{
		m_name = name;
		// 指针变量 需要new对象
		m_list = new list<IFile *>; // 每有一个对象 要新创建一个对象list保存其下目录
		m_list->clear();
	}
	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)
	{
		m_list->push_back(ifile);
		return 0;
	}
	virtual int remove(IFile *ifile)
	{
		m_list->remove(ifile);
		return 0;
	}
	virtual list<IFile *> *getChild()
	{
		return m_list;
	}

private:
	string m_name;
	list<IFile *> *m_list;
};

// 打印目录树
// 递归打印的过程

/*
	0. begin
	1.打印名字
	2.如果是文件 执行4
	3.如果是目录有孩子 0
	4.无孩子 5
	5.end
*/

void PrintDir(IFile *root, int level)
{
	if (root == NULL)
		return;

	root->display();
	// 存储当前根目录下有几个目录
	list<IFile *> *mlist = root->getChild();

	if (mlist == NULL)
		return;

	// 遍历每个目录， 确定是否递归
	for (list<IFile *>::iterator it = mlist->begin();
		 it != mlist->end(); it++)
	{
		if ((*it)->getChild() == NULL)
		{ // 文件
			for (int i = 0; i <= level; i++)
			{
				cout << "     ";
			}
			(*it)->display();
		}
		else
		{ // 目录
			PrintDir((*it), level++);
		}
	}
}
int main()
{
	/*

		c----
			|--dir1
			|
			|--dir2---
					 |--text1
					 |
					 |--text2

	*/
	IFile *root = new Dir("C");
	Dir *dir1 = new Dir("dir1");
	Dir *dir2 = new Dir("dir2");
	File *file1 = new File("text1");
	File *file2 = new File("text2");

	root->add(dir1);
	root->add(dir2);
	dir2->add(file1);
	dir2->add(file2);

	PrintDir(root, 0);
}