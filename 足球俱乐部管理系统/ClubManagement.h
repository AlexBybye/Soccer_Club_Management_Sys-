#pragma once
#include"club.h"
#include<fstream>
#define FILENAME2 "Clubrunning.txt"
using namespace std;
class ClubManagement
	//此类为俱乐部管理类，为负责俱乐部功能模块函数的集合
	//包括club*类型的俱乐部名称cm_name、资金cm_fund以及用于判断文件是否为空的bool类型m_FileISEmpty
{
private:
	bool m_FileISEmpty;//判断文件是否为空
	club* cm_name;
	club* cm_fund;
public:
	friend class club;//声明友元
	friend class StaffManagement;//声明友元
	ClubManagement();//自身构造函数
	void init_Club();//初始化数据并创建对象
	//保存文件
	void saveclub(); //(为了与StaffManagement的save区别，函数名改成了saveclub函数）
	//显示
	void Show_Club();
    //修改资金
	void changeClubfund();
    //修改队伍名
	void changeClubname();
	//解散俱乐部高层
	void Clean_file();
	//创建俱乐部
	void Create_club();
    //自身析构函数
	~ClubManagement();
};
