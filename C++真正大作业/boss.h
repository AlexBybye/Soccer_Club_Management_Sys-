#pragma once
#include"Worker.h"
#include<iostream>
using namespace std;
class boss : public Worker
{
public:
	boss(int id, string name, int dId);
	//显示个人信息
	void showInfo();
	//获取岗位名
	string getDeptName();
};