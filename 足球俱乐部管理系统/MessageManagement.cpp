#include"MessageManagement.h"
void MessageManagement::erasepoint(string filename)//清空文件
{
	ofstream outfile(filename, ios::out | ios::trunc); // 打开文件并截断，即清空文件内容
	if (!outfile) {
		cerr << "无法打开意见箱" << filename << "进行清空" << endl;
		return;
	}
	outfile.close(); // 关闭文件
}
void MessageManagement::Enterpoint(string filename)//写入意见
{
	ofstream outfile(filename, ios::out | ios::app); // 打开文件进行写入操作
	if (!outfile)
	{
		cerr << "无法打开意见箱" << filename << "写下意见" << endl;
		return;
	}
	cout << "请输入您的意见：" << endl;
	string opinion = " ";
	cin >> opinion;// 获取用户输入的意见

	outfile << opinion; // 将意见写入文件
	outfile << "|";
	cout << "意见已成功发送到意见箱" << endl;
	outfile.close(); // 关闭文件
}
void MessageManagement::Getpoint(string filename)//读取意见
{
	ifstream infile(filename, ios::in); // 打开文件进行读取操作
	if (!infile)
	{
		cerr << "无法打开意见箱" << filename << "阅读意见" << endl;
		return;
	}
	string opinion;
	getline(infile, opinion); // 从文件中读取意见
	if (opinion.empty()) {
		cout << "意见箱中暂无意见投稿呢" << endl;
	}
	else {
		cout << "各位的意见是：" << opinion << endl;
	}
	infile.close(); // 关闭文件
}