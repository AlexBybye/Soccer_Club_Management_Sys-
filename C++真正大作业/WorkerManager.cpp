#include "WorkerManager.h"
#include<iostream>
using namespace std;
WorkerManager::WorkerManager()
{
	//1:文件不存在初始化数据
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{	
		//cout << "文件不存在！" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2:文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//cout << "文件为空！" <<endl;
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
//3:文件存在并且记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为： " << num << endl;
	this->m_EmpNum=num;
	//下面开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件数据存到数组
	this->init_Emp();
	//测试代码
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号： " << this->m_EmpArray[i]->m_Id
			<< "姓名： " << this->m_EmpArray[i]->m_Name
			<< "部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}


void WorkerManager::Show_Menu()
{

	cout << "*************************************" << endl;
	cout << "*******欢迎使用职工管理系统!*********" << endl;
	cout << "*********** 0.退出管理程序 **********" << endl;
	cout << "*********** 1.增加职工信息 **********" << endl;
	cout << "*********** 2.显示职工信息 **********" << endl;
	cout << "*********** 3.删除离职职工 **********" << endl;
	cout << "*********** 4.修改职工信息 **********" << endl;
	cout << "*********** 5.查找职工信息 **********" << endl;
	cout << "*********** 6.按照编号排序 **********" << endl;
	cout << "*********** 7.清空所有文档 **********" << endl;
	cout << endl;
}
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp()
{
	cout << "请输入添加的职工数量: " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加并计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间人数
		//开辟新空间
		Worker** newSpace=new Worker* [newSize];
		//拷贝原来数据
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i <this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择
			cout << "请输入第 " << i + 1 << " 个新职工编号： " << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名： " << endl;
			cin >> name;
			cout << "请选择该职工岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 1);
				break;
			case 3:
				worker = new boss(id, name, 1);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
			//将创建员工职责，保存数组之中

		}
		delete[]this->m_EmpArray;//释放原有空间
		this->m_EmpArray = newSpace;//更改新空间指向
		this->m_EmpNum = newSize;//更新新职工人数
		this->m_FileIsEmpty = false;//追加非空状态
		this->save();//保存数据到文件中
		cout << "成功添加" << addNum << "名新职工" << endl;//提示成功
		
	}
	else
	{
		cout << "输入数据有误" << endl;//报错提示
	}
	//按任意键清屏回到上级目录
	system("pause");
	system("cls");
}
//下面保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//关闭文件
	ofs.close();
}
int WorkerManager::get_EmpNum()//3、用到的统计函数！
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数
		num++;
	}
	return num;
}
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)//普通员工
		{
			worker = new employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new manager(id, name, dId);
		}
		else if (dId == 3)//老板
		{
			worker = new boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;//索引递增
	}
	ifs.close();
}
//显示员工信息
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
//删除职工 本质就是数据迁移，从要删除后一位开始移动
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{ //按照编号删除
		cout << "请输入要删除员工的编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)//职工存在且要删除index处的员工
		{
			//数据前移
			for (int i = 0; i < m_EmpNum; i++)
			{
				//利用多态调用程序接口
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--;//更新总员工人数
			//同步到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
//判断存不存在！有则返回位置，无则返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}
//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{ //按照编号删除
		cout << "请输入要修改员工的编号" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)//职工存在且要修改index处的员工
		{
			//查找到编号的职工
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查到: " << id << "号职工, 请输入新职工号:" << endl;
			cin >> newId;

			cout << "请输入新姓名:" << endl;
			cin >> newName;
			cout << "请输入岗位:" << endl
				<< "1、普通职工" << endl
				<< "2、经理" << endl
				<< "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(newId, newName, dSelect);
			case 2:
				worker = new manager(newId, newName, dSelect);
			case 3:
				worker = new boss(newId, newName, dSelect);
			default:
				break;
			}
				//更新数据回到数组
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;
			//同步到文件中
			this->save();	
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}

	}
	//按任意键清屏
	system("pause");
	system("cls");
}
//查找员工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1、按照编号查：" << endl;
		cout << "2、按照姓名查：" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照编号查
			int id;
			cout << "请输入查找职工编号：" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				//找到职工
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，未找到该职工" << endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名查
			string name;
			cout << "请输入查找姓名：" << endl;
			cin >> name;

			//加入判断查找是否查到
			bool flag = false;//默认没找到

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为："
						<< this->m_EmpArray[i]->m_Id
						<< "号,该职工信息如下：" << endl;
					flag = true;
					//调用显示信息接口
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，未找到该职工" << endl;
			}
		}
		else
		{
			cout << "输入选项有误！" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//编号排序员工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		//按任意键清屏
		system("pause");
		system("cls");
	}
	else
	{
	
	cout << "请选择排序方式:" << endl;
	cout << "1、按职工号进行升序" << endl;
	cout << "2、按职工号进行降序" << endl;
	int select = 0;
	cin >> select;
	for (int i = 0; i < m_EmpNum; i++)
	{
		int minOrmax = i;//声明最小值或最大值下标
		for (int j = i + 1; j <this->m_EmpNum; j++)
		{
			if (select == 1)//升序
			{
				if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id)
				{
					minOrmax = j;
				}
			}
			else if (select == 2)//降序
			{
				if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id)
				{
					minOrmax = j;
				}	
			}
		}
		//判断一开始认定最小值最大值是否是计算的最小最大值，不是则交换数据
		if (i != minOrmax)
		{
			Worker* temp = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
			this->m_EmpArray[minOrmax] = temp;
		}
	}
	cout << "排序成功！排序后结果为：" << endl;
	this->save();//排序结果保存到文件
	this->Show_Emp();
}
}
//清空文件
void WorkerManager::Clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()//这里可以不写，系统自动操作
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;	
	}
}
