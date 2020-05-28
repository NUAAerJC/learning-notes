//studentlist.h
#pragma once
#ifndef STUDENTLIST_H_
#define STUDENTLIST_H_
#include"student_info.h"
class studentlist
{
public:
	studentlist(); //studentlist ��Ĺ��캯��
	void Set_Data(); //studentlist ������ú���
	void Set_Info_s(student*);//Ϊ������ĳһ���趨��Ϣ
	void Set_Info_c(unsigned);//Ϊָ�����ڽ����������趨��Ϣ
	void Add_Stu(); //��Ӻ���(���������β��,��������Ϣ)
	void Insert_In_s(student*);//��ָ�����ڵĺ��������������������Ϣ��
	void Insert_In_c(unsigned);//��ָ�����ڽ�����λ�ò�����������������Ϣ��
	void Display_All(); //��ʾ����(��ʾ����������ѧ������Ϣ)
	//��ȷ����
	student* Find_Cnt_p(unsigned);//���Һ���(ͨ������ڵ���)����ʾ��Ϣ
	unsigned Find_Name_p(char*); //���Һ���(ͨ������),��ʾ��Ϣ�������ظ�ѧ���������еĽڵ���
	unsigned Find_Sex_p(bool);//���Һ�����ͨ���Ա𣩣���ʾ���з���������ѧ����Ϣ��������ѡ�񷵻ر�ѡ��ѧ���Ľڵ���
	unsigned Find_Number_p(char*);//���Һ���(ͨ��ѧ��),��ʾ��Ϣ�������ظ�ѧ���������еĽڵ���
	unsigned Find_Id_p(char*);//���Һ���(ͨ��ID)����ʾ��Ϣ�������ظ�ѧ���������еĽڵ���
	unsigned Find_Telephone_p(char*);//���Һ���(ͨ���绰),��ʾ��Ϣ�������ظ�ѧ���������еĽڵ���
	unsigned Find_Major_p(char*);//���Һ�����ͨ���������רҵ������ʾ���з���������ѧ����Ϣ��������ѡ�񷵻ر�ѡ��ѧ���Ľڵ���
	//ģ������
	unsigned Find_Name_ip(char*);//���Һ�����ͨ�����ֵ�ǰn���ַ���nΪ�����ַ����ĳ��ȣ�����ʾ���з���������ѧ����Ϣ��������ѡ�񷵻ر�ѡ��ѧ���Ľڵ���
	unsigned Find_Number_ip(char*);//���Һ�����ͨ��ѧ�ŵ�ǰn���ַ���nͬ�ϣ�����ʾ���з���������ѧ����Ϣ��������ѡ�񷵻ر�ѡ��ѧ���Ľڵ���
	unsigned Find_Id_ip(char*);//���Һ�����ͨ��id��ǰn���ַ���nͬ�ϣ�����ʾ���з���������ѧ����Ϣ��������ѡ�񷵻ر�ѡ��ѧ���Ľڵ���
	unsigned Find_Telephone_ip(char*);//���Һ�����ͨ��id��ǰn���ַ���nͬ�ϣ�����ʾ���з���������ѧ����Ϣ��������ѡ�񷵻ر�ѡ��ѧ���Ľڵ���
	unsigned Find_Major_ip(char*);//���Һ���������������רҵ��ǰn���ַ�������ʾ���з���������ѧ����Ϣ��������ѡ�񷵻ر�ѡ��ѧ���Ľڵ���
	void Delete_All(); //��պ���
	void Write_Into_File(); //д���ļ��ĺ���
	void Read_From_File(); //���ļ������ĺ���
	void Modify(unsigned); //�޸ĺ���
	void Modify_Name(student*);//�޸�����
	void Modify_Sex(student*);//�޸��Ա�
	void Modify_Id(student*);//�޸�id
	void Modify_Telephone(student*);//�޸ĵ绰
	void Modify_Birthday(student*);//�޸�����
	void Modify_Number(student*);//�޸�ѧ��
	void Modify_Address(student*);//�޸ĵ�ַ
	void Modify_Dorm(student*);//�޸�����
	void Modify_Post(student*);//�޸�ְ��
	void Modify_Major(student*);//�޸�רҵ
	void Remove(student*); //ɾ������
	unsigned Get_Cnt() { return cnt; }
private:
	student* start; //����ͷ
	student* end; //����β
	unsigned cnt;//�����ܽ�����������β��start��end��
};

#endif