#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
	ת�����ѡ��
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
	// ������/���ȴ���1�򷵻�0��0����ʾ������ȷ��ѡ��
	return option;
}