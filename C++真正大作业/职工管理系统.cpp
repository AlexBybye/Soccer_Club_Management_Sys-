//���������ࣺ���û���ͨ�˵�
//��ְ����ɾ�Ĳ�
//���ļ���д����
//һ�㴴��һ��.h һ��.cpp
//�����뷨��
// ����Ҫ�ӿڶ�����main�У�Ҳ��������CPP
// ����Ҫ���ú����������� ͷ�ļ�����������Ĺ�ϵ��ͷ�ļ����Ծ��Ǽ򵥵ĳ�Ա��
//               һ�㶼����ͷ�ļ�ͬ��CPP�ļ����г�Ա�����Ķ���
//               ע�⣺������û��ʵ�֣����Բ��ô���.CPP
//               ע�⣺���ڲ�ͬ��ѡ���ͷ�ļ���д��
// ������д�̳е�ʱ��ǵ���������ͷ�ļ�ʱ��������ͷ�ļ�����
//
#include<iostream>
using namespace std;
#include"WorkerManager.h"
#include"Worker.h"
#include"employee.h"
#include"boss.h"

int main()
{
    WorkerManager wm;
	
	
	while (1)
	{
		int choice = 0;//�洢�û�ѡ��
		wm.Show_Menu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //�˳�ϵ�y
			wm.exitSystem();
			break;
		case 1: //���ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3: //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4: //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5: //����ְ��
			wm.Find_Emp();
			break;
		case 6: //����ְ��
			wm.Sort_Emp();
			break;
		case 7: //����ļ�
			wm.Clean_File();
			break;
		default:
			system("cls");//����
			break;
		}
	}
	system("pause");
}

