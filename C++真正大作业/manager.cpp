#include"manager.h"


manager::manager(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}
void manager::showInfo()
{
    cout << "ְ����ţ� " << this->m_Id << "\tְ�������� " << m_Name << "\t��λ�� " << this->getDeptName() << "\t��λְ�� ����ϰ彻�������񣬲��·�����" << endl;

}
string manager::getDeptName()
{
    return string("����");
}