#include"coach.h"
coach::coach(int id, string name, int dId,int salary,int ability)//����Ĺ��캯��
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
    this->m_salary = salary;
    this->m_ability = ability;
} //��ֵ
void coach::showInfo()//��ʾ������Ϣ
{
    cout << "ְ����ţ� " << this->m_Id
        << "\tְ�������� " << m_Name
        << "\t��λ�� " << this->getDeptName()
        << "\t��λְ�� �������ѵ����ս������"
        << "\t��н��" << this->m_salary
        << "\t��������ֵ��" << this->m_ability
        << endl;
}
string coach::getDeptName()//��ȡ��λ����
{
    return string("����");
}