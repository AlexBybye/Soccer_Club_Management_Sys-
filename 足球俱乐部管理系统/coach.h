#pragma once
#include"Staff.h"
#include<iostream>
using namespace std;
class coach : public Staff
	//此类为教练类，包括自身的构造函数，显示以及获取岗位名称函数，其父类为Staff类（二重继承）
{

public:
	coach(int id, string name, int dId,int salary,int ability );
	//显示个人信息
	void showInfo();
	//获取岗位名称
	string getDeptName();
};