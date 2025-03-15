#pragma once
#include"Staff.h"
#include<iostream>
using namespace std;
class Player : public Staff//球员抽象类，其父类为Staff
{
public:
	//显示个人信息
	virtual void showInfo()=0;
	//获取岗位名
	virtual string getDeptName()=0;

};