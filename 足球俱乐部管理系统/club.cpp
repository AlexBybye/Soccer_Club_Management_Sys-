#include"club.h"
using namespace std;
#include<iostream>
club::club(string a, int b)//�䱾���캯��
{
	c_name = a;
	c_fund = b;
}
int club::getFund() const// ��ȡ���ֲ��ʽ���getFund
{
	return c_fund;
}
void club::showClub()//��ʾ����showClub
{
	cout << "��������ֲ�����Ϊ��" <<this->c_name
		 << "�ֹ����ʽ�"<<this->c_fund
		 <<endl;
}
//������club���ʵ��չ��