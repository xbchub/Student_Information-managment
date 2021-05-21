//student.cpp
#include"student.h"
#include<iostream>
using namespace std;
ostream& operator << (ostream& output, student& stu)  //定义重载提取运算符
{
	cout << "学号："; output << stu.ID << "  ";
	cout << "姓名："; output << stu.name << "  ";
	cout << "年龄："; output << stu.age << "  ";
	cout << "学院："; output << stu.college << endl;
	cout << "班级："; output << stu.Classname << "  ";
	cout << "家庭住址："; output << stu.address << "  ";
	cout << "电话号码："; output << stu.phonenumber << "  ";
	cout << "C++成绩："; output << stu.cppscore << endl;
	cout << "数学成绩："; output << stu.mathscore << "  ";
	cout << "英语成绩："; output << stu.engscore << "  ";
	cout << "政治成绩："; output << stu.politicscore << "  ";
	cout << "平均成绩："; output << stu.averagescore << "  ";
	cout << "优良等级："; output << stu.grades << endl;
	return output;
}
istream& operator >> (istream& input, student& stu)  //定义重载插入运算符
{
	cout << "请输入学生姓名："; input >> stu.name;
	cout << "请输入学生学号："; input >> stu.ID;
	if (!input.good())  //判断输入数据与ID是否为同一类型
	{
		input.clear();
		input.sync();
		throw 1;  //try-catch，用于处理数据不匹配错误
	}
	cout << "请输入学生年龄："; input >> stu.age;
	if (!input.good())  //判断输入数据与年龄是否为同一类型
	{
		input.clear();
		input.sync();
		throw 1;
	}
	cout << "请输入学生学院："; input >> stu.college;
	cout << "请输入学生班级："; input >> stu.Classname;
	cout << "请输入学生家庭住址："; input >> stu.address;
	cout << "请输入学生电话号码："; input >> stu.phonenumber;
	cout << "请输入学生C++成绩："; input >> stu.cppscore;
	if (!input.good())
	{
		input.clear();
		input.sync();
		throw 1;
	}
	cout << "请输入学生数学成绩："; input >> stu.mathscore;
	if (!input.good())
	{
		input.clear();
		input.sync();
		throw 1;
	}
	cout << "请输入学生英语成绩："; input >> stu.engscore;
	if (!input.good())
	{
		input.clear();
		input.sync();
		throw 1;
	}
	cout << "请输入学生政治成绩："; input >> stu.politicscore;
	if (!input.good())
	{
		input.clear();
		input.sync();
		throw 1;
	}
	return input;  //返回上面输入值
}
void student::getgrade()  //定义学生等级函数
{
	double totscore = cppscore;  //录入c++成绩
	totscore += mathscore;
	totscore += engscore;
	totscore += politicscore;
	if (totscore >= 240)
	{
		if (totscore >= 320)
			grades = "优";
		else
		{
			if (totscore >= 280)
				grades = "良";
			else
				grades = "合格";
		}
	}
	else
		grades = "不合格";
}
void student::getaverage()  //求平均成绩
{
	double totscore = cppscore;
	totscore += mathscore;
	totscore += engscore;
	totscore += politicscore;
	averagescore = totscore/4;
}