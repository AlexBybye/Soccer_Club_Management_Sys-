#include"club.h"
using namespace std;
#include<iostream>
club::club(string a, int b)//其本身构造函数
{
	c_name = a;
	c_fund = b;
}
int club::getFund() const// 获取俱乐部资金函数getFund
{
	return c_fund;
}
void club::showClub()//显示函数showClub
{
	cout << "本足球俱乐部名称为：" <<this->c_name
		 << "现共有资金："<<this->c_fund
		 <<endl;
}
//这里是club类的实现展开