#pragma once
#include"Staff.h"
#include<iostream>
using namespace std;
class Player : public Staff//��Ա�����࣬�丸��ΪStaff
{
public:
	//��ʾ������Ϣ
	virtual void showInfo()=0;
	//��ȡ��λ��
	virtual string getDeptName()=0;

};