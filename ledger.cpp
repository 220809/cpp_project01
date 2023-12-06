#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct AmountInfo
{
	int amount;
	string remark;
	bool isIncome;
};
// 收支记录集合
vector<AmountInfo> amountInfos;

void printMainMenu();
int parseOption();
void loadAmountInfos(vector<AmountInfo>& infos);
void printAccountMenu();
void accountingOperation(vector<AmountInfo>& infos, int option);
void printSearchMenu();
void searchOperation(vector<AmountInfo>& infos, int option);

int main()
{
	bool flag = true;
	while (flag)
	{
		
		printMainMenu();
		int option = parseOption();
		switch (option)
		{
		case 1:
			while (true) {
				printAccountMenu();
				option = parseOption();
				accountingOperation(amountInfos, option);
				if (option == 3) {
					break;
				}
			}
			break;
		case 2:
			while (true) {
				printSearchMenu();
				option = parseOption();
				searchOperation(amountInfos, option);
				if (option == 4) {
					break;
				}
			}
			break;
		case 3:
		{
			cout << "您确定退出吗?(Y/N) ";
			string input;
			getline(cin, input);
			if (input == "Y") {
				flag = false;
			}
			break;
		}
		default:
			break;
		}
	}
}