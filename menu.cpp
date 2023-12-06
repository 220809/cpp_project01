#include <iostream>
using namespace std;

void printMainMenu()
{
	cout << "+---------- 记账本 ----------+" << endl;
	cout << "|          1. 记账           |" << endl;
	cout << "|          2. 查询           |" << endl;
	cout << "|          3. 退出           |" << endl;
	cout << "+----------------------------+" << endl;
	cout << "请输入选项: ";
}

void printAccountMenu()
{
	cout << "+----------------------------+" << endl;
	cout << "|          1. 收入           |" << endl;
	cout << "|          2. 支出           |" << endl;
	cout << "|          3. 返回           |" << endl;
	cout << "+----------------------------+" << endl;
	cout << "请输入选项: ";
}

void printSearchMenu()
{
	cout << "+----------------------------+" << endl;
	cout << "|        1. 总收支           |" << endl;
	cout << "|        2. 收入记录         |" << endl;
	cout << "|        3. 支出记录         |" << endl;
	cout << "|        4. 返回             |" << endl;
	cout << "+----------------------------+" << endl;
	cout << "请输入选项: ";
}