#pragma once
#include"Staff.h"
#include<iostream>
using namespace std;
class coach : public Staff
	//����Ϊ�����࣬��������Ĺ��캯������ʾ�Լ���ȡ��λ���ƺ������丸��ΪStaff�ࣨ���ؼ̳У�
{

public:
	coach(int id, string name, int dId,int salary,int ability );
	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ����
	string getDeptName();
};