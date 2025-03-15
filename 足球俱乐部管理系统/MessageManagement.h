#pragma once
#include<fstream>
#define FILENAME3 "Opinionbox.txt"//意见箱储存意见的文件
#include<string>
#include<iostream>
using namespace std;
class MessageManagement
{
public:
//匿名反馈意见
void Enterpoint(string);
//查看意见
void Getpoint(string);
//清空意见
void erasepoint(string);
};
