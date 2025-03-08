#include "WorkerManager.h"
#include<iostream>
using namespace std;
WorkerManager::WorkerManager()
{
	//1:�ļ������ڳ�ʼ������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open())
	{	
		//cout << "�ļ������ڣ�" << endl;
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
		//cout << "�ļ�Ϊ�գ�" <<endl;
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
	this->m_EmpNum=num;
	//���濪�ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ����ݴ浽����
	this->init_Emp();
	//���Դ���
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ� " << this->m_EmpArray[i]->m_Id
			<< "������ " << this->m_EmpArray[i]->m_Name
			<< "���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}


void WorkerManager::Show_Menu()
{

	cout << "*************************************" << endl;
	cout << "*******��ӭʹ��ְ������ϵͳ!*********" << endl;
	cout << "*********** 0.�˳�������� **********" << endl;
	cout << "*********** 1.����ְ����Ϣ **********" << endl;
	cout << "*********** 2.��ʾְ����Ϣ **********" << endl;
	cout << "*********** 3.ɾ����ְְ�� **********" << endl;
	cout << "*********** 4.�޸�ְ����Ϣ **********" << endl;
	cout << "*********** 5.����ְ����Ϣ **********" << endl;
	cout << "*********** 6.���ձ������ **********" << endl;
	cout << "*********** 7.��������ĵ� **********" << endl;
	cout << endl;
}
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp()
{
	cout << "��������ӵ�ְ������: " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//��Ӳ���������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ�����
		//�����¿ռ�
		Worker** newSpace=new Worker* [newSize];
		//����ԭ������
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i <this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��
			cout << "������� " << i + 1 << " ����ְ����ţ� " << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ�������� " << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 1);
				break;
			case 3:
				worker = new boss(id, name, 1);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
			//������Ա��ְ�𣬱�������֮��

		}
		delete[]this->m_EmpArray;//�ͷ�ԭ�пռ�
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
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//�ر��ļ�
	ofs.close();
}
int WorkerManager::get_EmpNum()//3���õ���ͳ�ƺ�����
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//ͳ������
		num++;
	}
	return num;
}
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)//��ͨԱ��
		{
			worker = new employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new manager(id, name, dId);
		}
		else if (dId == 3)//�ϰ�
		{
			worker = new boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;//��������
	}
	ifs.close();
}
//��ʾԱ����Ϣ
void WorkerManager::Show_Emp()
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
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	//�����������
	system("pause");
	system("cls");
}
//ɾ��ְ�� ���ʾ�������Ǩ�ƣ���Ҫɾ����һλ��ʼ�ƶ�
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{ //���ձ��ɾ��
		cout << "������Ҫɾ��Ա���ı��" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)//ְ��������Ҫɾ��index����Ա��
		{
			//����ǰ��
			for (int i = 0; i < m_EmpNum; i++)
			{
				//���ö�̬���ó���ӿ�
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--;//������Ա������
			//ͬ�����ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	
	}
	//�����������
	system("pause");
	system("cls");
}
//�жϴ治���ڣ����򷵻�λ�ã����򷵻�-1
int WorkerManager::IsExist(int id)
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
void WorkerManager::Mod_Emp()
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
			cout << "�鵽: " << id << "��ְ��, ��������ְ����:" << endl;
			cin >> newId;

			cout << "������������:" << endl;
			cin >> newName;
			cout << "�������λ:" << endl
				<< "1����ְͨ��" << endl
				<< "2������" << endl
				<< "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(newId, newName, dSelect);
			case 2:
				worker = new manager(newId, newName, dSelect);
			case 3:
				worker = new boss(newId, newName, dSelect);
			default:
				break;
			}
				//�������ݻص�����
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ���" << endl;
			//ͬ�����ļ���
			this->save();	
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}

	}
	//�����������
	system("pause");
	system("cls");
}
//����Ա��
void WorkerManager::Find_Emp()
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
			cout << "���������ְ����ţ�" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				//�ҵ�ְ��
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ�δ�ҵ���ְ��" << endl;
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

//�������Ա��
void WorkerManager::Sort_Emp()
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
	cout << "1����ְ���Ž�������" << endl;
	cout << "2����ְ���Ž��н���" << endl;
	int select = 0;
	cin >> select;
	for (int i = 0; i < m_EmpNum; i++)
	{
		int minOrmax = i;//������Сֵ�����ֵ�±�
		for (int j = i + 1; j <this->m_EmpNum; j++)
		{
			if (select == 1)//����
			{
				if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id)
				{
					minOrmax = j;
				}
			}
			else if (select == 2)//����
			{
				if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id)
				{
					minOrmax = j;
				}	
			}
		}
		//�ж�һ��ʼ�϶���Сֵ���ֵ�Ƿ��Ǽ������С���ֵ�������򽻻�����
		if (i != minOrmax)
		{
			Worker* temp = this->m_EmpArray[i];
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
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);
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
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()//������Բ�д��ϵͳ�Զ�����
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
