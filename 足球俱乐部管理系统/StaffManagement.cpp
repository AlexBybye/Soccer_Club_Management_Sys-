#include "StaffManagement.h"
#include<iostream>
#include <sstream>
using namespace std;
StaffManagement::StaffManagement()
{
	//1:�ļ������ڳ�ʼ������
	ifstream ifs;
	ifs.open(FILENAME1, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2:�ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3:�ļ����ڲ��Ҽ�¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ�� " << num << endl;
	this->m_EmpNum = num;
	//���濪�ٿռ�
	this->m_EmpArray = new Staff * [this->m_EmpNum];
	//���ļ����ݴ浽����
	this->init_Emp();
}

void StaffManagement::Show_Menu() // �û��˵�����
{
	cout << "\t*******************************************" << endl;
	cout << "\t ****** ��ӭʹ��������ֲ�����ϵͳ! ******" << endl;
	cout << "\t*******************************************" << endl;
	cout << "\t____________________________________________" << endl;
	cout << "\t|***  0. �˳��������\t\t\t***|" << endl;
	cout << "\t|***  1. ����Ա����Ϣ\t\t\t***|" << endl;
	cout << "\t|***  2. ��ʾԱ����Ϣ\t\t\t***|" << endl;
	cout << "\t|***  3. ɾ�����Ա��\t\t\t***|" << endl;
	cout << "\t|***  4. �޸�Ա����Ϣ\t\t\t***|" << endl;
	cout << "\t|***  5. ����Ա����Ϣ\t\t\t***|" << endl;
	cout << "\t|***  6. ����Ա������\t\t\t***|" << endl;
	cout << "\t|***  7. ��ɢ���ֲ��ײ�\t\t\t***|" << endl;
	cout << "\t|***  8. �޸ľ��ֲ��ʽ�\t\t\t***|" << endl;
	cout << "\t|***  9. �޸ľ��ֲ�����\t\t\t***|" << endl;
	cout << "\t|*** 10. ��ʾ���ֲ���Ϣ\t\t\t***|" << endl;
	cout << "\t|*** 11. ��ɢ���ֲ��߲�\t\t\t***|" << endl;
	cout << "\t|*** 12. �����¾��ֲ�\t\t\t***|" << endl;
	cout << "\t|*** 13. Ͷ�������\t\t\t***|" << endl;
	cout << "\t|*** 14. �鿴�����\t\t\t***|" << endl;
	cout << "\t|*** 15. ��������\t\t\t***|" << endl;
	cout << "\t--------------------------------------------" << endl;
	cout << endl;
}
void StaffManagement::exitSystem()//�˳�ϵͳ
{
	cout << "��ӭ�´�ʹ��!" << endl;
	system("pause");
	exit(0);
}

void StaffManagement::fundgiveme(string &n, int&c)
{
	ifstream ifs;
	ifs.open(FILENAME2,ios::in);
	ifs >> n;
	ifs >> c;
	ifs.close();
}
void StaffManagement::fundbackyou(string& n, int& d)//������ĺ��ʽ�
{
	ofstream ofs;
	ofs.open(FILENAME2,ios::out);
	ofs.flush();
	ofs << n <<" "<< d;
	ofs.close();
}
void StaffManagement::Add_Emp()//���
{
	cout << "�����뽻������ְ������: " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//��Ӳ���������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ�����
		//�����¿ռ�
		Staff** newSpace = new Staff * [newSize];
		//����ԭ������
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������
		string name;
		fundgiveme(name, club1_fund);

		// ������ְ������н�ܺ�
		int totalSalary = 0;
		int salary1;
		cout << "���ֲ������ʽ�Ϊ��" << club1_fund << endl;
		cout << "�����������ְ������н��" << endl;
		for (int j = 0; j < addNum; j++)
		{
			cin >> salary1;
			// ������ְ����н...
			totalSalary += salary1; // ���� salary ����ְ������н
		}
		// �ж��Ƿ񳬳����ֲ��ʽ�
		if (totalSalary > club1_fund)
		{
			cout << "��н�ܺͳ������ֲ��ʽ��޷������ְ����" << endl;
			return;
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��
			int salary;
			int ability;
			string speciality;

			cout << "������� " << i + 1 << " ����ְ����ţ� " << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ�������� " << endl;
			cin >> name;
			cout << "������� " << i + 1 << " ����ְ����н�� " << endl;
			cin >> salary;
			cout << "������� " << i + 1 << " ����ְ������ֵ�� " << endl;
			cin >> ability;
			cout << "��ѡ���ְ����λ�� " << endl;
			cout << "1������" << endl;
			cout << "2��ǰ��" << endl;
			cout << "3���г�" << endl;
			cout << "4������" << endl;
			cout << "5���Ž�" << endl;
			cin >> dSelect;
			if (dSelect != 1)
			{
				cout << "���������Ա�ĸ��˼���" << endl;
				cin >> speciality;
			}
			Staff* staff = NULL;
			switch (dSelect)
			{
			case 1:
				staff = new coach(id, name, 1, salary, ability);
				break;
			case 2:
				staff = new striker(id, name, 2, salary, ability, speciality);
				break;
			case 3:
				staff = new midfield(id, name, 3, salary, ability, speciality);
				break;
			case 4:
				staff = new defender(id, name, 4, salary, ability, speciality);
				break;
			case 5:
				staff = new goalkeeper(id, name, 5, salary, ability, speciality);
				break;
			default:
				break;
			}
			*(newSpace + this->m_EmpNum + i) = staff;
			//������Ա��ְ�𣬱�������֮��
			club1_fund -= salary;
            
		}
		fundbackyou(name,club1_fund);
		delete[] this->m_EmpArray;//�ͷ�ԭ�пռ�
		this->m_EmpArray = newSpace;//�����¿ռ�ָ��
		this->m_EmpNum = newSize;//������ְ������
		this->m_FileIsEmpty = false;//׷�ӷǿ�״̬
		this->save();//�������ݵ��ļ���
		cout << "�ɹ����" << addNum << "����ְ��" << endl;//��ʾ�ɹ�
	}
	else
	{
		cout << "������������" << endl;//������ʾ
	}
	
	//������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//���汣���ļ�
void StaffManagement::save()
{
	ofstream ofs;
	ofs.open(FILENAME1, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_DeptId == 1)
		{
			ofs << this->m_EmpArray[i]->m_Id << " "
				<< this->m_EmpArray[i]->m_Name << " "
				<< this->m_EmpArray[i]->m_DeptId << " "
				<< this->m_EmpArray[i]->m_salary << " "
				<< this->m_EmpArray[i]->m_ability << " "
				<< endl;
		}
		else
		{
			ofs << this->m_EmpArray[i]->m_Id << " "
				<< this->m_EmpArray[i]->m_Name << " "
				<< this->m_EmpArray[i]->m_DeptId << " "
				<< this->m_EmpArray[i]->m_salary << " "
				<< this->m_EmpArray[i]->m_ability << " "
				<< this->m_EmpArray[i]->m_speciality<<" "
				<< endl;
		}
	}
	//�ر��ļ�
	ofs.close();
}

int StaffManagement::get_EmpNum()//3���õ���ͳ�ƺ�����
{
	ifstream ifs;
	ifs.open(FILENAME1, ios::in);
	if (!ifs.is_open()) {
		// �ļ���ʧ�ܣ��������
		return -1;
	}
	int id;
	string name;
	int dId;
	int salary;
	int ability;
	string speciality;
	int num = 0;
	string line;
	while (getline(ifs, line))
	{
		istringstream iss(line);
		// ���ж�ȡԱ����Ϣ
		if (iss >> id >> name >> dId >> salary >> ability) {
			// ͳ������
			num++;
			// ������ű�Ų���1�����ȡ�س���Ϣ
			if (dId != 1) {
				iss >> speciality;
			}
		}
	}
	// �ر��ļ�
	ifs.close();

	return num;
}
void StaffManagement::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME1, ios::in);
	if (!ifs) 
	{
		std::cerr << "�޷����ļ�" << std::endl;
		return;
	}
	int id;
	string name;
	int dId;
	int salary;
	int ability;
	string speciality;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId&&ifs>>salary&&ifs>>ability&&ifs>>speciality)
	{
		Staff* staff = NULL;

		if (dId == 1)//����
		{
			staff = new coach(id, name, dId,salary,ability);
		}
		else if (dId == 2)//ǰ��
		{
			staff = new striker(id, name, dId,salary,ability,speciality);
		}
		else if (dId == 3)//�г�
		{
			staff = new midfield(id, name, dId, salary, ability, speciality);
		}
		else if (dId == 4)//����
		{
			staff = new striker(id, name, dId, salary, ability, speciality);
		}
		else if (dId == 5)//�Ž�
		{
			staff = new goalkeeper(id, name, dId, salary, ability, speciality);
		}
		this->m_EmpArray[index] = staff;
		index++;//��������
	}
	ifs.close();
}

void StaffManagement::Show_Emp()//��ʾԱ����Ϣ
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// ���ָ����Ч��
			if (m_EmpArray[i] != nullptr)
			{
				// ���ö�̬���ó���ӿ�
				m_EmpArray[i]->showInfo();
			}
			else
			{
				cout << "������Ч��Ա������ָ��" << endl;
			}
		}
	}
	//�����������
	system("pause");
	system("cls");
}
//����ְ�� ���ʾ�������Ǩ�ƣ���Ҫɾ����һλ��ʼ�ƶ�(ɾ����Ա�ڽ����ϲ���������Ҫ���ٽ��������ݣ�ɾ����Ա�ǽ����·������øı䣩
void StaffManagement::Del_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		return;
	}
	else
	{
		cout << "������Ҫɾ��Ա���ı��" << endl;
		int id = 0;
		cin >> id;
		//Ѱ��Ҫɾ����Ա��������
		int indexToDelete = -1;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != nullptr && this->m_EmpArray[i]->m_Id== id) {
				indexToDelete = i;
				break;
			}
		}

		if (indexToDelete == -1) {
			cout << "δ�ҵ��˱��Ա��" << endl;
			return;
		}
		// ɾ��Ա�����ͷ��ڴ�
		delete this->m_EmpArray[indexToDelete];
		this->m_EmpArray[indexToDelete] = nullptr;

		// �ƶ������Ԫ�����λ
		for (int i = indexToDelete; i < this->m_EmpNum - 1; i++) {
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpArray[this->m_EmpNum - 1] = nullptr; // ������ĩβ��Ϊnullptr

		// ����Ա������
		this->m_EmpNum--;

		// ��鲢���������еĽ�������Աλ��
		for (int i = indexToDelete; i < this->m_EmpNum; i++) {
			// �����ǰλ������Ա���������Ϸ��ǽ���������Ա����
			if (i > 0 && this->m_EmpArray[i] != nullptr && this->m_EmpArray[i]->m_DeptId != 1 &&
				this->m_EmpArray[i - 1] != nullptr && this->m_EmpArray[i - 1]->m_DeptId == 1)
			{
				swap(this->m_EmpArray[i], this->m_EmpArray[i - 1]);
				i--; // ���¼�������Ƶ�Ա��
			}
		}

		// ͬ�����ļ�
		this->save();
		cout << "ɾ���ɹ���" << endl;
	}
}

int StaffManagement::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}
//�޸�ְ��
void StaffManagement::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{ //���ձ��ɾ��
		cout << "������Ҫ�޸�Ա���ı��" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)//ְ��������Ҫ�޸�index����Ա��
		{
			//���ҵ���ŵ�ְ��
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			int newsalary = 0;
			int newability = 0;
			string newspeciality = "";
			cout << "�鵽: " << id << "��ְ��, ��������ְ����:" << endl;
			cin >> newId;
			cout << "������������:" << endl;
			cin >> newName;
			cout << "�������λ:" << endl
				<< "1������" << endl
				<< "2��ǰ��" << endl
				<< "3���г�" << endl
				<< "4������" << endl
				<< "5���Ž�" << endl;
			cin >> dSelect;
			cout << "�������µ�нˮ��" << endl;
			cin >> newsalary;
			cout << "�������µ�����ֵ��" << endl;
			cin >> newability;
			if (dSelect != 1)
			{
				cout << "���������Ա�ĸ����س���";
				cin >> newspeciality;
			}
			
			Staff* staff = NULL;
			switch (dSelect)
			{
			case 1:
				staff = new coach(newId, newName, dSelect,newsalary,newability);
				break;
			case 2:
				staff = new striker(newId, newName, dSelect,newsalary, newability,newspeciality);
				break;
			case 3:
				staff = new midfield(newId, newName, dSelect, newsalary, newability, newspeciality);
				break;
			case 4:
				staff = new defender(newId, newName, dSelect, newsalary, newability, newspeciality);
				break;
			case 5:
				staff = new goalkeeper(newId, newName, dSelect, newsalary, newability, newspeciality);
				break;
			default:
				break;
			}
			//�������ݻص�����
			this->m_EmpArray[ret] = staff;
			cout << "�޸ĳɹ���" << endl;
			//ͬ�����ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}

	}
	//�����������
	system("pause");
	system("cls");
}
//����Ա��
void StaffManagement::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1�����ձ�Ų飺" << endl;
		cout << "2�����������飺" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "���������Ա����ţ�" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				//�ҵ�ְ��
				cout << "���ҳɹ�����Ա����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ�δ�ҵ���Ա��" << endl;
			}
		}
		else if (select == 2)
		{
			//����������
			string name;
			cout << "���������������" << endl;
			cin >> name;

			//�����жϲ����Ƿ�鵽
			bool flag = false;//Ĭ��û�ҵ�

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< this->m_EmpArray[i]->m_Id
						<< "��,��ְ����Ϣ���£�" << endl;
					flag = true;
					//������ʾ��Ϣ�ӿ�
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ�δ�ҵ���ְ��" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

void StaffManagement::Sort_Emp()
{    
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		//�����������
		system("pause");
		system("cls");
	}
	else
	{

		cout << "��ѡ������ʽ:" << endl;
		cout << "1��������ֵ���н���" << endl;
		cout << "2������н���н���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrmax = i;//������Сֵ�����ֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����ability
				{
					if (this->m_EmpArray[minOrmax]->m_ability < this->m_EmpArray[j]->m_ability)
					{
						minOrmax = j;
					}
				}
				if (select == 2)//����salary
				{
					if (this->m_EmpArray[minOrmax]->m_salary < this->m_EmpArray[j]->m_salary)
					{
						minOrmax = j;
					}
				}
			}
			//�ж�һ��ʼ�϶���Сֵ���ֵ�Ƿ��Ǽ������С���ֵ�������򽻻�����
			if (i != minOrmax)
			{
				Staff* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}
		}
		cout << "����ɹ����������Ϊ��" << endl;
		this->save();//���������浽�ļ�
		this->Show_Emp();
	}
}
//����ļ�
void StaffManagement::Clean_File()
{
	cout << "ȷ����ɢ�����ֲ�������Ա��" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME1, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "�ɹ���ɢ��" << endl;
	}
	system("pause");
	system("cls");
}
StaffManagement::~StaffManagement()//������Բ�д��ϵͳ�Զ�����
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}