#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> v;
	cout << "이름을 5개 입력하라" << endl;
	for (int i = 1; i <= 5; i++)
	{
		string str;
		cout << i << ">>";
		getline(cin, str);
		v.push_back(str);
	}
	int str_big_index = 0;
	for (int i = 0; i < 5; i++)
	{
		if (v[i] > v[str_big_index])
		{
			str_big_index = i;
		}
	}
	cout << "사전에서 가장 뒤에 나오는 이름은 " << v[str_big_index] << endl;
	return 0;
}