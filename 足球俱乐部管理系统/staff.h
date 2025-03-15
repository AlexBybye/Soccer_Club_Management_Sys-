#pragma once
#include<iostream>
#include<string>
using namespace std;
class Staff//职工抽象基类
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	int m_Id; //职工编号
	string m_Name; //职工姓名
	int m_DeptId; //职工所在部门名称编号
	int m_salary;//职工薪水
	int m_ability;//职工个人能力值
	//球员特有：个人技巧
	string m_speciality;
};