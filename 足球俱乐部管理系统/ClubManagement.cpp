#include"ClubManagement.h"
#include<iostream>
using namespace std;
ClubManagement::ClubManagement()
{
	//1:文件不存在初始化数据
	ifstream ifs;
	ifs.open(FILENAME2, ios::in);//读文件
	if (!ifs.is_open())
	{
		this->cm_name = 0;
		this->cm_fund = 0;//初始化
		this->m_FileISEmpty = true;
		ifs.close();
		return;
	}
	//2:文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" <<endl;
		this->cm_name = 0;
		this->cm_fund = 0;//初始化
		//初始化文件是否为空
		this->m_FileISEmpty = true;
		ifs.close();
		return;
	}	
	//3:文件存在并且记录数据
	//将文件数据存到数组
	this->init_Club();
}
//下面保存文件(为了与StaffManagement的save区别，函数名改成了saveclub函数）
void ClubManagement::saveclub()
{
	ofstream ofs;
	ofs.open(FILENAME2, ios::out);
	ofs << cm_name->c_name << " " << cm_fund->c_fund << endl;
	//关闭文件
	ofs.close();
}
void ClubManagement::init_Club()//初始化并创建对象
{
	ifstream ifs;
	ifs.open(FILENAME2, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在或者记录为空" << endl;
		m_FileISEmpty = true;
		return;
	}
	m_FileISEmpty = false;
	string name;
	int fund;
	ifs >> name >> fund;
	// 创建俱乐部对象
	cm_name = new club(name, fund);
	cm_fund = new club(name, fund);
	ifs.close();
}
void ClubManagement::Show_Club()//显示
{
	//判断文件是否为空
	if (this->m_FileISEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		return;
	}
	else
	{
		// 如果指针不为空，则显示俱乐部信息
		if (this->cm_fund && this->cm_name)
		{
			cout << "俱乐部名称: " << this->cm_name->c_name << endl;
			cout << "俱乐部资金: " << this->cm_fund->c_fund << endl;
		}
		else
		{
			cout << "指针为空，无法显示俱乐部信息" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
void ClubManagement::changeClubfund()//修改资金函数
{
	if (this->m_FileISEmpty) 
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else 
	{
		int c_newfund = 0;
		cout << "请输入俱乐部新的资金" << endl;
		cin >> c_newfund;

		// 使用当前俱乐部的资金
		cm_fund->c_fund = c_newfund;

		cout << "修改成功！" << endl;
		// 同步到文件中
		this->saveclub();
		Show_Club();//再显示信息
	}
}

void ClubManagement::changeClubname()//修改俱乐部名字
{
	if (this->m_FileISEmpty) {
		cout << "文件不存在或者记录为空" << endl;
	}
	else 
	{
		string c_newname = "";
		cout << "请输入俱乐部新的名称" << endl;
		cin >> c_newname;

		// 使用当前俱乐部的名称
		cm_name->c_name = c_newname;

		cout << "修改成功！" << endl;
		// 同步到文件中
		this->saveclub();
		Show_Club();//再显示信息
	}
}
void ClubManagement::Clean_file()//清除文件，也就是解散俱乐部高层所有数据
//俱乐部高层包括名字和资金
{
	cout << "确定解散本俱乐部董事层？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME2, ios::trunc);
		ofs.close();
		if (cm_name != nullptr)
			delete cm_name;
		if (cm_fund != nullptr)
			delete cm_fund;
		this->m_FileISEmpty = true;
		cout << "成功解散！" << endl;
	}
system("pause");
system("cls");
}
void ClubManagement::Create_club()//创建俱乐部函数
{
	if (!m_FileISEmpty)
	{
		cout << "文件中已存在俱乐部数据，无法创建新俱乐部" << endl;
		system("pause");
		return;
	}
	string name;
	int fund;
	cout << "请输入新俱乐部的名称: ";
	cin >> name;
	cout << "请输入新俱乐部的资金: ";
	cin >> fund;
	cm_name = new club(name, fund);
	cm_fund = new club(name, fund);
	saveclub();
	cout << "俱乐部创建成功！" << endl;
	m_FileISEmpty = false;
	system("pause");
	system("cls");
}
ClubManagement::~ClubManagement()//其本身析构函数，防止溢出
{
	if (this->cm_name != NULL)
	{
		delete cm_name;
		this->cm_name = 0;
	}
	if (this->cm_fund != NULL)
	{
		delete cm_fund;
		this->cm_fund = 0;
	}
}
	