#include"StaffManagement.h"
#include"MessageManagement.h"
using namespace std;
int main()
{
	StaffManagement wm;
	ClubManagement vm;
	MessageManagement um;
	int password = 0;
	int safety = 5;//������Կ����
	int choice = 0;//�洢�û�ѡ��
	int decision = 0;
	cout << "��ӭʹ��������ֲ�����ϵͳ��" << endl;
Retry:
	if (safety)
	{
		
		cout << "������������Կ��" << endl;
		cout << "������" << safety << "�λ��ᣬ�����������Կ��" << endl;
		//��Ա��Կ�ݶ�100**��**Ϊ���±�ţ�������Կ101**,**Ϊ�����࣬������Կ10201)
		while (cin >> password)
		{
			if (password >=10000&&password <10100)
			{
				choice = 0;
				cout <<"��"<<password-10000 << "����Ա���ã�����������ѡ��:" << endl;
				while (1)
				{   
					wm.Show_Menu();
					cin >> choice;
					switch (choice)
					{
					case 0: //�˳�ϵͳ
						wm.exitSystem();
						break;
					case 1: //ת������ְ��
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 2://��ʾְ��
						wm.Show_Emp();
						break;
					case 3: //ת������ְ��
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 4: //�޸�ְ��
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 5: //����ְ��
						wm.Find_Emp();
						break;
					case 6: //����ְ��
						wm.Sort_Emp();
						break;
					case 7: //��ɢ���ֲ�
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 8://�ı���ֲ��ʽ�
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 9://�ı���ֲ�����
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 10://��ʾ���ֲ����ּ��ʽ�
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 11://��ɢ���ֲ��߲�
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 12://�������ֲ�
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 13://��Ա�����˷���
						cout << "����������Ҫ�����������" << endl;
						um.Enterpoint(FILENAME3);
						system("pause");
						system("cls");//����
						break;
					case 14://���¶˲鿴
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 15://���¶����
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					default:
						system("cls");//����
						break;
					}
				}
			}
			if (password >= 10100 && password < 10200)
			{
				choice = 0;//�洢�û�ѡ��
				cout << "�������ã�����������ѡ��:" << endl;
				while (1)
				{
					wm.Show_Menu();
					cin >> choice;
					switch (choice)
					{
					case 0: //�˳�ϵͳ
						wm.exitSystem();
						break;
					case 1: //ת������ְ��
						//wm.fundgiveme(vm);
						wm.Add_Emp();
						break;
					case 2://��ʾְ��
						wm.Show_Emp();
						break;
					case 3: //ת������ְ��
						//wm.fundgiveme(vm);
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
					case 7: //��ɢ���ֲ�
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 8://�ı���ֲ��ʽ�
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 9://�ı���ֲ�����
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 10://��ʾ���ֲ����ּ��ʽ�
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 11://��ɢ���ֲ��߲�
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 12://�������ֲ�
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 13://��Ա�����˷���
						cout << "����������Ҫ�����������" << endl;
						um.Enterpoint(FILENAME3);
						system("pause");
						system("cls");//����
						break;
					case 14://���¶˲鿴
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 15://���¶����
						cout << "��û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					default:
						system("pause");
						system("cls");//����
						break;
					}
				}
			}
			if (password == 10201)
			{
				choice = 0;//�洢�û�ѡ��
				cout << "�������ã�����������ѡ��:" << endl;
				while (1)
				{
					wm.Show_Menu();
					cin >> choice;
					switch (choice)
					{
					case 0: //�˳�ϵͳ
						wm.exitSystem();
						break;
					case 1: //ת������ְ��
						//wm.fundgiveme(vm);
						wm.Add_Emp();
						break;
					case 2://��ʾְ��
						wm.Show_Emp();
						break;
					case 3: //ת������ְ��
						//wm.fundgiveme(vm);
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
					case 7: //��ɢ���ֲ�
						wm.Clean_File();
						break;
					case 8://�ı���ֲ��ʽ�
						vm.changeClubfund();
						break;
					case 9://�ı���ֲ�����
						vm.changeClubname();
						break;
					case 10://��ʾ���ֲ����ּ��ʽ�
						vm.Show_Club();
						break;
					case 11://��ɢ���ֲ��߲�
						vm.Clean_file();
						break;
					case 12://�������ֲ�
						vm.Create_club();
						break; 
					case 13://��Ա�����˷���
						cout << "�𾴵Ķ��£���û��Ȩ�޽��д˲�����" << endl;
						system("pause");
						system("cls");//����
						break;
					case 14://���¶˲鿴
						cout << "�𾴵Ķ��£����ڵ�������£�" << endl;
						um.Getpoint(FILENAME3);
						system("pause");
						system("cls");//����
						break;
					case 15://���¶����
						cout << "��ȷ��Ҫ����������" << endl;
						cout << "1��YES!" << endl << "2��NO!" << endl;
						cin >> decision;
						if (decision == 1)
						{
							um.erasepoint(FILENAME3);
							cout << "��ճɹ���" << endl;
							system("pause");
							system("cls");//����
							break;
						}
						else
							cout << "�˻سɹ���" << endl;
							break;
						
					default:
						system("pause");
						system("cls");//����
						break;
					}
				}
			}
			else
			{
				cout << "������Կ�������������룡" << endl;
				safety--;
				goto Retry;
			}
		}
	}
	else//��λ����ù���
	{
		cout << "���������Կ�������࣡�Զ��˳�����" << endl;
		system("pause");
		return 0;
	}
	
	system("pause");
}

