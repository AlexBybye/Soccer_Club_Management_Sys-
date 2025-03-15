#include"coach.h"
#include"defender D.h"
#include"goalkeeper GK.h"
#include"midfield M.h"
#include"striker F.h"
#include "ClubManagement.h"
#define FILENAME1 "Clubmembers.txt"//俱乐部基层员工（教练与球员）的储存信息文件
using namespace std;
class StaffManagement
{
private:
	int club1_fund=0;
public:
	//构造函数
	StaffManagement();
	//展示菜单
	void Show_Menu();
	//退出系统函数
	void exitSystem();
	//记录员工人数
	int m_EmpNum;
	//员工数组指针
	Staff** m_EmpArray;//在CPP初始化
	//买入球员函数
	void Add_Emp();
	//保存文件
	void save();
	//追加判断文件是否为空
	bool m_FileIsEmpty;
	//统计数组人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示员工信息
	void Show_Emp();
	//删除离队员工
	void Del_Emp();
	//判断该职工存在与否
	int IsExist(int id);
	//修改员工信息
	void Mod_Emp();
	//查找员工
	void Find_Emp();
	//排序员工
	void Sort_Emp();
	//清空文件（解散俱乐部底层所有员工）
	void Clean_File();
	//ClubManagement的fund传到StaffManagement的传值函数
	void fundgiveme(string&,int &);
	//把StaffManagement的fund传回的传值函数
	void fundbackyou(string&,int&);
	//析构函数
	~StaffManagement();
};