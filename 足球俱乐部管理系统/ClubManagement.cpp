#include"ClubManagement.h"
#include<iostream>
using namespace std;
ClubManagement::ClubManagement()
{
	//1:�ļ������ڳ�ʼ������
	ifstream ifs;
	ifs.open(FILENAME2, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		this->cm_name = 0;
		this->cm_fund = 0;//��ʼ��
		this->m_FileISEmpty = true;
		ifs.close();
		return;
	}
	//2:�ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" <<endl;
		this->cm_name = 0;
		this->cm_fund = 0;//��ʼ��
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileISEmpty = true;
		ifs.close();
		return;
	}	
	//3:�ļ����ڲ��Ҽ�¼����
	//���ļ����ݴ浽����
	this->init_Club();
}
//���汣���ļ�(Ϊ����StaffManagement��save���𣬺������ĳ���saveclub������
void ClubManagement::saveclub()
{
	ofstream ofs;
	ofs.open(FILENAME2, ios::out);
	ofs << cm_name->c_name << " " << cm_fund->c_fund << endl;
	//�ر��ļ�
	ofs.close();
}
void ClubManagement::init_Club()//��ʼ������������
{
	ifstream ifs;
	ifs.open(FILENAME2, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		m_FileISEmpty = true;
		return;
	}
	m_FileISEmpty = false;
	string name;
	int fund;
	ifs >> name >> fund;
	// �������ֲ�����
	cm_name = new club(name, fund);
	cm_fund = new club(name, fund);
	ifs.close();
}
void ClubManagement::Show_Club()//��ʾ
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileISEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		return;
	}
	else
	{
		// ���ָ�벻Ϊ�գ�����ʾ���ֲ���Ϣ
		if (this->cm_fund && this->cm_name)
		{
			cout << "���ֲ�����: " << this->cm_name->c_name << endl;
			cout << "���ֲ��ʽ�: " << this->cm_fund->c_fund << endl;
		}
		else
		{
			cout << "ָ��Ϊ�գ��޷���ʾ���ֲ���Ϣ" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}
void ClubManagement::changeClubfund()//�޸��ʽ���
{
	if (this->m_FileISEmpty) 
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else 
	{
		int c_newfund = 0;
		cout << "��������ֲ��µ��ʽ�" << endl;
		cin >> c_newfund;

		// ʹ�õ�ǰ���ֲ����ʽ�
		cm_fund->c_fund = c_newfund;

		cout << "�޸ĳɹ���" << endl;
		// ͬ�����ļ���
		this->saveclub();
		Show_Club();//����ʾ��Ϣ
	}
}

void ClubManagement::changeClubname()//�޸ľ��ֲ�����
{
	if (this->m_FileISEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else 
	{
		string c_newname = "";
		cout << "��������ֲ��µ�����" << endl;
		cin >> c_newname;

		// ʹ�õ�ǰ���ֲ�������
		cm_name->c_name = c_newname;

		cout << "�޸ĳɹ���" << endl;
		// ͬ�����ļ���
		this->saveclub();
		Show_Club();//����ʾ��Ϣ
	}
}
void ClubManagement::Clean_file()//����ļ���Ҳ���ǽ�ɢ���ֲ��߲���������
//���ֲ��߲�������ֺ��ʽ�
{
	cout << "ȷ����ɢ�����ֲ����²㣿" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME2, ios::trunc);
		ofs.close();
		if (cm_name != nullptr)
			delete cm_name;
		if (cm_fund != nullptr)
			delete cm_fund;
		this->m_FileISEmpty = true;
		cout << "�ɹ���ɢ��" << endl;
	}
system("pause");
system("cls");
}
void ClubManagement::Create_club()//�������ֲ�����
{
	if (!m_FileISEmpty)
	{
		cout << "�ļ����Ѵ��ھ��ֲ����ݣ��޷������¾��ֲ�" << endl;
		system("pause");
		return;
	}
	string name;
	int fund;
	cout << "�������¾��ֲ�������: ";
	cin >> name;
	cout << "�������¾��ֲ����ʽ�: ";
	cin >> fund;
	cm_name = new club(name, fund);
	cm_fund = new club(name, fund);
	saveclub();
	cout << "���ֲ������ɹ���" << endl;
	m_FileISEmpty = false;
	system("pause");
	system("cls");
}
ClubManagement::~ClubManagement()//�䱾��������������ֹ���
{
	if (this->cm_name != NULL)
	{
		delete cm_name;
		this->cm_name = 0;
	}
	if (this->cm_fund != NULL)
	{
		delete cm_fund;
		this->cm_fund = 0;
	}
}
	