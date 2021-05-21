//student.cpp
#include"student.h"
#include<iostream>
using namespace std;
ostream& operator << (ostream& output, student& stu)  //����������ȡ�����
{
	cout << "ѧ�ţ�"; output << stu.ID << "  ";
	cout << "������"; output << stu.name << "  ";
	cout << "���䣺"; output << stu.age << "  ";
	cout << "ѧԺ��"; output << stu.college << endl;
	cout << "�༶��"; output << stu.Classname << "  ";
	cout << "��ͥסַ��"; output << stu.address << "  ";
	cout << "�绰���룺"; output << stu.phonenumber << "  ";
	cout << "C++�ɼ���"; output << stu.cppscore << endl;
	cout << "��ѧ�ɼ���"; output << stu.mathscore << "  ";
	cout << "Ӣ��ɼ���"; output << stu.engscore << "  ";
	cout << "���γɼ���"; output << stu.politicscore << "  ";
	cout << "ƽ���ɼ���"; output << stu.averagescore << "  ";
	cout << "�����ȼ���"; output << stu.grades << endl;
	return output;
}
istream& operator >> (istream& input, student& stu)  //�������ز��������
{
	cout << "������ѧ��������"; input >> stu.name;
	cout << "������ѧ��ѧ�ţ�"; input >> stu.ID;
	if (!input.good())  //�ж�����������ID�Ƿ�Ϊͬһ����
	{
		input.clear();
		input.sync();
		throw 1;  //try-catch�����ڴ������ݲ�ƥ�����
	}
	cout << "������ѧ�����䣺"; input >> stu.age;
	if (!input.good())  //�ж����������������Ƿ�Ϊͬһ����
	{
		input.clear();
		input.sync();
		throw 1;
	}
	cout << "������ѧ��ѧԺ��"; input >> stu.college;
	cout << "������ѧ���༶��"; input >> stu.Classname;
	cout << "������ѧ����ͥסַ��"; input >> stu.address;
	cout << "������ѧ���绰���룺"; input >> stu.phonenumber;
	cout << "������ѧ��C++�ɼ���"; input >> stu.cppscore;
	if (!input.good())
	{
		input.clear();
		input.sync();
		throw 1;
	}
	cout << "������ѧ����ѧ�ɼ���"; input >> stu.mathscore;
	if (!input.good())
	{
		input.clear();
		input.sync();
		throw 1;
	}
	cout << "������ѧ��Ӣ��ɼ���"; input >> stu.engscore;
	if (!input.good())
	{
		input.clear();
		input.sync();
		throw 1;
	}
	cout << "������ѧ�����γɼ���"; input >> stu.politicscore;
	if (!input.good())
	{
		input.clear();
		input.sync();
		throw 1;
	}
	return input;  //������������ֵ
}
void student::getgrade()  //����ѧ���ȼ�����
{
	double totscore = cppscore;  //¼��c++�ɼ�
	totscore += mathscore;
	totscore += engscore;
	totscore += politicscore;
	if (totscore >= 240)
	{
		if (totscore >= 320)
			grades = "��";
		else
		{
			if (totscore >= 280)
				grades = "��";
			else
				grades = "�ϸ�";
		}
	}
	else
		grades = "���ϸ�";
}
void student::getaverage()  //��ƽ���ɼ�
{
	double totscore = cppscore;
	totscore += mathscore;
	totscore += engscore;
	totscore += politicscore;
	averagescore = totscore/4;
}