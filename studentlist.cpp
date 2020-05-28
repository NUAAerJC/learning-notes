//studentlist.cpp
#include<iostream>
#include"student_info.h"
#include<cstring>
#include<string>
#include<fstream>
#include"studentlist.h"
using namespace std;
//class studentlist methods

studentlist::studentlist()
{
	//链表表头表尾初始化

	start = new student;
	end = new student;

	start->previous = NULL;
	start->next = end;
	
	end->previous = start;
	end->next = NULL;

	//0个链表节点

	cnt = 0;

	//我打算将每个链表的头节点的相关数据成员（仅针对C风格字符串）设置为其名称（以制成表头），以方便在输出时成表格式输出

	char s_name[20] = "name";
	start->Set_Name(s_name);
	bool s_sex = 0;
	start->Set_Sex(s_sex);
	char s_id[20] = "ID";
	start->Set_Id(s_id);
	char s_telephone[12] = "telephone";
	start->Set_Telephone(s_telephone);
	Date s_birthday;
	start->Set_Birthday(s_birthday);
	char s_number[20] = "number";
	start->Set_Number(s_number);
	char s_address[20] = "address";
	start->Set_Address(s_address);
	Dormitory s_dorm;
	start->Set_Dorm(s_dorm);
	char s_post[20] = "post";
	start->Set_Post(s_post);
	char s_major[10] = "major";
	start->Set_Major(s_major);

	//然后再将链表的表尾处每个数据成员初始化为“end”以表示表格的结束位置

	char e_name[20] = "end";
	end->Set_Name(e_name);

	bool e_sex = 0;
	end->Set_Sex(e_sex);

	char e_id[20] = "end";
	end->Set_Id(e_id);

	char e_telephone[12] = "end";
	end->Set_Telephone(e_telephone);

	Date e_birthday;
	end->Set_Birthday(e_birthday);

	char e_number[20] = "end";
	end->Set_Number(e_number);

	char e_address[20] = "end";
	end->Set_Address(e_address);

	Dormitory e_dorm;
	end->Set_Dorm(e_dorm);

	char e_post[20] = "end";
	end->Set_Post(e_post);

	char e_major[10] = "end";
	end->Set_Major(e_major);
}

//（重新）设置链表节点数

void studentlist::Set_Data()
{
	cnt = 0;
	student* p = start;
	for (; p->next != NULL; p = p->next)
	{
		cnt += 1;
	}
	cnt -= 1;
}

//添加学生(添加至链表尾部)

void studentlist::Add_Stu()
{

	//先在链表尾部插入一个节点

	student* stu = new student, * p;
	p = end;
	p = p->previous;
	p->next = stu;
	stu->previous = p;
	stu->next = end;
	end->previous = stu;

	cnt += 1;
}

void studentlist::Set_Info_s(student* stu)
{
	
	//再给该节点设置信息
	
	char name[20];
	cout << "name:";
	cin.getline(name, 20);
	stu->Set_Name(name);

	bool sex;
	cout << "sex:";
	cin >> sex;
	stu->Set_Sex(sex);

	cin.ignore(1, '\n');
	char id[20];
	cout << "id:";
	cin.getline(id, 20);
	stu->Set_Id(id);

	char telephone[12];
	cout << "telephone:";
	cin.getline(telephone, 12);
	stu->Set_Telephone(telephone);

	Date birthday;
	cout << "birthday:";
	cin >> birthday;
	stu->Set_Birthday(birthday);

	cin.ignore(1, '\n');
	char number[20];
	cout << "number:";
	cin.getline(number, 20);
	stu->Set_Number(number);

	char address[20];
	cout << "address:";
	cin.getline(address, 20);
	stu->Set_Address(address);

	Dormitory dorm;
	cout << "dorm:";
	cin >> dorm;
	stu->Set_Dorm(dorm);

	cin.ignore();
	char post[20];
	cout << "post:";
	cin.getline(post, 20);
	stu->Set_Post(post);

	char major[20];
	cout << "major:";
	cin.getline(major, 20);
	stu->Set_Major(major);
}

void studentlist::Set_Info_c(unsigned n)
{
	unsigned i;
	student* p;
	p = start;
	for (i = 0; i < n; i++)
	{
		p = p->next;
	}
	
	char name[20];
	cout << "name:";
	cin.getline(name, 20);
	p->Set_Name(name);

	bool sex;
	cout << "sex:";
	cin >> sex;
	p->Set_Sex(sex);

	cin.ignore(1, '\n');
	char id[20];
	cout << "id:";
	cin.getline(id, 20);
	p->Set_Id(id);

	char telephone[12];
	cout << "telephone:";
	cin.getline(telephone, 12);
	p->Set_Telephone(telephone);

	Date birthday;
	cout << "birthday:";
	cin >> birthday;
	p->Set_Birthday(birthday);

	cin.ignore(1, '\n');
	char number[20];
	cout << "number:";
	cin.getline(number, 20);
	p->Set_Number(number);

	char address[20];
	cout << "address:";
	cin.getline(address, 20);
	p->Set_Address(address);

	Dormitory dorm;
	cout << "dorm:";
	cin >> dorm;
	p->Set_Dorm(dorm);

	cin.ignore();
	char post[20];
	cout << "post:";
	cin.getline(post, 20);
	p->Set_Post(post);

	char major[20];
	cout << "major:";
	cin.getline(major, 20);
	p->Set_Major(major);
}

void studentlist::Insert_In_s(student* p)
{
	student* stu,* ap;
	stu = new student;
	stu->previous = p;
	ap = p->next;
	stu->next = ap;
	ap->previous = stu;
	cnt += 1;
}

void studentlist::Insert_In_c(unsigned n)
{
	unsigned count;
	student* p,* ap,* bp,* stu;
	stu = new student;
	p = start;
	for (count = 0; count < n - 1; count++)
	{
		p = p->next;
	}
	ap = p;
	bp = ap->next;

	ap->next = stu;
	bp->previous = stu;

	stu->previous = ap;
	stu->next = bp;

	cnt += 1;
}

void studentlist::Display_All()
{
	student* p;
	p = start;
	cout.fill('-');
	cout.width(84);
	cout.setf(ios_base::right, ios_base::adjustfield);
	cout << "NUAA";
	cout.width(96);
	cout.setf(ios_base::left, ios_base::adjustfield);
	cout << "所有学生学籍信息" << endl;
	cout.fill(' ');
	for (; p->next != NULL; p = p->next)
	{
		p->Output_Info();
	}
	cout.fill('-');
	cout.width(180);
	cout << '-';
	cout.fill(' ');
}

//精准查找

//按链节数查找

student* studentlist::Find_Cnt_p(unsigned n)
{
	if (cnt != 0)
	{
		student* p;
		p = start;
		unsigned i;
		for (i = 0; i < cnt; i++)
		{
			p = p->next;
		}
		start->Output_Info();
		p->Output_Info();
		end->Output_Info();
		return p;
	}
	else
	{
		cout << "该链表中无学生，无法执行该项操作!" << endl;
		return start;
	}
}

//按名字查找

unsigned studentlist::Find_Name_p(char* wanted_name)
{
	if (cnt != 0)
	{
		char name[20];
		unsigned* candidate;
		unsigned i = 0, j, count = 0, limit;
		student* p;
		bool status = 0;
		p = start;
		candidate = new unsigned[cnt];
		candidate = { 0 };
		if (strlen(wanted_name) < 20)
			limit = strlen(wanted_name);
		else
			limit = 20;

		cout << '0';
		start->Output_Info();
		for (; p->next != NULL; p = p->next)
		{
			i += 1;
			strncpy_s(name, p->Get_Name(), 20);
			if (strlen(wanted_name) == strlen(name))
			{
				for (j = 0; j < limit; j++)
				{
					if (*(wanted_name + j) == *(name + j))
						status = 1;
					else
					{
						status = 0;
						break;
					}
				}
			}
			else
				status = 0;
			if (status == 1)
			{
				count += 1;
				cout << count;
				p->Output_Info();
				*(candidate + count - 1) = i;
			}
			else
				continue;
		}
		end->Output_Info();
		cout << "请输入学生信息前的序号以返回该学生的节点数";
		unsigned choice;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "该链表中无学生，无法执行该项操作!" << endl;
		return 0;
	}
}

//按照性别查找

unsigned studentlist::Find_Sex_p(bool wanted_sex)
{
	if (cnt != 0)
	{
		student* p;
		p = start->next;
		unsigned* candidate;
		unsigned i=0,count = 0;
		candidate = new unsigned[cnt];
		candidate = { 0 };
		cout << '0';
		start->Output_Info();
		for (; p->next != NULL; p = p->next)
		{
			i += 1;
			if (p->Get_Sex() == wanted_sex)
			{
				count += 1;
				cout << count;
				p->Output_Info();
				*(candidate + count-1) = i;
			}
			else
				continue;
		}
		cout << count;
		end->Output_Info();
		cout << "请输入学生前的序列号以返回该学生的链表节数!" << endl;
		unsigned choice;
		cin >> choice;
		return *(candidate + choice - 1);
	}
	else
		cout << "该链表中无学生，无法执行该项操作!" << endl;
	return 0;
}

//按照ID查找

unsigned studentlist::Find_Id_p(char* wanted_id)
{
	if (cnt != 0)
	{
		char id[20];
		unsigned* candidate;
		unsigned i = 0, j, count = 0, limit;
		student* p;
		bool status = 0;
		p = start;
		candidate = new unsigned[cnt];
		candidate = { 0 };
		if (strlen(wanted_id) < 20)
			limit = strlen(wanted_id);
		else
			limit = 20;

		cout << '0';
		start->Output_Info();
		for (; p->next != NULL; p = p->next)
		{
			i += 1;
			strncpy_s(id, p->Get_Id(), 20);
			if (strlen(wanted_id) == strlen(id))
			{
				for (j = 0; j < limit; j++)
				{
					if (*(wanted_id + j) == *(id + j))
						status = 1;
					else
					{
						status = 0;
						break;
					}
				}
			}
			else
				status = 0;
			if (status == 1)
			{
				count += 1;
				cout << count;
				p->Output_Info();
				*(candidate + count - 1) = i;
			}
			else
				continue;
		}
		end->Output_Info();
		cout << "请输入学生信息前的序号以返回该学生的节点数";
		unsigned choice;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "该链表中无学生，无法执行该项操作!" << endl;
		return 0;
	}
}

//按照学号查找

unsigned studentlist::Find_Number_p(char* wanted_number)
{
	if (cnt != 0)
	{
		char number[20];
		unsigned* candidate;
		unsigned i = 0, j, count = 0, limit;
		student* p;
		bool status = 0;
		p = start;
		candidate = new unsigned[cnt];
		candidate = { 0 };
		if (strlen(wanted_number) < 20)
			limit = strlen(wanted_number);
		else
			limit = 20;

		cout << '0';
		start->Output_Info();
		for (; p->next != NULL; p = p->next)
		{
			i += 1;
			strncpy_s(number, p->Get_Number(), 20);
			if (strlen(wanted_number) == strlen(number))
			{
				for (j = 0; j < limit; j++)
				{
					if (*(wanted_number + j) == *(number + j))
						status = 1;
					else
					{
						status = 0;
						break;
					}
				}
			}
			else
				status = 0;
			if (status == 1)
			{
				count += 1;
				cout << count;
				p->Output_Info();
				*(candidate + count - 1) = i;
			}
			else
				continue;
		}
		end->Output_Info();
		cout << "请输入学生信息前的序号以返回该学生的节点数";
		unsigned choice;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "该链表中无学生，无法执行该项操作!" << endl;
		return 0;
	}
}

//按照电话查找

unsigned studentlist::Find_Telephone_p(char* wanted_telephone)
{
	if (cnt != 0)
	{
		char telephone[20];
		unsigned* candidate;
		unsigned i = 0, j, count = 0, limit;
		student* p;
		bool status = 0;
		p = start;
		candidate = new unsigned[cnt];
		candidate = { 0 };
		if (strlen(wanted_telephone) < 20)
			limit = strlen(wanted_telephone);
		else
			limit = 20;

		cout << '0';
		start->Output_Info();
		for (; p->next != NULL; p = p->next)
		{
			i += 1;
			strncpy_s(telephone, p->Get_Telephone(), 20);
			if (strlen(wanted_telephone) == strlen(telephone))
			{
				for (j = 0; j < limit; j++)
				{
					if (*(wanted_telephone + j) == *(telephone + j))
						status = 1;
					else
					{
						status = 0;
						break;
					}
				}
			}
			else
				status = 0;
			if (status == 1)
			{
				count += 1;
				cout << count;
				p->Output_Info();
				*(candidate + count - 1) = i;
			}
			else
				continue;
		}
		end->Output_Info();
		cout << "请输入学生信息前的序号以返回该学生的节点数";
		unsigned choice;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "该链表中无学生，无法执行该项操作!" << endl;
		return 0;
	}
}

//按照专业查找

unsigned studentlist::Find_Major_p(char* wanted_major)
{
	if (cnt != 0)
	{
		char major[20];
		unsigned* candidate;
		unsigned i = 0, j, count = 0, limit;
		student* p;
		bool status = 0;
		p = start;
		candidate = new unsigned[cnt];
		if (strlen(wanted_major) < 20)
			limit = strlen(wanted_major);
		else
			limit = 20;

		cout << '0';
		start->Output_Info();
		for (; p->next != NULL; p = p->next)
		{
			i += 1;
			strncpy_s(major, p->Get_Major(), 20);
			if (strlen(wanted_major) == strlen(major))
			{
				for (j = 0; j < limit; j++)
				{
					if (*(wanted_major + j) == *(major + j))
						status = 1;
					else
					{
						status = 0;
						break;
					}
				}
			}
			else
				status = 0;
			if (status == 1)
			{
				count += 1;
				cout << count;
				p->Output_Info();
				*(candidate + count - 1) = i;
			}
			else
				continue;
		}
		end->Output_Info();
		cout << "请输入学生信息前的序号以返回该学生的节点数";
		unsigned choice;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "该链表中无学生，无法执行该项操作!" << endl;
		return 0;
	}
}

//模糊查找

//按名字查找

unsigned studentlist::Find_Name_ip(char* wanted_name)
{
	if (cnt != 0)
	{
		char name[20];
		unsigned* candidate;
		unsigned i = 0, j, count = 0, limit;
		student* p;
		bool status = 0;
		p = start;
		candidate = new unsigned[cnt];
		if (strlen(wanted_name) < 20)
			limit = strlen(wanted_name);
		else
			limit = 20;

		cout << '0';
		start->Output_Info();
		for (; p->next != NULL; p = p->next)
		{
			i += 1;
			strncpy_s(name, p->Get_Name(), 20);
			for (j = 0; j < limit; j++)
			{
				if (*(wanted_name + j) == *(name + j))
					status = 1;
				else
				{
					status = 0;
					break;
				}
			}
			if (status == 1)
			{
				count += 1;
				cout << count;
				p->Output_Info();
				*(candidate + count - 1) = i;
			}
			else
				continue;
		}
		end->Output_Info();
		cout << "请输入学生信息前的序号以返回该学生的节点数";
		unsigned choice;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "该链表中无学生，无法执行该项操作!" << endl;
		return 0;
	}
}

unsigned studentlist::Find_Number_ip(char* wanted_number)
{
	if (cnt != 0)
	{
		char number[20];
		unsigned* candidate;
		unsigned i = 0, j, count = 0, limit;
		student* p;
		bool status = 0;
		p = start;
		candidate = new unsigned[cnt];
		if (strlen(wanted_number) < 20)
			limit = strlen(wanted_number);
		else
			limit = 20;

		cout << '0';
		start->Output_Info();
		for (; p->next != NULL; p = p->next)
		{
			i += 1;
			strncpy_s(number, p->Get_Number(), 20);
			for (j = 0; j < limit; j++)
			{
				if (*(wanted_number + j) == *(number + j))
					status = 1;
				else
				{
					status = 0;
					break;
				}
			}
			if (status == 1)
			{
				count += 1;
				cout << count;
				p->Output_Info();
				*(candidate + count - 1) = i;
			}
			else
				continue;
		}
		end->Output_Info();
		cout << "请输入学生信息前的序号以返回该学生的节点数";
		unsigned choice;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "该链表中无学生，无法执行该项操作!" << endl;
		return 0;
	}
}

unsigned studentlist::Find_Id_ip(char* wanted_id)
{
	if (cnt != 0)
	{
		char id[20];
		unsigned* candidate;
		unsigned i = 0, j, count = 0, limit;
		student* p;
		bool status = 0;
		p = start;
		candidate = new unsigned[cnt];
		if (strlen(wanted_id) < 20)
			limit = strlen(wanted_id);
		else
			limit = 20;

		cout << '0';
		start->Output_Info();
		for (; p->next != NULL; p = p->next)
		{
			i += 1;
			strncpy_s(id, p->Get_Id(), 20);
			for (j = 0; j < limit; j++)
			{
				if (*(wanted_id + j) == *(id + j))
					status = 1;
				else
				{
					status = 0;
					break;
				}
			}
			if (status == 1)
			{
				count += 1;
				cout << count;
				p->Output_Info();
				*(candidate + count - 1) = i;
			}
			else
				continue;
		}
		end->Output_Info();
		cout << "请输入学生信息前的序号以返回该学生的节点数";
		unsigned choice;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "该链表中无学生，无法执行该项操作!" << endl;
		return 0;
	}
}

unsigned studentlist::Find_Telephone_ip(char* wanted_telephone)
{
	if (cnt != 0)
	{
		char telephone[12];
		unsigned* candidate;
		unsigned i = 0, j, count = 0, limit;
		student* p;
		bool status = 0;
		p = start;
		candidate = new unsigned[cnt];
		if (strlen(wanted_telephone) < 12)
			limit = strlen(wanted_telephone);
		else
			limit = 12;

		cout << '0';
		start->Output_Info();
		for (; p->next != NULL; p = p->next)
		{
			i += 1;
			strncpy_s(telephone, p->Get_Telephone(), 12);
			for (j = 0; j < limit; j++)
			{
				if (*(wanted_telephone + j) == *(telephone + j))
					status = 1;
				else
				{
					status = 0;
					break;
				}
			}
			if (status == 1)
			{
				count += 1;
				cout << count;
				p->Output_Info();
				*(candidate + count - 1) = i;
			}
			else
				continue;
		}
		end->Output_Info();
		cout << "请输入学生信息前的序号以返回该学生的节点数";
		unsigned choice;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "该链表中无学生，无法执行该项操作!" << endl;
		return 0;
	}
}

unsigned studentlist::Find_Major_ip(char* wanted_major)
{
	if (cnt != 0)
	{
		char major[20];
		unsigned* candidate;
		unsigned i = 0, j, count = 0, limit;
		student* p;
		bool status = 0;
		p = start;
		candidate = new unsigned[cnt];
		if (strlen(wanted_major) < 10)
			limit = strlen(wanted_major);
		else
			limit = 10;

		cout << '0';
		start->Output_Info();
		for (; p->next != NULL; p = p->next)
		{
			i += 1;
			strncpy_s(major, p->Get_Major(), 10);
			for (j = 0; j < limit; j++)
			{
				if (*(wanted_major + j) == *(major + j))
					status = 1;
				else
				{
					status = 0;
					break;
				}
			}
			if (status == 1)
			{
				count += 1;
				cout << count;
				p->Output_Info();
				*(candidate + count - 1) = i;
			}
			else
				continue;
		}
		end->Output_Info();
		cout << "请输入学生信息前的序号以返回该学生的节点数";
		unsigned choice;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "该链表中无学生，无法执行该项操作!" << endl;
		return 0;
	}
}

//清空函数

void studentlist::Delete_All()
{
	start->next = end;
	end->previous = start;
	cnt = 0;
}

//写入文件的函数

void studentlist::Write_Into_File()
{
	string new_file;
	cout << "请输入要保存的文件名：";
	cin >> new_file;
	fstream file;
	file.open(new_file.c_str(), ios::out);
	if (file.bad())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Set_Data();
	file << cnt << endl;
	student* pHead = start;
	while (pHead != NULL)
	{
		file << pHead->Get_Name() << endl;
		file << pHead->Get_Sex() << endl;
		file << pHead->Get_Id() << endl;
		file << pHead->Get_Telephone() << endl;
		file << pHead->Get_Birthday().Get_Year()
			<< '-' << pHead->Get_Birthday().Get_Month()
			<< '-' << pHead->Get_Birthday().Get_Day()
			<< endl;
		file << pHead->Get_Number() << endl;
		file << pHead->Get_Address() << endl;
		file << pHead->Get_Dorm().Get_Building()
			<< '-' << pHead->Get_Dorm().Get_Floor()
			<< '-' << pHead->Get_Dorm().Get_Room()
			<< endl;
		file << pHead->Get_Post() << endl;
		file << pHead->Get_Major() << endl;
		pHead = pHead->next;
	}
	file.close();
	cout << "保存成功！" << endl;
	return;
}

//从文件读出的函数

void studentlist::Read_From_File()
{
	string new_file;
	cout << "请输入要读取的学生信息文件名：";
	cin >> new_file;
	cin.get();
	fstream file;
	file.open(new_file.c_str(), ios::in);
	if (file.bad())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	int len = 0, n_cnt = cnt;
	file >> len;
	while (!len)
	{
		cout << "文件数据异常！" << endl;
		return;
	}
	if (len > n_cnt)
	{
		for (int i = 0; i < len - n_cnt; i++)
		{
			Add_Stu();
		}
	}
	else if (len < n_cnt)
	{
		student* p = start;
		int i = 0;
		for (; i<len; p = p->next, i += 1)
			;
		p->next = end;
		end->previous = p;
	}
	student* pHead = start;
	len += 2;
	file.get();
	while (len--)
	{
		char name[20];
		file.getline(name, 20);
		pHead->Set_Name(name);
		bool sex;
		file >> sex;
		pHead->Set_Sex(sex);
		file.get();
		char id[20];
		file.getline(id, 20);
		pHead->Set_Id(id);
		char telephone[12];
		file.getline(telephone, 12);
		pHead->Set_Telephone(telephone);
		Date birthday;
		int temp;
		file >> temp;
		birthday.Set_Year(temp);
		file.get();
		file >> temp;
		birthday.Set_Month(temp);
		file.get();
		file >> temp;
		birthday.Set_Day(temp);
		file.get();
		pHead->Set_Birthday(birthday);
		char number[20];
		file.getline(number, 20);
		pHead->Set_Number(number);
		char address[20];
		file.getline(address, 20);
		pHead->Set_Address(address);
		Dormitory dorm;
		file >> temp;
		dorm.Set_Building(temp);
		file.get();
		file >> temp;
		dorm.Set_Floor(temp);
		file.get();
		file >> temp;
		dorm.Set_Room(temp);
		pHead->Set_Dorm(dorm);
		file.get();
		char post[20];
		file.getline(post, 20);
		pHead->Set_Post(post);
		char major[20];
		file.getline(major, 20);
		pHead->Set_Major(major);
		pHead = pHead->next;
	}
	file.close();
	cout << "文件读入成功！" << endl;
	return;
}

void studentlist::Modify(unsigned num)
{
	student* p;
	unsigned i = 0;
	for (p = start; i < num; p = p->next, i++)
		;
	start->Output_Info();
	p->Output_Info();
	cout << "你确定要修改该学生的信息吗？" << endl;
	cout << "1.Yes    0.No";
	bool choice_1;
	cin >> choice_1;
	if (choice_1)
	{
		short choice_2;
		do
		{
			cout << "你想改变该学生的哪项信息？" << endl;
			cout << "1.姓名    2.性别    3.id    4.电话" << endl;
			cout << "5.生日    6.学号    7.地址    8.宿舍" << endl;
			cout << "9.职务    10.专业    11.退出";
			cin >> choice_2;
			switch (choice_2)
			{
			case 1:Modify_Name(p);
				break;
			case 2:Modify_Sex(p);
				break;
			case 3:Modify_Id(p);
				break;
			case 4:Modify_Telephone(p);
				break;
			case 5:Modify_Birthday(p);
				break;
			case 6:Modify_Number(p);
				break;
			case 7:Modify_Address(p);
				break;
			case 8:Modify_Dorm(p);
				break;
			case 9:Modify_Post(p);
				break;
			case 10:Modify_Major(p);
				break;
			}
		} while (choice_2 != 11);
		cout << "现在该学生的信息是:" << endl;
		cout << start;
		cout << p;
	}
	else
		cout << "请选择正确的学生" << endl;
	return;
}

void studentlist::Modify_Name(student* p)
{
	char name[20];
	cout << "请输入新名字:";
	cin.getline(name, 20);
	bool choice;
	cout << endl;
	cout << "你确定将原名字" << p->Get_Name() << "替换成" << name << "吗？" << endl;
	cout << "0.否   1.是" << endl;
	cin >> choice;
	if (choice)
		p->Set_Name(name);
	else
	{
		cout << "输入了错误的名字还是不替换名字？" << endl;
		cout << "0.不准备替换    1.错误的名字" << endl;
		if (choice)
			Modify_Name(p);
	}
	return;
}

void studentlist::Modify_Sex(student* p)
{
	bool sex;
	cout << "请输入新性别:" << endl;
	cout << "1.男    0.女";
	cin >> sex;
	cout << endl;
	cout << "你确定将性别";
	if (p->Get_Sex())
		cout << "男";
	else if(!p->Get_Sex())
		cout << "女";
	cout << "替换为";
	if (sex)
		cout << "男";
	else if (!sex)
		cout << "女";
	cout << "?";
	cout << endl;
	bool choice;
	cout << "0.否    1.是";
	cin >> choice;
	if (choice)
		p->Set_Sex(sex);
	else if (!choice)
	{
		cout << "错误性别还是错误操作？";
		cout << endl;
		cout << "0.错误性别    1.错误操作";
		cin >> choice;
		if (!choice)
			Modify_Sex(p);
	}
	return;
}

void studentlist::Modify_Id(student* p)
{
	char id[20];
	cout << "请输入新id:";
	cin.getline(id, 20);
	bool choice;
	cout << "你确定要将原id";
	cout << p->Get_Id();
	cout << "替换为";
	cout << id;
	cout << "吗？" << endl;
	cout << "0.否 1.是";
	cin >> choice;
	if (choice)
		p->Set_Id(id);
	else if (!choice)
	{
		cout << "错误操作还是错误ID？";
		cout << endl;
		cout << "0.错误操作    1.错误id";
		cin >> choice;
		if (choice)
			Modify_Id(p);
	}
	return;
}

void studentlist::Modify_Telephone(student* p)
{
	char telephone[12];
	cout << "请输入新电话:";
	cin.getline(telephone, 12);
	bool choice;
	cout << "你确定要将原电话";
	cout << p->Get_Telephone();
	cout << "替换为";
	cout << telephone;
	cout << "吗？";
	cout << endl;
	cout << "0.否    1.是";
	cin >> choice;
	if (choice)
		p->Set_Telephone(telephone);
	else if (!choice)
	{
		cout << "错误操作还是错误电话？";
		cout << endl;
		cout << "0.错误操作    1.错误电话";
		cin >> choice;
		if (choice)
			Modify_Telephone(p);
	}
	return;
}

void studentlist::Modify_Birthday(student* p)
{
	Date birthday, o_birth;
	o_birth = p->Get_Birthday();
	cout << "请输入新的生日:";
	cin >> birthday;
	bool choice;
	cout << "你确定要将原生日";
	cout << o_birth;
	cout << "替换为";
	cout << birthday;
	cout << "吗？";
	cout << endl;
	cout << "0.否    1.是";
	cin >> choice;
	if (choice)
		p->Set_Birthday(birthday);
	else if (!choice)
	{
		cout << "错误操作还是错误生日?";
		cout << "0.错误操作    1.错误生日";
		cin >> choice;
		if (choice)
			Modify_Birthday(p);
	}
	return;
}

void studentlist::Modify_Number(student* p)
{
	char number[20];
	cout << "请输入新学号:";
	cin.getline(number, 20);
	bool choice;
	cout << "你确定要把原学号";
	cout << p->Get_Number();
	cout << "替换为";
	cout << number;
	cout << "吗？";
	cout << endl;
	cout << "0.否    1.是";
	cin >> choice;
	if (choice)
		p->Set_Number(number);
	else if (!choice)
	{
		cout << "错误操作还是错误学号?";
		cout << endl;
		cout << "0.错误操作    1.错误学号";
		cin >> choice;
		if (choice)
			Modify_Number(p);
	}
	return;
}

void studentlist::Modify_Address(student* p)
{
	char address[20];
	cout << "请输入新地址:";
	cin.getline(address, 20);
	bool choice;
	cout << "你确定要将原地址";
	cout << p->Get_Address();
	cout << "替换为";
	cout << address;
	cout << "吗？";
	cout << endl;
	cout << "0.否    1.是";
	cin >> choice;
	if (choice)
		p->Set_Address(address);
	else if (!choice)
	{
		cout << "错误操作还是错误地址？";
		cout << endl;
		cout << "0.错误操作    1.错误地址";
		cin >> choice;
		if (choice)
			Modify_Address(p);
	}
	return;
}

void studentlist::Modify_Dorm(student* p)
{
	Dormitory dorm,o_dorm;
	o_dorm = p->Get_Dorm();
	cout << "请输入新宿舍:";
	cin >> dorm;
	cout << "你确定要把原宿舍";
	cout << o_dorm;
	cout << "替换为";
	cout << dorm;
	cout << "吗？";
	cout << endl;
	cout << "0.否    1.是";
	bool choice;
	cin >> choice;
	if (choice)
		p->Set_Dorm(dorm);
	else if (!choice)
	{
		cout << "错误操作还是错误宿舍?";
		cout << endl;
		cout << "0.错误操作    1.错误宿舍";
		cin >> choice;
		if (choice)
			Modify_Dorm(p);
	}
	return;
}

void studentlist::Modify_Post(student* p)
{
	char post[20];
	cout << "请输入新职务:";
	cin.getline(post, 20);
	cout << "你确定将原职务";
	cout << p->Get_Post();
	cout << "替换为";
	cout << post;
	cout << "吗？";
	cout << endl;
	cout << "0.否    1.是";
	bool choice;
	cin >> choice;
	if (choice)
		p->Set_Post(post);
	else if (!choice)
	{
		cout << "错误操作还是错误职务?";
		cout << endl;
		cout << "0.错误操作    1.错误职务";
		cin >> choice;
		if (choice)
			Modify_Post(p);
	}
	return;
}

void studentlist::Modify_Major(student* p)
{
	char major[10];
	cout << "请输入新专业:";
	cin.getline(major, 10);
	cout << "你确定将原专业";
	cout << p->Get_Major();
	cout << "替换为";
	cout << major;
	cout << "吗？";
	cout << endl;
	cout << "0.否    1.是";
	bool choice;
	cin >> choice;
	if (choice)
		p->Set_Major(major);
	else if (!choice)
	{
		cout << "错误操作还是错误专业?";
		cout << endl;
		cout << "0.错误操作   1.错误专业";
		cin >> choice;
		if (choice)
			Modify_Major(p);
	}
	return;
}

void studentlist::Remove(student* p)
{
	student* before,* after;
	before = p->previous;
	after = p->next;
	before->next = after;
	after->previous = before;
	p->previous = NULL;
	p->next = NULL;
	cnt -= 1;
	return;
}