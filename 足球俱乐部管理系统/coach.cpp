#include"coach.h"
coach::coach(int id, string name, int dId,int salary,int ability)//自身的构造函数
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
    this->m_salary = salary;
    this->m_ability = ability;
} //传值
void coach::showInfo()//显示个人信息
{
    cout << "职工编号： " << this->m_Id
        << "\t职工姓名： " << m_Name
        << "\t岗位： " << this->getDeptName()
        << "\t岗位职责： 负责球队训练及战术安排"
        << "\t年薪：" << this->m_salary
        << "\t教练能力值：" << this->m_ability
        << endl;
}
string coach::getDeptName()//获取岗位名称
{
    return string("教练");
}