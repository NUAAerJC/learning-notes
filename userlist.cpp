#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include"userlist.h"
#include"user.h"

using namespace std;

//userlist calss methods

userlist::userlist()
{
	//设立链表表头表尾

	start = new user;
	end = new user;

	start->prev = NULL;
	start->next = end;

	end->prev = start;
	end->next = NULL;

	//设置链表节点数

	u_cnt = 0;

	//设置最高权限状态

	The_Right = 0;

	//设置验证码

	strncpy_s(verification_code, "3141592653", 11);

	//链表表头初始化

	char username_1[20] = "name";
	start->Set_Name(username_1);

	char userpassword_1[20] = "password";
	start->Set_Password(userpassword_1);

	bool status_1 = 0;
	start->Set_Status(status_1);

	//链表表尾初始化

	char username_2[20] = "end";
	end->Set_Name(username_2);

	char userpassword_2[20] = "end";
	end->Set_Password(userpassword_2);

	bool status_2 = 0;
	end->Set_Status(status_2);
}

void userlist::Set_Data()
{
	if (The_Right)
	{
		u_cnt = 0;
		user* p = start->next;
		for (; p->next != NULL; p = p->next)
		{
			u_cnt += 1;
		}
		u_cnt -= 1;
	}
	else
		cout << "未开启最高权限，无法执行该项操作!" << endl;
	return;
}

void userlist::Set_Info_u(user* p)
{
	if (The_Right)
	{
		char name[20];
		cout << "name:";
		cin.getline(name, 20);
		p->Set_Name(name);

		char password[20];
		cout << "password:";
		cin.getline(password, 20);
		p->Set_Password(password);

		bool status = 0;
		p->Set_Status(status);
	}
	else
		cout << "未开启最高权限，无法执行该项操作!" << endl;
	return;
}

void userlist::Set_Info_c(unsigned n)
{
	if (The_Right)
	{
		user* p;
		p = start;
		unsigned count;

		for (count = 0; count < n; count++)
		{
			p = p->next;
		}

		char name[20];
		cout << "name:";
		cin.getline(name, 20);
		p->Set_Name(name);

		char password[20];
		cout << "password:";
		cin.getline(password, 20);
		p->Set_Password(password);

		bool status = 0;
		p->Set_Status(status);
	}
	else
		cout << "未开启最高权限，无法执行该项操作!" << endl;
	return;
}

void userlist::Set_Code(char* code)
{
	if (The_Right)
	{
		strncpy_s(verification_code, code, 11);
		cout << "已设置验证码!" << endl;
	}
	else
		cout << "未开启最高权限，无法执行该项操作!" << endl;
	return;
}

bool userlist::Verify_Code(char* code)
{
	bool status = 1;
	int i;
	
	for (i = 0; i < 10; i++)
	{
		if (verification_code[i] == *(code + i))
			continue;
		else
		{
			status = 0;
			break;
		}
	}
	
	if (status)
		cout << "验证成功!" << endl;
	else
		cout << "验证失败!" << endl;
	
	return status;
}

void userlist::Set_The_Right(bool status)
{
	bool choice;
	
	if (status)
	{
		cout << "你想执行哪一项操作？" << endl;
		cout << "0.关闭最高权限    1.开启最高权限" << endl;
		cin >> choice;
		
		if (choice)
		{
			The_Right = 1;
			cout << "已开启最高权限!" << endl;
		}
		else
		{
			The_Right = 0;
			cout << "已关闭最高权限!" << endl;
		}
	
	}
	
	else
		cout << "验证不成功，无法对最高权限状态进行修改!" << endl;

	return;
}

void userlist::Add_User()
{
	if (The_Right)
	{
		user* p, * np;

		np = new user;
		p = end;
		p = p->prev;

		p->next = np;

		np->prev = p;
		np->next = end;

		end->prev = np;

		u_cnt += 1;
	}
	else
		cout << "未开启最高权限，无法执行该项操作!" << endl;
	return;
}

void userlist::Insert_In_u(user* u)
{
	if (The_Right)
	{
		user* p, * nu;
		nu = u->next;
		p = new user;

		p->prev = u;
		p->next = nu;

		u->next = p;

		nu->prev = p;

		u_cnt += 1;
	}
	else
		cout << "未开启最高权限，无法执行该项操作!" << endl;
	return;
}

void userlist::Insert_In_c(unsigned n)
{
	if (The_Right)
	{
		user* p, * new_p, * next_p;
		p = start;
		unsigned count;
		for (count = 0; count < n - 1; count++)
		{
			p = p->next;
		}
		next_p = p->next;

		new_p = new user;

		p->next = new_p;
		next_p->prev = new_p;

		new_p->prev = p;
		new_p->next = next_p;

		u_cnt += 1;
	}
	else
		cout << "未开启最高权限，无法执行该项操作!" << endl;
	return;
}

void userlist::Display_All()
{
	if (The_Right)
	{
		user* p;
		p = start;
		cout.fill('-');
		cout.width(32);
		cout.setf(ios_base::right, ios_base::adjustfield);
		cout << "账号";
		cout.width(32);
		cout.setf(ios_base::left, ios_base::adjustfield);
		cout << "信息";
		cout << endl;
		cout.fill(' ');
		for (; p->next != NULL; p = p->next)
		{
			p->Output_Info();
		}
		cout.fill('-');
		cout.width(64);
		cout << '-';
	}
	else
		cout << "未开启最高权限，无法执行该项操作!" << endl;
	
	return;
}

user* userlist::Find_Cnt(unsigned n)
{
	if (The_Right)
	{
		unsigned i;
		user* p;
		p = start;
		for (i = 0; i < n; i++)
		{
			p = p->next;
		}
		start->Output_Info();
		p->Output_Info();
		return p;
	}
	else
	{
		cout << "未开启最高权限，无法执行该项操作!" << endl;
		return start;
	}
}

unsigned userlist::Find_Name(char* name)
{
	if (The_Right)
	{
		user* p;
		p = start;
		bool match = 0;
		unsigned i, j = 0;
		for (; p->next != NULL; p = p->next, j += 1)
		{
			for (i = 0; i < 20; i++)
			{
				if (*(name + i) == *(p->Get_Name() + i))
				{
					match = 1;
				}
				else
				{
					match = 0;
					break;
				}
			}
			if (match)
			{
				start->Output_Info();
				p->Output_Info();
				break;
			}
		}
		return j;
	}
	else
	{
		cout << "未开启最高权限，无法进行该项操作!" << endl;
		return 0;
	}
}

unsigned userlist::Find_Password(char* password)
{
	if (The_Right)
	{
		user* p;
		unsigned* candidate;
		unsigned i, j=0,count = 0;
		bool match = 0;
		candidate = new unsigned[u_cnt];
		p = start;
		cout << '|';
		cout << 0;
		start->Output_Info();
		for (; p->next != NULL; p = p->next,j += 1)
		{
			for (i = 0; i < 20; i++)
			{
				if (*(password + i) == *(p->Get_Password() + i))
				{
					match = 1;
				}
				else
				{
					match = 0;
					break;
				}
			}
			if (match)
			{
				count += 1;
				candidate[count - 1] = j;
				cout << count;
				p->Output_Info();
			}
		}
		cout << '|';
		cout << candidate;
		end->Output_Info();

		unsigned choice;
		cout << "你想返回第几位用户的链表序列号？" << endl;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "未开启最高权限，无法执行该项操作!" << endl;
		return 0;
	}
}

void userlist::Delete_All()
{
	if (The_Right)
	{
		start->next = end;
		end->prev = start;
		u_cnt = 0;
	}
	else
		cout << "未开启最高权限，无法执行该项操作!" << endl;
	return;
}

void	userlist::Write_Into_File()
{
	char code[11];
	
	while (true)
	{
		cout << "请设置新的验证码:" << endl;
		cin.getline(code, 11);
		cout << "你确定要将验证码设置为";
		cout << code;
		cout << "吗？" << endl;
		bool choice;
		cout << "0.否    1.是";
		cin >> choice;
		if (choice)
		{
			Set_Code(code);
			cout << "现在验证码为";
			cout << verification_code << endl;
			break;
		}
		else
		{
			cout << "请输入正确的验证码";
		}
	}
	
	string new_file;
	cout << "请输入要保存的文件名:";
	cin >> new_file;
	fstream file;
	file.open(new_file.c_str(), ios::out);
	if (file.bad())
	{
		cout << "打开文件失败!" << endl;
		return;
	}
	
	Set_Data();
	
	file << u_cnt << endl;
	file << verification_code << endl;
	
	user* p;
	p = start;
	
	while (p != NULL)
	{
		file << p->Get_Name() << endl;
		file << p->Get_Password() << endl;
		p = p->next;
	}
	
	file.close();
	cout << "保存成功!" << endl;
	
	return;
}

void userlist::Read_From_File()
{
	string new_file;
	cout << "请输入要读取的用户文件名:";
	cin >> new_file;
	cin.get();
	
	fstream file;
	file.open(new_file.c_str(), ios_base::in);
	if (file.bad())
	{
		cout << "文件打开失败!" << endl;
		return;
	}
	
	unsigned used_cnt;
	used_cnt = u_cnt;
	file >> u_cnt;
	
	if (used_cnt < u_cnt)
	{
		unsigned count;
		for (count = used_cnt; count < u_cnt; count += 1)
		{
			Add_User();
		}
	}
	else if (used_cnt > u_cnt)
	{
		user* p;
		p = start;
		unsigned count = 0;
		for (; count < u_cnt; count += 1)
		{
			p = p->next;
		}
		p->next = end;
		end->prev = p;
	}

	file.get();
	file >> verification_code;
	file.get();

	user* p;
	p = start;
	
	for (; p != NULL; p = p->next)
	{
		char name[20];
		file >> name;
		file.get();
		p->Set_Name(name);

		char password[20];
		file >> password;
		file.get();
		p->Set_Password(password);

		bool status = 0;
		p->Set_Status(status);
	}
	
	file.close();
	
	cout << "文件读取成功!" << endl;
	
	return;
}

void userlist::Modify(unsigned n)
{
	if (The_Right)
	{
		unsigned count;
		user* p;
		p = start;
		for (count = 0; count < n; count++)
		{
			p = p->next;
		}
		cout << "该账号的信息是:" << endl;
		start->Output_Info();
		p->Output_Info();
		cout << "你确定要改变该账号的信息吗？" << endl;
		cout << "0.No    1.Yes" << endl;
		bool choice_1;
		cin >> choice_1;
		if (choice_1)
		{
			short choice_2;
			do
			{
				cout << "你想改变该账号的哪项信息?" << endl;
				cout << "1.用户名    2.密码  3.退出" << endl;
				cin >> choice_2;
				if (choice_2 == 1)
				{
					Modify_Name(p);
				}
				else if (choice_2 == 2)
				{
					Modify_Password(p);
				}
			} while (choice_2 != 3);
		}
		else
		{
			cout << "请选择正确的账号!" << endl;
		}
	}
	else
		cout << "未开启最高权限，无法执行该项操作!" << endl;
	return;
}

void userlist::Modify_Name(user* p)
{
	char name[20];
	cout << "请输入新的用户名:";
	cin.getline(name, 20);
	cout << "你确定要将原用户名";
	cout << p->Get_Name();
	cout << "替换为";
	cout << name;
	cout << "吗？";
	cout << endl;
	bool choice;
	cout << "0.否    1.是";
	cin >> choice;
	cin.get();
	if (choice)
	{
		p->Set_Name(name);
	}
	else if (!choice)
	{
		cout << "错误名字还是不替换名字?" << endl;
		cout << "0.错误名字    1.不替换名字";
		cin >> choice;
		cin.get();
		if (!choice)
		{
			cout << "请输入正确的名字" << endl;
			Modify_Name(p);
		}
	}
	return;
}

void userlist::Modify_Password(user* p)
{
	char password[20];
	cout << "请输入新的密码:";
	cin.getline(password, 20);
	cout << "你确定要将原密码";
	cout << p->Get_Password();
	cout << "替换为";
	cout << password;
	cout << "吗？";
	cout << endl;
	bool choice;
	cout << "0.否    1.是";
	cin >> choice;
	cin.get();
	if (choice)
	{
		p->Set_Password(password);
	}
	else if (!choice)
	{
		cout << "错误密码还是不替换密码?" << endl;
		cout << "0.错误密码    1.不替换密码";
		cin >> choice;
		cin.get();
		if (!choice)
		{
			cout << "请输入正确的密码" << endl;
			Modify_Password(p);
		}
	}
	return;
}

void userlist::Remove(user* p)
{
	if (The_Right)
	{
		user* bp, * ap;

		bp = p->prev;
		ap = p->next;

		bp->next = ap;
		ap->prev = bp;

		p->prev = NULL;
		p->next = NULL;

		u_cnt -= 1;
	}
	else
		cout << "未开启最高权限，无法执行该项操作!" << endl;
	return;
}

user* userlist::Log_In()
{
	cout << "请登录!" << endl;
	cout << "name:";
	char name[20];
	char password[20];
	cin.getline(name, 20);
	cout << "password:";
	cin.getline(password, 20);
	user* p;
	p = start;
	for (; p->next != NULL; p = p->next)
	{
		if (strcmp(name,p->Get_Name()) == 0)
		{
			if (strcmp(password, p->Get_Password()) == 0)
			{
				p->Set_Status(true);
				cout << "登录成功!" << endl;
			}
			else
				cout << "登录失败!" << endl;
			break;
		}
	}
	return p;
}

void userlist::Log_Out(user* p)
{
	p->Set_Status(false);
	cout << "已退出该账号!" << endl;
	return;
}