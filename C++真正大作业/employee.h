#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
class employee :public Worker
{
public:
	employee(int id,string name,int dId);
	void showInfo();//��ʾ������Ϣ
	string getDeptName();//��ȡ��λ����
};
