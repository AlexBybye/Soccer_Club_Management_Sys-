#include"StaffManagement.h"
#include"MessageManagement.h"
using namespace std;
int main()
{
	StaffManagement wm;
	ClubManagement vm;
	MessageManagement um;
	int password = 0;
	int safety = 5;//输入密钥次数
	int choice = 0;//存储用户选项
	int decision = 0;
	cout << "欢迎使用足球俱乐部管理系统！" << endl;
Retry:
	if (safety)
	{
		
		cout << "请输入您的密钥：" << endl;
		cout << "您还有" << safety << "次机会，请输入身份密钥！" << endl;
		//球员密钥暂定100**（**为球衣编号，教练密钥101**,**为教练编，董事密钥10201)
		while (cin >> password)
		{
			if (password >=10000&&password <10100)
			{
				choice = 0;
				cout <<"第"<<password-10000 << "号球员您好！请输入您的选择:" << endl;
				while (1)
				{   
					wm.Show_Menu();
					cin >> choice;
					switch (choice)
					{
					case 0: //退出系统
						wm.exitSystem();
						break;
					case 1: //转会买入职工
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 2://显示职工
						wm.Show_Emp();
						break;
					case 3: //转会卖出职工
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 4: //修改职工
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 5: //查找职工
						wm.Find_Emp();
						break;
					case 6: //排序职工
						wm.Sort_Emp();
						break;
					case 7: //解散俱乐部
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 8://改变俱乐部资金
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 9://改变俱乐部名字
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 10://显示俱乐部名字及资金
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 11://解散俱乐部高层
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 12://创建俱乐部
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 13://球员教练端反馈
						cout << "请输入您想要反馈的意见！" << endl;
						um.Enterpoint(FILENAME3);
						system("pause");
						system("cls");//清屏
						break;
					case 14://董事端查看
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 15://董事端清空
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					default:
						system("cls");//清屏
						break;
					}
				}
			}
			if (password >= 10100 && password < 10200)
			{
				choice = 0;//存储用户选项
				cout << "教练您好！请输入您的选择:" << endl;
				while (1)
				{
					wm.Show_Menu();
					cin >> choice;
					switch (choice)
					{
					case 0: //退出系统
						wm.exitSystem();
						break;
					case 1: //转会买入职工
						//wm.fundgiveme(vm);
						wm.Add_Emp();
						break;
					case 2://显示职工
						wm.Show_Emp();
						break;
					case 3: //转会卖出职工
						//wm.fundgiveme(vm);
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
					case 7: //解散俱乐部
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 8://改变俱乐部资金
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 9://改变俱乐部名字
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 10://显示俱乐部名字及资金
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 11://解散俱乐部高层
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 12://创建俱乐部
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 13://球员教练端反馈
						cout << "请输入您想要反馈的意见！" << endl;
						um.Enterpoint(FILENAME3);
						system("pause");
						system("cls");//清屏
						break;
					case 14://董事端查看
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 15://董事端清空
						cout << "您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					default:
						system("pause");
						system("cls");//清屏
						break;
					}
				}
			}
			if (password == 10201)
			{
				choice = 0;//存储用户选项
				cout << "董事您好！请输入您的选择:" << endl;
				while (1)
				{
					wm.Show_Menu();
					cin >> choice;
					switch (choice)
					{
					case 0: //退出系统
						wm.exitSystem();
						break;
					case 1: //转会买入职工
						//wm.fundgiveme(vm);
						wm.Add_Emp();
						break;
					case 2://显示职工
						wm.Show_Emp();
						break;
					case 3: //转会卖出职工
						//wm.fundgiveme(vm);
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
					case 7: //解散俱乐部
						wm.Clean_File();
						break;
					case 8://改变俱乐部资金
						vm.changeClubfund();
						break;
					case 9://改变俱乐部名字
						vm.changeClubname();
						break;
					case 10://显示俱乐部名字及资金
						vm.Show_Club();
						break;
					case 11://解散俱乐部高层
						vm.Clean_file();
						break;
					case 12://创建俱乐部
						vm.Create_club();
						break; 
					case 13://球员教练端反馈
						cout << "尊敬的董事，您没有权限进行此操作！" << endl;
						system("pause");
						system("cls");//清屏
						break;
					case 14://董事端查看
						cout << "尊敬的董事，近期的意见如下：" << endl;
						um.Getpoint(FILENAME3);
						system("pause");
						system("cls");//清屏
						break;
					case 15://董事端清空
						cout << "您确定要清空意见箱吗？" << endl;
						cout << "1、YES!" << endl << "2、NO!" << endl;
						cin >> decision;
						if (decision == 1)
						{
							um.erasepoint(FILENAME3);
							cout << "清空成功！" << endl;
							system("pause");
							system("cls");//清屏
							break;
						}
						else
							cout << "退回成功！" << endl;
							break;
						
					default:
						system("pause");
						system("cls");//清屏
						break;
					}
				}
			}
			else
			{
				cout << "输入密钥错误，请重新输入！" << endl;
				safety--;
				goto Retry;
			}
		}
	}
	else//五次机会用光了
	{
		cout << "输入错误密钥次数过多！自动退出程序！" << endl;
		system("pause");
		return 0;
	}
	
	system("pause");
}

