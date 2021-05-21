//class.h
#pragma once
#include"student.h"
class Node  //定义链表类
{
public:
	student data;                      //数据域
	Node* next;                     //指针域
};
class Class
{
private:
	int studentnumber;  //班级总人数
	double passrate[4];  //定义挂科率
	int numofscores[4][4];  //各学科各分数段的人数
	Node* head;
public:
	Class(int m)    //定义构造函数
	{
		studentnumber = m;                //学生数量
		head = new Node;                  //定义head
		head->data.ID = 0;                //学号
		head->data.name = " ";            //学生姓名
		head->data.age = 0;               //年龄
		head->data.college = " ";         //学院
		head->data.Classname = " ";       //班级
		head->data.address = " ";         //住址
		head->data.phonenumber = " ";     //手机号码
		head->data.cppscore = 0;          //c++成绩
		head->data.mathscore = 0;         //数学成绩
		head->data.engscore = 0;          //英语成绩
		head->data.politicscore = 0;      //政治成绩
		head->data.averagescore = 0;      //平均成绩
		head->data.grades = " ";          //优良等级
		head->next = NULL;                //结尾，指向空

	};
	~Class() {};  //定义析构函数
	void ClassInitila(student*, int);                      //初始化
	void add(student);                                     //添加学生
	void change(int&);                                     //修改学生信息
	void del(int&);                                        //删除
	void find(int, Node*&);                                //查找
	void getrate();                                        //返回各科及格率
	void getnumofscores();                                 //返回各科各分数段人数
	void getstunum();                                      //返回班级总人数
	void print();                                          //显示班级学生信息 
	void sort(int);                                        //排序
	void cal();                                            //统计
	friend void operation(Class, student*, int);
	friend void write(Class);
	friend void readinitial(Class);  //读取文件
};