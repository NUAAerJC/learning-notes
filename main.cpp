//main.cpp
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include"student_info.h"
#include"user.h"
#include"studentlist.h"
#include"userlist.h"
using namespace std;
void menu();
void Delete_u(userlist& u);
void Modify_u(userlist& u);
void Query_u(userlist& u);
void Modify_s(studentlist& s);
void Query_s(studentlist& s);
void Delete_s(studentlist& s);
int main()
{
	studentlist stu_list;
	userlist user_list;
	system("cls");
	user_list.Read_From_File();
	system("cls");
	stu_list.Read_From_File();
	user* account;
	system("cls");
	do
	{
		account = user_list.Log_In();
	} while (account->Get_Status() == 0);

	do
	{
		char code[20];
		cout << "��������֤��:";
		cin >> code;
		user_list.Set_The_Right(user_list.Verify_Code(code));
	} while (user_list.Get_Right() == 0);

	menu();

	short choice;
	do
	{
		cout << "������ָ��ǰ�����:";
		cin >> choice;
		while (cin.fail())
		{
			cin.clear();
			while (!isspace(cin.get()))
			{
				continue;
			}
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
			system("cls");
			user_list.Add_User();
			user_list.Set_Info_c(user_list.Get_Cnt());
			break;
		case 2:
			system("cls");
			user_list.Display_All();
			break;
		case 3:
			system("cls");
			Delete_u(user_list);
			break;
		case 4:
			system("cls");
			Modify_u(user_list);
			break;
		case 5:
			system("cls");
			user_list.Delete_All();
			break;
		case 6:
			system("cls");
			Query_u(user_list);
			break;
		case 7:
			system("cls");
			stu_list.Add_Stu();
			stu_list.Set_Info_c(stu_list.Get_Cnt());
			break;
		case 8:
			system("cls");
			stu_list.Display_All();
			break;
		case 9:
			system("cls");
			Delete_s(stu_list);
			break;
		case 10:
			system("cls");
			Modify_s(stu_list);
			break;
		case 11:
			system("cls");
			stu_list.Delete_All();
			break;
		case 12:
			system("cls");
			Query_s(stu_list);
			break;
		case 0:
			system("cls");
			break;
		default:
			system("cls");
			cout << "��������ȷ��ѡ��!" << endl;
			menu();
			break;
		}
	} while (choice != 0);
	system("cls");
	user_list.Write_Into_File();
	system("cls");
	stu_list.Write_Into_File();
	return 0;
}

void menu()
{
	cout.fill('-');
	cout.width(51);
	cout << "-";
	cout << endl;
	cout << "|              ѧ��ѧ����Ϣ����ϵͳ             |\n";
	cout.width(51);
	cout << '-';
	cout << endl;
	cout << "| 1��ע���¹���Ա�˺�  |    7�������ѧ����Ϣ   |\n";
	cout << "|   2����ʾ����Ա�˺�    |  8����ʾѧ����Ϣ     |\n";
	cout << "|   3��ɾ������Ա�˺�    |  9��ɾ��ѧ����Ϣ     |\n";
	cout << "|   4���޸Ĺ���Ա�˺�    |  10���޸�ѧ����Ϣ    |\n";
	cout << "|   5���������Ա�˺�    |  11�����ѧ����Ϣ    |\n";
	cout << "|  6�����ҹ���Ա�˺�     |  12������ѧ����Ϣ    |\n";
	cout.width(51);
	cout << '-';
	cout << endl;
	cout << "|                     0���˳�                                                |\n";
	cout.width(51);
	cout << '-';
	cout << endl;
	cout.fill(' ');
}

void Delete_u(userlist& u)
{
	char name[20];
	unsigned n;
	cout << "������Ҫɾ�����˺�:";
	cin.getline(name, 20);
	n = u.Find_Name(name);
	u.Remove(u.Find_Cnt(n));
}

void Modify_u(userlist& u)
{
	char name[20];
	unsigned n;
	cout << "������Ҫ�޸ĵ��˺�:";
	cin.getline(name, 20);
	n = u.Find_Name(name);
	u.Modify(n);
}

void Query_u(userlist& u)
{
	cout << "��ѡ�������" << endl;
	short choice;
	cout << "1.�˻���    2.����" << endl;
	cin >> choice;
	if (choice == 1)
	{
		char name[20];
		cout << "����������:";
		cin.getline(name, 20);
		u.Find_Name(name);
	}
	else
	{
		char password[20];
		cout << "����������:";
		cin.getline(password, 20);
		u.Find_Password(password);
	}
}

void Modify_s(studentlist& s)
{
	char name[20];
	unsigned n;
	cout << "������Ҫ�޸ĵ�ѧ��������:";
	cin.getline(name, 20);
	n = s.Find_Name_p(name);
	s.Modify(n);
}

void Query_s(studentlist& s)
{
	cout << "��ѡ����ҷ��:";
	cout << "0.ģ������    1.��ȷ����";
	bool choice_1;
	cin >> choice_1;
	if (choice_1)
	{
		cout << "��ѡ�������:" << endl;
		cout << "1.�����ֲ���    2.��ѧ�Ų���    3.���Ա����    4.��id����    5.���绰����    6.��רҵ����" << endl;
		short choice_2;
		cin >> choice_2;
		switch (choice_2)
		{
		case 1:
			char name[20];
			cout << "����������:";
			cin.getline(name, 20);
			s.Find_Name_p(name);
			break;
		case 2:
			char number[20];
			cout << "������ѧ��:";
			cin.getline(number, 20);
			s.Find_Number_p(number);
			break;
		case 3:
			bool sex;
			cout << "�������Ա�:(1��ʾ�У�0��ʾŮ)";
			cin >> sex;
			s.Find_Sex_p(sex);
			break;
		case 4:
			char id[20];
			cout << "������id:";
			cin.getline(id, 20);
			s.Find_Id_p(id);
			break;
		case 5:
			char telephone[12];
			cout << "������绰:";
			cin.getline(telephone, 12);
			s.Find_Telephone_p(telephone);
			break;
		case 6:
			char major[10];
			cout << "������רҵ:";
			cin.getline(major, 10);
			s.Find_Major_p(major);
			break;
		}
	}
	else
	{
		cout << "��ѡ�������:" << endl;
		cout << "1.�����ֲ���    2.��ѧ�Ų���    3.��id����    4.���绰����    5.��רҵ����";
		short choice_2;
		cin >> choice_2;
		switch (choice_2)
		{
		case 1:
			char name[20];
			cout << "����������:";
			cin.getline(name, 20);
			s.Find_Name_ip(name);
			break;
		case 2:
			char number[20];
			cout << "������ѧ��:";
			cin.getline(number, 20);
			s.Find_Number_ip(number);
			break;
		case 3:
			char id[20];
			cout << "������id:";
			cin.getline(id, 20);
			s.Find_Id_ip(id);
			break;
		case 4:
			char telephone[12];
			cout << "������绰:";
			cin.getline(telephone, 12);
			s.Find_Telephone_ip(telephone);
			break;
		case 5:
			char major[10];
			cout << "������רҵ:";
			cin.getline(major, 12);
			s.Find_Major_ip(major);
			break;
		}
	}
}

void Delete_s(studentlist& s)
{
	char name[20];
	unsigned n;
	cout << "������Ҫɾ�����˺�:";
	cin.getline(name, 20);
	n = s.Find_Name_p(name);
	s.Remove(s.Find_Cnt_p(n));
}