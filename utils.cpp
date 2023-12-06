#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
	转换输出选项
*/
int parseOption()
{
	string input;
	int option = 0;
	getline(cin, input);
	if (input.length() == 1)
	{
		stringstream(input) >> option;
	}
	// 非数字/长度大于1则返回0，0会提示输入正确的选项
	return option;
}