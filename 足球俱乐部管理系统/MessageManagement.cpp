#include"MessageManagement.h"
void MessageManagement::erasepoint(string filename)//����ļ�
{
	ofstream outfile(filename, ios::out | ios::trunc); // ���ļ����ضϣ�������ļ�����
	if (!outfile) {
		cerr << "�޷��������" << filename << "�������" << endl;
		return;
	}
	outfile.close(); // �ر��ļ�
}
void MessageManagement::Enterpoint(string filename)//д�����
{
	ofstream outfile(filename, ios::out | ios::app); // ���ļ�����д�����
	if (!outfile)
	{
		cerr << "�޷��������" << filename << "д�����" << endl;
		return;
	}
	cout << "���������������" << endl;
	string opinion = " ";
	cin >> opinion;// ��ȡ�û���������

	outfile << opinion; // �����д���ļ�
	outfile << "|";
	cout << "����ѳɹ����͵������" << endl;
	outfile.close(); // �ر��ļ�
}
void MessageManagement::Getpoint(string filename)//��ȡ���
{
	ifstream infile(filename, ios::in); // ���ļ����ж�ȡ����
	if (!infile)
	{
		cerr << "�޷��������" << filename << "�Ķ����" << endl;
		return;
	}
	string opinion;
	getline(infile, opinion); // ���ļ��ж�ȡ���
	if (opinion.empty()) {
		cout << "��������������Ͷ����" << endl;
	}
	else {
		cout << "��λ������ǣ�" << opinion << endl;
	}
	infile.close(); // �ر��ļ�
}