// main.cpp
#include"student.h"
#include"stdio.h"
#include"Class.h"
#include<fstream>
#include<windows.h>
#include<iomanip>
using namespace std;
int getlinelength(char*);
void readinitial(student* stu, int& initialnum);               //��ȡ�ļ�
void operation(Class clas, student* stu, int m);
void main()
{
	cout << "------------------��ӭ����ѧ����Ϣ����ϵͳ------------------" << endl;
	cout << "-------------------��ѡ���ȡ�ļ�������---------------------" << endl;
	cout << "             1--��ȡdat�ļ�        2--��ȡtxt�ļ�           " << endl;
	cout << "(�״�ʹ�����ȡtxt�ļ�����������ѧ����Ϣ���иĶ����ȡ������dat�ļ��� " << endl;
	student* rstu = new student[50];  //Ԥ��50����λ
	int istunum = 0;  //Ԥ���ļ�����Ϊ0
	try  //�ж��ļ��Ƿ��ȡ����ʧ��
	{
		readinitial(rstu, istunum);
		cout << "�ļ���ȡ�ɹ�������к���������" << endl;
		Class cla(istunum);
		operation(cla, rstu, istunum);
	}
	catch (int)
	{
		cout << "�ļ���ȡʱʧ�ܣ������ļ��Ƿ���ȷ�������Ƿ����" << endl;
	}
	catch (char)
	{
		cout << "�ļ�����ʱʧ�ܣ������ļ��Ƿ���ȷ�������Ƿ����" << endl;
	}
	system("pause");
}
void readinitial(student* stu, int& initialnum)  //��ȡ�ļ�
{
	int n; bool judge = true; int i = 0; int i1 = 0;
	ifstream infile;  //�����ļ�
	while (judge)
	{
		judge = false;
		cin >> n;  //n=1/2����Ӧ�����ļ���ȡ
		switch (n)
		{
		case 1:
			infile.open("D:\\students.dat", ios::in || ios::binary);
			if (!infile)
				throw 1;

			while (!infile.eof())  //�ж��Ƿ񵽴��ļ�β��,�Է�ֹ�����ļ���ȡ����
			{
				infile.read((char*)&stu[i], sizeof(student));  //һ�ζ�һ���ࣨ��txt�е�һ�У�
				i++;
			}
			initialnum = i - 1;  //�ļ�����
			infile.close();
			break;
		case 2:
			infile.open("D:\\students.txt", ios::in || ios::binary);
			if (!infile)
				throw 1;
			try
			{
				initialnum = getlinelength("D:\\students.txt");  //�򿪴��󼴷��ش���1
			}
			catch (int)
			{
				throw 1;
			}
			infile.seekg(0, ios::beg);  //���������ļ������ļ���ָ��λ��
			for (i1 = 0; i1 < initialnum; i1++)  //initialnum�ж�Ӧѧ������
			{
				infile >> stu[i1].ID;
				infile >> stu[i1].name;
				infile >> stu[i1].age;
				infile >> stu[i1].college;
				infile >> stu[i1].Classname;    //������ѧ����Ϣ���ļ���ÿ��ѧ������Ϣ������ȡ�����������δ����ڶ�̬student�������Ԫ����
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
			cout << "����������������룡" << endl;
			judge = true;
			break;
		}
		if (judge = false)
			break;
	}
}
int getlinelength(char* fname)  //��ȡtxt�ļ�����
{
	ifstream infile1;
	char ch = ' ';  //ÿ�ζ�ȡ����ch
	infile1.open(fname, ios::in || ios::binary);
	if (!infile1)
		throw 0;
	int m = 0;
	while (!infile1.eof())  //�ж��ļ��Ƿ��ȡ���
	{
		ch = infile1.get();  //���ļ��ı��ж�ȡ����
		if (ch == '\n')     //ÿ��ȡ�����з���m+1,���ڲ��ܶ�ȡ���ļ����һ�еĻ��з������Գ�ʼmΪ1
			m++;
	}
	return m;  //����txt�ļ�����
}
void operation(Class clas, student* stu, int m)  //����̨����
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
	system("cls");  //����
	cout << "                ��ɽ��еĲ���                " << endl;
	cout << "           1-���ѧ��    2-�޸�ѧ����Ϣ       " << endl;
	cout << "           3-ɾ��ѧ��    4-����ѧ����Ϣ       " << endl;
	cout << "           5-����        6-��ʾѧ����Ϣ       " << endl;
	cout << "           7-ͳ��        0-�˳�               " << endl;
	cout << "                ��ѡ����ز���                " << endl;
	bool judge = true;
	student pstu;
	int n, findID;  //�ж�ѡ����ֹ��ܲ���
	while (judge)
	{
		cin >> n;
		switch (n)
		{
		case 0:  //�����˳�����
			system("cls");
			cout << "����ѡ��0-�˳�" << endl;
			cout << "byebye~~,�´��ټ�" << endl;
			judge = false;
			break;
		case 1:  //������ӹ���
			system("cls");
			cout << "����ѡ��1-���ѧ��" << endl;
			cout << "��������Ҫ��ӵ�ѧ����Ϣ" << endl;
		d:
			try
			{
				cin >> pstu;
			}
			catch (int)
			{
				system("cls");
				cout << "���벻�Ϸ����ݣ�������������" << endl;
				goto d;
			}
			pstu.getaverage();
			pstu.getgrade();
			clas.add(pstu);
			try
			{
				write(clas);  //д��clas
			}
			catch (int)
			{
				cout << endl;
			}
			cout << "������ɲ��Ѵ��浽dat�ļ��У�������ѧ����Ϣ��ѧ������Ϊ��" << endl;
			clas.print();  //����print������д��������ļ�
			break;
		case 2:  //�����޸Ĺ���
			system("cls");
			cout << "����ѡ��2-�޸�ѧ����Ϣ" << endl;

			if (clas.studentnumber == 0)  //�鿴�༶�����Ƿ�Ϊ0
			{
				cout << "��ǰ��ѧ����Ϣ��" << endl;
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
						write(clas);  //�޸ĺ�����д�뵱ǰ����
					}
					catch (int)
					{
						cout << endl;
					}
					cout << "������ɲ��Ѵ��浽dat�ļ��У�������ѧ����Ϣ��ѧ������Ϊ��" << endl;
					clas.print();
				}
				break;
			}
		case 3:  //����ɾ������
			system("cls");
			cout << "����ѡ��3-ɾ��ѧ����Ϣ" << endl;
			if (clas.studentnumber == 0)  //ͬ����鿴�༶�����Ƿ�Ϊ0
			{
				cout << "��ǰ��ѧ����Ϣ��" << endl;
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
						write(clas);  //ɾ��������д�뵱ǰ����
					}
					catch (int)
					{
						cout << endl;
					}
					cout << "������ɲ��Ѵ��浽dat�ļ��У�������ѧ����Ϣ��ѧ������Ϊ��" << endl;
					clas.print();
				}
				break;
			}
		case 4:  //���ò��� ����
			system("cls");
			cout << "����ѡ��4-����ѧ����Ϣ" << endl;
			if (clas.studentnumber == 0)
			{
				cout << "��ǰ��ѧ����Ϣ��" << endl;
				break;
			}
			else
			{
				cout << "��������Ҫ���ҵ�ѧ����ѧ�ţ�" << endl;
				int i = 0;
				cin >> findID;
				Node* p1 = new Node;
				clas.find(findID, p1);  //����Node��Ѱ�Ҷ�Ӧѧ��ѧ��
				while (p1 == NULL && i <= 2)
				{
					cout << "��ѧ�Ų����ڣ�����������" << endl;
					cin >> findID;
					clas.find(findID, p1);
					i++;
					if (p1 == NULL && i >= 2)
					{
						cout << "����������Ч��ѧ�ţ���ѡ����������" << endl;
						goto a;  //��α���������ѭ��
					}
				}
				cout << "��ѧ������ϢΪ��" << endl;
				cout << p1->data;
				break;
			a:break;
			}
		case 5:  //����������
			system("cls");
			cout << "����ѡ��5-����" << endl;
			if (clas.studentnumber == 0)
			{
				cout << "��ǰ��ѧ����Ϣ��" << endl;
				break;
			}
			else
			{
				cout << "��ѡ����Ҫ���õ�����ʽ" << endl;
				cout << " 0-��������ĸ  1-ѧ�Ŵ�С  2-C++�ɼ�  3-��ѧ�ɼ�  4-Ӣ��ɼ�  5-���γɼ�" << endl;
				int m;
				cin >> m;
				clas.sort(m);
				cout << "������ɣ�������������ѧ����ϢΪ" << endl;
				clas.print();
				Sleep(200);
				break;
			}
		case 6:  //������ʾ����
			system("cls");
			cout << "����ѡ��6-��ʾѧ����Ϣ" << endl;
			if (clas.studentnumber == 0)
			{
				cout << "��ǰ��ѧ����Ϣ��" << endl;
				break;
			}
			else
			{
				cout << "ѧ����Ϣ��ѧ������Ϊ��";
				clas.print();
				break;
			}
		case 7:  //����ͳ�ƹ���
			system("cls");
			cout << "����ѡ��7-ͳ��" << endl;
			if (clas.studentnumber == 0)
			{
				cout << "��ǰ��ѧ����Ϣ��" << endl;
				break;
			}
			else
			{
				clas.cal();
				cout << "�༶������Ϊ�� " << clas.studentnumber << endl;
				cout << setiosflags(ios::fixed) << setprecision(2);
				cout << "C++��Ŀ������Ϊ: " << clas.passrate[0] << endl;
				cout << "C++�ɼ����ֶ�����Ϊ�� " << endl;
				cout << "[0,60)  " << clas.numofscores[0][0] << "  " << "[60,70)  " << clas.numofscores[0][1] << "  " << "[70,80)  " << clas.numofscores[0][2] << "  " << "[80,100)  " << clas.numofscores[0][3] << endl;
				cout << setiosflags(ios::fixed) << setprecision(2);
				cout << "��ѧ��Ŀ������Ϊ: " << clas.passrate[1] << endl;
				cout << "��ѧ�ɼ����ֶ�����Ϊ�� " << endl;
				cout << "[0,60)  " << clas.numofscores[1][0] << "  " << "[60,70)  " << clas.numofscores[1][1] << "  " << "[70,80)  " << clas.numofscores[1][2] << "  " << "[80,100)  " << clas.numofscores[1][3] << endl;
				cout << "Ӣ���Ŀ������Ϊ: " << clas.passrate[2] << endl;
				cout << setiosflags(ios::fixed) << setprecision(2);
				cout << "Ӣ��ɼ����ֶ�����Ϊ�� " << endl;
				cout << "[0,60)  " << clas.numofscores[2][0] << "  " << "[60,70)  " << clas.numofscores[2][1] << "  " << "[70,80)  " << clas.numofscores[2][2] << "  " << "[80,100)  " << clas.numofscores[2][3] << endl;
				cout << setiosflags(ios::fixed) << setprecision(2);
				cout << "���ο�Ŀ������Ϊ: " << clas.passrate[3] << endl;
				cout << "���γɼ����ֶ�����Ϊ�� " << endl;
				cout << "[0,60)  " << clas.numofscores[3][0] << "  " << "[60,70)  " << clas.numofscores[3][1] << "  " << "[70,80)  " << clas.numofscores[3][2] << "  " << "[80,100)  " << clas.numofscores[3][3] << endl;
				break;
			}
		default:
			cout << "����������������룡" << endl;
			break;
		}
		cout << endl;
		cout << "�����������������y;����������n!\n";
		char ch = '0';
		cin >> ch;
		if (judge == true)  //�ж����������Ƿ���ȷ
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
			cout << "                  ��ӭ����                    " << endl;
			cout << "                ��ɽ��еĲ���                " << endl;
			cout << "           1-���ѧ��    2-�޸�ѧ����Ϣ       " << endl;
			cout << "           3-ɾ��ѧ��    4-����ѧ����Ϣ       " << endl;
			cout << "           5-����        6-��ʾѧ����Ϣ       " << endl;
			cout << "           7-ͳ��        0-�˳�               " << endl;
			cout << "                ��ѡ����ز���                " << endl;
		}
	}
}
void write(Class class1)  //д�뺯����д��dat�ļ�
{
	ofstream outfile1("D:\\students.dat", ios::out || ios::binary);
	if (!outfile1)  //����Ƿ���ȷ
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