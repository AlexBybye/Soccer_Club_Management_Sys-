#pragma once
#include<iostream>
#include<string>
using namespace std;
class club
    //����Ϊ���ֲ��࣬�������ֲ�����c_name�Լ����ֲ��ʽ�c_fund
{
public:
    string c_name;
    int c_fund;
    club(string name, int fund);//�䱾���캯��
    int getFund() const;// ��ȡ���ֲ��ʽ���getFund
    void showClub();//��ʾ����showClub
};