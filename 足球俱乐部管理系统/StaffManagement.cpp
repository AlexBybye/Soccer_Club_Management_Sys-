#include "StaffManagement.h"
#include<iostream>
#include <sstream>
using namespace std;
StaffManagement::StaffManagement()
{
	//1:文件不存在初始化数据
	ifstream ifs;
	ifs.open(FILENAME1, ios::in);//读文件
	if (!ifs.is_open())
	{
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
	this->m_EmpNum = num;
	//下面开辟空间
	this->m_EmpArray = new Staff * [this->m_EmpNum];
	//将文件数据存到数组
	this->init_Emp();
}

void StaffManagement::Show_Menu() // 用户菜单界面
{
	cout << "\t*******************************************" << endl;
	cout << "\t ****** 欢迎使用足球俱乐部管理系统! ******" << endl;
	cout << "\t*******************************************" << endl;
	cout << "\t____________________________________________" << endl;
	cout << "\t|***  0. 退出管理程序\t\t\t***|" << endl;
	cout << "\t|***  1. 买入员工信息\t\t\t***|" << endl;
	cout << "\t|***  2. 显示员工信息\t\t\t***|" << endl;
	cout << "\t|***  3. 删除离队员工\t\t\t***|" << endl;
	cout << "\t|***  4. 修改员工信息\t\t\t***|" << endl;
	cout << "\t|***  5. 查找员工信息\t\t\t***|" << endl;
	cout << "\t|***  6. 进行员工排序\t\t\t***|" << endl;
	cout << "\t|***  7. 解散俱乐部底层\t\t\t***|" << endl;
	cout << "\t|***  8. 修改俱乐部资金\t\t\t***|" << endl;
	cout << "\t|***  9. 修改俱乐部名称\t\t\t***|" << endl;
	cout << "\t|*** 10. 显示俱乐部信息\t\t\t***|" << endl;
	cout << "\t|*** 11. 解散俱乐部高层\t\t\t***|" << endl;
	cout << "\t|*** 12. 创建新俱乐部\t\t\t***|" << endl;
	cout << "\t|*** 13. 投稿意见箱\t\t\t***|" << endl;
	cout << "\t|*** 14. 查看意见箱\t\t\t***|" << endl;
	cout << "\t|*** 15. 清空意见箱\t\t\t***|" << endl;
	cout << "\t--------------------------------------------" << endl;
	cout << endl;
}
void StaffManagement::exitSystem()//退出系统
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);
}

void StaffManagement::fundgiveme(string &n, int&c)
{
	ifstream ifs;
	ifs.open(FILENAME2,ios::in);
	ifs >> n;
	ifs >> c;
	ifs.close();
}
void StaffManagement::fundbackyou(string& n, int& d)//保存更改后资金
{
	ofstream ofs;
	ofs.open(FILENAME2,ios::out);
	ofs.flush();
	ofs << n <<" "<< d;
	ofs.close();
}
void StaffManagement::Add_Emp()//添加
{
	cout << "请输入交易入会的职工数量: " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加并计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间人数
		//开辟新空间
		Staff** newSpace = new Staff * [newSize];
		//拷贝原来数据
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加
		string name;
		fundgiveme(name, club1_fund);

		// 计算新职工的年薪总和
		int totalSalary = 0;
		int salary1;
		cout << "俱乐部现有资金为：" << club1_fund << endl;
		cout << "请先输入各个职工的年薪：" << endl;
		for (int j = 0; j < addNum; j++)
		{
			cin >> salary1;
			// 输入新职工年薪...
			totalSalary += salary1; // 假设 salary 是新职工的年薪
		}
		// 判断是否超出俱乐部资金
		if (totalSalary > club1_fund)
		{
			cout << "年薪总和超出俱乐部资金，无法添加新职工！" << endl;
			return;
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择
			int salary;
			int ability;
			string speciality;

			cout << "请输入第 " << i + 1 << " 个新职工编号： " << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名： " << endl;
			cin >> name;
			cout << "请输入第 " << i + 1 << " 个新职工年薪： " << endl;
			cin >> salary;
			cout << "请输入第 " << i + 1 << " 个新职工能力值： " << endl;
			cin >> ability;
			cout << "请选择该职工岗位： " << endl;
			cout << "1、教练" << endl;
			cout << "2、前锋" << endl;
			cout << "3、中场" << endl;
			cout << "4、后卫" << endl;
			cout << "5、门将" << endl;
			cin >> dSelect;
			if (dSelect != 1)
			{
				cout << "请输入此球员的个人技巧" << endl;
				cin >> speciality;
			}
			Staff* staff = NULL;
			switch (dSelect)
			{
			case 1:
				staff = new coach(id, name, 1, salary, ability);
				break;
			case 2:
				staff = new striker(id, name, 2, salary, ability, speciality);
				break;
			case 3:
				staff = new midfield(id, name, 3, salary, ability, speciality);
				break;
			case 4:
				staff = new defender(id, name, 4, salary, ability, speciality);
				break;
			case 5:
				staff = new goalkeeper(id, name, 5, salary, ability, speciality);
				break;
			default:
				break;
			}
			*(newSpace + this->m_EmpNum + i) = staff;
			//将创建员工职责，保存数组之中
			club1_fund -= salary;
            
		}
		fundbackyou(name,club1_fund);
		delete[] this->m_EmpArray;//释放原有空间
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
void StaffManagement::save()
{
	ofstream ofs;
	ofs.open(FILENAME1, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_DeptId == 1)
		{
			ofs << this->m_EmpArray[i]->m_Id << " "
				<< this->m_EmpArray[i]->m_Name << " "
				<< this->m_EmpArray[i]->m_DeptId << " "
				<< this->m_EmpArray[i]->m_salary << " "
				<< this->m_EmpArray[i]->m_ability << " "
				<< endl;
		}
		else
		{
			ofs << this->m_EmpArray[i]->m_Id << " "
				<< this->m_EmpArray[i]->m_Name << " "
				<< this->m_EmpArray[i]->m_DeptId << " "
				<< this->m_EmpArray[i]->m_salary << " "
				<< this->m_EmpArray[i]->m_ability << " "
				<< this->m_EmpArray[i]->m_speciality<<" "
				<< endl;
		}
	}
	//关闭文件
	ofs.close();
}

int StaffManagement::get_EmpNum()//3、用到的统计函数！
{
	ifstream ifs;
	ifs.open(FILENAME1, ios::in);
	if (!ifs.is_open()) {
		// 文件打开失败，处理错误
		return -1;
	}
	int id;
	string name;
	int dId;
	int salary;
	int ability;
	string speciality;
	int num = 0;
	string line;
	while (getline(ifs, line))
	{
		istringstream iss(line);
		// 逐行读取员工信息
		if (iss >> id >> name >> dId >> salary >> ability) {
			// 统计人数
			num++;
			// 如果部门编号不是1，则读取特长信息
			if (dId != 1) {
				iss >> speciality;
			}
		}
	}
	// 关闭文件
	ifs.close();

	return num;
}
void StaffManagement::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME1, ios::in);
	if (!ifs) 
	{
		std::cerr << "无法打开文件" << std::endl;
		return;
	}
	int id;
	string name;
	int dId;
	int salary;
	int ability;
	string speciality;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId&&ifs>>salary&&ifs>>ability&&ifs>>speciality)
	{
		Staff* staff = NULL;

		if (dId == 1)//教练
		{
			staff = new coach(id, name, dId,salary,ability);
		}
		else if (dId == 2)//前锋
		{
			staff = new striker(id, name, dId,salary,ability,speciality);
		}
		else if (dId == 3)//中场
		{
			staff = new midfield(id, name, dId, salary, ability, speciality);
		}
		else if (dId == 4)//后卫
		{
			staff = new striker(id, name, dId, salary, ability, speciality);
		}
		else if (dId == 5)//门将
		{
			staff = new goalkeeper(id, name, dId, salary, ability, speciality);
		}
		this->m_EmpArray[index] = staff;
		index++;//索引递增
	}
	ifs.close();
}

void StaffManagement::Show_Emp()//显示员工信息
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
			// 检查指针有效性
			if (m_EmpArray[i] != nullptr)
			{
				// 利用多态调用程序接口
				m_EmpArray[i]->showInfo();
			}
			else
			{
				cout << "发现无效的员工对象指针" << endl;
			}
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
//交易职工 本质就是数据迁移，从要删除后一位开始移动(删除球员在教练上侧或教练，需要动临近两个数据，删除球员是教练下方，不用改变）
void StaffManagement::Del_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者记录为空" << endl;
		return;
	}
	else
	{
		cout << "请输入要删除员工的编号" << endl;
		int id = 0;
		cin >> id;
		//寻找要删除的员工的索引
		int indexToDelete = -1;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != nullptr && this->m_EmpArray[i]->m_Id== id) {
				indexToDelete = i;
				break;
			}
		}

		if (indexToDelete == -1) {
			cout << "未找到此编号员工" << endl;
			return;
		}
		// 删除员工并释放内存
		delete this->m_EmpArray[indexToDelete];
		this->m_EmpArray[indexToDelete] = nullptr;

		// 移动后面的元素填补空位
		for (int i = indexToDelete; i < this->m_EmpNum - 1; i++) {
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpArray[this->m_EmpNum - 1] = nullptr; // 将数组末尾设为nullptr

		// 更新员工总数
		this->m_EmpNum--;

		// 检查并调整数组中的教练和球员位置
		for (int i = indexToDelete; i < this->m_EmpNum; i++) {
			// 如果当前位置是球员，并且其上方是教练，则将球员上移
			if (i > 0 && this->m_EmpArray[i] != nullptr && this->m_EmpArray[i]->m_DeptId != 1 &&
				this->m_EmpArray[i - 1] != nullptr && this->m_EmpArray[i - 1]->m_DeptId == 1)
			{
				swap(this->m_EmpArray[i], this->m_EmpArray[i - 1]);
				i--; // 重新检查新上移的员工
			}
		}

		// 同步到文件
		this->save();
		cout << "删除成功！" << endl;
	}
}

int StaffManagement::IsExist(int id)
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
void StaffManagement::Mod_Emp()
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
			int newsalary = 0;
			int newability = 0;
			string newspeciality = "";
			cout << "查到: " << id << "号职工, 请输入新职工号:" << endl;
			cin >> newId;
			cout << "请输入新姓名:" << endl;
			cin >> newName;
			cout << "请输入岗位:" << endl
				<< "1、教练" << endl
				<< "2、前锋" << endl
				<< "3、中场" << endl
				<< "4、后卫" << endl
				<< "5、门将" << endl;
			cin >> dSelect;
			cout << "请输入新的薪水：" << endl;
			cin >> newsalary;
			cout << "请输入新的能力值：" << endl;
			cin >> newability;
			if (dSelect != 1)
			{
				cout << "请输入该球员的个人特长：";
				cin >> newspeciality;
			}
			
			Staff* staff = NULL;
			switch (dSelect)
			{
			case 1:
				staff = new coach(newId, newName, dSelect,newsalary,newability);
				break;
			case 2:
				staff = new striker(newId, newName, dSelect,newsalary, newability,newspeciality);
				break;
			case 3:
				staff = new midfield(newId, newName, dSelect, newsalary, newability, newspeciality);
				break;
			case 4:
				staff = new defender(newId, newName, dSelect, newsalary, newability, newspeciality);
				break;
			case 5:
				staff = new goalkeeper(newId, newName, dSelect, newsalary, newability, newspeciality);
				break;
			default:
				break;
			}
			//更新数据回到数组
			this->m_EmpArray[ret] = staff;
			cout << "修改成功！" << endl;
			//同步到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，未找到该职工" << endl;
		}

	}
	//按任意键清屏
	system("pause");
	system("cls");
}
//查找员工
void StaffManagement::Find_Emp()
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
			cout << "请输入查找员工编号：" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				//找到职工
				cout << "查找成功！该员工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，未找到该员工" << endl;
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

void StaffManagement::Sort_Emp()
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
		cout << "1、按能力值进行降序" << endl;
		cout << "2、按年薪进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrmax = i;//声明最小值或最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//降序ability
				{
					if (this->m_EmpArray[minOrmax]->m_ability < this->m_EmpArray[j]->m_ability)
					{
						minOrmax = j;
					}
				}
				if (select == 2)//降序salary
				{
					if (this->m_EmpArray[minOrmax]->m_salary < this->m_EmpArray[j]->m_salary)
					{
						minOrmax = j;
					}
				}
			}
			//判断一开始认定最小值最大值是否是计算的最小最大值，不是则交换数据
			if (i != minOrmax)
			{
				Staff* temp = this->m_EmpArray[i];
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
void StaffManagement::Clean_File()
{
	cout << "确定解散本俱乐部所有人员？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME1, ios::trunc);
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
		cout << "成功解散！" << endl;
	}
	system("pause");
	system("cls");
}
StaffManagement::~StaffManagement()//这里可以不写，系统自动操作
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