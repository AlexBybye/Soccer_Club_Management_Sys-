//创建管理类：与用户沟通菜单
//对职工增删改查
//与文件读写交互
//一般创建一个.h 一个.cpp
//个人想法：
// ①主要接口都是在main中，也就是主干CPP
// ②主要调用函数必须是在 头文件声明过与类的关系（头文件可以就是简单的成员）
//               一般都会在头文件同名CPP文件进行成员函数的定义
//               注意：抽象类没有实现，所以不用创建.CPP
//               注意：由于不同类选择分头文件编写，
// 所以在写继承的时候记得在派生类头文件时包含父类头文件名。
//
#include<iostream>
using namespace std;
#include"WorkerManager.h"
#include"Worker.h"
#include"employee.h"
#include"boss.h"

int main()
{
    WorkerManager wm;
	
	
	while (1)
	{
		int choice = 0;//存储用户选项
		wm.Show_Menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系統
			wm.exitSystem();
			break;
		case 1: //添加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3: //删除职工
			wm.Del_Emp();
			break;
		case 4: //修改职工
			wm.Mod_Emp();
			break;
		case 5: //查找职工
			wm.Find_Emp();
			break;
		case 6: //排序职工
			wm.Sort_Emp();
			break;
		case 7: //清空文件
			wm.Clean_File();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	system("pause");
}

