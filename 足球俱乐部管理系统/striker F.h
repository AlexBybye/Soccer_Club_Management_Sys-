#pragma once
#include"Staff.h"
#include"Player.h"
#include<iostream>
using namespace std;
class striker : public Player
	//此类为前锋类，包括自身的构造函数，显示以及获取岗位名称函数，其父类为Player类,Player基类为Staff类（三层继承）
{
public:
	striker(int id, string name, int dId, int salary, int ability,string speciality);
	//显示个人信息
	void showInfo();
	//获取岗位名
	string getDeptName();
};
