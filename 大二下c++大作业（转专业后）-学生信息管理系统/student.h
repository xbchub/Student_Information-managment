// ========================================================================
// ��������ѧ��������ϢѧԺ18����Ϣ�������౾������س�
// ========================================================================

// ���ߣ���س�
// ѧ�ţ�201866020434
// ʱ�䣺2020-05-23
// �ļ�����Stu_info_mgt_system��ѧ����Ϣ����ϵͳ��
// ����������Visual Studio 2010��vc10��
// �汾��V3.0
// ��Ŀ�е�һЩ���ܲο���һ��ɵ�c++����ҵ��Ʒ��Ϣ����ϵͳ��github��ַ��https://github.com/scutxbc/2019c-.git��
//student.h
#pragma once
#include<iostream>
#include<string>
using namespace std;
#define _STUDENT_H_
class student  //����student��
{
	friend class Class; //
private:
	string name;                         //����
	int age;                             //����
	string college;                      //ѧԺ
	string Classname;                    //�༶
	string address;                      //��ͥסַ
	string phonenumber;                  //�绰����
	double cppscore;                     //C++�ɼ�
	double mathscore;                    //��ѧ�ɼ�
	double engscore;                     //Ӣ��ɼ�
	double politicscore;                 //���γɼ�
	double averagescore;                 //ƽ���ɼ�
	int ID;                              //ѧ��
	string grades;                       //�����ȼ�
public:
	student() {};                                                            //���캯��
	~student() {};                                                           //��������
	friend ostream& operator << (ostream&, student& stu);                    //�������ء�<<��
	friend istream& operator >> (istream&, student& stu);                    //�������ء�>>��
	friend void readinitial(student*, int& initialnum);  //��ȡtxt/dat�ļ�
	friend void write(Class);  //д��dat�ļ�
	void getgrade();
	void getaverage();
};