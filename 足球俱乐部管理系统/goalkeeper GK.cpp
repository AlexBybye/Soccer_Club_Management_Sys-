#include"goalkeeper GK.h"
goalkeeper::goalkeeper(int id, string name, int dId, int salary, int ability, string speciality)//自身的构造函数
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
    this->m_salary = salary;
    this->m_ability = ability;
    this->m_speciality = speciality;
} //传值
void goalkeeper::showInfo()//显示个人信息
{
    cout << "球衣号码： " << this->m_Id
        << "\t球员姓名： " << m_Name
        << "\t岗位： " << this->getDeptName()
        << "\t岗位职责：守住对面射门，组织后场站位"
        << "\t年薪：" << this->m_salary
        << "\t球员能力值：" << this->m_ability
        << "\t个人技巧：" << this->m_speciality
        << endl;

}
string goalkeeper::getDeptName()//获取岗位名称
{
    return string("门将");
}