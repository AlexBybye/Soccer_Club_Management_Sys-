#pragma once //��ֹͷ�ļ��ظ�����
#include<iostream>
#include"Worker.h"//ͳ��ְ��������
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "members.txt"
using namespace std;
class WorkerManager
{
public:

	//���캯��
	WorkerManager();
	//չʾ�˵�
	void Show_Menu();
	//��������
	void exitSystem();
	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;//��CPP��ʼ��
	//���ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//׷���ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾԱ����Ϣ
	void Show_Emp();
	//ɾ��ְ��
	void Del_Emp();
	//�жϸ�ְ���������
	int IsExist(int id);
	//�޸�ְ��
	void Mod_Emp();
	//����Ա��
	void Find_Emp();
	//����Ա��
	void Sort_Emp();
	//����ļ�
	void Clean_File();
	//��������
	~WorkerManager();

};
