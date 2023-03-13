#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	cout << "새 암호를 입력하세요 >> ";
	getline(cin, str1);
	cout << "새 암호를 다시 한번 입력하세요 >> ";
	getline(cin, str2);
	if (str1 == str2)
	{
		cout << "같습니다." << endl;
	}
	else
	{
		cout << "같지 않습니다." << endl;
	}

	return 0;
}