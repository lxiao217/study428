#include <iostream>
#include <list>
using namespace std;

// 医生看病
class Doctor
{
public:
	void treat_eye()
	{
		cout << "treat eye" << endl;
	}
	void treat_nose()
	{
		cout << "treat nose" << endl;
	}
};

////////新增部分
class Command
{
public:
	virtual void treat() = 0;
};

// 护士
class Nurse
{
public:
	Nurse(Command *command)
	{
		m_command = command;
	}
	void SubmittedCase() // 提交病例， 下单命令
	{
		m_command->treat();
	}

private:
	Command *m_command;
};

// 护士长  /对护士提交的命令进行安排治疗
class HeadNurse
{
public:
	HeadNurse()
	{
		m_list.clear();
	}
	void setCommand(Command *command)
	{
		m_list.push_back(command);
	}
	void SubmittedCase() // 提交病例， 下单命令
	{
		for (list<Command *>::iterator it = m_list.begin();
			 it != m_list.end(); it++)
		{
			(*it)->treat();
		}
	}

private:
	list<Command *> m_list;
};

///////////////

class CommandTreatEye : public Command
{
public:
	CommandTreatEye(Doctor *doctor)
	{
		m_doctor = doctor;
	}

	void treat()
	{
		m_doctor->treat_eye();
	}

private:
	Doctor *m_doctor;
};

class CommandTreatNose : public Command
{
public:
	CommandTreatNose(Doctor *doctor)
	{
		m_doctor = doctor;
	}

	void treat()
	{
		m_doctor->treat_nose();
	}

private:
	Doctor *m_doctor;
};

// 通过命令模式
void main001()
{
	Doctor *doctor = new Doctor;
	Command *comte = new CommandTreatEye(doctor);
	comte->treat();
	delete comte;

	Command *comtn = new CommandTreatNose(doctor);
	comtn->treat();
	delete comtn;

	delete doctor;
}

// 护士
void main002()
{
	Doctor *doctor = new Doctor;
	// Command *com = new CommandTreatNose(doctor);
	Command *com = new CommandTreatEye(doctor);
	Nurse *nurse = new Nurse(com);
	nurse->SubmittedCase();

	delete nurse;
	delete com;
	delete doctor;
}

// 护士长
void main003()
{

	Doctor *doctor = new Doctor;
	HeadNurse *headNurse = new HeadNurse();
	Command *com1 = new CommandTreatNose(doctor);
	Command *com2 = new CommandTreatEye(doctor);

	headNurse->setCommand(com1);
	headNurse->setCommand(com2);
	headNurse->SubmittedCase();

	delete com2;
	delete com1;
	delete headNurse;
	delete doctor;
}

int main()
{
	main002();
}