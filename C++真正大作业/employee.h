#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
class employee :public Worker
{
public:
	employee(int id,string name,int dId);
	void showInfo();//显示个人信息
	string getDeptName();//获取岗位名称
};
