#pragma once
#ifndef USERLIST_H_
#define USERLIST_H_
#include"user.h"

class userlist
{
private:
	user* start;//����ͷ�ڵ�
	user* end;//����β�ڵ�
	unsigned u_cnt;//�����ܽ���
	bool The_Right;//���Ȩ�ޣ���������Ϊ1ʱ�ſ���ִ��ɾ�������û���һЩ�߼�����
								//Ϊ0ʱֻ��ִ�е�¼����
	char verification_code[11];//10λ��֤�룬ֻ������֤ͨ������ܿ������Ȩ��
public:
	userlist();//userlist ��Ĺ��캯��
	void Set_Data();//�����������
	void Set_Info_u(user*);//����������ָ��ĳһ�ڵ���Ϣ
	void Set_Info_c(unsigned);//�趨������ָ��ĳһ�ڵ���Ϣ
	void Add_User();//������β�����һ��������������Ϣ��
	void Insert_In_u(user*);//��ָ����������ĺ������һ��������������Ϣ��
	void Insert_In_c(unsigned);//��ָ��������λ�ò���һ��������������Ϣ��
	void Display_All();//��ʾ���е��û��������Ӧ������
	user* Find_Cnt(unsigned);//�ҵ�������Ӧ�������������ʾ�ýڵ���ϸ��Ϣ,�����ظý�����
	unsigned Find_Name(char*);//���������ҵ���Ӧ�����ڣ���ʾ�ýڵ���ϸ��Ϣ�����ظýڵĽ���
	unsigned Find_Password(char*);//���������ҵ���Ӧ�����ڣ����ܲ�ֹһ��������ʾ��ϸ��Ϣ�͸ýڵĽ���,�������û�ѡ�񷵻���Ӧ�Ľ���
	void Delete_All();//�������
	void Write_Into_File();//д���ļ�
	void Read_From_File();//���ļ��ж�������
	void Modify(unsigned);//�޸�ĳһ�ڵ���Ϣ
	void Modify_Name(user*);//�޸�ĳһ�ڵ��û���
	void Modify_Password(user*);//�޸�ĳһ�ڵ�����
	void Remove(user*);//�Ƴ�ĳһ��
	void Set_The_Right(bool);//����Verify_Code��������ֵ��������Ϊ�������Դ�ȷ���Ƿ��������Ȩ�ޣ����Կ���Ҳ���Թرգ�
	void Set_Code(char*);//������֤��
	bool Verify_Code(char*);//��֤��֤��ĺ���������֤�ɹ��򷵻�1������֮
	user* Log_In();//��¼����
	void Log_Out(user*);//�˳�����
	bool Get_Right() { return The_Right; }
	unsigned Get_Cnt() { return u_cnt; }
};

#endif