#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str[5];
	for(int i = 0 ; i < 5; i++)
	{ 
	cout << "�̸� >> ";
	getline(cin, str[i], '\n');
	}
	int str_big_index = 0;
	for (int i = 0; i < 5; i++)
	{
		if (str[i] > str[str_big_index])
		{
			str_big_index = i;
		}
	}
	cout << "�������� ���� �ڿ� ������ ���ڿ��� " << str[str_big_index] << endl;
	return 0;
}