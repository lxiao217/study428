#include <iostream>
#include <string>
using namespace std;

class Worker;
class State
{
public:
	virtual void doSomeThing(Worker *w) = 0;
};

class State1 : public State
{
public:
	void doSomeThing(Worker *w);
};

class State2 : public State
{
public:
	void doSomeThing(Worker *w);
};

class Worker
{
public:
	Worker();
	int getHour()
	{
		return m_hour;
	}

	void setHour(int hour)
	{
		m_hour = hour;
	}

	State *getCurrentState()
	{
		return m_currstate;
	}

	void setCurrentState(State *state)
	{
		m_currstate = state;
	}

	void doSomeThing() // Ä³¸ö×´Ì¬µÄÄ³¼þÊÂ
	{
		m_currstate->doSomeThing(this);
	}

private:
	int m_hour;
	State *m_currstate;
};

// ×´Ì¬×ª»»ÔÚ×Ô¼ºÄÚ²¿×ª»»
void State1::doSomeThing(Worker *w)
{
	if (w->getHour() == 7 || w->getHour() == 8)
	{
		cout << "have breakfast" << endl;
	}
	else
	{
		// ×´Ì¬1²»Âú×ã ÇÐ»»µ½×´Ì¬2
		delete w->getCurrentState();		  // É¾³ýµ±Ç°×´Ì¬
		w->setCurrentState(new State2);		  // Éú³ÉÐÂ×´Ì¬
		w->getCurrentState()->doSomeThing(w); // ÇÐ»»×´Ì¬
	}
}

void State2::doSomeThing(Worker *w)
{
	if (w->getHour() == 9 || w->getHour() == 10)
	{
		cout << "working" << endl;
	}
	else
	{
		// ×´Ì¬2²»Âú×ã ÇÐ»»µ½×´Ì¬3   ×´Ì¬»Ö¸´µ½µ±³õ×´Ì¬
		delete w->getCurrentState();
		w->setCurrentState(new State1);
		cout << "current time: " << w->getHour() << " unknown" << endl;
	}
}

Worker::Worker()
{
	m_currstate = new State1;
}

int main()
{
	Worker *worker = new Worker;
	worker->setHour(8);
	worker->doSomeThing();

	worker->setHour(11);
	worker->doSomeThing();

	delete worker;
}
