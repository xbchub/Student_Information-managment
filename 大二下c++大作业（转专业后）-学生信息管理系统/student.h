// ========================================================================
// 华南理工大学电子与信息学院18级信息工程六班本科生许柏城
// ========================================================================

// 作者：许柏城
// 学号：201866020434
// 时间：2020-05-23
// 文件名：Stu_info_mgt_system（学生信息管理系统）
// 开发环境：Visual Studio 2010（vc10）
// 版本：V3.0
// 项目中的一些功能参考大一完成的c++大作业商品信息管理系统（github网址：https://github.com/scutxbc/2019c-.git）
//student.h
#pragma once
#include<iostream>
#include<string>
using namespace std;
#define _STUDENT_H_
class student  //定义student类
{
	friend class Class; //
private:
	string name;                         //姓名
	int age;                             //年龄
	string college;                      //学院
	string Classname;                    //班级
	string address;                      //家庭住址
	string phonenumber;                  //电话号码
	double cppscore;                     //C++成绩
	double mathscore;                    //数学成绩
	double engscore;                     //英语成绩
	double politicscore;                 //政治成绩
	double averagescore;                 //平均成绩
	int ID;                              //学号
	string grades;                       //优良等级
public:
	student() {};                                                            //构造函数
	~student() {};                                                           //析构函数
	friend ostream& operator << (ostream&, student& stu);                    //声明重载“<<”
	friend istream& operator >> (istream&, student& stu);                    //声明重载“>>”
	friend void readinitial(student*, int& initialnum);  //读取txt/dat文件
	friend void write(Class);  //写入dat文件
	void getgrade();
	void getaverage();
};