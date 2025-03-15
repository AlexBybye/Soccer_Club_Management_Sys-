#include"midfield M.h"
midfield::midfield(int id, string name, int dId, int salary, int ability, string speciality)//自身的构造函数
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
    this->m_salary = salary;
    this->m_ability = ability;
    this->m_speciality = speciality;
} //传值
void midfield::showInfo()//显示个人信息
{
    cout << "球衣号码： " << this->m_Id
        << "\t球员姓名： " << m_Name
        << "\t岗位： " << this->getDeptName()
        << "\t岗位职责：打好传控，将球权后场转移前场"
        << "\t年薪：" << this->m_salary
        << "\t球员能力值：" << this->m_ability
        << "\t个人技巧：" << this->m_speciality
        << endl;

}
string midfield::getDeptName()//获取岗位名称
{
    return string("中场");
}