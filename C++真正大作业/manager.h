#pragma once
#include"Worker.h"
#include<iostream>
using namespace std;
class manager : public Worker
{
public:
	manager(int id, string name, int dId);
	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ��
	string getDeptName();
};