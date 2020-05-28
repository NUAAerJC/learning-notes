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
	//���������ͷ��β

	start = new user;
	end = new user;

	start->prev = NULL;
	start->next = end;

	end->prev = start;
	end->next = NULL;

	//��������ڵ���

	u_cnt = 0;

	//�������Ȩ��״̬

	The_Right = 0;

	//������֤��

	strncpy_s(verification_code, "3141592653", 11);

	//�����ͷ��ʼ��

	char username_1[20] = "name";
	start->Set_Name(username_1);

	char userpassword_1[20] = "password";
	start->Set_Password(userpassword_1);

	bool status_1 = 0;
	start->Set_Status(status_1);

	//�����β��ʼ��

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
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
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
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
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
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
	return;
}

void userlist::Set_Code(char* code)
{
	if (The_Right)
	{
		strncpy_s(verification_code, code, 11);
		cout << "��������֤��!" << endl;
	}
	else
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
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
		cout << "��֤�ɹ�!" << endl;
	else
		cout << "��֤ʧ��!" << endl;
	
	return status;
}

void userlist::Set_The_Right(bool status)
{
	bool choice;
	
	if (status)
	{
		cout << "����ִ����һ�������" << endl;
		cout << "0.�ر����Ȩ��    1.�������Ȩ��" << endl;
		cin >> choice;
		
		if (choice)
		{
			The_Right = 1;
			cout << "�ѿ������Ȩ��!" << endl;
		}
		else
		{
			The_Right = 0;
			cout << "�ѹر����Ȩ��!" << endl;
		}
	
	}
	
	else
		cout << "��֤���ɹ����޷������Ȩ��״̬�����޸�!" << endl;

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
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
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
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
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
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
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
		cout << "�˺�";
		cout.width(32);
		cout.setf(ios_base::left, ios_base::adjustfield);
		cout << "��Ϣ";
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
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
	
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
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
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
		cout << "δ�������Ȩ�ޣ��޷����и������!" << endl;
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
		cout << "���뷵�صڼ�λ�û����������кţ�" << endl;
		cin >> choice;
		return candidate[choice - 1];
	}
	else
	{
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
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
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
	return;
}

void	userlist::Write_Into_File()
{
	char code[11];
	
	while (true)
	{
		cout << "�������µ���֤��:" << endl;
		cin.getline(code, 11);
		cout << "��ȷ��Ҫ����֤������Ϊ";
		cout << code;
		cout << "��" << endl;
		bool choice;
		cout << "0.��    1.��";
		cin >> choice;
		if (choice)
		{
			Set_Code(code);
			cout << "������֤��Ϊ";
			cout << verification_code << endl;
			break;
		}
		else
		{
			cout << "��������ȷ����֤��";
		}
	}
	
	string new_file;
	cout << "������Ҫ������ļ���:";
	cin >> new_file;
	fstream file;
	file.open(new_file.c_str(), ios::out);
	if (file.bad())
	{
		cout << "���ļ�ʧ��!" << endl;
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
	cout << "����ɹ�!" << endl;
	
	return;
}

void userlist::Read_From_File()
{
	string new_file;
	cout << "������Ҫ��ȡ���û��ļ���:";
	cin >> new_file;
	cin.get();
	
	fstream file;
	file.open(new_file.c_str(), ios_base::in);
	if (file.bad())
	{
		cout << "�ļ���ʧ��!" << endl;
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
	
	cout << "�ļ���ȡ�ɹ�!" << endl;
	
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
		cout << "���˺ŵ���Ϣ��:" << endl;
		start->Output_Info();
		p->Output_Info();
		cout << "��ȷ��Ҫ�ı���˺ŵ���Ϣ��" << endl;
		cout << "0.No    1.Yes" << endl;
		bool choice_1;
		cin >> choice_1;
		if (choice_1)
		{
			short choice_2;
			do
			{
				cout << "����ı���˺ŵ�������Ϣ?" << endl;
				cout << "1.�û���    2.����  3.�˳�" << endl;
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
			cout << "��ѡ����ȷ���˺�!" << endl;
		}
	}
	else
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
	return;
}

void userlist::Modify_Name(user* p)
{
	char name[20];
	cout << "�������µ��û���:";
	cin.getline(name, 20);
	cout << "��ȷ��Ҫ��ԭ�û���";
	cout << p->Get_Name();
	cout << "�滻Ϊ";
	cout << name;
	cout << "��";
	cout << endl;
	bool choice;
	cout << "0.��    1.��";
	cin >> choice;
	cin.get();
	if (choice)
	{
		p->Set_Name(name);
	}
	else if (!choice)
	{
		cout << "�������ֻ��ǲ��滻����?" << endl;
		cout << "0.��������    1.���滻����";
		cin >> choice;
		cin.get();
		if (!choice)
		{
			cout << "��������ȷ������" << endl;
			Modify_Name(p);
		}
	}
	return;
}

void userlist::Modify_Password(user* p)
{
	char password[20];
	cout << "�������µ�����:";
	cin.getline(password, 20);
	cout << "��ȷ��Ҫ��ԭ����";
	cout << p->Get_Password();
	cout << "�滻Ϊ";
	cout << password;
	cout << "��";
	cout << endl;
	bool choice;
	cout << "0.��    1.��";
	cin >> choice;
	cin.get();
	if (choice)
	{
		p->Set_Password(password);
	}
	else if (!choice)
	{
		cout << "�������뻹�ǲ��滻����?" << endl;
		cout << "0.��������    1.���滻����";
		cin >> choice;
		cin.get();
		if (!choice)
		{
			cout << "��������ȷ������" << endl;
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
		cout << "δ�������Ȩ�ޣ��޷�ִ�и������!" << endl;
	return;
}

user* userlist::Log_In()
{
	cout << "���¼!" << endl;
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
				cout << "��¼�ɹ�!" << endl;
			}
			else
				cout << "��¼ʧ��!" << endl;
			break;
		}
	}
	return p;
}

void userlist::Log_Out(user* p)
{
	p->Set_Status(false);
	cout << "���˳����˺�!" << endl;
	return;
}