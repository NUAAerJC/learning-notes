//studentlist.h
#pragma once
#ifndef STUDENTLIST_H_
#define STUDENTLIST_H_
#include"student_info.h"
class studentlist
{
public:
	studentlist(); //studentlist 类的构造函数
	void Set_Data(); //studentlist 类的设置函数
	void Set_Info_s(student*);//为链表中某一节设定信息
	void Set_Info_c(unsigned);//为指定链节节数的链表设定信息
	void Add_Stu(); //添加函数(添加至链表尾部,不设置信息)
	void Insert_In_s(student*);//在指定链节的后面插入新链表（不设置信息）
	void Insert_In_c(unsigned);//在指定链节节数的位置插入新链表（不设置信息）
	void Display_All(); //显示函数(显示链表中所有学生的信息)
	//精确查找
	student* Find_Cnt_p(unsigned);//查找函数(通过链表节点数)，显示信息
	unsigned Find_Name_p(char*); //查找函数(通过名字),显示信息，并返回该学生在链表中的节点数
	unsigned Find_Sex_p(bool);//查找函数（通过性别），显示所有符合条件的学生信息，并根据选择返回被选择学生的节点数
	unsigned Find_Number_p(char*);//查找函数(通过学号),显示信息，并返回该学生在链表中的节点数
	unsigned Find_Id_p(char*);//查找函数(通过ID)，显示信息，并返回该学生在链表中的节点数
	unsigned Find_Telephone_p(char*);//查找函数(通过电话),显示信息，并返回该学生在链表中的节点数
	unsigned Find_Major_p(char*);//查找函数（通过所输入的专业），显示所有符合条件的学生信息，并根据选择返回被选择学生的节点数
	//模糊查找
	unsigned Find_Name_ip(char*);//查找函数（通过名字的前n个字符，n为参数字符串的长度），显示所有符合条件的学生信息，并根据选择返回被选择学生的节点数
	unsigned Find_Number_ip(char*);//查找函数（通过学号的前n个字符，n同上），显示所有符合条件的学生信息，并根据选择返回被选择学生的节点数
	unsigned Find_Id_ip(char*);//查找函数（通过id的前n个字符，n同上），显示所有符合条件的学生信息，并根据选择返回被选择学生的节点数
	unsigned Find_Telephone_ip(char*);//查找函数（通过id的前n个字符，n同上），显示所有符合条件的学生信息，并根据选择返回被选择学生的节点数
	unsigned Find_Major_ip(char*);//查找函数（根据所输入专业的前n个字符），显示所有符合条件的学生信息，并根据选择返回被选择学生的节点数
	void Delete_All(); //清空函数
	void Write_Into_File(); //写入文件的函数
	void Read_From_File(); //从文件读出的函数
	void Modify(unsigned); //修改函数
	void Modify_Name(student*);//修改名字
	void Modify_Sex(student*);//修改性别
	void Modify_Id(student*);//修改id
	void Modify_Telephone(student*);//修改电话
	void Modify_Birthday(student*);//修改生日
	void Modify_Number(student*);//修改学号
	void Modify_Address(student*);//修改地址
	void Modify_Dorm(student*);//修改宿舍
	void Modify_Post(student*);//修改职务
	void Modify_Major(student*);//修改专业
	void Remove(student*); //删除函数
	unsigned Get_Cnt() { return cnt; }
private:
	student* start; //链表头
	student* end; //链表尾
	unsigned cnt;//链表总节数（不算首尾的start与end）
};

#endif