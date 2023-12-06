#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

struct AmountInfo
{
	int amount;
	string remark;
	bool isIncome;
};
AmountInfo createAmountInfo(int amount, string remark);
void printAmountInfo(AmountInfo amountInfo);

void storeAmountInfos(vector<AmountInfo>& infos)
{
	ofstream output("storage.txt");
	for (AmountInfo info : infos)
	{
		output << info.amount << endl;
		output << info.remark << endl;
	}
}

void addRecord(vector<AmountInfo>& infos, int amount, string remark)
{
	AmountInfo info = createAmountInfo(amount, remark);
	infos.push_back(info);
	storeAmountInfos(infos);
}

void printRecords(vector<AmountInfo>& infos, int& total) 
{
	for (AmountInfo info : infos)
	{
		printAmountInfo(info);
		total += info.amount;
	}
}

void printRecords(vector<AmountInfo>& infos, bool isIncome, int & total)
{
	for (AmountInfo info : infos)
	{
		if (isIncome == info.isIncome) 
		{
			printAmountInfo(info);
			total += info.amount;
		}
	}
}

void loadAmountInfos(vector<AmountInfo>& infos) {
	ifstream input("storage.txt");
	int amount;
	string line;
	string remark;
	while (getline(input, line))
	{
		stringstream(line) >> amount;
		getline(input, remark);
		AmountInfo info = createAmountInfo(amount, remark);
		infos.push_back(info);
	}
}

void addIncomeRecord(vector<AmountInfo>& infos)
{
	int amount;
	string input;
	string remark;
	cout << "������������: ";
	getline(cin, input);
	stringstream(input) >> amount;

	cout << "��ע: ";
	getline(cin, remark);

	addRecord(infos, amount, remark);
	cout << "------ ���˳ɹ�! ------" << endl;
}

void addOutcomeRecord(vector<AmountInfo>& infos)
{
	int amount;
	string input;
	string remark;
	cout << "������֧�����: ";
	getline(cin, input);
	stringstream(input) >> amount;

	cout << "��ע: ";
	getline(cin, remark);

	addRecord(infos, -amount, remark);
	cout << "------ ���˳ɹ�! ------" << endl;
}

void accountingOperation(vector<AmountInfo>& infos, int option) {
	switch (option) 
	{
	case 1:
		addIncomeRecord(infos);
		break;
	case 2:
		addOutcomeRecord(infos);
		break;
	case 3:
		break;
	default:
		cout << "��������ȷ��ѡ��(1-3)" << endl;
	}
}

void printTotalRecords(vector<AmountInfo>& infos, int & total)
{
	cout << "+------------- ����֧ ------------+" << endl;
	cout << " ����\t\t" << "���\t\t" << "��ע " << endl;
	printRecords(infos, total);
	cout << "+---------------------------------+" << endl;
	cout << "����֧: " << total << endl;
}

void printIncomeRecords(vector<AmountInfo>& infos, int& total)
{
	cout << "+------------- �����¼ --------------+" << endl;
	cout << " ����\t\t" << "���\t\t" << "��ע " << endl;
	printRecords(infos, true, total);
	cout << "+-------------------------------------+" << endl;
	cout << "������: " << total << endl;
}

void printOutcomeRecords(vector<AmountInfo>& infos, int& total)
{
	cout << "+------------- ֧����¼ --------------+" << endl;
	cout << " ����\t\t" << "���\t\t" << "��ע " << endl;
	printRecords(infos, false, total);
	cout << "+-------------------------------------+" << endl;
	cout << "��֧��: " << total << endl;
}

void searchOperation(vector<AmountInfo>& infos, int option)
{
	int total = 0;
	switch (option)
	{
	case 1:
		printTotalRecords(infos, total);
		break;
	case 2:
		printIncomeRecords(infos, total);
		break;
	case 3:
		printOutcomeRecords(infos, total);
		break;
	case 4:
		break;
	default:
		cout << "��������ȷ��ѡ��(1-4)" << endl;
	}
	if (option != 4) {
		cout << "�����������~";
		cin.get();
	}
}