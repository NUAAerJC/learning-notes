#pragma once
//student_info.h

#ifndef STUDENT_INFO_H_
#define STUDENT_INFO_H_
#include<iostream>
using namespace std;
class Date
{
private:
	int stu_year;
	int stu_month;
	int stu_day;
public:
	Date();
	void Set_Data();//���ļ��汾
	friend istream& operator >>(istream& in, Date& da);
	friend ostream& operator <<(ostream& out, Date& da);
	void operator=(Date da);
	void Output_Date();
	void Input_Date();
	int Get_Year();
	int Get_Month();
	int Get_Day();
	void Set_Year(int);
	void Set_Month(int);
	void Set_Day(int);
};

class Dormitory
{
private:
	int stu_buliding;
	int stu_floor;
	int stu_room;
public:
	Dormitory();
	void Set_Data();
	friend istream& operator>>(istream& in, Dormitory& d);
	friend ostream& operator<<(ostream& out, Dormitory& d);
	void operator=(Dormitory d);
	void Output_Dorm();
	void Input_Dorm();
	int Get_Building();
	int Get_Floor();
	int Get_Room();
	void Set_Building(int);
	void Set_Floor(int);
	void Set_Room(int);
};

class student
{
public:
	student(); //student ��Ĺ��캯��
	//�ļ�ר��
	friend ostream& operator <<(ostream& out, student& p); //���ء�<<��(���ð汾)
	friend ostream& operator <<(ostream& out, student* p);//���ء�<<��(ָ��汾)
	friend istream& operator >>(istream& in, student& p); //���ء�>>�������ð汾��
	friend istream& operator >>(istream& in, student* p);//���ء�>>��(ָ��汾)
	
	void operator =(student p); //���ء�=��
	//�������ר��
	void Output_Info();
	void Input_Info();
	void Set_Data(); //student ������ú���
	char* Get_Name(); //�������
	bool Get_Sex(); //����Ա�
	char* Get_Id(); //��� id
	char* Get_Telephone(); //��õ绰����
	Date Get_Birthday(); //�������
	char* Get_Number(); //���ѧ��
	char* Get_Address();//��ü�ͥסַ
	Dormitory Get_Dorm();//�������
	char* Get_Post();//���ְ��
	char* Get_Major();//���רҵ
	void Set_Name(char*); //��������
	void Set_Sex(bool); //�����Ա�
	void Set_Id(char*); //���� id 
	void Set_Number(char*); //����ѧ��
	void Set_Address(char*); //���ü�ͥ��ַ
	void Set_Telephone(char*); //���õ绰����
	void Set_Birthday(Date&); //���ó�������
	void Set_Dorm(Dormitory&); //��������
	void Set_Post(char*); //����ְ��
	void Set_Major(char*); //����רҵ
protected:
	char stu_name[20]; //����
	bool stu_sex; //�Ա�:1��ʾ�У�0��ʾŮ
	char stu_id[20]; //���֤��
	char stu_telephone[12]; //�绰����
	Date stu_birthday; //��������
	char stu_number[20]; //ѧ��
	char stu_address[20]; //��ͥ��ַ
	Dormitory stu_dorm;//����
	char stu_post[20]; //ְ��
	char stu_major[10]; //רҵ
public:
	student* next; //��һ���ڵ�
	student* previous; //��һ���ڵ�
};

#endif