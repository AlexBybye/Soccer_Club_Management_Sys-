#pragma once
#include<iostream>
#include<string>
using namespace std;
class club
    //此类为俱乐部类，包括俱乐部名称c_name以及俱乐部资金c_fund
{
public:
    string c_name;
    int c_fund;
    club(string name, int fund);//其本身构造函数
    int getFund() const;// 获取俱乐部资金函数getFund
    void showClub();//显示函数showClub
};