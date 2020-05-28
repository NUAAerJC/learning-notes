//user.h
#pragma once
#include<iostream>
#ifndef USER_H
#define USER_H

using namespace std;

class user
{
public:
	user();
	friend ostream& operator<<(ostream& out,user& account);
	friend istream& operator>>(istream& in, user& account);
	friend ostream& operator<<(ostream& out, user* account);
	friend istream& operator>>(istream& in, user* account);
	void operator=(user& account);
	void operator=(user* account);
	void Output_Info();
	void Input_Info();
	char* Get_Name();
	char* Get_Password();
	bool Get_Status();
	void Set_Name(char*);
	void Set_Password(char*);
	void Set_Status(bool);
protected:
	char u_name[20];
	char u_password[20];
	bool log_status;//0表示未登录,1表示已登录
public:
	user* prev;
	user* next;
};

#endif