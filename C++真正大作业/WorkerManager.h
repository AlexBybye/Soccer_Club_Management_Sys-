#pragma once //防止头文件重复包含
#include<iostream>
#include"Worker.h"//统计职工数量用
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "members.txt"
using namespace std;
class WorkerManager
{
public:

	//构造函数
	WorkerManager();
	//展示菜单
	void Show_Menu();
	//析构函数
	void exitSystem();
	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;//在CPP初始化
	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//追加判断文件是否为空
	bool m_FileIsEmpty;
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示员工信息
	void Show_Emp();
	//删除职工
	void Del_Emp();
	//判断该职工存在与否
	int IsExist(int id);
	//修改职工
	void Mod_Emp();
	//查找员工
	void Find_Emp();
	//排序员工
	void Sort_Emp();
	//清空文件
	void Clean_File();
	//析构函数
	~WorkerManager();

};
