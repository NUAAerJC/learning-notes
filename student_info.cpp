//student_info.cpp
#include<iostream>
#include"student_info.h"
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

//class Date methods

Date::Date()
{
	stu_day = 0;
	stu_month = 0;
	stu_year = 0;
}

void Date::Set_Data()
{
	cout << "year:";
	cin >> stu_year;
	cout << "month:";
	cin >> stu_month;
	cout << "day:";
	cin >> stu_day;
}

ostream& operator <<(ostream& out, Date& da)
{
	out << da.stu_year;
	out << endl;
	out << da.stu_month;
	out << endl;
	out << da.stu_day;
	return out;
}

istream& operator >>(istream& in, Date& da)
{
	in >> da.stu_year;
	in.get();
	in >> da.stu_month;
	in.get();
	in >> da.stu_day;
	return in;
}

void Date::operator = (Date da)
{
	this->stu_year = da.stu_year;
	this->stu_month = da.stu_month;
	this->stu_day = da.stu_day;
}

void Date::Output_Date()
{
	cout << stu_year
		<< '-' << stu_month
		<< "-" << stu_day;
}


void Date::Input_Date()
{
	cout << "year:";
	cin >> stu_year;
	cout << "month:";
	cin >> stu_month;
	cout << "day:";
	cin >> stu_day;
}

int Date::Get_Year()
{
	return this->stu_year;
}

int Date::Get_Month()
{
	return this->stu_month;
}

int Date::Get_Day()
{
	return this->stu_day;
}

void Date::Set_Year(int year)
{
	stu_year = year;
}

void Date::Set_Month(int month)
{
	stu_month = month;
}

void Date::Set_Day(int day)
{
	stu_day = day;
}

//class Dormitory methods

Dormitory::Dormitory()
{
	stu_buliding = 0;
	stu_floor = 0;
	stu_room = 0;
}

void Dormitory::Set_Data()
{
	cout << "building:";
	cin >> stu_buliding;
	cout << "floor:";
	cin >> stu_floor;
	cout << "room:";
	cin >> stu_room;
}

istream& operator>>(istream& in, Dormitory& d)
{
	in >> d.stu_buliding;
	in.get();
	in >> d.stu_floor;
	in.get();
	in >> d.stu_room;
	return in;
}

ostream& operator<<(ostream& out, Dormitory& d)
{
	out << d.stu_buliding;
	out << endl;
	out << d.stu_floor;
	out << endl;
	out << d.stu_room;
	return out;
}

void Dormitory::operator = (Dormitory d)
{
	this->stu_buliding = d.stu_buliding;
	this->stu_floor = d.stu_floor;
	this->stu_room = d.stu_room;
}

void Dormitory::Output_Dorm()
{
	cout << stu_buliding
		<< '-' << stu_floor
		<< '-' << stu_room;
}

void Dormitory::Input_Dorm()
{
	cout << "building:";
	cin >> stu_buliding;
	cout << "floor:";
	cin >> stu_floor;
	cout << "room:";
	cin >> stu_room;
}

int Dormitory::Get_Building()
{
	return this->stu_buliding;
}

int Dormitory::Get_Floor()
{
	return this->stu_floor;
}

int Dormitory::Get_Room()
{
	return this->stu_room;
}

void Dormitory::Set_Building(int building)
{
	stu_buliding = building;
}

void Dormitory::Set_Floor(int floor)
{
	stu_floor = floor;
}

void Dormitory::Set_Room(int room)
{
	stu_room = room;
}

//class student methods

student::student()
{
	strncpy_s(stu_name, "student", 20);
	strncpy_s(stu_id, "0", 20);
	stu_sex = 0;
	strncpy_s(stu_telephone, "10086", 10);
	Date();
	strncpy_s(stu_number, "1619001", 20);
	strncpy_s(stu_address, "address", 20);
	Dormitory();
	strncpy_s(stu_post, "none", 20);
	strncpy_s(stu_major, "CS", 10);
	next = NULL;
	previous = NULL;
}

//重载运算符

ostream& operator<<(ostream& out, student& p)
{
	
	out << p.stu_name;
	out << endl;
	if (p.stu_sex == 1)
		out << "male";
	else
		out << "female";
	out << endl;
	out << p.stu_id;
	out << endl;
	out << p.stu_telephone;
	out << endl;
	out << p.stu_birthday;
	out << endl;
	out << p.stu_number;
	out << endl;
	out << p.stu_address;
	out << endl;
	out << p.stu_dorm;
	out << endl;
	out << p.stu_post;
	out << endl;
	out << p.stu_major;
	out << endl;

	return out;
}


ostream& operator<<(ostream& out, student* p)
{
	out << p->stu_name;
	out << endl;
	if (p->stu_sex == 1)
		out << "male";
	else
		out << "female";
	out << endl;
	out << p->stu_id;
	out << endl;
	out << p->stu_telephone;
	out << endl;
	out << p->stu_birthday;
	out << endl;
	out << p->stu_number;
	out << endl;
	out << p->stu_address;
	out << endl;
	out << p->stu_dorm;
	out << endl;
	out << p->stu_post;
	out << endl;
	out << p->stu_major;
	out << endl;

	return out;
}

istream& operator>>(istream& in, student& p)
{
	in >> p.stu_name;
	in.get();
	in >> p.stu_sex;
	in.get();
	in >> p.stu_id;
	in.get();
	in >> p.stu_telephone;
	in.get();
	in >> p.stu_birthday;
	in.get();
	in >> p.stu_number;
	in.get();
	in >> p.stu_address;
	in.get();
	in >> p.stu_dorm;
	in.get();
	in >> p.stu_post;
	in.get();
	in >> p.stu_major;
	in.get();
	cout << "successfully input.";
	
	return in;
}

istream& operator>>(istream& in, student* p)
{
	in >> p->stu_name;
	in.get();
	in >> p->stu_sex;
	in.get();
	in >> p->stu_id;
	in.get();
	in >> p->stu_telephone;
	in.get();
	in >> p->stu_birthday;
	in.get();
	in >> p->stu_number;
	in.get();
	in >> p->stu_address;
	in.get();
	in >> p->stu_dorm;
	in.get();
	in >> p->stu_post;
	in.get();
	in >> p->stu_major;
	in.get();
	cout << "successfully input.";

	return in;
}

void student::operator=(student p)
{
	strncpy_s(this->stu_name, p.stu_name, 20);
	this->stu_sex = p.stu_sex;
	strncpy_s(this->stu_id, p.stu_id, 20);
	strncpy_s(this->stu_telephone, p.stu_telephone, 10);
	this->stu_birthday = p.stu_birthday;
	strncpy_s(this->stu_number, p.stu_number, 20);
	strncpy_s(this->stu_address, p.stu_address, 20);
	this->stu_dorm = p.stu_dorm;
	strncpy_s(this->stu_post, p.stu_post, 20);
	strncpy_s(this->stu_major, p.stu_major, 10);
}

//student类的总设置函数

void student::Set_Data()
{
	cout << "name:";
	cin >> stu_name;
	cout << "sex:";
	cin >> stu_sex;
	cout << "id:";
	cin >> stu_id;
	cin.ignore();
	cout << "telephone:";
	cin >> stu_telephone;
	cin.ignore();
	cout << "birthday:";
	cin >> stu_birthday;
	cout << "number:";
	cin >> stu_number;
	cin.ignore();
	cout << "address:";
	cin >> stu_address;
	cout << "dorm:";
	cin >> stu_dorm;
	cout << "post:";
	cin >> stu_post;
	cin.ignore();
	cout << "major:";
	cin >> stu_major;
}

//获取信息的函数

char* student::Get_Name()
{
	return stu_name;
}

bool student::Get_Sex()
{
	return this->stu_sex;
}

char* student::Get_Id()
{
	return this->stu_id;
}

char* student::Get_Telephone()
{
	return this->stu_telephone;
}

Date student::Get_Birthday()
{
	return this->stu_birthday;
}

char* student::Get_Number()
{
	return this->stu_number;
}

char* student::Get_Address()
{
	return this->stu_address;
}

Dormitory student::Get_Dorm()
{
	return this->stu_dorm;
}

char* student::Get_Post()
{
	return this->stu_post;
}

char* student::Get_Major()
{
	return this->stu_major;
}

//各项信息的设置函数

void student::Set_Name(char* name)
{
	cout << "name is setting...";
	strncpy_s(stu_name, name, 20);
	cout << "done." << endl;
}

void student::Set_Sex(bool sex)
{
	cout << "sex is setting...";
	stu_sex = sex;
	cout << "done." << endl;
}

void student::Set_Id(char* id)
{
	cout << "id is setting...";
	strncpy_s(stu_id,id,20);
	cout << "done." << endl;
}

void student::Set_Number(char* number)
{
	cout << "number is setting...";
	strncpy_s(stu_number, number, 20);
	cout << "done." << endl;
}

void student::Set_Address(char* address)
{
	cout << "address is setting...";
	strncpy_s(stu_address, address, 20);
	cout << "done." << endl;
}

void student::Set_Telephone(char* telephone)
{
	cout << "telephone is setting...";
	strncpy_s(stu_telephone, telephone, 12);
	cout << "done." << endl;
}

void student::Set_Birthday(Date& birthday)
{
	cout << "birthday is setting...";
	stu_birthday = birthday;
	cout << "done." << endl;
}

void student::Set_Dorm(Dormitory& dorm)
{
	cout << "dorm is setting...";
	stu_dorm = dorm;
	cout << "done." << endl;
}

void student::Set_Post(char* post)
{
	cout << "post is setting...";
	strncpy_s(stu_post, post, 20);
	cout << "done." << endl;
}

void student::Set_Major(char* major)
{
	cout << "major is setting...";
	strncpy_s(stu_major, major, 12);
	cout << "done." << endl;
}

void student::Output_Info()
{
	cout << "|";
	cout.width(22);
	cout << stu_name;
	cout << "|";
	cout.width(8);
	if (stu_sex == 1)
		cout << "male";
	else
		cout << "female";
	cout << "|";
	cout.width(20);
	cout << stu_id;
	cout << "|";
	cout.width(15);
	cout << stu_telephone;
	cout << "|";
	cout.width(11);
	cout << stu_birthday;
	cout << "|";
	cout.width(22);
	cout << stu_number;
	cout << "|";
	cout.width(25);
	cout << stu_address;
	cout << "|";
	cout.width(11);
	cout << stu_dorm;
	cout << "|";
	cout.width(22);
	cout << stu_post;
	cout << "|";
	cout.width(14);
	cout << stu_major;
	cout << "|";

	cout << endl;
}

void student::Input_Info()
{
	cout << "name:";
	cin >> stu_name;
	cout << "sex:";
	cin >> stu_sex;
	cout << "id:";
	cin >> stu_id;
	cin.ignore(1, '\n');
	cout << "telephone:";
	cin >> stu_telephone;
	cin.ignore(1, '\n');
	cout << "birthday:";
	cin >> stu_birthday;
	cout << "number:";
	cin >> stu_number;
	cin.ignore(1, '\n');
	cout << "address:";
	cin >> stu_address;
	cout << "dorm:";
	cin >> stu_dorm;
	cout << "post:";
	cin >> stu_post;
	cin.ignore(1, '\n');
	cout << "major:";
	cin >> stu_major;
	return;
}