#pragma once
#include"Worker.h"
#include<iostream>
using namespace std;
class boss : public Worker
{
public:
	boss(int id, string name, int dId);
	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ��
	string getDeptName();
};