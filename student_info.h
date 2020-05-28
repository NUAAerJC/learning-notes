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
	void Set_Data();//非文件版本
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
	student(); //student 类的构造函数
	//文件专用
	friend ostream& operator <<(ostream& out, student& p); //重载“<<”(引用版本)
	friend ostream& operator <<(ostream& out, student* p);//重载“<<”(指针版本)
	friend istream& operator >>(istream& in, student& p); //重载“>>”（引用版本）
	friend istream& operator >>(istream& in, student* p);//重载“>>”(指针版本)
	
	void operator =(student p); //重载“=”
	//输入输出专用
	void Output_Info();
	void Input_Info();
	void Set_Data(); //student 类的设置函数
	char* Get_Name(); //获得姓名
	bool Get_Sex(); //获得性别
	char* Get_Id(); //获得 id
	char* Get_Telephone(); //获得电话号码
	Date Get_Birthday(); //获得生日
	char* Get_Number(); //获得学号
	char* Get_Address();//获得家庭住址
	Dormitory Get_Dorm();//获得宿舍
	char* Get_Post();//获得职务
	char* Get_Major();//获得专业
	void Set_Name(char*); //设置姓名
	void Set_Sex(bool); //设置性别
	void Set_Id(char*); //设置 id 
	void Set_Number(char*); //设置学号
	void Set_Address(char*); //设置家庭地址
	void Set_Telephone(char*); //设置电话号码
	void Set_Birthday(Date&); //设置出生日期
	void Set_Dorm(Dormitory&); //设置宿舍
	void Set_Post(char*); //设置职务
	void Set_Major(char*); //设置专业
protected:
	char stu_name[20]; //姓名
	bool stu_sex; //性别:1表示男，0表示女
	char stu_id[20]; //身份证号
	char stu_telephone[12]; //电话号码
	Date stu_birthday; //出生日期
	char stu_number[20]; //学号
	char stu_address[20]; //家庭地址
	Dormitory stu_dorm;//宿舍
	char stu_post[20]; //职务
	char stu_major[10]; //专业
public:
	student* next; //下一个节点
	student* previous; //上一个节点
};

#endif