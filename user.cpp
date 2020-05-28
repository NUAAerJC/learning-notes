//user.cpp
#include"user.h"
#include<iostream>
#include<cstring>
#include<fstream>

//user class methods

using namespace std;

user::user()
{
	strncpy_s(u_name, "user", 20);
	strncpy_s(u_password, "password", 20);
	log_status = 0;
	prev = NULL;
	next = NULL;
}

ostream& operator<<(ostream& out, user& account)
{
	out << account.u_name;
	out << endl;
	out << account.u_password;
	out << endl;
	out << account.log_status;
	out << endl;
	return out;
}

istream& operator>>(istream& in, user& account)
{
	in >> account.u_name;
	in.get();
	in >> account.u_password;
	in.get();
	in >> account.log_status;
	in.get();
	return in;
}

ostream& operator<<(ostream& out, user* account)
{
	out << account->u_name;
	out << endl;
	out << account->u_password;
	out << endl;
	out << account->log_status;
	out << endl;
	return out;
}

istream& operator>>(istream& in, user* account)
{
	in >> account->u_name;
	in.get();
	in >> account->u_password;
	in.get();
	in >> account->log_status;
	in.get();
	return in;
}

void user::operator=(user& account)
{
	strncpy_s(u_name, account.u_name, 20);
	strncpy_s(u_password, account.u_password, 20);
	log_status = account.log_status;
}

void user::operator=(user* account)
{
	strncpy_s(u_name, account->u_name, 20);
	strncpy_s(u_password, account->u_password, 20);
	log_status = account->log_status;
}

void user::Output_Info()
{
	cout << '|';
	cout.width(25);
	cout << u_name;
	cout << '|';
	cout.width(25);
	cout << u_password;
	cout << '|';
	cout.width(5);
	cout << log_status;
	cout << '|';
	cout << endl;
}

void user::Input_Info()
{
	cout << "name:";
	cin.getline(u_name, 20);
	cout << "password:";
	cin.getline(u_password, 20);
	cout << "status:";
	cin >> log_status;
	cin.get();
}

char* user::Get_Name()
{
	return u_name;
}

char* user::Get_Password()
{
	return u_password;
}

bool user::Get_Status()
{
	return log_status;
}

void user::Set_Name(char* name)
{
	cout << "正在设置名字...";
	cout << endl;
	strncpy_s(u_name, name, 20);
	cout << "设置完成";
	cout << endl;
}

void user::Set_Password(char* password)
{
	cout << "正在设置密码...";
	cout << endl;
	strncpy_s(u_password, password, 20);
	cout << "设置完成";
	cout << endl;
}

void user::Set_Status(bool status)
{
	cout << "正在设置登录状态...";
	cout << endl;
	log_status = status;
	cout << "设置完成";
	cout << endl;
}