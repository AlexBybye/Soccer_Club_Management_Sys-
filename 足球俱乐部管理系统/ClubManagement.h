#pragma once
#include"club.h"
#include<fstream>
#define FILENAME2 "Clubrunning.txt"
using namespace std;
class ClubManagement
	//����Ϊ���ֲ������࣬Ϊ������ֲ�����ģ�麯���ļ���
	//����club*���͵ľ��ֲ�����cm_name���ʽ�cm_fund�Լ������ж��ļ��Ƿ�Ϊ�յ�bool����m_FileISEmpty
{
private:
	bool m_FileISEmpty;//�ж��ļ��Ƿ�Ϊ��
	club* cm_name;
	club* cm_fund;
public:
	friend class club;//������Ԫ
	friend class StaffManagement;//������Ԫ
	ClubManagement();//�����캯��
	void init_Club();//��ʼ�����ݲ���������
	//�����ļ�
	void saveclub(); //(Ϊ����StaffManagement��save���𣬺������ĳ���saveclub������
	//��ʾ
	void Show_Club();
    //�޸��ʽ�
	void changeClubfund();
    //�޸Ķ�����
	void changeClubname();
	//��ɢ���ֲ��߲�
	void Clean_file();
	//�������ֲ�
	void Create_club();
    //������������
	~ClubManagement();
};
