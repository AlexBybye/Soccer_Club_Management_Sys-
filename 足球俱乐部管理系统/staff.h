#pragma once
#include<iostream>
#include<string>
using namespace std;
class Staff//ְ���������
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int m_Id; //ְ�����
	string m_Name; //ְ������
	int m_DeptId; //ְ�����ڲ������Ʊ��
	int m_salary;//ְ��нˮ
	int m_ability;//ְ����������ֵ
	//��Ա���У����˼���
	string m_speciality;
};