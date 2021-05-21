//class.h
#pragma once
#include"student.h"
class Node  //����������
{
public:
	student data;                      //������
	Node* next;                     //ָ����
};
class Class
{
private:
	int studentnumber;  //�༶������
	double passrate[4];  //����ҿ���
	int numofscores[4][4];  //��ѧ�Ƹ������ε�����
	Node* head;
public:
	Class(int m)    //���幹�캯��
	{
		studentnumber = m;                //ѧ������
		head = new Node;                  //����head
		head->data.ID = 0;                //ѧ��
		head->data.name = " ";            //ѧ������
		head->data.age = 0;               //����
		head->data.college = " ";         //ѧԺ
		head->data.Classname = " ";       //�༶
		head->data.address = " ";         //סַ
		head->data.phonenumber = " ";     //�ֻ�����
		head->data.cppscore = 0;          //c++�ɼ�
		head->data.mathscore = 0;         //��ѧ�ɼ�
		head->data.engscore = 0;          //Ӣ��ɼ�
		head->data.politicscore = 0;      //���γɼ�
		head->data.averagescore = 0;      //ƽ���ɼ�
		head->data.grades = " ";          //�����ȼ�
		head->next = NULL;                //��β��ָ���

	};
	~Class() {};  //������������
	void ClassInitila(student*, int);                      //��ʼ��
	void add(student);                                     //���ѧ��
	void change(int&);                                     //�޸�ѧ����Ϣ
	void del(int&);                                        //ɾ��
	void find(int, Node*&);                                //����
	void getrate();                                        //���ظ��Ƽ�����
	void getnumofscores();                                 //���ظ��Ƹ�����������
	void getstunum();                                      //���ذ༶������
	void print();                                          //��ʾ�༶ѧ����Ϣ 
	void sort(int);                                        //����
	void cal();                                            //ͳ��
	friend void operation(Class, student*, int);
	friend void write(Class);
	friend void readinitial(Class);  //��ȡ�ļ�
};