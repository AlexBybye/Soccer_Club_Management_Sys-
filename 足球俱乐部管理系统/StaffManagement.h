#include"coach.h"
#include"defender D.h"
#include"goalkeeper GK.h"
#include"midfield M.h"
#include"striker F.h"
#include "ClubManagement.h"
#define FILENAME1 "Clubmembers.txt"//���ֲ�����Ա������������Ա���Ĵ�����Ϣ�ļ�
using namespace std;
class StaffManagement
{
private:
	int club1_fund=0;
public:
	//���캯��
	StaffManagement();
	//չʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ����
	void exitSystem();
	//��¼Ա������
	int m_EmpNum;
	//Ա������ָ��
	Staff** m_EmpArray;//��CPP��ʼ��
	//������Ա����
	void Add_Emp();
	//�����ļ�
	void save();
	//׷���ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	//ͳ����������
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾԱ����Ϣ
	void Show_Emp();
	//ɾ�����Ա��
	void Del_Emp();
	//�жϸ�ְ���������
	int IsExist(int id);
	//�޸�Ա����Ϣ
	void Mod_Emp();
	//����Ա��
	void Find_Emp();
	//����Ա��
	void Sort_Emp();
	//����ļ�����ɢ���ֲ��ײ�����Ա����
	void Clean_File();
	//ClubManagement��fund����StaffManagement�Ĵ�ֵ����
	void fundgiveme(string&,int &);
	//��StaffManagement��fund���صĴ�ֵ����
	void fundbackyou(string&,int&);
	//��������
	~StaffManagement();
};