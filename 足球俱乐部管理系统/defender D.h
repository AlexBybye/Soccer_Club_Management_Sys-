#pragma once
#include"Staff.h"
#include"Player.h"
#include<iostream>
using namespace std;
class defender : public Player
	//����Ϊ�����࣬��������Ĺ��캯������ʾ�Լ���ȡ��λ���ƺ������丸��ΪPlayer��,Player����ΪStaff�ࣨ����̳У�
{
public:
	defender(int id, string name, int dId, int salary, int ability, string speciality);
	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ��
	string getDeptName();
};