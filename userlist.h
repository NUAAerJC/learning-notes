#pragma once
#ifndef USERLIST_H_
#define USERLIST_H_
#include"user.h"

class userlist
{
private:
	user* start;//链表头节点
	user* end;//链表尾节点
	unsigned u_cnt;//链表总节数
	bool The_Right;//最高权限，当被设置为1时才可以执行删除增添用户等一些高级操作
								//为0时只能执行登录操作
	char verification_code[11];//10位验证码，只有在验证通过后才能开启最高权限
public:
	userlist();//userlist 类的构造函数
	void Set_Data();//设置链表节数
	void Set_Info_u(user*);//设置链表中指定某一节的信息
	void Set_Info_c(unsigned);//设定链表中指定某一节的信息
	void Add_User();//在链表尾部添加一节链表（不设置信息）
	void Insert_In_u(user*);//在指定链表节数的后面插入一节链表（不设置信息）
	void Insert_In_c(unsigned);//在指定节数的位置插入一节链表（不设置信息）
	void Display_All();//显示所有的用户名和相对应的密码
	user* Find_Cnt(unsigned);//找到参数对应的链表节数，显示该节的详细信息,并返回该节链表
	unsigned Find_Name(char*);//根据名字找到对应的链节，显示该节的详细信息并返回该节的节数
	unsigned Find_Password(char*);//根据密码找到对应的链节（可能不止一个），显示详细信息和该节的节数,并根据用户选择返回相应的节数
	void Delete_All();//清空链表
	void Write_Into_File();//写入文件
	void Read_From_File();//从文件中读出链表
	void Modify(unsigned);//修改某一节的信息
	void Modify_Name(user*);//修改某一节的用户名
	void Modify_Password(user*);//修改某一节的密码
	void Remove(user*);//移除某一节
	void Set_The_Right(bool);//接收Verify_Code函数返回值并将其作为参数，以此确定是否设置最高权限（可以开启也可以关闭）
	void Set_Code(char*);//设置验证码
	bool Verify_Code(char*);//验证验证码的函数，若验证成功则返回1，否则反之
	user* Log_In();//登录函数
	void Log_Out(user*);//退出函数
	bool Get_Right() { return The_Right; }
	unsigned Get_Cnt() { return u_cnt; }
};

#endif