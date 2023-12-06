#include <iostream>
#include <string>
using namespace std;
struct AmountInfo
{
	int amount;
	string remark;
	bool isIncome;
};

AmountInfo createAmountInfo(int amount, string remark)
{
	return { amount, remark, amount > 0 };
}

void printAmountInfo(AmountInfo amountInfo)
{
	cout << (amountInfo.isIncome ? "收入" : "支出") << '\t';
	printf("%8d\t", amountInfo.amount);
	cout << amountInfo.remark << endl;
}