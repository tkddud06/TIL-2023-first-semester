#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, string> dic;

	dic.insert(make_pair("love", "���"));
	dic.insert(make_pair("apple", "���"));
	dic["cherry"] = "ü��";

	cout << "����� �ܾ� ����" << dic.size() << endl;

	string eng;
	while (true)
	{
		cout << "ã�� ���� �ܾ�>> ";
		cin >> eng;
		if (eng == "exit")
		{
			break;
		}
		if (dic.end() == dic.find(eng))
		{
			cout << "����" << endl;
		}
		else
		{
			cout << dic[eng] << endl;
		}
	}
	cout << "�����մϴ�..." << endl;
	return 0;
}