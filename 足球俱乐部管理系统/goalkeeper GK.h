#pragma once
#include"Staff.h"
#include"Player.h"
#include<iostream>
using namespace std;
class goalkeeper : public Player
	//����Ϊ����Ա�࣬��������Ĺ��캯������ʾ�Լ���ȡ��λ���ƺ������丸��ΪPlayer��,Player����ΪStaff�ࣨ����̳У�
{
public:
	goalkeeper(int id, string name, int dId, int salary, int ability, string speciality);
	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ��
	string getDeptName();
};