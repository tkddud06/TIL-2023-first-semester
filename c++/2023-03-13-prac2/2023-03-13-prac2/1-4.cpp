#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	cout << "�� ��ȣ�� �Է��ϼ��� >> ";
	getline(cin, str1);
	cout << "�� ��ȣ�� �ٽ� �ѹ� �Է��ϼ��� >> ";
	getline(cin, str2);
	if (str1 == str2)
	{
		cout << "�����ϴ�." << endl;
	}
	else
	{
		cout << "���� �ʽ��ϴ�." << endl;
	}

	return 0;
}