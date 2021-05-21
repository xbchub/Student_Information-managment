// main.cpp
#include"student.h"
#include"stdio.h"
#include"Class.h"
#include<fstream>
#include<windows.h>
#include<iomanip>
using namespace std;
int getlinelength(char*);
void readinitial(student* stu, int& initialnum);               //读取文件
void operation(Class clas, student* stu, int m);
void main()
{
	cout << "------------------欢迎来到学生信息管理系统------------------" << endl;
	cout << "-------------------请选择读取文件的类型---------------------" << endl;
	cout << "             1--读取dat文件        2--读取txt文件           " << endl;
	cout << "(首次使用请读取txt文件，后面若对学生信息进行改动请读取保存后的dat文件） " << endl;
	student* rstu = new student[50];  //预存50个单位
	int istunum = 0;  //预设文件行数为0
	try  //判断文件是否读取读入失败
	{
		readinitial(rstu, istunum);
		cout << "文件读取成功，请进行后续操作！" << endl;
		Class cla(istunum);
		operation(cla, rstu, istunum);
	}
	catch (int)
	{
		cout << "文件读取时失败，请检查文件是否正确命名或是否出错" << endl;
	}
	catch (char)
	{
		cout << "文件读入时失败，请检查文件是否正确命名或是否出错" << endl;
	}
	system("pause");
}
void readinitial(student* stu, int& initialnum)  //读取文件
{
	int n; bool judge = true; int i = 0; int i1 = 0;
	ifstream infile;  //读入文件
	while (judge)
	{
		judge = false;
		cin >> n;  //n=1/2，对应两种文件读取
		switch (n)
		{
		case 1:
			infile.open("D:\\students.dat", ios::in || ios::binary);
			if (!infile)
				throw 1;

			while (!infile.eof())  //判断是否到达文件尾部,以防止出现文件读取错误
			{
				infile.read((char*)&stu[i], sizeof(student));  //一次读一个类（即txt中的一行）
				i++;
			}
			initialnum = i - 1;  //文件行数
			infile.close();
			break;
		case 2:
			infile.open("D:\\students.txt", ios::in || ios::binary);
			if (!infile)
				throw 1;
			try
			{
				initialnum = getlinelength("D:\\students.txt");  //打开错误即返回错误1
			}
			catch (int)
			{
				throw 1;
			}
			infile.seekg(0, ios::beg);  //设置输入文件流的文件流指针位置
			for (i1 = 0; i1 < initialnum; i1++)  //initialnum行对应学生总数
			{
				infile >> stu[i1].ID;
				infile >> stu[i1].name;
				infile >> stu[i1].age;
				infile >> stu[i1].college;
				infile >> stu[i1].Classname;    //将存有学生信息的文件中每个学生的信息依次提取出来，并依次储存在动态student类数组的元素中
				infile >> stu[i1].address;
				infile >> stu[i1].phonenumber;
				infile >> stu[i1].cppscore;
				infile >> stu[i1].mathscore;
				infile >> stu[i1].engscore;
				infile >> stu[i1].politicscore;
				stu[i1].getaverage();
				stu[i1].getgrade();
			}
			infile.close();
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			judge = true;
			break;
		}
		if (judge = false)
			break;
	}
}
int getlinelength(char* fname)  //获取txt文件行数
{
	ifstream infile1;
	char ch = ' ';  //每次读取存入ch
	infile1.open(fname, ios::in || ios::binary);
	if (!infile1)
		throw 0;
	int m = 0;
	while (!infile1.eof())  //判断文件是否读取完成
	{
		ch = infile1.get();  //从文件文本中读取数据
		if (ch == '\n')     //每读取到换行符，m+1,由于不能读取到文件最后一行的换行符，所以初始m为1
			m++;
	}
	return m;  //返回txt文件行数
}
void operation(Class clas, student* stu, int m)  //控制台操作
{
	clas.ClassInitila(stu, m);  //
	try
	{
		write(clas);
	}
	catch (int)
	{
		cout << endl;
	}
	system("cls");  //清屏
	cout << "                你可进行的操作                " << endl;
	cout << "           1-添加学生    2-修改学生信息       " << endl;
	cout << "           3-删除学生    4-查找学生信息       " << endl;
	cout << "           5-排序        6-显示学生信息       " << endl;
	cout << "           7-统计        0-退出               " << endl;
	cout << "                请选择相关操作                " << endl;
	bool judge = true;
	student pstu;
	int n, findID;  //判断选择何种功能操作
	while (judge)
	{
		cin >> n;
		switch (n)
		{
		case 0:  //调用退出功能
			system("cls");
			cout << "你已选择0-退出" << endl;
			cout << "byebye~~,下次再见" << endl;
			judge = false;
			break;
		case 1:  //调用添加功能
			system("cls");
			cout << "你已选择1-添加学生" << endl;
			cout << "请输入你要添加的学生信息" << endl;
		d:
			try
			{
				cin >> pstu;
			}
			catch (int)
			{
				system("cls");
				cout << "输入不合法数据，请检查重新输入" << endl;
				goto d;
			}
			pstu.getaverage();
			pstu.getgrade();
			clas.add(pstu);
			try
			{
				write(clas);  //写入clas
			}
			catch (int)
			{
				cout << endl;
			}
			cout << "操作完成并已储存到dat文件中，操作后学生信息按学号排序为：" << endl;
			clas.print();  //调用print函数，写入二进制文件
			break;
		case 2:  //调用修改功能
			system("cls");
			cout << "你已选择2-修改学生信息" << endl;

			if (clas.studentnumber == 0)  //查看班级人数是否为0
			{
				cout << "当前无学生信息！" << endl;
				break;
			}
			else
			{
				int ischange = 1;
				clas.change(ischange);
				if (ischange)
				{
					try
					{
						write(clas);  //修改后重新写入当前数据
					}
					catch (int)
					{
						cout << endl;
					}
					cout << "操作完成并已储存到dat文件中，操作后学生信息按学号排序为：" << endl;
					clas.print();
				}
				break;
			}
		case 3:  //调用删除功能
			system("cls");
			cout << "你已选择3-删除学生信息" << endl;
			if (clas.studentnumber == 0)  //同样需查看班级人数是否为0
			{
				cout << "当前无学生信息！" << endl;
				break;
			}
			else
			{
				int isdel = 1;
				clas.del(isdel);
				if (isdel)
				{
					try
					{
						write(clas);  //删除后重新写入当前数据
					}
					catch (int)
					{
						cout << endl;
					}
					cout << "操作完成并已储存到dat文件中，操作后学生信息按学号排序为：" << endl;
					clas.print();
				}
				break;
			}
		case 4:  //调用查找 功能
			system("cls");
			cout << "你已选择4-查找学生信息" << endl;
			if (clas.studentnumber == 0)
			{
				cout << "当前无学生信息！" << endl;
				break;
			}
			else
			{
				cout << "请输入你要查找的学生的学号：" << endl;
				int i = 0;
				cin >> findID;
				Node* p1 = new Node;
				clas.find(findID, p1);  //遍历Node，寻找对应学号学生
				while (p1 == NULL && i <= 2)
				{
					cout << "该学号不存在，请重新输入" << endl;
					cin >> findID;
					clas.find(findID, p1);
					i++;
					if (p1 == NULL && i >= 2)
					{
						cout << "三次输入无效的学号，请选择其他操作" << endl;
						goto a;  //多次报错即跳出该循环
					}
				}
				cout << "该学生的信息为：" << endl;
				cout << p1->data;
				break;
			a:break;
			}
		case 5:  //调用排序功能
			system("cls");
			cout << "你已选择5-排序" << endl;
			if (clas.studentnumber == 0)
			{
				cout << "当前无学生信息！" << endl;
				break;
			}
			else
			{
				cout << "请选择你要采用的排序方式" << endl;
				cout << " 0-名字首字母  1-学号大小  2-C++成绩  3-数学成绩  4-英语成绩  5-政治成绩" << endl;
				int m;
				cin >> m;
				clas.sort(m);
				cout << "操作完成，进行相关排序后学生信息为" << endl;
				clas.print();
				Sleep(200);
				break;
			}
		case 6:  //调用显示功能
			system("cls");
			cout << "你已选择6-显示学生信息" << endl;
			if (clas.studentnumber == 0)
			{
				cout << "当前无学生信息！" << endl;
				break;
			}
			else
			{
				cout << "学生信息按学号排序为：";
				clas.print();
				break;
			}
		case 7:  //调用统计功能
			system("cls");
			cout << "你已选择7-统计" << endl;
			if (clas.studentnumber == 0)
			{
				cout << "当前无学生信息！" << endl;
				break;
			}
			else
			{
				clas.cal();
				cout << "班级总人数为： " << clas.studentnumber << endl;
				cout << setiosflags(ios::fixed) << setprecision(2);
				cout << "C++科目及格率为: " << clas.passrate[0] << endl;
				cout << "C++成绩各分段人数为： " << endl;
				cout << "[0,60)  " << clas.numofscores[0][0] << "  " << "[60,70)  " << clas.numofscores[0][1] << "  " << "[70,80)  " << clas.numofscores[0][2] << "  " << "[80,100)  " << clas.numofscores[0][3] << endl;
				cout << setiosflags(ios::fixed) << setprecision(2);
				cout << "数学科目及格率为: " << clas.passrate[1] << endl;
				cout << "数学成绩各分段人数为： " << endl;
				cout << "[0,60)  " << clas.numofscores[1][0] << "  " << "[60,70)  " << clas.numofscores[1][1] << "  " << "[70,80)  " << clas.numofscores[1][2] << "  " << "[80,100)  " << clas.numofscores[1][3] << endl;
				cout << "英语科目及格率为: " << clas.passrate[2] << endl;
				cout << setiosflags(ios::fixed) << setprecision(2);
				cout << "英语成绩各分段人数为： " << endl;
				cout << "[0,60)  " << clas.numofscores[2][0] << "  " << "[60,70)  " << clas.numofscores[2][1] << "  " << "[70,80)  " << clas.numofscores[2][2] << "  " << "[80,100)  " << clas.numofscores[2][3] << endl;
				cout << setiosflags(ios::fixed) << setprecision(2);
				cout << "政治科目及格率为: " << clas.passrate[3] << endl;
				cout << "政治成绩各分段人数为： " << endl;
				cout << "[0,60)  " << clas.numofscores[3][0] << "  " << "[60,70)  " << clas.numofscores[3][1] << "  " << "[70,80)  " << clas.numofscores[3][2] << "  " << "[80,100)  " << clas.numofscores[3][3] << endl;
				break;
			}
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		cout << endl;
		cout << "若还需操作，请输入y;否则，请输入n!\n";
		char ch = '0';
		cin >> ch;
		if (judge == true)  //判断输入类型是否正确
		{
			if (ch == 'y')
				judge = true;
			else
			{
				cout << "byebye" << endl;
				judge = false;
			}
		}

		if (judge == true)
		{
			system("cls");
			cout << "                  欢迎继续                    " << endl;
			cout << "                你可进行的操作                " << endl;
			cout << "           1-添加学生    2-修改学生信息       " << endl;
			cout << "           3-删除学生    4-查找学生信息       " << endl;
			cout << "           5-排序        6-显示学生信息       " << endl;
			cout << "           7-统计        0-退出               " << endl;
			cout << "                请选择相关操作                " << endl;
		}
	}
}
void write(Class class1)  //写入函数，写入dat文件
{
	ofstream outfile1("D:\\students.dat", ios::out || ios::binary);
	if (!outfile1)  //输出是否正确
		throw 'a';
	Node* p = new Node;
	p = class1.head->next;
	while (p != NULL)
	{
		outfile1.write((char*)&p->data, sizeof(p->data));
		p = p->next;
		if (p == NULL)
			outfile1.close();
	}
	outfile1.close();
}