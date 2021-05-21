#include"Class.h"
#include<string>

void Class::ClassInitila(student*stu, int n)  //初始化链表信息
{
	Node*p1 = new Node;
	Node*p2 = new Node;
	p1 = head;  //用p1和p2完成初始化工作
	for (int i = 0; i < n; i++)
	{
		p2 = new Node;
		p2->data = stu[i];
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
	}
	sort(1);  //默认以1标准进行排序

}
void Class::add(student stu1)  //添加学生信息
{
	Node *p1 = new Node;
	Node*p = head;
	p1->data = stu1;
	p1->next = p->next;
	p->next = p1;
	studentnumber++;
	sort(1);
}
void Class::change(int&m2)
{
	int m; bool judge1 = true;
	cout << "请输入你要修改的学生的学号:" << endl;
	while (judge1)
	{
		cin >> m;
		Node*p = new Node;
		find(m, p);  //寻找m对应数据的指针
		int i = 0;
		while (p == NULL&&i <= 2)
		{
			cout << "该学号不存在，请重新输入" << endl;
			cin >> m;
			find(m, p);
			i++;
			if (p == NULL&&i >= 2)
			{
				cout << "三次输入无效的学号，请选择其他操作" << endl;
				goto a;
			}
		}
		cout << "你要修改的学生的初始信息为：\n";
		cout << p->data;
		cout << "请重新输入该学生的信息：" << endl;
	d:
		try
		{
			cin >> p->data;  //数据不合法的异常处理
		}
		catch (int)
		{
			system("cls");
			cout << "输入不合法数据，请检查重新输入" << endl;
			goto d;  //返回重新执行d，重新输入
		}
		p->data.getaverage();
		p->data.getgrade();
		sort(1);
		judge1 = false;  //当judge=false，退出循环
	a:
		if (judge1)
			m2 = 0;
		break;

	}
}
void Class::del(int&m1)  //删除函数
{
	int m; bool judge2 = true;
	cout << "请输入你要删除的学生的学号:" << endl;
	while (judge2)
	{
		cin >> m;
		Node*p = new Node;  
		find(m, p);
		int i = 0;
		while (p == NULL && i <= 2)  //指针错误，重新输入
		{
			cout << "该学号不存在，请重新输入" << endl;
			cin >> m;
			find(m, p);
			i++;
			if (p == NULL&&i >= 2)
			{
				cout << "三次输入无效的学号，请选择其他操作" << endl;
				goto a;
			}
		};
		Node*p1 = head;
		while (p1->next != NULL)
		{
			if (p1->next == p)
				break;
			else
				p1 = p1->next;
		}
		p1->next = p->next;
		delete p;  //删除并总数减一
		studentnumber--;
		judge2 = false;
	a:
		if (judge2)
			m1 = 0;
		break;
	}
}
void Class::find(int w, Node*&q)  //查找函数
{
	Node*p = head->next;
	while (p != NULL)
	{
		if (p->data.ID == w)
			break;
		p = p->next;
	}
	q = p;
}
void Class::getrate()  //通过率函数
{
	double a = 0, b = 0, c = 0, d = 0;
	Node *p = new Node;
	p = head->next;
	while (p != NULL)
	{
		if (p->data.cppscore >= 60)
			a++;
		if (p->data.mathscore >= 60)
			b++;
		if (p->data.engscore >= 60)
			c++;
		if (p->data.politicscore >= 60)
			d++;
		p = p->next;
	}
	passrate[0] = double(a / studentnumber);
	passrate[1] = double(b / studentnumber);
	passrate[2] = double(c / studentnumber);
	passrate[3] = double(d / studentnumber);
}
void Class::getnumofscores()  //定义各学科评分等级
{
	Node*p = head->next;
	int a, b, c, d;  //c++、数学、英语、政治的评分等级
	while (p != NULL)
	{
		a = int(p->data.cppscore / 10);
		b = int(p->data.mathscore / 10);
		c = int(p->data.engscore / 10);
		d = int(p->data.politicscore / 10);
		switch (a)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:  numofscores[0][0]++; break;
		case 6:  numofscores[0][1]++; break;
		case 7:  numofscores[0][2]++; break;
		case 8:
		case 9:
		case 10: numofscores[0][3]++; break;
		default:break;
		}
		switch (b)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:  numofscores[1][0]++; break;
		case 6:  numofscores[1][1]++; break;
		case 7:  numofscores[1][2]++; break;
		case 8:
		case 9:
		case 10: numofscores[1][3]++; break;
		default:break;
		}
		switch (c)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:  numofscores[2][0]++; break;
		case 6:  numofscores[2][1]++; break;
		case 7:  numofscores[2][2]++; break;
		case 8:
		case 9:
		case 10: numofscores[2][3]++; break;
		default:break;
		}
		switch (d)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:  numofscores[3][0]++; break;
		case 6:  numofscores[3][1]++; break;
		case 7:  numofscores[3][2]++; break;
		case 8:
		case 9:
		case 10: numofscores[3][3]++; break;
		default:break;
		}
		p = p->next;
	}
}
void Class::sort(int a)  //排序函数
{
	Node*p0 = NULL;
	Node*p1 = NULL;
	Node*p2 = NULL;
	Node*p3 = NULL;
	Node*p4 = NULL;
	Node*p5 = NULL;
	switch (a)
	{
	case 0:  //以姓名为标准排序
		p0 = head->next;
		for (int i = 0; i < studentnumber - 1; i++)
		{
			Node *q0 = p0->next;
			for (int j = i + 1; j < studentnumber; j++)
			{
				if (p0->data.name>q0->data.name)
				{
					student temp = q0->data;
					q0->data = p0->data;
					p0->data = temp;              
				}
				q0 = q0->next;
			}
			p0 = p0->next;
		}
		break;
	case 1:  //以学号为标准排序
		p1 = head->next;
		for (int i = 0; i < studentnumber - 1; i++)
		{
			Node *q1 = p1->next;
			for (int j = i + 1; j < studentnumber; j++)
			{
				if (p1->data.ID>q1->data.ID)
				{
					student temp = q1->data;
					q1->data = p1->data;
					p1->data = temp;                           
				}
				q1 = q1->next;
			}
			p1 = p1->next;
		}
		break;
	case 2:  //以c++为标准排序
		p2 = head->next;
		for (int i = 0; i < studentnumber - 1; i++)
		{
			Node *q2 = p2->next;
			for (int j = i + 1; j < studentnumber; j++)
			{
				if (p2->data.cppscore>q2->data.cppscore)
				{
					student temp = q2->data;
					q2->data = p2->data;
					p2->data = temp;                                    //
				}
				q2 = q2->next;
			}
			p2 = p2->next;
		}
		break;
	case 3:  //以数学为标准排序
		p3 = head->next;
		for (int i = 0; i < studentnumber - 1; i++)
		{
			Node *q3 = p3->next;
			for (int j = i + 1; j < studentnumber; j++)
			{
				if (p3->data.mathscore>q3->data.mathscore)
				{
					student temp = q3->data;
					q3->data = p3->data;
					p3->data = temp;                                    //
				}
				q3 = q3->next;
			}
			p3 = p3->next;

		}
		break;
	case 4:  //以英语为标准排序
		p4 = head->next;
		for (int i = 0; i < studentnumber - 1; i++)
		{
			Node *q4 = p4->next;
			for (int j = i + 1; j < studentnumber; j++)
			{
				if (p4->data.engscore>q4->data.engscore)
				{
					student temp = q4->data;
					q4->data = p4->data;
					p4->data = temp;                                    //
				}
				q4 = q4->next;
			}
			p4 = p4->next;
		}
		break;
	case 5:  //以政治为标准排序
		p5 = head->next;
		for (int i = 0; i < studentnumber - 1; i++)
		{
			Node *q5 = p5->next;
			for (int j = i + 1; j < studentnumber; j++)
			{
				if (p5->data.politicscore>q5->data.politicscore)
				{
					student temp = q5->data;
					q5->data = p5->data;
					p5->data = temp;                                    //
				}
				q5 = q5->next;
			}
			p5 = p5->next;
		}
		break;
	}
}
void Class::print()  //打印输出函数。将data信息打印出来
{
	Node*p = new Node;
	p = head->next;
	int i = 1;
	while (p != NULL)
	{
		cout << endl;
		cout << "学生" << i << "的信息为：\n";
		cout << p->data;
		i++;
		p = p->next;
	}
}
void Class::cal()  //统计信息打印出来，其他功能结束后自动调用该函数
{
	getrate();
	getnumofscores();
}