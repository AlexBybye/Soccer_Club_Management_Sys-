#include"defender D.h"
defender::defender(int id, string name, int dId, int salary, int ability, string speciality)//����Ĺ��캯��
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
    this->m_salary = salary;
    this->m_ability = ability;
    this->m_speciality = speciality;
} //��ֵ
void defender::showInfo()//��ʾ������Ϣ
{
    cout << "���º��룺 " << this->m_Id
        << "\t��Ա������ " << m_Name
        << "\t��λ�� " << this->getDeptName()
        << "\t��λְ�𣺶Կ����谭�Է����򣬳�����֯�칥"
        << "\t��н��" << this->m_salary
        << "\t��Ա����ֵ��" << this->m_ability
        << "\t���˼��ɣ�" << this->m_speciality
        << endl;

}
string defender::getDeptName()//��ȡ��λ����
{
    return string("����");
}